#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct person {
    char name[200];
    int age;
} Person;



int new_person(char* name, int age) {
    Person person1;
    strcpy(person1.name,name);
    person1.age = age;
    int fd = open("pessoas.bin", O_CREAT | O_APPEND | O_RDWR, 0644);
    write(fd,&person1,sizeof(person1));
    //returna a posicao
    return ftell(fd) - sizeof(person1);
}

//nao testei merda nenhuma pode estar errado pesado
int person_change_age(char* name, int age) {
    int fd = open("pessoas.bin", O_RDWR, 0644);
    Person person1;
    while(read(fd,&person1,sizeof(person1))) {
        if(strcmp(person1.name, name) == 0) {
            person1.age = age;
            lseek(fd,-sizeof(person1),SEEK_CUR); //para voltar atras na posicao
            write(fd,&person1,sizeof(person1));
            return 0;
        }
    }
    return -1;
}

int person_change_age(long pos,int age) {
    int fd = open("pessoas.bin", O_RDWR, 0644);
    lseek(fd,pos,SEEK_SET);
    write(fd,&age,sizeof(int));
    return 0;
}

int main(int argc, char const *argv[])
{
    int fd = open("pessoas.bin", O_CREAT | O_APPEND | O_RDWR, 0644);

    Person person1;
    strcpy(person1.name, "Jose Mourinho");
    person1.age = 50;
    printf("Name: %s\n",person1.name);
    printf("Age: %d\n",person1.age);
    

    write(fd, &person1, sizeof(Person));

    Person person1_read;
    //reinicia a posicao de onde estamos no ficheiro
    lseek(fd, 0,SEEK_SET);

    if(read(fd, &person1_read, sizeof(Person)) > 0) {
        printf("personal1_read.name: %s\n", person1_read.name);
        printf("personal1_read.age: %d\n",person1_read.age);
    }
    close(fd);
    
    return 0;
}
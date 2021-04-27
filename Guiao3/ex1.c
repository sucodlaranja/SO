#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    if(fork() == 0) {
    execl("/bin/ls","ls","-l",NULL);
    perror("exec");
    _exit(0);
    }
    int status;
    wait(&status);

    printf("Exec done\n");
    return 0;
}
 
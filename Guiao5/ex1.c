#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pipefd[2];

    if(pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
    }

    int pid = -1;
    if((pid = fork()) == 0) {
        close(pipefd[1]); 

        char buf[10];
        int bytes = read(pipefd[0],buf,10);
        close(pipefd[0]);
        write(STDOUT_FILENO,buf, bytes);
        _exit(0);
    } else {
        close(pipefd[0]);

        char * str = "teste";
        
        write(pipefd[1], str, strlen(str));
        close(pipefd[1]);
        
        wait(NULL);
    }
    /* code */
    return 0;
}

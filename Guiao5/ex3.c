#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pipefd[2];
    if(pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
    }
    int pid;

    if((pid = fork()) == 0) {
        close(pipefd[1]);
        dup2(pipefd[0],STDIN_FILENO);
        close(pipefd[0]);
        execlp("wc","wc",NULL);
    } else {
        close(pipefd[0]);
        int bytes;
        char buf[10];
        while((bytes = read(STDIN_FILENO,buf,10)) > 0) {
            write(pipefd[1],buf, bytes);
        }
        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}

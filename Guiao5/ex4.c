#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pipefd[2];
    if(pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
    }

    if(fork() == 0) {
        close(pipefd[0]);
        dup2(pipefd[1],STDIN_FILENO);
        close(pipefd[1]);
        execlp("ls", "ls", "/etc", NULL);
        _exit(1);
    }

    close(pipefd[1]);

    if(fork() == 0) {
        dup2(pipefd[0],STDIN_FILENO);
        close(pipefd[0]);
        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }
    
    close(pipefd[0]);

    if(wait(NULL) == -1) puts("Error");
    if(wait(NULL) == -1) puts("Error");
    return 0;
}

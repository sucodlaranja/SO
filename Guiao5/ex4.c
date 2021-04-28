#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    if(pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }


    if(fork() == 0) {
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execlp("ls", "ls","/etc", NULL);
        _exit(1);
    }
    close(fd[1]);
    wait(NULL);
    
    if(fork() == 0) {
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("wc", "wc", "-l",NULL);
        _exit(1);
    }
    close(fd[0]);
    wait(NULL);

    return 0;
}

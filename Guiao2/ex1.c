#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    for(int i = 1; i <= 10; i++) {
        if(fork() == 0) {
            printf("[CHILD %d] Child pid %d\n",i,getpid());
            printf("[CHILD %d] Parent pid %d\n",i,getppid());
            
        } else {

            int status;
            int termitated_pid = wait(&status);
            printf("[parent] child pid %d, exit code %d\n",termitated_pid,WEXITSTATUS(status));
            _exit(i-1);
        }
    }
    _exit(10);
    /*ex4
    for(int i = 1; i<=10;i++) {
        if(fork() == 0) {
            printf("[CHILD %d] Child pid %d\n",i,getpid());
            printf("[CHILD %d] Parent pid %d\n",i,getppid());
            _exit(i);
        }
    }

    for(int i = 1;i <= 10;i++) {
        int status;
        int termitated_pid = wait(&status);
        printf("[parent] child pid %d, exit code %d\n",termitated_pid,WEXITSTATUS(status));
    }
    */
    /*ex3
    for(int i = 1; i <= 10; i++) {
        if(fork() == 0) {
            printf("[CHILD %d] Child pid %d\n",i,getpid());
            printf("[CHILD %d] Parent pid %d\n",i,getppid());
            _exit(i);
        } else {

            int status;
            int termitated_pid = wait(&status);
            printf("[parent] child pid %d, exit code %d\n",termitated_pid,WEXITSTATUS(status));
        }
    }
    */

   
    /*
    int child_pid;
    if((child_pid = fork()) == 0) {
        printf("[CHILD] Child pid %d\n",getpid());
        printf("[CHILD] Parent pid %d\n",getppid());
        _exit(5);
    } else {
        //se pai
        printf("[parent]pid: %d\n", getpid());
        printf("[parent]Parent pid: %d\n",getppid());
        printf("[parent] child pid: %d\n",child_pid);

        int status;
        int termitated_pid = wait(&status);
        printf("[parent] child pid %d, exit code %d\n",termitated_pid,WEXITSTATUS(status));
    }

    printf("exited %d\n",getpid());
    */
    return 0;
}

#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int i = 2;
    int pid[argc-2];
    int status;
    while(i < argc) {
        if((pid[i-2] = fork()) == 0) {
            execlp("grep", "grep", argv[1],argv[i],NULL);
            _exit(0);
        }
        
        
        wait(&status);
        if(status == 0) {
            printf("Process with pid %d found the word (%d file)\n",pid[i-2],i-1);
            for(int j = 0; j < argc-2;j++) {
                if(pid[j] != pid[i-2] && pid[j] >= 0) {
                kill(pid[j],SIGKILL);
                printf("%d killed\n",pid[j]);
                }
            }
            
        }
        
        i++;
    }
    return 0;
}

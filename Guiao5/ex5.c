#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char* comandos[4] = {"cut","-f7","-d","uniq"};
    int p[2][2];
    
    for(int i = 0; i < 4; i++) {

        if(i == 0) {
            if(pipe(p[0]) != 0) {
                perror("pipe");
                exit(1);
            }
            

            if(fork() == 0) {
                close(p[0][0]);
                dup2(p[0][1],1);
                close(p[0][1]);
                execlp("grep", "grep", "-v", "^#", "/etc/passwd",NULL);
                _exit(1);
            }
            
            close(p[0][1]);
        }

        else if(i == 3) {
            if(fork() == 0) {
                close(p[2][1]);
                dup2(p[2][0],0);
                close(p[2][0]);
                execlp("wc","wc","-l",NULL);
            }
            
            close(p[2][0]);
            close(p[2][1]);
        }

        else {
            if(pipe(p[i]) < 0) {
                perror("pipe");
                exit(1);
            }
            if(fork() == 0) {
                close(p[i][0]);

                dup2(p[i-1][0],0);
                close(p[i-1][0]);
                dup2(p[i][1],1);
                close(p[i][1]);
                
                if(i==1) execlp("cut", "cut", "-f7", "-d:", NULL);
                else execlp("uniq", "uniq", NULL);
                _exit(1);

            }
            close(p[i-1][0]);
        }

    }
    
    
    for(int i = 0; i < 4; i++) {
        wait(NULL);
    }
}

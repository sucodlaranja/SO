#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ctrl_c_counter = 0;
int seconds = 0;
void ctrl_c_handler(int signum) {
    printf("\nCTRL+C\n");
    printf("Time: %d s\n",seconds);
    ctrl_c_counter++;
}
void ctrl_backslash_handler(int signum) {
    printf("\nvezes clicadas em CTRL+C %d\n",ctrl_c_counter);
    exit(0);
}

void sigalrm_handler() {
    seconds++;
    alarm(1);
}

int main(int argc, char const *argv[])
{
    if(signal(SIGINT,ctrl_c_handler) == SIG_ERR) {
        perror("SIGINT ERROR");
    }
    if(signal(SIGQUIT,ctrl_backslash_handler) == SIG_ERR) {
        perror("SIGQUIT ERROR");
        exit(1);
    }
    if(signal(SIGALRM,sigalrm_handler) == SIG_ERR) {
        perror("SIGALRM ERROR");
        
    }
    
    alarm(1);
    while(1);
    return 0;
}

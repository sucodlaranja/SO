#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int random_max = 10000;
    int value = atoi(argv[1]);
    int rows = 10;
    int cols = 1800;
    int matriz[rows][cols];

    printf("Populate matrix with rando number between 0 and %d...\n",random_max);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matriz[i][j] = rand() % random_max;
        }
    }

    //create processes

    for(int i = 0; i < rows; i++) {
        if(fork() == 0) {
            for(int j = 0; j < cols; j++) {
            
                if(matriz[i][j] == value) {
                    _exit(i);
                }
            
            }
            _exit(255);
        }
    }

    int status;

    for(int i = 0; i < rows; i++) {
        pid_t terminated_pid = wait(&status);

        if(WIFEXITED(status)) {
            if(WEXITSTATUS(status) < 255) {
                printf("[PAI] process %d exited, found number at row: %d\n", terminated_pid,WEXITSTATUS(status));
            } else {
                printf("[PAI] process %d exited, nothing found\n", terminated_pid);
            }
        } else {
            printf("[PAI] process %d exited, something went wrong.\n", terminated_pid);
        }
    }
    return 0;
}
  
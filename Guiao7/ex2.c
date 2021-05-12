#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int i = 2;
    while(i < argc) {
        if(fork() == 0) {
            execlp("grep", "grep", argv[1],argv[i],NULL);
        }
    }
    return 0;
}

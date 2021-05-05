#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd = open("fifo",O_WRONLY);
    printf("Writing\n");
    printf("%s",argv[1]);
    if(write(fd,argv[1],strlen(argv[1])) == 0) {
        perror("write");
    }
    close(fd);
    return 0;
}

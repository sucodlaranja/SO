#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    if(mkfifo("fifo",0666) == -1) {
        perror("mkfifo");
    }

    int bytes_read;
    int logfile = open("log.txt",O_CREAT | O_TRUNC | O_WRONLY);
    int fd = open("fifo",O_RDONLY);
    char buffer[1024];
    
    printf("Reading\n");
    while (1)
    {
        if(open("fifo",O_RDONLY) != -1) {
        if((bytes_read = read(fd,buffer,1024)) > 0) {
            printf("Writing %s", buffer);
            write(logfile,buffer,bytes_read);
        }
        }
    }
    close(fd);
    close(logfile);
    return 0;
}

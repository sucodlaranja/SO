#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int bytes_read;
    int fd = open("fifo",O_RDONLY);
    char buffer[1024];
    printf("Reading\n");
    while ((bytes_read = read(fd,buffer,1024)) > 0)
    {
        write(STDOUT_FILENO,buffer,bytes_read);
    }
    close(fd);
    
    return 0;
}

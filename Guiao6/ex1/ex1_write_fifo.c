#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd = open("fifo",O_WRONLY);
    int bytes_read;
    char buffer[1024];
    printf("Writing\n");
    while ((bytes_read = read(STDIN_FILENO,buffer,1024)) > 0)
    {
        write(fd,buffer,bytes_read);
    }
    return 0;
}

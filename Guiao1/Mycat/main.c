#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char buffer[1024];
    ssize_t bytes_read = 0;
    while(bytes_read = read(0, buffer, 1024)) {
        write(STDOUT_FILENO,buffer,bytes_read);
    }
    return 0;
}

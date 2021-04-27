#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    execl("print_args", "ls", "arg1", "arg2", "arg3", NULL);
    perror("exec");
    return 0;
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_system(char * command) {
    return 0;
}

int my_systemv(char * execv_args[]) {
    int pid = 0;

    if((pid = fork()) == 0) {

    execvp(execv_args[0], execv_args);
        perror("execvp");
        _exit(255);


    } 

    int status = 0;

    if(waitpid(pid, &status, 0) < 0) {
        return -1;

        } 
        
    return WEXITSTATUS(status);
   
}

int main(int argc, char const *argv[])
{
    char * exec_args_ls[] = {
        "ls",
        "-l",
        NULL,
    };

    my_systemv(exec_args_ls);

    char * exec_args_print_args[] = {
        "./print_args",
        NULL,
    };

    my_systemv(exec_args_print_args);
    return 0;
}

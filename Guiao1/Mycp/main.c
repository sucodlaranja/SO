#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int main()
{
   int buffer_size =20;

    clock_t start_time = clock();
    int source = open("test.txt", O_RDONLY);
    
    int dest = open("copiado.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);

    char *buffer = malloc(buffer_size);
    ssize_t bytesRead;

    while((bytesRead = read(source, buffer, buffer_size)) > 0) {
        write(dest,buffer,bytesRead);
    }

    printf("Execution time = %lfs\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);

    close(source);
    close(dest);
    free(buffer);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    mkfifo("tmp/ex1", 0777);

    int fd = open("tmp/ex1", O_RDONLY);
    if (fd == -1)
    {
        printf("Error while opening pipe\n");
        return 1;
    }

    char message[1024];
    while (read(fd, message, sizeof(message)))
    {
        printf("%s", message);
        sleep(1);
    }
    close(fd);

    return EXIT_SUCCESS;
}

// mkfifo reference
// https://man7.org/linux/man-pages/man3/mkfifo.3.html
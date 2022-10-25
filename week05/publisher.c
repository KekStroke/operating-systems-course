#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    mkfifo("tmp/ex1", 0777);

    int fd = open("tmp/ex1", O_WRONLY);
    if (fd == -1)
    {
        printf("Error while opening pipe\n");
        return 1;
    }

    char message[1024];
    while (fgets(message, 1024, stdin))
    {

        for (int i = 0; i < n; i++)
        {
            if (write(fd, message, sizeof(message)) == -1)
            {
                printf("Error while writing message\n");
                return 2;
            }
        }
        sleep(1);
    }
    close(fd);

    return EXIT_SUCCESS;
}

// pipe reference
// https://man7.org/linux/man-pages/man2/pipe.2.html

// mkfifo reference
// https://man7.org/linux/man-pages/man3/mkfifo.3.html
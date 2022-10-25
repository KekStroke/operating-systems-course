#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1)
        return 1;

    pid_t id = fork();
    if (id == -1)
        return 2;

    if (id == 0)
    {
        // child process
        close(fd[0]);
        char message[1024];
        while (fgets(message, 1024, stdin))
        {
            write(fd[1], message, sizeof(message));
            sleep(1);
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char message[1024];
        while (read(fd[0], message, sizeof(message)))
        {
            printf("%s", message);
            sleep(1);
        }
        close(fd[0]);
    }

    return EXIT_SUCCESS;
}

// pipe reference
// https://man7.org/linux/man-pages/man2/pipe.2.html
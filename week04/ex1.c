#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t t;
    int n = 1;
    pid_t fork_id = fork();
    if (fork_id != 0)
    {
        pid_t fork_id = fork();
        if (fork_id == 0)
        {

            n += 2;
        }
    }
    else
    {
        n++;
    }
    t = clock();
    printf("%d: Process pid: %d,\tParent pid: %d \t (%f ms)\n", n, getpid(), getppid(), ((float)t) / CLOCKS_PER_SEC * 1000);

    return EXIT_SUCCESS;
}
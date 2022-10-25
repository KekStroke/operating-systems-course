#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// <WRITE YOUR CODE HERE>

int main(int argc, char **argv)
{

    int n;
    sscanf(argv[1], "%d", &n);

    printf("%d", n);
    for (int i = 0; i < n; i++)
    {
        fork();
        sleep(5);
    }

    return EXIT_SUCCESS;
}
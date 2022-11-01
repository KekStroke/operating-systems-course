#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MB 1024 * 1024

int main()
{
    struct rusage usage;

    for (int i = 0; i < 10; i++)
    {
        int *ptr = malloc(MB * 10);
        memset(ptr, 0, MB * 10);

        getrusage(RUSAGE_SELF, &usage);

        printf("Max resident set size: %ld\tIntegral shared memory size: %ld\tIntegral unshared data size: %ld\tIntegral unshared stack size: %ld\n", usage.ru_maxrss, usage.ru_ixrss, usage.ru_idrss, usage.ru_isrss);

        sleep(1);
    }
    return 0;
}
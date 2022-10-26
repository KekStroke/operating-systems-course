#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MB 1024 * 1024

int main()
{
    for (int i = 0; i < 10; i++)
    {
        int *ptr = malloc(MB * 10);
        memset(ptr, 0, MB * 10);
        sleep(1);
        free(ptr);
    }
    return 0;
}
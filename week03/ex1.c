#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int);

int main()
{
    const int x = 10;
    const int *q = &x;
    const int *const p = malloc(sizeof(const int) * 5);
    int *z = p;
    for (int i = 0; i < 5; i++)
    {
        z[i] = x;
        printf("%p\n", p + i);
    }
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", z + i);
    }
    for (int i = 0; i < 5; i++)
    {
        z[i] = foo(z[i]);
    }
    free(p);
    return 0;
}

int foo(int n)
{
    return 2022 - n;
}
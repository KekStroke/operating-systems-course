#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void *realloc(void *ptr, size_t n)
{
    if (ptr == NULL)
    {
        ptr = malloc(n);
    }
    if (n == 0)
    {
        free(ptr);
    }
    void *temp = malloc(n);
    if (n <= malloc_usable_size(ptr))
    {
        memcpy(temp, ptr, (int)n);
    }
    else
    {
        memcpy(temp, ptr, (int)malloc_usable_size(ptr));
    }

    free(ptr);
    return temp;
}

int main()
{
    /*Example taken from https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm*/
    char *str;
    /* Initial memory allocation */
    str = (char *)malloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %u\n", str, str);

    /* Reallocating memory */
    str = (char *)realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    /* Reallocating memory */
    str = (char *)realloc(str, 15);
    printf("String = %s,  Address = %u\n", str, str);

    free(str);

    return 0;
}
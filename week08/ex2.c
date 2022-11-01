#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MB 1024 * 1024 * 10

int main()
{
    // Add comments to your source code with your findings. for ex2'
    /*
    Ex2.
    I see only 0 values in si and so feilds. So I assume that swap memory is not being
    used on my pc. Most likely, it is because 10 MB is not enough to fill the main
    memory. If I used something like 1 GB or more, on last tries, it would show higher
    numbers for si and so.
    */

    // Add comments to your source code with your findings. for ex3
    /*
    Ex3.
    We can see that ex2 file is constantly using some memory in the %MEM column. This
    numbers are increasing identifying that each time more and more memory is being
    used. These values are growing from 0.1 to 1.4, then program terminates.
    */
    for (int i = 0; i < 10; i++)
    {
        int *ptr = malloc(MB * 10);
        memset(ptr, 0, MB * 10);
        sleep(1);
        free(ptr);
    }
    return 0;
}
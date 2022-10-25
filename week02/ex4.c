#include <stdio.h>
#include <string.h>

int count(char[], char);
void countAll(char[]);

int main(void)
{
    char str[256];
    fgets(str, 256, stdin);
    countAll(str);
    return 0;
}

void countAll(char str[])
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            count(str, str[i] - 'A' + 'a');
        else
            count(str, str[i]);
        if (i == size - 1)
            continue;
        printf(", ");
    }
}

int count(char str[], char c)
{
    int size = strlen(str);
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if ((str[i] == c) ^ (str[i] - 'A' == c - 'a'))
            counter++;
    }
    printf("%c:%d", c, counter);
    return counter;
}
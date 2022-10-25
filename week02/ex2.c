#include <stdio.h>
#include <string.h>

int main(void)
{
    char c;
    char str[256];
    while ((c = getchar()) != EOF)
    {
        if (c == '.')
            break;
        strncat(str, &c, 1);
    }
    int size = strlen(str);
    char revstr[size + 2];
    for (int i = 1; i <= size; i++)
    {
        revstr[i] = str[size - i];
    }
    revstr[0] = '"';
    revstr[size + 1] = '"';
    revstr[size + 2] = '\0';
    puts(revstr);
    return 0;
}
#include <stdio.h>

void triangle(int);
void square(int);
void angle(int);

int main(void)
{
    angle(7);
    triangle(4);
    square(7);
    return 0;
}

void square(int height)
{
    int width = 2 * height - 1;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < width; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
}

void triangle(int height)
{

    int width = 2 * height - 1;
    int spaces = height - 1;

    for (int i = 1; i <= width; i++)
    {
        int cur_height = height - spaces;
        for (int j = 0; j < height; j++)
        {
            if (j < cur_height)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
        if (i > width / 2)
            spaces++;
        else
            spaces--;
    }
    printf("\n");
}

void angle(int height)
{
    int width = 2 * height - 1;
    int len = 1;
    int mid = width / 2;

    for (int i = 1; i <= height; i++)
    {

        for (int j = 0; j < len; j++)
            printf("*");

        if (i <= mid)
            len++;
        else
            len--;

        printf("\n");
    }
    printf("\n");
}
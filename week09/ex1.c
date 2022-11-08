#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int hitRate = 0, missRate = 0, size = 0;
    printf("Page frames: \n");
    scanf("%d", &size);

    FILE *file;
    file = fopen("inputs.txt", "r");
    int current;
    int *AG = malloc(size * sizeof(int));
    memset(AG, 0, size);
    int *FR = malloc(size * sizeof(int));
    memset(FR, 0, size);

    while (fscanf(file, "%d", &current) != EOF)
    {
        int frameNum = -1;
        for (int i = 0; i < size; i++)
        {
            if (current == FR[i])
            {
                frameNum = i;
                break;
            }
        }
        if (frameNum == -1)
        {
            int min = 0;
            for (int i = 0; i < size; i++)
            {
                if (AG[i] < AG[min])
                {
                    min = i;
                }
            }
            AG[min] = 1 << 7;
            FR[min] = current;
            missRate++;
        }
        else
        {
            AG[frameNum] = (AG[frameNum] >> 1) | (1 << 7);
            hitRate++;
        }
    }

    printf("Hit rate:\t%d\n", hitRate);
    printf("Miss rate:\t%d\n", missRate);
    if (missRate != 0)
    {
        printf("hit/miss:\t%lf\n", (double)hitRate / (double)missRate);
    }

    free(AG);
    free(FR);
    fclose(file);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void clearFile()
{
    FILE *pFile;
    pFile = fopen("temp.txt", "w");
    if (pFile != NULL)
    {
        fclose(pFile);
    }
}

void writeToFile(int num)
{
    FILE *pFile;
    pFile = fopen("temp.txt", "a");
    if (pFile != NULL)
    {
        fprintf(pFile, "%d\n", num);
        fclose(pFile);
    }
}

int *readFromFile(int n)
{
    FILE *pFile;
    pFile = fopen("temp.txt", "r");
    int *nums = malloc(sizeof(int) * n);
    if (pFile != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(pFile, "%d[^\n]", nums + i);
        }
        fclose(pFile);
    }
    return nums;
}

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end)
{

    int result = 0;

    for (int i = start; i < end; i++)
    {
        result += u[i] * v[i];
    }

    return result;
}

int main(void)
{
    srand(time(NULL));
    clearFile();
    int m = 120;
    int u[m], v[m];

    for (int i = 0; i < m; i++)
    {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    int n;
    scanf("%d", &n);

    int split_size = m / n;

    pid_t main_process = getpid();
    pid_t processes[10];
    int offset = 0;

    for (int i = 0; i < n; i++)
    {
        if (getpid() == main_process)
        {
            processes[i] = fork();
        }
        if (getpid() != main_process)
        {
            writeToFile(dotprod(u, v, offset, offset + split_size));
            exit(EXIT_SUCCESS);
        }
        offset += split_size;
    }

    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }

    int res = 0;
    int *res_vec;
    res_vec = readFromFile(n);
    for (int i = 0; i < n; i++)
    {
        res += res_vec[i];
    }

    printf("%d\n", res);

    return EXIT_SUCCESS;
}

/*
Example:
Assume that
u = [u1, u2, u3, u4]
v = [v1, v2, v3, v4]
k=1 ==> n = 2 processes
Equally distribute the dot product calculation task. We have multiple ways to distribute the task equally.
1- A possible task distribution is as follows:
First process will calculate dot product for the first two components
Second process will calculate dot product for the last two components
The computation result of the first process is u1 * v1 + u2 * v2 ==> c1
The computation result of the second process is u3 * v3 + u4 * v4 ==> c2
2- Another possible distribution is as follows:
First process will calculate dot product for the even components
Second process will calculate dot product for the odd components
The computation result of the first process is u2 * v2 + u4 * v4 ==> c1
The computation result of the second process is u1 * v1 + u3 * v3 ==> c2
The file temp.txt will contain as follows: (format is not restricted)
-------------------
c1
c2
-------------------
The "main" process will aggregate all dot product computations of its children
It will read the lines and aggregate.
c1 + c2 ==> result of u * v
*/
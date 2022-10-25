#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

struct Thread
{
    pthread_t id;
    int i;
    char message[256];
};

void *func(void *arg)
{
    printf("%s", (*(struct Thread *)arg).message);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Thread threads[n];

    for (int i = 0; i < n; i++)
    {
        threads[i].i = i;
        sprintf(threads[i].message, "Hello from thread %d\n", i);
        pthread_create(&(threads[i].id), NULL, &func, threads + i);
        printf("Thread %d created\n", i);
        pthread_join(threads[i].id, NULL);
    }

    pthread_exit(NULL);

    // return EXIT_SUCCESS;
}
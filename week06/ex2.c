#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_PROC 10

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int arrival_time[MAX_PROC];
    int burst_time[MAX_PROC];
    int turn_around_time[MAX_PROC];
    int execution_time[MAX_PROC];
    int waiting_time[MAX_PROC];
    bool is_executed[MAX_PROC];

    int n, min_arrival_time = INT_MAX;
    double average_TAT = 0, average_WT = 0;

    printf("Enter amount of processes to execute:\n");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Arrival Time of process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Burst Time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);

        is_executed[i] = false;
        if (arrival_time[i] < min_arrival_time)
            min_arrival_time = arrival_time[i];
    }

    printf("\n");

    int cur_time = min_arrival_time;
    int i = 0;
    while (1)
    {
        cur_time = max(cur_time, arrival_time[i]);

        int idx = -1, min_burst_time = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (arrival_time[i] <= cur_time && !is_executed[j] && burst_time[j] < min_burst_time && arrival_time[j] <= cur_time)
            {
                idx = j;
                min_burst_time = burst_time[j];
            }
        }

        if (idx == -1)
            continue;

        is_executed[idx] = true;
        cur_time += burst_time[idx];
        execution_time[idx] = cur_time;

        turn_around_time[idx] = execution_time[idx] - arrival_time[idx];
        waiting_time[idx] = turn_around_time[idx] - burst_time[idx];

        average_TAT += (double)turn_around_time[idx] / n;
        average_WT += (double)waiting_time[idx] / n;

        i++;
        if (i >= n)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arival Time: %d\n", arrival_time[i]);
        printf("Burst Time: %d\n", burst_time[i]);
        printf("Turnaround Time: %d\n", turn_around_time[i]);
        printf("Waiting Time: %d\n", waiting_time[i]);
        printf("Execution Time: %d\n\n", execution_time[i]);
    }

    printf("Average TAT: %f\n", average_TAT);
    printf("Average WT: %f\n", average_WT);
}
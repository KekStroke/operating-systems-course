#include <stdio.h>

#define MAX_PROCESSES 10

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int arrival_time[MAX_PROCESSES];
    int burst_time[MAX_PROCESSES];
    int turn_around_time[MAX_PROCESSES];
    int execution_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];

    int n;
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
    }

    printf("\n");

    int cur_time = arrival_time[0];
    for (int i = 0; i < n; i++)
    {
        cur_time = max(cur_time, arrival_time[i]);
        cur_time += burst_time[i];
        execution_time[i] = cur_time;
        turn_around_time[i] = execution_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        average_TAT += (double)turn_around_time[i] / n;
        average_WT += (double)waiting_time[i] / n;
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
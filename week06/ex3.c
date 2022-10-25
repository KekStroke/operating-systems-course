#include <stdio.h>
#include <stdbool.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{

    int n, quant_size;
    double average_TAT = 0, average_WT = 0;

    printf("Enter amount of processes to execute:\n");
    scanf("%d", &n);

    int arrival_time[n];
    int burst_time[n];
    int turn_around_time[n];
    int execution_time[n];
    int waiting_time[n];
    int burst_time_finish[n];
    bool is_executed[n];

    printf("Enter Quantum size: ");
    scanf("%d", &quant_size);

    printf("Enter Arrival Time and Burst Time:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Arrival Time of process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Burst Time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);

        burst_time_finish[i] = burst_time[i];
        is_executed[i] = false;
    }

    int current_time = arrival_time[0], finish = 0;
    int i = 0;
    while (finish != n)
    {
        if (is_executed[i] == false && arrival_time[i] <= current_time)
        {
            if (burst_time[i] > quant_size)
            {
                current_time += quant_size;
                burst_time[i] -= quant_size;
            }
            else
            {
                is_executed[i] = true;
                current_time += burst_time[i];
                execution_time[i] = current_time;

                turn_around_time[i] = execution_time[i] - arrival_time[i];
                waiting_time[i] = turn_around_time[i] - burst_time_finish[i];

                average_TAT += (double)turn_around_time[i] / n;
                average_WT += (double)waiting_time[i] / n;
                finish++;
            }
        }
        i = (i + 1) % n;
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
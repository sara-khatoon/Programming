#include <stdio.h>
#include <limits.h>

void non_preemptive_sjf(int n, int arrival[], int burst[])
{
    int wt[n], tat[n], completed[n], time = 0, total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
        completed[i] = 0; // Initialize completed array

    printf("\nNon-Preemptive SJF:\n");

    for (int completed_count = 0; completed_count < n;)
    {
        int idx = -1, min_burst = INT_MAX;

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (!completed[i] && arrival[i] <= time && burst[i] < min_burst)
            {
                min_burst = burst[i];
                idx = i;
            }
        }

        if (idx != -1)
        {
            wt[idx] = time - arrival[idx];   // Waiting Time = Current Time - Arrival Time
            time += burst[idx];              // Update current time
            tat[idx] = wt[idx] + burst[idx]; // Turnaround Time = Waiting Time + Burst Time
            completed[idx] = 1;              // Mark process as completed
            total_wt += wt[idx];
            total_tat += tat[idx];
            completed_count++;
        }
        else
        {
            time++; // Increment time if no process has arrived yet
        }
    }

    printf("Avg Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Avg Turnaround Time: %.2f\n", (float)total_tat / n);
}

void preemptive_sjf(int n, int arrival[], int burst[])
{
    int remaining[n], wt[n], tat[n], time = 0, completed = 0;
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
        remaining[i] = burst[i]; // Initialize remaining burst times

    printf("\nPreemptive SJF (SRTF):\n");

    while (completed != n)
    {
        int idx = -1, min_remaining = INT_MAX;

        // Find the process with the shortest remaining burst time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_remaining)
            {
                min_remaining = remaining[i];
                idx = i;
            }
        }

        if (idx != -1)
        {
            remaining[idx]--; // Execute the process for 1 unit of time
            if (remaining[idx] == 0)
            { // If the process is completed
                completed++;
                int finish_time = time + 1;                        // Completion time is current time + 1
                wt[idx] = finish_time - burst[idx] - arrival[idx]; // WT = CT - BT - AT
                tat[idx] = finish_time - arrival[idx];             // TAT = CT - AT
                total_wt += wt[idx];
                total_tat += tat[idx];
            }
        }
        time++; // Increment time
    }

    printf("Avg Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Avg Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process %d Arrival & Burst: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    non_preemptive_sjf(n, arrival, burst);
    preemptive_sjf(n, arrival, burst);

    return 0;
}

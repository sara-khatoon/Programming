#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], wt[20], tat[20], ct[20];
    int pid[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort processes by Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Completion time calculation
    ct[0] = at[0] + bt[0]; // First process
    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            // If CPU is idle, start the process when it arrives
            ct[i] = at[i] + bt[i];
        } else {
            // Otherwise, continue execution
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Turnaround Time (TAT) and Waiting Time (WT) calculation
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // TAT = CT - AT
        wt[i] = tat[i] - bt[i]; // WT = TAT - BT
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}

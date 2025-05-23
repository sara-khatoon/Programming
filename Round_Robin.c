#include <stdio.h>
struct Process
{
    int id, at, bt, ct, tat, wt, remaining_bt;
};
int main()
{
    int n, quantum, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].remaining_bt = p[i].bt;
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    while (completed < n)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].remaining_bt > 0 && p[i].at <= time)
            {
                done = 0;
                if (p[i].remaining_bt > quantum)
                {
                    time += quantum;
                    p[i].remaining_bt -= quantum;
                }
                else
                {
                    time += p[i].remaining_bt;
                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    p[i].remaining_bt = 0;
                    completed++;
                }
            }
        }
        if (done)
            time++;
    }
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat,
               p[i].wt);
    }
    return 0;
}
#include <stdio.h>
struct Process
{
    int id, at, bt, ct, tat, wt, priority, completed;
};
int main()
{
    int n, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("Enter arrival time, burst time and priority for process %d: ", i + 1);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].completed = 0;
    }
    while (completed < n)
    {
        int idx = -1, highest = 9999;
        for (int i = 0; i < n; i++)
        {
            if (!p[i].completed && p[i].at <= time && p[i].priority < highest)
            {
                highest = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1)
        {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = 1;
            completed++;
        }
        else
        {
            time++;
        }
    }
    printf("\nID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
    }
    return 0;
}
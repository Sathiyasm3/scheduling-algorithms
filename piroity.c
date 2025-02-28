#include <stdio.h>

int main() {
    int n, at[10], bt[10], pri[10], rt[10], ct[10], tat[10], wt[10], completed = 0, time = 0, highest;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (AT BT Priority): ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        highest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (highest == -1 || pri[i] < pri[highest]) {
                    highest = i;
                }
            }
        }

        if (highest == -1) {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if (rt[highest] == 0) {
            completed++;
            ct[highest] = time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];
            atat += tat[highest];
            awt += wt[highest];
        }
    }

    atat /= n;
    awt /= n;

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT");
    printf("\n-------------------------------------------------");
    for (int i = 0; i < n; i++)
        printf("\nP%d\t%d\t%d\t%d\t\t%d\t%d\t%d", i + 1, at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);

    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}

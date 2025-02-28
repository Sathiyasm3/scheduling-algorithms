#include <stdio.h>

int main() {
    int n, at[10], bt[10], rt[10], ct[10], tat[10], wt[10], completed = 0, time = 0, min, shortest;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (AT BT): ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        min = 9999, shortest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = time + 1;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            atat += tat[shortest];
            awt += wt[shortest];
        }
        time++;
    }

    atat /= n;
    awt /= n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);
    return 0;
}

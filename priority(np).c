#include <stdio.h>

int main() {
    int n, at[10], bt[10], pri[10], ct[10], tat[10], wt[10], completed[10] = {0};
    float awt = 0, atat = 0, time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (AT BT Priority): ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
    }

    for (int i = 0; i < n; i++) {
        int highest = -1, pos = -1;
        for (int j = 0; j < n; j++) {
            if (!completed[j] && at[j] <= time) {
                if (pos == -1 || pri[j] < pri[pos]) {
                    pos = j;
                }
            }
        }
        if (pos == -1) {
            time++;
            i--;
        } else {
            ct[pos] = time + bt[pos];
            time = ct[pos];
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];
            atat += tat[pos];
            awt += wt[pos];
            completed[pos] = 1;
        }
    }

    atat /= n;
    awt /= n;

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d", i + 1, at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);

    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);
    return 0;
}

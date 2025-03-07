#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], wt[10], tat[10], ct[10], remaining_bt[10], n, i, j, time, tq;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process %d (AT BT): ", p[i]);
        scanf("%d %d", &at[i], &bt[i]);
        remaining_bt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int remaining_processes = n;
    time = 0;

    while (remaining_processes > 0) {
        for (i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (at[i] <= time) {
                    if (remaining_bt[i] > tq) {
                        time += tq;
                        remaining_bt[i] -= tq;
                    } else {
                        time += remaining_bt[i];
                        wt[i] = time - at[i] - bt[i];
                        tat[i] = wt[i] + bt[i];
                        remaining_bt[i] = 0;
                        remaining_processes--;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        ct[i] = at[i] + tat[i];
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    printf("\n-----------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}

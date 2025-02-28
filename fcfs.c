#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp, n;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process %d (AT BT): ", p[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }

    atat /= n;
    awt /= n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    printf("\n-----------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}


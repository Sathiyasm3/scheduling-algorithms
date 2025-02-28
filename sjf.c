#include <stdio.h>

int main() {
    int n, i, j, temp, pos;
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], completed[10] = {0};
    float awt = 0, atat = 0, currentTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process %d (AT BT): ", p[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    for (i = 0; i < n; i++) {
        pos = -1;
        for (j = 0; j < n; j++) {
            if (!completed[j] && at[j] <= currentTime) {
                if (pos == -1 || bt[j] < bt[pos]) {
                    pos = j;
                }
            }
        }

        if (pos == -1) {
            currentTime++;
            i--;
        } else {
            ct[pos] = currentTime + bt[pos];
            currentTime = ct[pos];
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];
            atat += tat[pos];
            awt += wt[pos];
            completed[pos] = 1;
        }
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

~          

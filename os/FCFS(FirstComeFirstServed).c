#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter Burst Time for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    // Calculate waiting time
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
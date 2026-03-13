#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], wt[n], tat[n], p[n];

    // Input burst time and priority
    printf("Enter Burst Time and Priority for each process:\n");
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sorting processes based on priority
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {
                int temp;

                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i] = p[j];  p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    // Calculate waiting time
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
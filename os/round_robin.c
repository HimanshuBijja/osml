#include <stdio.h>

int main() {
    int n, tq;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem_bt[n], wt[n], tat[n];
    
    printf("Enter Burst Time for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];   // remaining burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0;

    while(1) {
        int done = 1;

        for(int i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;

                if(rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if(done == 1)
            break;
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
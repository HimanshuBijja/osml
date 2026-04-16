#include <stdio.h>

int main() {
    int msize, psize, pages, n, i;

    printf("Enter size of main memory: ");
    scanf("%d", &msize);

    printf("Enter page size: ");
    scanf("%d", &psize);

    pages = msize / psize;
    printf("Total pages available = %d\n", pages);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process;
    for (i = 0; i < n; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process);

        int req = process / psize;
        if (process % psize != 0)
            req++;

        if (req <= pages) {
            printf("Process %d allocated %d pages\n", i + 1, req);
            pages -= req;
        } else {
            printf("Process %d cannot be allocated\n", i + 1);
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    int msize, psize, pages, frames;

    printf("Enter size of main memory: ");
    scanf("%d", &msize);

    printf("Enter page size: ");
    scanf("%d", &psize);

    pages = msize / psize;
    printf("Total number of pages available in memory = %d\n", pages);

    printf("Enter number of processes: ");
    scanf("%d", &frames);

    int process[frames];

    for(int i = 0; i < frames; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process[i]);

        int req_pages = process[i] / psize;

        if(process[i] % psize != 0)
            req_pages++;

        if(req_pages <= pages) {
            printf("Process %d is allocated %d pages\n", i + 1, req_pages);
            pages -= req_pages;
        } else {
            printf("Process %d cannot be allocated (Not enough memory)\n", i + 1);
        }
    }

    return 0;
}
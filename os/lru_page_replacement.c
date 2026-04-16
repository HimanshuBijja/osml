#include <stdio.h>

int main() {
    int n, f, i, j, flag, faults = 0, min, pos;

    printf("Enter pages and frames: ");
    scanf("%d %d", &n, &f);

    int p[n], fr[f], last[f];
    for (i = 0; i < f; i++) {
        fr[i] = -1;
        last[i] = -1;
    }

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++)
            if (fr[j] == p[i]) { flag = 1; last[j] = i; break; }

        if (!flag) {
            pos = -1;
            for (j = 0; j < f; j++)
                if (fr[j] == -1) { pos = j; break; }

            if (pos == -1) {
                min = last[0]; pos = 0;
                for (j = 1; j < f; j++)
                    if (last[j] < min) { min = last[j]; pos = j; }
            }

            fr[pos] = p[i];
            last[pos] = i;
            faults++;
            printf("Page %d -> Fault  [", p[i]);
            for (j = 0; j < f; j++) printf(" %d", fr[j]);
            printf(" ]\n");
        } else {
            printf("Page %d -> Hit\n", p[i]);
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}

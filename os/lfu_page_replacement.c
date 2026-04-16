#include <stdio.h>

int main() {
    int n, f, i, j, flag, faults = 0, min, pos;

    printf("Enter pages and frames: ");
    scanf("%d %d", &n, &f);

    int p[n], fr[f], freq[f];
    for (i = 0; i < f; i++) {
        fr[i] = -1;
        freq[i] = 0;
    }

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++)
            if (fr[j] == p[i]) { flag = 1; freq[j]++; break; }

        if (!flag) {
            pos = -1;
            for (j = 0; j < f; j++)
                if (fr[j] == -1) { pos = j; break; }

            if (pos == -1) {
                min = freq[0]; pos = 0;
                for (j = 1; j < f; j++)
                    if (freq[j] < min) { min = freq[j]; pos = j; }
            }

            fr[pos] = p[i];
            freq[pos] = 1;
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

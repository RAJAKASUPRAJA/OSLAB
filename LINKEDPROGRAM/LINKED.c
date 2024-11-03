#include <stdio.h>
#include <stdlib.h>  // for exit()

int main() {
    int f[50], p, i, j, k, a, st, len, n, c;
    
    // Initialize all blocks as unallocated
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    printf("Enter the number of blocks that are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers that are already allocated:\n");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < 50) {
            f[a] = 1;
        } else {
            printf("Invalid block number %d. Skipping.\n", a);
        }
    }

    while (1) {
        printf("Enter the starting index block and length: ");
        scanf("%d%d", &st, &len);

        k = len;
        
        for (j = st; j < (k + st); j++) {
            if (j >= 50) {
                printf("Block number %d is out of bounds. Stopping allocation.\n", j);
                break;
            }

            if (f[j] == 0) {
                f[j] = 1;
                printf("%d -> %d\n", j, f[j]);
            } else {
                printf("%d -> file is already allocated\n", j);
                k++;
            }
        }

        // Ask the user if they want to enter more files
        printf("Do you want to enter one more file? (yes-1 / no-0): ");
        scanf("%d", &c);
        if (c == 0) {
            break;
        }
    }

    return 0;
}

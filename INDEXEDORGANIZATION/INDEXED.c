#include <stdio.h>
#include <stdlib.h>  // for exit()

int f[50], i, k, j, inde[50], n, c, p;

int main() {
    // Initialize the file allocation array to 0 (unallocated)
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    while (1) {
        printf("Enter index block: ");
        scanf("%d", &p);

        if (f[p] == 0) {
            f[p] = 1;
            printf("Enter the number of files on index: ");
            scanf("%d", &n);
        } else {
            printf("Block already allocated\n");
            continue;  // Start over if block is already allocated
        }

        // Input file blocks
        printf("Enter the file blocks: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &inde[i]);
        }

        // Check if blocks are already allocated
        int block_allocated = 0;
        for (i = 0; i < n; i++) {
            if (f[inde[i]] == 1) {
                printf("Block %d already allocated\n", inde[i]);
                block_allocated = 1;
                break;
            }
        }

        if (block_allocated) {
            continue;  // Skip to the next index block if any block is already allocated
        }

        // Allocate blocks if none are already allocated
        for (j = 0; j < n; j++) {
            f[inde[j]] = 1;
        }

        // Display allocation results
        printf("\nAllocated\nFile indexed:");
        for (k = 0; k < n; k++) {
            printf("\n %d -> %d : %d", p, inde[k], f[inde[k]]);
        }

        // Check if user wants to continue
        printf("\nEnter 1 to enter more files and 0 to exit: ");
        scanf("%d", &c);
        if (c == 0) {
            break;
        }
    }

    return 0;
}


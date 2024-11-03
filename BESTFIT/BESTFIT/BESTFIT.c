#include <stdio.h>
#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest;
    static int bf[max] = {0}, ff[max] = {0}; // Initialize bf to 0 and ff to 0 for unallocated

    printf("\n\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the size of each memory block
    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    // Input the size of each file
    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // Apply Best Fit algorithm
    for (i = 0; i < nf; i++) {
        lowest = 10000; // Reset lowest for each file
        int block_index = -1;
        
        for (j = 0; j < nb; j++) {
            if (bf[j] == 0) {                // Check if block is free
                temp = b[j] - f[i];
                if (temp >= 0 && temp < lowest) {
                    lowest = temp;
                    block_index = j;
                }
            }
        }

        // If a suitable block was found
        if (block_index != -1) {
            ff[i] = block_index;              // Store block index for file
            bf[block_index] = 1;              // Mark block as allocated
            frag[i] = lowest;                 // Store the fragmentation value
        } else {
            ff[i] = -1;                       // Mark file as not allocated
        }
    }

    // Output allocation details
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", 
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }

    return 0;
}

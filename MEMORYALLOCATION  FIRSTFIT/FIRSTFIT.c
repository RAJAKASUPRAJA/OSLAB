#include <stdio.h>
#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max] = {0}, ff[max] = {0};  // Block and file allocation flags initialized to 0

    printf("\n\tMemory Management Scheme - First Fit");
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

    // Apply First Fit algorithm
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) {  // Check if block is free and can fit the file
                bf[j] = 1;                      // Mark block as allocated
                ff[i] = j;                      // Store block index in file allocation array
                frag[i] = b[j] - f[i];          // Calculate and store fragmentation
                break;
            }
        }
    }

    // Output allocation details
    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != 0 || (bf[ff[i]] && b[ff[i]] >= f[i])) {   // If block is assigned to the file
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", 
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }

    return 0;
}

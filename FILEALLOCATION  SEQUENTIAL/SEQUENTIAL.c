
#include <stdio.h>
#include <stdlib.h>  // for exit()

int main() {
    int f[50], i, st, j, len, c;
    
    // Initialize the array to 0
    for(i = 0; i < 50; i++)
        f[i] = 0;
    
    // Loop to allocate files
    while (1) {
        printf("\nEnter the starting block & length of file: ");
        scanf("%d%d", &st, &len);
        
        // Check for space availability and allocate blocks
        for(j = st; j < (st + len); j++) {
            if (f[j] == 0) {
                f[j] = 1;
                printf("\n%d -> %d", j, f[j]);
            } else {
                printf("\nBlock already allocated at %d", j);
                break;
            }
        }
        
        // Check if all blocks have been allocated
        if (j == (st + len)) {
            printf("\nThe file is allocated to disk.");
        }
        
        // Ask the user if they want to enter more files
        printf("\nDo you want to enter more files? (y-1/n-0): ");
        scanf("%d", &c);
        
        // Exit the loop if the user chooses not to continue
        if (c == 0) {
            break;
        }
    }
    
    return 0;
}

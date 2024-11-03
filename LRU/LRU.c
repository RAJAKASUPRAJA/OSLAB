#include <stdio.h>

int fr[3];

void display() {
    int i;
    printf("\n");
    for(i = 0; i < 3; i++)
        printf("\t%d", fr[i]);
}

int main() {
    int p[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int i, j, fs[3], index, k, l;
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3;

    // Initialize frame array with -1 to indicate empty frames
    for(i = 0; i < 3; i++) {
        fr[i] = -1;
    }

    for(j = 0; j < 12; j++) {
        flag1 = 0;
        flag2 = 0;

        // Check if the page is already in any frame
        for(i = 0; i < 3; i++) {
            if(fr[i] == p[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // If page is not in any frame and there is an empty frame
        if(flag1 == 0) {
            for(i = 0; i < 3; i++) {
                if(fr[i] == -1) {
                    fr[i] = p[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        // If page is not in any frame and all frames are full
        if(flag2 == 0) {
            for(i = 0; i < 3; i++)
                fs[i] = 0;

            // Check backward in the reference string for frame usage
            for(k = j - 1, l = 1; l <= frsize - 1; l++, k--) {
                for(i = 0; i < 3; i++) {
                    if(fr[i] == p[k]) fs[i] = 1;
                }
            }

            // Find a frame not recently used
            for(i = 0; i < 3; i++) {
                if(fs[i] == 0) {
                    index = i;
                    break;
                }
            }
            
            fr[index] = p[j];
            pf++; // Increment page fault count
        }

        display();
    }

    printf("\nNumber of page faults: %d", pf + frsize);
    getchar(); // To pause output in some environments
    return 0;
}

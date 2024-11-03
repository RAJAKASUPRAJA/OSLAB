#include <stdio.h>
#include <conio.h>

int fr[3];

void display() {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%d\t", fr[i]);
}

int main() {
    int i, j, page[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3, top = 0;

    // Initialize frame array with -1
    for (i = 0; i < frsize; i++) {
        fr[i] = -1;
    }

    // Process each page in the sequence
    for (j = 0; j < 12; j++) {
        flag1 = 0;
        flag2 = 0;

        // Check if the page is already in the frame
        for (i = 0; i < frsize; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // If page is not in frame and there's an empty spot
        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        // If page is not in frame and no empty spot, replace using FIFO
        if (flag2 == 0) {
            fr[top] = page[j];
            top++;
            pf++;
            if (top >= frsize)
                top = 0;
        }

        // Display the current state of frames
        display();
    }

    printf("\nNumber of page faults: %d\n", pf + frsize);

    return 0;
}

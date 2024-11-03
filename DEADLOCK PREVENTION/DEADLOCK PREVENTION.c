#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char job[10][10];
    int time[10], avail, temp[10], tem[10];
    int safe[10];
    int ind = 1, i, j, q, n, t;

    // Input: Number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Input: Job names and their times
    for (i = 0; i < n; i++) {
        printf("Enter job name and required time: ");
        scanf("%s %d", job[i], &time[i]);
    }

    // Input: Available resources
    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Initialize temp arrays to sort based on time
    for (i = 0; i < n; i++) {
        temp[i] = time[i];
        tem[i] = i;
    }

    // Sort jobs by their required time (temp) in ascending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                // Swap times
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
                
                // Swap indexes
                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;
            }
        }
    }

    // Find the safe sequence
    printf("Safe sequence is: ");
    for (i = 0; i < n; i++) {
        q = tem[i];  // Index of the job with current minimum time
        if (time[q] <= avail) {
            safe[ind] = q;  // Store job index in safe sequence
            avail -= time[q];  // Decrement available resources
            printf("%s ", job[safe[ind]]);
            ind++;
        } else {
            printf("\nNo safe sequence available.\n");
            return 0;
        }
    }

    // Print the full safe sequence with job names and times
    printf("\nSafe sequence with job times:\n");
    for (i = 1; i < ind; i++) {
        printf("%s %d\n", job[safe[i]], time[safe[i]]);
    }

    return 0;
}

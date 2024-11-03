#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int need[10][10];
    int i, j, k, n, m;
    int count = 0, c = 0;
    char finish[10];

    // Initialize finish array to 'n'
    for (i = 0; i < 10; i++) {
        finish[i] = 'n';
    }

    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    printf("Enter the claim matrix (max resource requirements for each process):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix (currently allocated resources for each process):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the resource vector (total resources available): ");
    for (i = 0; i < m; i++) {
        scanf("%d", &total[i]);
    }

    // Calculate the available resources
    for (i = 0; i < m; i++) {
        avail[i] = total[i];
        for (j = 0; j < n; j++) {
            avail[i] -= alloc[j][i];
        }
    }

    // Initialize work array with available resources
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    // Calculate the need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's algorithm for safe sequence
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 'n') {  // Process not finished
                c = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] <= work[j]) {
                        c++;
                    }
                }

                if (c == m) {  // All resources for process i can be allocated
                    printf("All resources can be allocated to Process %d\n", i + 1);
                    for (k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 'y';
                    found = 1;
                    count++;

                    printf("Current available resources after executing process %d: ", i + 1);
                    for (k = 0; k < m; k++) {
                        printf("%4d", work[k]);
                    }
                    printf("\n");
                }
            }
        }

        if (found == 0) {
            printf("\nThe system is not in a safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\n");
    printf("The given state is a safe state.\n");

    return 0;
}

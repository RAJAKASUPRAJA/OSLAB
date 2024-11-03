#include <stdio.h>
#include <stdlib.h>

int tph, philname[20], status[20], howhung, hu[20], cho;

// Function prototypes
void one();
void two();

int main() {
    int i;
    printf("\n\nDINING PHILOSOPHER PROBLEM");
    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &tph);

    // Initialize philosopher names and statuses (1 = thinking)
    for (i = 0; i < tph; i++) {
        philname[i] = (i + 1);
        status[i] = 1;
    }

    printf("How many philosophers are hungry: ");
    scanf("%d", &howhung);

    // Check for deadlock scenario
    if (howhung == tph) {
        printf("\nAll philosophers are hungry. Deadlock stage will occur.");
        printf("\nExiting\n");
        return 0;
    } else {
        // Input positions of hungry philosophers
        for (i = 0; i < howhung; i++) {
            printf("Enter philosopher %d position: ", (i + 1));
            scanf("%d", &hu[i]);
            status[hu[i]] = 2; // 2 = hungry
        }

        do {
            printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit");
            printf("\nEnter your choice: ");
            scanf("%d", &cho);

            switch (cho) {
                case 1:
                    one();
                    break;
                case 2:
                    two();
                    break;
                case 3:
                    return 0;
                default:
                    printf("\nInvalid option.");
            }
        } while (1);
    }
}

// Function to allow one philosopher to eat at a time
void one() {
    int pos = 0, x, i;
    printf("\nAllowing one philosopher to eat at a time\n");

    for (i = 0; i < howhung; i++, pos++) {
        printf("\nP %d is granted to eat", philname[hu[pos]]);
        
        // Display waiting philosophers
        for (x = pos + 1; x < howhung; x++) {
            printf("\nP %d is waiting", philname[hu[x]]);
        }
    }
}

// Function to allow two philosophers to eat at a time
void two() {
    int i, j, s = 0, t, r, x;
    printf("\nAllowing two philosophers to eat at the same time\n");

    for (i = 0; i < howhung; i++) {
        for (j = i + 1; j < howhung; j++) {
            // Ensure that philosophers are not immediate neighbors to avoid deadlock
            if (abs(hu[i] - hu[j]) >= 2) {
                printf("\n\nCombination %d", (s + 1));
                t = hu[i];
                r = hu[j];
                s++;

                printf("\nP %d and P %d are granted to eat", philname[t], philname[r]);

                // Display other philosophers as waiting
                for (x = 0; x < howhung; x++) {
                    if (hu[x] != t && hu[x] != r) {
                        printf("\nP %d is waiting", philname[hu[x]]);
                    }
                }
            }
        }
    }
}

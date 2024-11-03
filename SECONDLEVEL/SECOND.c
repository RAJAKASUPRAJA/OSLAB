#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct {
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir[10];

int main() {
    int i, ch, dcnt = 0, k;
    char f[30], d[30];

    while (1) {
        printf("\n\n1. Create Directory\t2. Create File\t3. Delete File");
        printf("\n4. Search File\t\t5. Display\t6. Exit\t Enter your choice -- ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (dcnt < 10) {
                    printf("\nEnter name of directory -- ");
                    scanf("%s", dir[dcnt].dname);
                    dir[dcnt].fcnt = 0;  // Initialize file count for new directory
                    dcnt++;
                    printf("Directory created\n");
                } else {
                    printf("Maximum directory limit reached\n");
                }
                break;

            case 2:
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        if (dir[i].fcnt < 10) {  // Ensure not to exceed the file limit
                            printf("Enter name of the file -- ");
                            scanf("%s", dir[i].fname[dir[i].fcnt]);
                            dir[i].fcnt++;
                            printf("File created\n");
                        } else {
                            printf("Maximum file limit reached in directory %s\n", d);
                        }
                        break;  // Exit the directory loop after creating the file
                    }
                }
                if (i == dcnt) {
                    printf("Directory %s not found\n", d);
                }
                break;

            case 3:
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter name of the file -- ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is deleted\n", f);
                                dir[i].fcnt--;
                                strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]); // Move last file to the deleted spot
                                break;
                            }
                        }
                        if (k == dir[i].fcnt) {
                            printf("File %s not found\n", f);
                        }
                        break; // Exit the directory loop
                    }
                }
                if (i == dcnt) {
                    printf("Directory %s not found\n", d);
                }
                break;

            case 4:
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file -- ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is found\n", f);
                                break; // Exit the loop if found
                            }
                        }
                        if (k == dir[i].fcnt) {
                            printf("File %s not found\n", f);
                        }
                        break; // Exit the directory loop
                    }
                }
                if (i == dcnt) {
                    printf("Directory %s not found\n", d);
                }
                break;

            case 5:
                if (dcnt == 0) {
                    printf("\nNo directories available\n");
                } else {
                    printf("\nDirectory\tFiles\n");
                    for (i = 0; i < dcnt; i++) {
                        printf("%s\t\t", dir[i].dname);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            printf("\t%s", dir[i].fname[k]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 6:
                return 0; // Exit the program

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

#include <stdio.h>

#include "utils.h"

void show_menu() {
    printf("--------------------------\n");
    printf("|      MONSTER LIST      |\n");
    printf("--------------------------\n");
    printf("| 1. Filter by name      |\n");
    printf("| 2. Filter by HP        |\n");
    printf("| 3. Filter by AC        |\n");
    printf("| 4. Filter by stats     |\n");
    printf("| 5. Exit                |\n");
    printf("--------------------------\n");
}

int main(int argc, char *argv[]) {
    // TODO: Validate input arguments
    // TODO: Attempt to open file given by first command line argument
    FILE *fp = NULL;
    // TODO: Load monsters

    // Run menu loop
    int choice = 0;
    while (choice != EXIT_CHOICE) {
        show_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // TODO: Implement name filtering
                // TODO: Filter by name and print
                break;
            case 2:
                // TODO: Implement HP filtering
                // TODO: Filter by HP and print
                break;
            case 3:
                // TODO: Implement AC filtering
                // TODO: Filter by AC and print
                break;
            case 4:
                // TODO: Implement stats filtering
                // TODO: Filter by stats and print
                break;
            case 5:
                if (fp) {
                    fclose(fp);
                }
                break;
        }
    }
    return 0;
}

#include <stdio.h>

int main() {
    while (1) {
        int c = 0;

        printf("1. Start\n");
        printf("2. Load\n");
        printf("3. Save\n");
        printf("4. Exit\n");

        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Starting game.\n");
                break;
            case 2:
                printf("Loading game.\n");
                break;
            case 3:
                printf("Saving game.\n");
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}

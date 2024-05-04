#include <stdio.h>
#include <string.h>

int main(void)
{
    double num[4]= {0,0,0,0};
    int i = 0;

    printf("Enter the first number: ");
        scanf("%lf", &num[0]);
    printf("Enter the second number: ");
        scanf("%lf", &num[1]);
    printf("Enter the third number: ");
        scanf("%lf", &num[2]);
    printf("Enter the fourth number: ");
        scanf("%lf", &num[3]);

    printf("Array: [%lf, %lf, %lf, %lf]\n", num[0],num[1],num[2],num[3]);

    printf("Menu:\n");
    printf("1: Change a number \n");
    printf("2: Print a number \n");
    printf("3: Swap array positions \n");
    printf("\nEnter your choice: ");
        scanf("%d", &i);
    int pos = 0;
    double topos = 0;
    int input1 = 0;
    int input2 = 0;
    double swap = 0;
    switch(i)
    {
    case 1:
        printf("Which position do you want to change (0, 1, 2, 3)? ");
            scanf("%d", &pos);
        switch(pos)
        {
        case 0:

            printf("What number do you want to change to? ");
                scanf("%lf", &topos);
            num[0] = topos;
            break;
        case 1:
            printf("What number do you want to change to? ");
                scanf("%lf", &topos);
            num[1] = topos;
            break;
        case 2:
            printf("What number do you want to change to? ");
                scanf("%lf", &topos);
            num[2] = topos;
            break;
        case 3:
            printf("What number do you want to change to? ");
                scanf("%lf", &topos);
            num[3] = topos;
            break;
        default:
            printf("\nInvalid position.");
            break;
        }
        printf("\nArray: [%lf, %lf, %lf, %lf]", num[0],num[1],num[2],num[3]);
        break;
    case 2:
        printf("Which position would you like to print (0, 1, 2, 3)? ");
            scanf("%d", &pos);
        switch(pos)
        {
        case 0:
            printf("Value at index %d: %lf", pos, num[0]);
            break;
        case 1:
            printf("Value at index %d: %lf", pos, num[1]);
            break;
        case 2:
            printf("Value at index %d: %lf", pos, num[2]);
            break;
        case 3:
            printf("Value at index %d: %lf", pos, num[3]);
            break;
        default:
            printf("\nInvalid position.");
            break;
        }
        printf("\nArray: [%lf, %lf, %lf, %lf]", num[0],num[1],num[2],num[3]);
        break;


    case 3:

        printf("List the positions you want to swap separated by a space (e.g. 0 3): ");
            scanf("%d %d", &input1,&input2);

        switch(input1)
        {
        case 0:
            swap = num[0];
            num[0] = num[input2];
            num[input2] = swap;
            printf("Swap %lf with %lf", num[0], num[input2]);

            break;
        case 1:
            swap = num[1];
            num[1] = num[input2];
            num[input2] = swap;
            printf("Swap %lf with %lf", num[1], num[input2]);

            break;
        case 2:
            swap = num[2];
            num[2] = num[input2];
            num[input2] = swap;
            printf("Swap %lf with %lf", num[2], num[input2]);
            break;
        case 3:
            swap = num[3];
            num[3] = num[input2];
            num[input2] = swap;
            printf("Swap %lf with %lf", num[3], num[input2]);
            break;
        default:
            printf("\nInvalid input.");
            break;
        }
        printf("\nArray: [%lf, %lf, %lf, %lf]", num[0],num[1],num[2],num[3]);
        break;


    default:
        printf("\nInvalid menu choice.");
        break;
    }



    return 0;
}

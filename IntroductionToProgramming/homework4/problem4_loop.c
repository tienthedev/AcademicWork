#include <stdio.h>

int main(void)
{
    int num = 0;
    int i = 0;
        do
        {
            int num = 0;

            printf("Please enter an interger: ");
            scanf("%d", &num);

            int rem_2 = num % 2;
            int rem_3 = num % 3;

            if(num < 0)
            {
                printf("The number is negative.\n");
            }
            else if((rem_2 == 0) && (rem_3 == 0))
            {
                printf("The number is even and divisible by 3.\n");
            }
            else if((rem_2 != 0) && (rem_3 == 0))
            {
                printf("The number is odd and divisible by 3.\n");
            }
            else if((rem_2 == 0) && (rem_3 != 0))
            {
                printf("The number is even and not divisible by 3.\n");
            }
            else
            {
                printf("The number is odd and not divisible by 3.\n");
            }
            i++;
        }
        while(i < 5);
    return 0;
}
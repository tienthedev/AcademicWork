#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Welcome to the Ridiculon Advanced Numerical Terminal\n");
    printf("Enter a number: ");
    double num = 0;
    scanf("%lf", &num);
    double betterNum = (num * 12.334) / 5;
    printf("Hmm, a better number would be %lf\n", betterNum);
    return 0;

}
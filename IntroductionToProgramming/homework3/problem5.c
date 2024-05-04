#include <stdio.h>
#include <math.h>


int main(void)
{
    int days = 0;
    
    printf("Enter a number of days: ");
    scanf("%d", &days);
    
    int years = days / 365;
    int dayRemain = days % 365;
    int weeks = dayRemain / 7;
    dayRemain = dayRemain % 7;

    printf("%.0d days is equal to: %.0d years, %.0d weeks, %.0d days.\n", days, years, weeks, dayRemain);
    printf("\nNOTE: Empty field means the value = 0, (example: *1 year,   week, 3 days*).");

    
}
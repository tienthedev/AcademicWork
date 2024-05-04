#include <stdio.h>

int main(void)
{
    //declaring the variable of the formula for area and perimeter
    double length = 0; 
    double width = 0;

    //ask user to enter the value for length
    printf("Enter the rectangle length: ");
    length = scanf("%lf", length);

    //ask user to enter the value for width
    printf("Enter the rectangle width: ");
    width = scanf("%lf", width);
    //declareing variables area and perimeter and assigning the formula for it.
    double area = length * width;
    double perimeter = (length + width)*2;

    //calculate and print the result
    printf("The area is: %.3f\n", area);
    printf("The perimeter is: %.3f\n", perimeter);

    //finish and exit code 0
    return 0;
}
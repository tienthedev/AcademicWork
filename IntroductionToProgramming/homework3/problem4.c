#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("HOUR CALCULATOR\n");
    double EmpID = 0;
    double workHr = 0;
    double rate = 0;
    printf("Enter employee ID: ");
    scanf("%lf", &EmpID);
    printf("Enter hours worked: ");
    scanf("%lf", &workHr);
    printf("Enter hourly rate: ");
    scanf("%lf", &rate);
    double earnMoney = workHr * rate;
    printf("Employee %1.lf earned $%4.2lf\n", EmpID, earnMoney);
    return 0;
}
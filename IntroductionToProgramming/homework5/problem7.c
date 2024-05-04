#include <stdio.h>

int main(void)
{
    int m,n;
    int c=0;

    printf("Enter an integer M: ");
    scanf("%d", &m);

    printf("Enter an integer N: ");
    scanf("%d", &n);
    for(int i = m; i<= n;i++)
    {
        if(i % 11 == 0)
            {
                c++;
            }
    }

    printf("%d numbers between %d and %d are multiples of 11.", c,m,n);


    return 0;

}

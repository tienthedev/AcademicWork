#include <stdio.h>

int main(void)
{
    int l,h;

    printf("Enter low: ");
    scanf("%d", &l);

    printf("Enter high: ");
    scanf("%d", &h);

    if(l <= h)
    {
        for(int n = l; n <= h; n++)
        {
            if(n % 4 != 0)
            {
                printf("%d\n", n);
            }
        }
    }
    else if(l > h)
    {
            printf("no numbers found");

    }
    return 0;

}

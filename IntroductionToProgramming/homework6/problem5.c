#include <stdio.h>
#define PI 3.14159

float cubeFloat(float number)
{
    return number*number*number;
}

float getRadius()
{

    float number = 0;
    do
    {
        number = 0;
        printf("Enter a radius >= 0 or -1 to quit: ");
        scanf("%f", &number);
        if((number < -1))
        {
            printf ("The number should be >= -1.\n");
        }
    }
    while(number < -1);
    number = cubeFloat(number);
    return number;
}

float sphereVolume(float radius)
{
    float volume = (4.00/3.00)* PI * radius;
    return volume;
}
int main()
{
    float radius = getRadius();
    while (radius != -1)
    {
        float volume = sphereVolume(radius);
        printf("Volume = %.2f\n\n", volume);
        radius = getRadius();
    }

    return 0;
}

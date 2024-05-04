#include "car.h"
void Trim(char *str[])
{
    if(str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] == 0;
    }
}
struct Car AddCar()
{
    char name[BUFFER_SIZE] = 0;
    fgets(name, BUFFER_SIZE, stdin);
    Trim(name);
    struct Car car;
    return car;
}
int main(int argc, char argv[])
{
    int buffer = 0;
    FILE *stream = fopen("car.csv", "r+");

    struct Car car = AddCar();
    printf("Menu:\n1. Add car\n2. View inventory\n\n>");
    fgets(buffer, BUFFER_SIZE, stdin);
    switch(buffer)
    {
        case 1:
        AddCar();
        break;
        case 2:
        AddCar();
        break;
        default:
        return 0;
        break;
    }
    fclose(stream);

    return 1;
}
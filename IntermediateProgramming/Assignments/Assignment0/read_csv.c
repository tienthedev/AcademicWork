#include <stdio.h>
#include <string.h>
#define BUF_SIZE 1024
int main(void)
{
    //declare input varables
    printf("Tien Dung Le (ID: 1002024297)\n");
    char filename[BUF_SIZE] = {0};
    //get file name
    printf("Enter a filename: "); 
    fgets(filename, BUF_SIZE, stdin);
    filename[strlen(filename) - 1] = 0;
    //open file stream with the input filename from user
    FILE *stream = fopen(filename, "r+");
    if(!stream)
    {
        printf("Error opening file");
        return 0;
    }
    while(fgets(filename, BUF_SIZE, stream))
    {
        filename[strlen(filename) -1 ]=0;
        printf("%s\n", filename);
    }
    fclose(stream);

    return 1;
}

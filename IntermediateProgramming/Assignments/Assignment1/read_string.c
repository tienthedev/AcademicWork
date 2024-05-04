#include <stdio.h>
#include <string.h>
#define ROWS 4
#define COLS 32

int main() 
{
    //initialize the 2d array and other vars
    char arr[ROWS][COLS] = {0};
    int r, smallest = 0;
    for(int r = 0; r < ROWS; r++)
    {
        printf("String %d: ", r+1);
        fgets(arr[r], sizeof(arr), stdin);
        arr[r][strlen(arr[r])-1] = '\0';
        //printf("%s", arr[r]); <= USE THIS TO TEST PRINT STRINGS

    }
    
    int h = 0;
    do{
        for(int r = 0; r < ROWS; r++)
        {
        char oldRow[COLS] = {0};
        if(strlen(arr[r+1]) > strlen(arr[r]))
        {
            for(int c = 0; c < COLS; c++)
            {
                oldRow[c] = arr[r][c];
                arr[r][c] = arr[r+1][c];
                arr[r+1][c] = oldRow[c];
            }
        }
        } h++;
    }while(h<3);    
    for(int r = 0; r< ROWS; r++)
    {
        printf("%d. %s\n", r+1, arr[r]);
    }
    
    return 0;
}
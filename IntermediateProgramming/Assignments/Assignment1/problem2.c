#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256
char CompareString(char str[BUFFER_SIZE], char ToCompare, int index)
{
    for(index = 0; index < strlen(str); index++)
    {
        if(str[index] == ToCompare)
        {
            return '*';
        }
    }
    
}

int main() 
{
    char str0[BUFFER_SIZE], str1[BUFFER_SIZE] = { 0 };
    int index = 0;
    char ToCompare = 0;


    //GET INPUT AND CHECK IF STRING SIZE <=5
    printf("Enter the first string: ");
    fgets(str0, BUFFER_SIZE, stdin);
    //REMOVE NEWLINE FOR THE FIRST STRING
    str0[strlen(str0) - 1] = '\0';
    if(strlen(str0) != 5)
    {
        printf("Both strings must contain 5 characters. Existing... ");
        return 0;
    }
    printf("Enter the second string: ");
    fgets(str1, BUFFER_SIZE, stdin);
    //REMOVE NEWLINE FOR THE SECOND STRING
    str1[strlen(str1) - 1] = '\0';
    if(strlen(str1) != 5)
    {
        printf("Both strings must contain 5 or fewer character. Existing... ");
        return 0;
    }

    //FUNCTION CALL TO COMPARE STRING
    printf("%s\n", str0);
    for(index = 0; index < strlen(str0); index++)
    {
        char star = CompareString(str1, str0[index], index);
        if(star == '*')
        {
            if(str0[index] != str1[index])
            {
                printf("^");
            }
            else
            {
                printf("*");
            }
            
        }
        else
        {
            printf(" ");
        } 
    }
    //END OF PROGRAM
    return 1;
}

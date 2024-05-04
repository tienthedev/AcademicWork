#include <stdio.h>

char *FindAddress(char *buffer) 
{
    while (*buffer != '\0') 
    {
        if (*buffer == '?') 
        {
            return buffer;
        }
        buffer++; 
    }
    return NULL;
}
int main() 
{
    char buffer[] = "What is your name?";
    char* addy = FindAddress(buffer);
    printf("Address of question mark: %p\n", addy);
    return 0;
}
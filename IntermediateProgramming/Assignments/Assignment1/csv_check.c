#include "csv_check.h"
void NewLineDel(char *buffer) 
{
    int i = strlen(buffer);
    if (buffer[i-1] == '\n') 
    {
        buffer[i-1] = 0;
    }
}
int Validate(char *original) 
{
    char *buffer= strdup(original);

    int attribute = 0;
    char *token = strtok(buffer, ",");
    
    while (token != NULL) 
    {
        attribute++;
        token = strtok(NULL, ",");
    }
    if(attribute < 4)
    {    
        printf("Invalid on line: ");
        return 0;
    }
    return 1;

}

int main()
{
    char buffer[BUFFER_SIZE], filename[BUFFER_SIZE] = {0};
    bool valid = true;

    printf("Enter filename: ");
    fgets(filename,sizeof(filename),stdin); 
    filename[strlen(filename) -1] = '\0';

    FILE *stream = fopen(filename, "r+");
    if(stream == NULL)
    {
        printf("File <%s> not found." , filename);
        return 1;
    }
    while (fgets(buffer, BUFFER_SIZE, stream) != NULL) 
    {
        NewLineDel(buffer);
        int validSignal = Validate(buffer);
        if(validSignal == 0)
        {    
            printf("%s\n", buffer);
            valid = false;
        }
    }
    
    if(valid == true)
    {
        printf("File <%s> is valid.", filename);
    }
    fclose(stream);
    return 0;
}

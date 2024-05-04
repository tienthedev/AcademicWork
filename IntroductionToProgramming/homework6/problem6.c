#include <stdio.h>
#include <string.h>

int countOccurrences(char word[], char c)
{
    int max_count = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i]== c)
        {
            max_count++;
        }

    }
    return max_count;
}
char mostFrequentCharacter(char word[])
{
    char max_char;
    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i+1] == word[i])
        {
            max_char = word[i];
        }
    }
    return max_char;
}
int main()
{
    char word[51];
    printf("Enter a word or q to quit: ");
    scanf("%50s", word);

    while (strcmp(word, "q") != 0 && strcmp(word, "Q") != 0)
    {
        char c = mostFrequentCharacter(word);
        int count = countOccurrences(word, c);
        printf("Most frequent character: %c\n", c);
        printf("Number of occurrences of %c: %d\n\n", c, count);

        printf("Enter a word or q to quit: ");
        scanf("%50s", word);
    }
    return 0;
}

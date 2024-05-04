#include <stdio.h>
#include<string.h>


int main(void)
{
    char input[20];
    printf("Please enter a word: ");
    scanf("%s", input);
    switch(tolower(input[0]))
    {
        //CHECK FOR VOWEL
        case 'a':
            printf("%s starts with a vowel.", input);
            break;
        case 'e':
            printf("%s starts with a vowel.", input);
            break;
        case 'i':
            printf("%s starts with a vowel.", input);
            break;
        case 'o':
            printf("%s starts with a vowel.", input);
            break;
        case 'u':
            printf("%s starts with a vowel.", input);
            break;
//CHECK FOR CONSONANT
        case 'b':
            printf("%s starts with a consonant.", input);
            break;
        case 'c':
            printf("%s starts with a consonant.", input);
            break;
        case 'd':
            printf("%s starts with a consonant.", input);
            break;
        case 'f':
            printf("%s starts with a consonant.", input);
            break;
        case 'g':
            printf("%s starts with a consonant.", input);
            break;
        case 'j':
            printf("%s starts with a consonant.", input);
            break;
        case 'k':
            printf("%s starts with a consonant.", input);
            break;
        case 'l':
            printf("%s starts with a consonant.", input);
            break;
        case 'm':
            printf("%s starts with a consonant.", input);
            break;
        case 'n':
            printf("%s starts with a consonant.", input);
            break;
        case 'p':
            printf("%s starts with a consonant.", input);
            break;
        case 'q':
            printf("%s starts with a consonant.", input);
            break;
        case 's':
            printf("%s starts with a consonant.", input);
            break;
        case 't':
            printf("%s starts with a consonant.", input);
            break;
        case 'v':
            printf("%s starts with a consonant.", input);
            break;
        case 'x':
            printf("%s starts with a consonant.", input);
            break;
        case 'h':
            printf("%s starts with a consonant.", input);
            break;
        case 'r':
            printf("%s starts with a consonant.", input);
            break;
        case 'w':
            printf("%s starts with a consonant.", input);
            break;
        case 'y':
            printf("%s starts with a consonant.", input);
            break;
        default:
            printf("%s starts with neither a vowel nor a consonant.", input);
    }
    return 0;
}

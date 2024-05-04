#include "spell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MAX_LEN:
Student answer:  Theta(T x D x MAX_LEN^2)

*/

int min(int x, int y, int z) {
    return (x < y ? (x < z ? x : z) : (y < z ? y : z));
}

void print_table(int **table, int len1, int len2, char *str1, char *str2) {
    int i, j;
    printf("        ");
    for (j = 0; j < len2; j++){
        printf(" %4c|", str2[j]);
    }
    printf("\n--------");
    for (j = 0; j < len2; j++){
        printf("------");
    }

    
    printf("\n");

    for (i = 0; i <= len1; i++) {
        if (i > 0) printf("%c|", str1[i-1]);
        else printf("  ");
        for (j = 0; j <= len2; j++) {
            printf(" %4d|", table[i][j]);
        }
        printf("\n--------");
        for (j = 0; j < len2; j++){
            printf("------");
        }
        printf("\n");
        
    }
}


/*
Parameters:
  - first_string - pointer to the first string (displayed vertical in the table)
  - second_string - pointer to the second string (displayed horizontal in the table)
  - print_table - If 1, the table with the calculations for the edit distance will be printed.
                  If 0 (or any value other than 1)it will not print the table
Return:  the value of the edit distance
*/



int edit_distance(char *first_str, char *second_str, int should_print_table) {
    int len1 = strlen(first_str);
    int len2 = strlen(second_str);
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (first_str[i-1] == second_str[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    if (should_print_table) {
        print_table(dp, len1, len2, first_str, second_str);
    }

    int result = dp[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

/*
Parameters:
  - testname - string containing the name of the file with the paragraph to spell check, includes file extenssion e.g. "text1.txt" 
  - dictname - name of file with dictionary words. Includes file extenssion, e.g. "dsmall.txt"
Behavior: If any of the files cannot be open displays a message and returns. (Does not exit the program.)
*/
void spell_check(char *dictname, char *testname) {
    FILE *dictFile = fopen(dictname, "r");
    FILE *testFile = fopen(testname, "r");
    if (!dictFile || !testFile) {
        perror("Error opening files");
        return;
    }

    // Read dictionary size from the first line of the dictionary file
    int dictSize = 0;
    if (fscanf(dictFile, "%d", &dictSize) != 1) {
        printf("Error reading dictionary size.\n");
        fclose(dictFile);
        fclose(testFile);
        return;
    }

    char **dictionary = malloc(dictSize * sizeof(char *));
    if (!dictionary) {
        printf("Memory allocation error.\n");
        fclose(dictFile);
        fclose(testFile);
        return;
    }

    char word[101];  // Max word length is 100
    for (int i = 0; i < dictSize; i++) {
        if (fscanf(dictFile, "%s", word) != 1) {
            printf("Error reading dictionary.\n");
            fclose(dictFile);
            fclose(testFile);
            for (int j = 0; j < i; j++) {
                free(dictionary[j]);
            }
            free(dictionary);
            return;
        }
        dictionary[i] = strdup(word);
    }
    fclose(dictFile);

    printf("Dictionary size: %d\n", dictSize);

    // Skip the first line in the test file
    char line[101];
    if (fgets(line, sizeof(line), testFile) == NULL) {
        printf("Error reading test file.\n");
        fclose(testFile);
        return;
    }

    char testWord[101];
    while (fscanf(testFile, "%s", testWord) == 1) {
        if (strlen(testWord) > 100) {
            printf("Word exceeds maximum length. Skipping...\n");
            continue;
        }
        printf("--->|%s|\n", testWord);
        printf("-1 - type correction\n 0 - leave word as is (do not fix spelling)\n");

        int minDistance = INT_MAX;
        int *distances = malloc(dictSize * sizeof(int));
        if (!distances) {
            printf("Memory allocation error.\n");
            break;
        }
        for (int i = 0; i < dictSize; i++) {
            distances[i] = edit_distance(testWord, dictionary[i], 0);
            if (distances[i] < minDistance) {
                minDistance = distances[i];
            }
        }

        printf("     Minimum distance: %d\n", minDistance);
        printf("     Words with minimum distance:\n");
        int count = 1;
        for (int i = 0; i < dictSize; i++) {
            if (distances[i] == minDistance) {
                printf("%d - %s\n", count, dictionary[i]);
                count++;
            }
        }

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == -1) {
            char newWord[101];
            printf("Type the corrected word: ");
            scanf("%100s", newWord); // Limit input to prevent buffer overflow
            printf("Corrected to: %s\n", newWord);
        } else if (choice == 0) {
            printf("Word remains unchanged.\n");
        } else if (choice > 0 && choice < count) {
            int wordIndex = 0;
            int wordCount = 0;
            for (int i = 0; i < dictSize; i++) {
                if (distances[i] == minDistance) {
                    wordCount++;
                    if (wordCount == choice) {
                        wordIndex = i;
                        break;
                    }
                }
            }
            printf("Corrected to: %s\n", dictionary[wordIndex]);
        } else {
            printf("Invalid choice. Original word will be kept.\n");
            printf("The corrected word is: %s\n\n", testWord);
        }
        
        free(distances); // Free distances array here
    }

    for (int i = 0; i < dictSize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    fclose(testFile);
}

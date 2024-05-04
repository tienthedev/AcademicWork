#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64

/*
 * Removes trailing newline characters.
 */
void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

/*
 * Parses a line of CSV and returns the number of attributes read in the line.
 */
int parse_line(char line[]) {
    char *token = strtok(line, ",");
    int num_attr = 0;

    while (token) {
        num_attr++;
        token = strtok(NULL, ",");
    }

    return num_attr;
}

int main() {
    char input[BUF_SIZE] = { 0 };
    char output_filename[BUF_SIZE] = { 0 };

    printf("Enter the name of the input file: ");
    fgets(input, BUF_SIZE, stdin);
    trim(input);

    FILE *input_fp = fopen(input, "r");

    if (!input_fp) {
        printf("Couldn't open file \"%s\".\n", input);
        return 1;
    }

    printf("Enter the name of the output file: ");
    fgets(output_filename, BUF_SIZE, stdin);
    trim(output_filename);

    FILE *output_fp = fopen(output_filename, "w");

    if (!output_fp) {
        printf("Couldn't open file \"%s\".\n", output_filename);
        return 1;
    }

    while (fgets(input, BUF_SIZE, input_fp)) {
        trim(input);
        int attr = parse_line(input);
        if(attr != 4)
        {    
            fprintf(output_fp, "%s\n", input);
        }
    }
    
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}
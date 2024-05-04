#include "string_utils.h"


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

    FILE *output_fp = fopen(output_filename, "wb");

    if (!output_fp) {
        printf("Couldn't open file \"%s\".\n", output_filename);
        return 1;
    }
     struct product_t product[BUF_SIZE] = {0}
    while (fgets(input, BUF_SIZE, input_fp)) {
        trim(input);
        parse_line(input);
        write_product(output_fp, product); 
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}

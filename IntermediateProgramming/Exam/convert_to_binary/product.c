#include "product.h"


/*
 * Parses a line of CSV and returns the number of attributes read in the line.
 */
struct product_t parse_line(char line[]) {
    struct product_t product = { 0 };
    char *token = strtok(line, ",");
    int attr = 0;

    while (token) {
        attr++;
        switch (attr) {
            case 1:
                product.id = atoi(token);
                break;
                
            case 2:
                strcpy(product.name, token, NAME_SIZE);
                break;
                
            case 3:
                product.price = atoi(token);
                break;
            case 4:
                product.quantity = atoi(token);
                break;
            default:
                break;
        }
        token = strtok(NULL, ",");
    }

    return product;
}
void write_product(FILE *fp, struct product_t product) {
    fwrite(&product, sizeof(product), 1, fp);
}


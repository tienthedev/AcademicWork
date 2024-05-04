#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <stdio.h>
#include <string.h>
// TODO: Add constants and function declarations here
#define NAME_SIZE 32
struct product_t{
    int id;
    char name[NAME_SIZE];
    double price;
    int quantity;
};
void write_product(FILE *, struct product_t);
#endif

#include <string.h>
#include <stdlib.h>

#include "utils.h"


void swap_int(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void parse_monster(monster_s *monster, char *csv_line) {
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token) {
        switch(attr) {
            case 0:
                strcpy(monster->name, token);
                break;
            case 1:
                strcpy(monster->type, token);
                break;
            case 2:
                monster->hp = atoi(token);
                break;
            case 3:
                monster->ac = atoi(token);
                break;
            case 4:
                monster->str = atoi(token);
                break;
            case 5:
                monster->dex = atoi(token);
                break;
            case 6:
                monster->con = atoi(token);
                break;
        }

        attr++;
    }
}

/*
 * Loads all monsters from a CSV file into memory.
 * Allocates memory pointed to by `*monsters_ptr`
 *
 * Args
 * ----
 *  monster_s **monsters_ptr - A double pointer to `monster_s`.
 *      Dereferencing this once (`*monsters_ptr`) returns the value to where the
 *      allocated memory should be stored. That is, you should assign the result
 *      of an allocation call to `*monsters_ptr`.
 *
 *  FILE *fp - A file pointer representing an open CSV file.
 *
 * Return
 * ------
 *  Returns an `int` representing the number of monsters loaded.
 */
int load_monster_csv(monster_s **monsters_ptr, FILE *fp) {
    char buffer[MAX_LEN] = { 0 };
    int num_read = 0;

    while (fgets(buffer, MAX_LEN, fp)) {
        trim(buffer);
        // Complete the function by parsing the csv line and storing the data into each monster_s entry.
        // For each item, you will need to reallocate the data to support 1 more.
    }

    return num_read;
}

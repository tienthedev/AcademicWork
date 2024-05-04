#include "string_utils.h"

#include <stdio.h>
#include <string.h>

/*
 * Removes trailing newline characters.
 */
void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

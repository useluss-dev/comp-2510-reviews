#include <stdlib.h>

int string_length(const char *s) {
    if (s == NULL)
        return -1; // Indicates invalid input.

    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }

    return length;
}

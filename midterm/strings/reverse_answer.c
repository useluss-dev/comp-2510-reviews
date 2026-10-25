#include <string.h>

void reverse_range(char *s, size_t left, size_t right) {
    if (left >= right)
        return;

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse_range(s, left + 1, right - 1);
}

const char *reverse(char *s) {
    if (s == NULL)
        return NULL;

    size_t len = strlen(s);
    if (len > 0)
        reverse_range(s, 0, len - 1);

    return s;
}

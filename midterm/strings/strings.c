/* What is a string in C?
 *
 * Is there a `String` type like in Java?
 *
 */
#include "strings.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_basics(void) {
    char color1[] = "blue";
    char color2[] = {'b', 'l', 'u', 'e', '\0'};
    const char *color3 = "blue";

    /* Are these three the same string?
     *
     */
    printf("%s %s %s\n", color1, color2, color3);

    char word[10] = "hi";

    /* What do `strlen(word)` and `sizeof word` print?
     *
     * Why are they different?
     *
     */
    printf("strlen = %zu, sizeof = %zu\n", strlen(word), sizeof word);

    /* How many bytes does `char s[] = "hello"` take up?
     *
     */
    char s[] = "hello";
    printf("sizeof s = %zu\n", sizeof s);

    /* Why does this loop stop?
     *
     */
    for (size_t i = 0; s[i] != '\0'; i++) {
        printf("[%c]", s[i]);
    }
    printf("\n");

    /* Is 'a' the same as "a"?
     *
     * What are their sizes?
     *
     */
    printf("sizeof 'a' = %zu, sizeof \"a\" = %zu\n\n", sizeof 'a', sizeof "a");
}

void character_handling(void) {
    /* What do these return? Is it always 1 for true?
     *
     */
    printf("isdigit('8') = %s, isdigit('#') = %s\n",
           isdigit('8') ? "yes" : "no", isdigit('#') ? "yes" : "no");
    printf("isalpha('A') = %s, isspace(' ') = %s\n",
           isalpha('A') ? "yes" : "no", isspace(' ') ? "yes" : "no");

    printf("toupper('u') = %c, tolower('L') = %c, toupper('7') = %c\n",
           toupper('u'), tolower('L'), toupper('7'));

    char text[] = "Hello, World 42";
    shout(text);
    printf("%s\n\n", text);
}

void string_conversion(void) {
    printf("atoi(\"2593\") = %d\n", atoi("2593"));
    printf("atof(\"99.5\") = %.1f\n", atof("99.5"));

    /* What does `atoi` do with text that is not a number?
     *
     * What can `strtol` tell us that `atoi` can't?
     *
     */
    char *end;
    long value = strtol("-1234abc", &end, 10);

    /* Why do we pass `&end` and not `end`?
     *
     */
    printf("strtol -> %ld, leftover: \"%s\"\n\n", value, end);
}

void formatted_io(void) {
    /* `fgets` keeps the newline. What do we do about it?
     *
     */
    char line[] = "hello\n";
    printf("before: strlen = %zu\n", strlen(line));
    line[strcspn(line, "\n")] = '\0';
    printf("after:  strlen = %zu\n", strlen(line));

    /* Where does the output of `snprintf` go?
     *
     * Why is `snprintf` safer than `sprintf`?
     *
     */
    char buffer[40];
    snprintf(buffer, sizeof buffer, "integer:%4d double:%6.2f", 298, 87.375);
    printf("%s\n", buffer);

    /* What does `sscanf` return?
     *
     * Why do `x` and `y` need `&`?
     *
     */
    int x;
    double y;
    int fields = sscanf("31298 87.375", "%d %lf", &x, &y);
    printf("x = %d, y = %.3f, fields = %d\n\n", x, y, fields);
}

void copy_and_concatenate(void) {
    char source[] = "Happy Birthday to You";
    char full[25];
    char part[15];

    strcpy(full, source);

    /* Is `part` a valid string after `strncpy`?
     *
     * Why do we write the '\0' ourselves?
     *
     */
    strncpy(part, source, 14);
    part[14] = '\0';
    printf("full = \"%s\", part = \"%s\"\n", full, part);

    char greeting[20] = "Happy ";

    /* What would happen if `greeting` only had room for 10 characters?
     *
     * Which character of "New Year" overwrites the old '\0'?
     *
     */
    strcat(greeting, "New Year");
    printf("greeting = \"%s\"\n\n", greeting);
}

void compare_strings(void) {
    const char *a = "Happy New Year";
    const char *b = "Happy Holidays";

    /* What sign will each of these have?
     *
     * Where do the strings first differ?
     *
     */
    printf("strcmp(a, a) = %s\n", strcmp(a, a) == 0 ? "zero" : "not zero");
    printf("strcmp(a, b) is %s\n",
           strcmp(a, b) > 0 ? "positive" : "not positive");
    printf("strcmp(b, a) is %s\n",
           strcmp(b, a) < 0 ? "negative" : "not negative");

    /* Why is this zero for 6 but not for 7?
     *
     */
    printf("strncmp(a, b, 6) = %s\n",
           strncmp(a, b, 6) == 0 ? "zero" : "not zero");
    printf("strncmp(a, b, 7) = %s\n",
           strncmp(a, b, 7) == 0 ? "zero" : "not zero");

    /* Why can we not use `==` to compare strings?
     *
     * What does it compare instead?
     *
     */
    char x[] = "same";
    char y[] = "same";
    const char *px = x;
    const char *py = y;
    printf("strcmp says %s, == says %s\n\n",
           strcmp(x, y) == 0 ? "equal" : "different",
           px == py ? "equal" : "different");
}

void search_strings(void) {
    const char *text = "This is a test";

    /* What does `strchr` return?
     *
     * How do we turn that into an index?
     *
     */
    const char *found = strchr(text, 'a');
    if (found != NULL) {
        printf("'a' at index %td, rest = \"%s\"\n", found - text, found);
    }

    /* What do we get back when the character is not there?
     *
     */
    printf("'z' is %s\n", strchr(text, 'z') == NULL ? "NULL" : "found");

    const char *sub = strstr(text, "test");
    printf("\"test\" starts at index %td\n", sub - text);

    char sentence[] = "This is a sentence with 7 tokens";

    /* Why must `sentence` be an array and not a `const char *`?
     *
     * Why do we pass NULL after the first call?
     *
     */
    printf("tokens:\n");
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        printf("  %s\n", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void memory_functions(void) {
    char copy[17];

    /* How is `memcpy` different from `strcpy`?
     *
     */
    memcpy(copy, "Copy this string", 17);
    printf("%s\n", copy);

    char buf[] = "abcdef";

    /* Why `memmove` and not `memcpy` here?
     *
     * What will `buf` be afterwards?
     *
     */
    memmove(buf + 2, buf, 4);
    printf("%s\n", buf);

    char fill[15] = "BBBBBBBBBBBBBB";

    /* What will this print?
     *
     * Does `memset` care about the '\0'?
     *
     */
    memset(fill, 'b', 7);
    printf("%s\n\n", fill);
}

int main(void) {
    string_basics();
    character_handling();
    string_conversion();
    formatted_io();
    copy_and_concatenate();
    compare_strings();
    search_strings();
    memory_functions();

    // char test[] = "hello";
    // reverse(test);
    // printf("%s\n", test);

    return 0;
}

/* Why do we cast to `unsigned char` before calling `toupper`?
 *
 * Why does this change the caller's string without returning anything?
 */
void shout(char s[]) {
    for (size_t i = 0; s[i] != '\0'; i++) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

/* Let's implement a recursive reverse
 */

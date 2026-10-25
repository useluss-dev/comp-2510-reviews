/* What is a string in C?
 *
 * Is there a `String` type like in Java?
 *
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shout(char s[]);

/**
 * Check your understanding on the basics of strings
 */
void string_basics(void) {
    /* Are these three the same string?
     *
     */
    char color1[] = "blue";
    char color2[] = {'b', 'l', 'u', 'e', '\0'};
    const char *color3 = "blue";
    printf("%s %s %s\n", color1, color2, color3);

    char word[10] = "hi";

    /* What will `strlen(word)` and `sizeof word` print?
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

/**
 * Check your understanding on functions for characters
 */
void character_handling(void) {
    /* What do the functions `isdigit()` `isalpha()` and `isspace()` return?
     *
     * What do the functions `toupper()` and `tolower()` return?
     *
     * Why do `toupper()` and `tolower()` take integers and not chars?
     *
     */
    printf("isdigit('8') = %s, isdigit('#') = %s\n",
           isdigit('8') ? "yes" : "no", isdigit('#') ? "yes" : "no");
    printf("isalpha('A') = %s, isspace(' ') = %s\n",
           isalpha('A') ? "yes" : "no", isspace(' ') ? "yes" : "no");

    printf("toupper('u') = %c, tolower('L') = %c, toupper('7') = %c\n",
           toupper('u'), tolower('L'), toupper('7'));

    char text[] = "Hello, World 42";
    /* Why can we pass `text[]` to `shout()` when `shout()` takes `char *s`
     *
     */
    shout(text);
    printf("%s\n\n", text);
}

/**
 * Check your understanding on character manipulation
 */
void shout(char s[]) {
    /* Why do we cast to `unsigned char` before calling `toupper`?
     *
     * Why does this change the caller's string without returning anything?
     *
     */
    for (size_t i = 0; s[i] != '\0'; i++) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

/**
 * Check your understanding on converting strings to other types
 */
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

    /* Why do we pass `&end` and not `end` to `strtol()`?
     *
     */
    printf("strtol -> %ld, leftover: \"%s\"\n\n", value, end);
}

/**
 * Check your understanding on formatting io
 */
void formatted_io(void) {
    /* `line` has a new line character. What does strcspn do to get rid of it?
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

/**
 * Check your understanding on copying and concatenating strings
 */
void copy_and_concatenate(void) {
    char source[] = "Happy Birthday to You";
    char full[25];
    char part[15];

    strcpy(full, source);

    /* Is `part` a valid string after `strncpy`?
     *
     */
    strncpy(part, source, 14);
    /* Why do we have to add the '\0' to `part` ourselves?
     *
     */
    part[14] = '\0';
    printf("full = \"%s\", part = \"%s\"\n", full, part);

    char greeting[20] = "Happy ";

    /* What would happen if `greeting` only had room for 10 characters?
     *
     */
    strcat(greeting, "New Year");
    printf("greeting = \"%s\"\n\n", greeting);
}

/**
 * Check your understanding on comparing strings.
 */
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
     * What does `==` on strings compare instead?
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

/**
 * Check your understanding on searching through strings
 */
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

    /* What does strstr do?
     *
     */
    const char *sub = strstr(text, "test");
    printf("\"test\" starts at index %td\n", sub - text);

    char sentence[] = "This is a sentence with 7 tokens";

    /* Why must `sentence` be an array and not a `const char *` when using
     * `strtok`?
     *
     * Why do we pass NULL after the first call?
     *
     */
    printf("tokens:\n");
    /* What does strtok do here?
     *
     */
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        printf("  %s\n", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

/* Can you implement a recursive function that reverses a string?
 */
const char *reverse(char *s) { return s; }

int main(void) {
    string_basics();
    character_handling();
    string_conversion();
    formatted_io();
    copy_and_concatenate();
    compare_strings();
    search_strings();

    char test[] = "hello";
    reverse(test);
    printf("%s\n", test);

    return 0;
}

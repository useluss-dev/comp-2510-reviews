/* What are #include directives for?
 *
 * When does the preprocessor run?
 *
 */
#include "basics.h"
#include <limits.h>
#include <stdio.h>

#define NUM_NAMES 3

void prefix_postfix() {
    char *names[NUM_NAMES] = {"Linus", "Dennis", "Ken"};
    int i = 0;

    printf("Names with postfix:\n");
    // Could this be changed into a for loop without changing any other
    // line?
    while (i < NUM_NAMES) {
        /* What will print here?
         *
         */
        printf("%s\n", names[i++]);
    }
    printf("\n");
    i = 0;

    printf("Names with prefix:\n");
    while (++i < NUM_NAMES) {
        /* What will print here?
         *
         */
        printf("%s\n", names[i]);
    }
    printf("\n");
    i = 0;

    printf("Names with prefix + do while:\n");
    do {
        /* Will this output something different than the last while loop?
         *
         */
        printf("%s\n", names[i]);
    } while (++i < NUM_NAMES);
    printf("\n");
}

int main() {
    prefix_postfix();

    /* How does the ternary operator `x ? y : z` work?
     *
     */
    printf("Is 5 less than 10: %s\n\n",
           (is_less_than(5, 10) ? "true" : "false"));

    data_types();

    printf("countdown:\n");
    recursive_countdown(10);

    // printf("\nfibonacci:\n");
    // printf("%d\n", fib(10));

    /* Why does the main function return an integer?
     *
     */
    return 0;
}

/* Why is this allowed to be declared after it's used?
 *
 * Why does `prefix_postfix()` have to be defined before it's used?
 *
 */
_Bool is_less_than(int a, int b) { return a < b; }

void recursive_countdown(int n) {
    static int calls = 0;
    calls++;

    printf("n = %d, call #%d\n", n, calls);

    /* What would happen without this?
     */
    if (n <= 0) {
        return;
    }

    recursive_countdown(n - 1);
}

/* Let's implement fibonacci
 */

void data_types(void) {
    char letter = 'A';
    int count = 42;
    long int cap = LONG_MAX;
    float temperature = 21.5f;
    double distance = 1234.5678;
    _Bool is_ready = 1;
    int numbers[] = {10, 20, 30};
    int *int_ptr = numbers;
    double *double_ptr = &distance;

    /* Why don't I need brackets around the `sizeof()` function?
     *
     */
    printf("Basic data types:\n");
    printf("char:   value '%c', size %zu byte(s)\n", letter, sizeof letter);
    printf("int:    value %d, size %zu byte(s)\n", count, sizeof count);
    printf("long:   value %ld, size %zu byte(s)\n", cap, sizeof cap);
    printf("float:  value %.1f, size %zu byte(s)\n", temperature,
           sizeof temperature);
    printf("double: value %.4f, size %zu byte(s)\n", distance, sizeof distance);
    printf("_Bool:  value %d, size %zu byte(s)\n", is_ready, sizeof is_ready);

    printf("\nArrays and pointers:\n");
    printf("int    array: size %zu bytes, %zu element(s)\n", sizeof numbers,
           sizeof numbers / sizeof numbers[0]);
    /* Why are these pointers the same size?
     *
     */
    printf("int    pointer: size %zu byte(s)\n", sizeof int_ptr);
    printf("double pointer: size %zu byte(s)\n", sizeof double_ptr);
    printf("\n");
}

#include <limits.h>
#include <stdio.h>

// Constants
#define NUM_NAMES 3

/* What does putting this up here do?
 *
 */
_Bool is_less_than(int, int);

/**
 * This is to check your understanding on prefix and postfix operations
 */
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

/**
 * Check your understanding on recursion
 */
void recursive_countdown(int n) {
    /* What does the `static` do to this variable?
     */
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

/**
 * Check your understanding of data types and `sizeof`
 */
void data_types(void) {
    // I know some of the formatting here sucks most C formatting standards are
    // awful and the one I'm using is no different. Feel free to change it.

    char letter = 'A'; // char type is 1 byte
    int number = -42;  // int is variable in length depending on platform. on
                       // most 64 bit platforms it is 4 bytes.
    unsigned int number_2 =
        7849; // unsigned ints will be the same size as int, however, they
              // cannot represent negative numbers.
    long int cap = LONG_MAX; // The long keyword before int specifies that it is
                             // (typically) larger than int. on most 64 bit
                             // platforms it is 8 bytes.
    float temperature = 21.5f;   // Floats are 4 bytes
    double distance = 1234.5678; // Doubles are 8 bytes
    _Bool is_ready = 1; // _Bool is a custom type implemented in C99 and after.
                        // It is typically 1 byte. Many libc functions will
                        // use `int` instead of bool for portability.

    int numbers[] = {
        10, 20, 30}; // Arrays size are the number of elements * bytes of type
                     // so here it would be 3 elements * 4 bytes so 12 bytes.
    int *int_ptr = numbers; // Pointers no matter the type will be the same size
                            // on any given architecture. on modern 64 bit
                            // machines pointers are typically 8 bytes
    double *double_ptr = &distance; // Still 8 bytes

    /* Why don't I need brackets around the `sizeof()` function?
     *
     */
    printf("Basic data types:\n");
    printf("char:	  value '%c', size %zu byte(s)\n", letter, sizeof letter);
    printf("int:	  value %d, size %zu byte(s)\n", number, sizeof number);
    printf("unsigned: value %d, size %zu byte(s)\n", number_2, sizeof number_2);
    printf("long:	  value %ld, size %zu byte(s)\n", cap, sizeof cap);
    printf("float:	  value %.1f, size %zu byte(s)\n", temperature,
           sizeof temperature);
    printf("double:	  value %.4f, size %zu byte(s)\n", distance,
           sizeof distance);
    printf("_Bool:	  value %d, size %zu byte(s)\n", is_ready, sizeof is_ready);

    printf("\nArrays and pointers:\n");
    printf("int    array: size %zu bytes, %zu element(s)\n", sizeof numbers,
           sizeof numbers / sizeof numbers[0]);
    printf("int    pointer: size %zu byte(s)\n", sizeof int_ptr);
    printf("double pointer: size %zu byte(s)\n", sizeof double_ptr);
    printf("\n");
}

/* Can you implement the fibonacci sequence?
 */
int fib(int n) { return n; }

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

    printf("\nfibonacci:\n");
    printf("%d\n", fib(10));

    /* Why does the main function return an integer?
     *
     */
    return 0;
}

/* Why can this be defined after it's used?
 *
 */
_Bool is_less_than(int a, int b) { return a < b; }

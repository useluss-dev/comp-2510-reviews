/* What does a pointer store?
 *
 * Why do all pointers on one machine have the same size (on most machines...)?
 *
 */
#include <stdio.h>

// Constants
#define SIZE 5

// Function declarations
int apply(int (*op)(int, int), int x, int y);
int min_int(int a, int b);
int max_int(int a, int b);
void swap(int *a, int *b);

void half_by_value(int n) { n /= 2; }
void half_by_reference(int *p) { *p /= 2; }

/**
 * Check your understanding on getting addresses and dereferencing pointers
 */
void address_and_dereference(void) {
    int n = 3;
    int *p = &n;
    int *q = p;

    /* What do `n`, `*p` and `*q` print?
     *
     * Is `&n == p` true?
     *
     */
    printf("n = %d, *p = %d, *q = %d\n", n, *p, *q);
    printf("&n == p: %s\n", (&n == p) ? "true" : "false");

    *q = 5;

    /* What is `n` now?
     *
     * Why did it change when we never touched `n` or `p`?
     *
     */
    printf("after *q = 5: n = %d, *p = %d\n\n", n, *p);
}

/**
 * Check your understanding on pointer arithmetic
 */
void pointer_arithmetic(void) {
    int v[SIZE] = {10, 20, 30, 40, 50};
    int *p = v;

    printf("*p = %d\n", *p);

    p += 2;

    /* How many bytes did `p` move?
     *
     * What does `*p` print?
     *
     */
    printf("after p += 2: *p = %d\n", *p);

    p++;
    printf("after p++:    *p = %d\n", *p);

    /* Are these two the same thing?
     *
     * Why?
     *
     */
    printf("p[1] = %d, *(p + 1) = %d\n", p[1], *(p + 1));

    /* Why can `p` be moved but `v` can't?
     *
     */
    // v = v + 2;
    printf("\n");
}

/**
 * Check your understanding on pass by reference
 */
void pass_by_reference(void) {
    int a = 4, b = 4;

    half_by_value(a);
    half_by_reference(&b);

    /* What will `a` and `b` be?
     *
     */
    printf("a = %d, b = %d\n", a, b);

    /*
     * In C functions are pass-by-value. So how can `half_by_reference` change
     * `b`?
     *
     */

    int x = 1, y = 3;
    /* Will this actually swap the variables or will they remain the same?
     *
     */
    swap(&x, &y);
    printf("after swap: x = %d, y = %d\n", x, y);
}

/**
 * Check your understanding on the relationship between arrays and pointers
 */
void arrays_vs_pointers(void) {
    char array[] = "hello";
    const char *literal = "hello";

    array[0] = 'j';
    literal = "world";

    /* Why can we change `array[0]` but not `literal[0]`?
     *
     * Why can we reassign `literal` but not `array`?
     *
     */
    // literal[0] = 'j';
    // array = "world";
    printf("array = %s, literal = %s\n", array, literal);

    /* Why is `other_str` not reassignable?
     *
     */
    char *const other_str = "hello";
    // other_str = "world";
    printf("other_str = %s\n", other_str);

    /* Why are these two sizes different?
     *
     */
    printf("sizeof array = %zu, sizeof literal = %zu\n\n", sizeof array,
           sizeof literal);
}

/**
 * Check your understanding on function pointers
 */
void function_pointers(void) {
    int (*op)(int, int) = max_int;

    /* Why is there no `&` and no `()` after `max_int`?
     *
     */
    printf("max: %d\n", op(1, 3));

    op = min_int;
    printf("min: %d\n", op(1, 3));

    /* What is `apply` doing with its first parameter?
     *
     */
    printf("apply(max_int, 8, 5) = %d\n\n", apply(max_int, 8, 5));
}

/**
 * Check your understanding on pointers to pointers
 */
void pointer_to_pointer(void) {
    int n = 3;
    int *p = &n;
    int **pp = &p;

    /* How many `*` do we need to get from `pp` to `n`?
     *
     */
    printf("n = %d, *p = %d, **pp = %d\n", n, *p, **pp);

    **pp = 99;

    /* What is `n` now?
     *
     */
    printf("after **pp = 99: n = %d\n\n", n);
}

/**
 * Check your understanding on operator precedence and incrementing pointers
 */
void increment_family(void) {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr;
    int r;

    /* https://en.cppreference.com/c/language/operator_precedence
     * For each of the next four lines:
     *   What is `r`?
     *
     */
    r = *p++; // r is
    printf("r = *p++   -> r = %d, *p = %d, arr[0] = %d\n", r, *p, arr[0]);

    p = arr;
    r = (*p)++; // r is
    printf("r = (*p)++ -> r = %d, *p = %d, arr[0] = %d\n", r, *p, arr[0]);

    arr[0] = 10;
    p = arr;
    r = ++*p; // r is
    printf("r = ++*p   -> r = %d, *p = %d, arr[0] = %d\n", r, *p, arr[0]);

    arr[0] = 10;
    p = arr;
    r = *++p; // r is
    printf("r = *++p   -> r = %d, *p = %d, arr[0] = %d\n\n", r, *p, arr[0]);
}

/**
 * Check your understanding on void pointers
 */
void void_pointers(void) {
    int number = 42;
    double value = 3.14;

    /* What does `void *` tell us about `ptr`?
     *
     */
    void *ptr = &number;
    printf("number through void pointer: %d\n", *(int *)ptr);

    /* Can ptr point to values of any type or only specific types?
     *
     */
    ptr = &value;
    printf("value through void pointer: %.2f\n", *(double *)ptr);

    /* Why can't we write *ptr or ptr++ directly?
     *
     */
}

/* Why would `swap(int a, int b)` not work?
 *
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* What does `const int *` promise?
 *
 * Can `p` itself still be reassigned?
 *
 * How is `int *const p` different?
 *
 */
int peek(const int *p) { return *p + 1; }

/* Can you implement getting a string length using pointers?
 */
int string_length(const char *s) { return 0; }

int main(void) {
    address_and_dereference();
    pointer_arithmetic();
    pass_by_reference();
    arrays_vs_pointers();
    function_pointers();
    pointer_to_pointer();
    increment_family();

    /* What does `NULL` mean?
     *
     * What happens if we dereference it?
     *
     */
    int *nothing = NULL;
    // uncomment it and see what happens...
    // printf("Dereferenced null: %d\n\n", *nothing);

    printf("Length of \"hello\": %d\n", string_length("hello"));

    return 0;
}

int apply(int (*op)(int, int), int x, int y) { return op(x, y); }
int min_int(int a, int b) { return a < b ? a : b; }
int max_int(int a, int b) { return a > b ? a : b; }

/* What does a pointer store?
 *
 * Why do all pointers on one machine have the same size (on most machines...)?
 *
 */
#include "pointers.h"
#include <stdio.h>

#define SIZE 5

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

    /* Which of `a`, `b` and `c` are pointers?
     *
     * What do the sizes tell us?
     *
     */
    char *a = NULL, b = 'b', *c = NULL;
    printf("sizeof a = %zu, b = %zu, c = %zu\n\n", sizeof a, sizeof b,
           sizeof c);
}

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

    int *end = &v[SIZE - 1];

    /* Does `end - p` give us bytes or elements?
     *
     * What value will it be?
     *
     */
    printf("end - p = %td\n", end - p);

    /* Are these two the same thing?
     *
     */
    printf("p[1] = %d, *(p + 1) = %d\n", p[1], *(p + 1));

    /* Why can `p` be moved but `v` can't?
     *
     */
    // v = v + 2;
    printf("\n");
}

void pass_by_reference(void) {
    int a = 4, b = 4;

    half_by_value(a);
    half_by_reference(&b);

    /* What will `a` and `b` be?
     *
     */
    printf("a = %d, b = %d\n", a, b);
    /*
     * C is pass-by-value. So how can `half_by_reference` change `b`?
     *
     */

    int x = 1, y = 3;
    swap(&x, &y);
    printf("after swap: x = %d, y = %d\n", x, y);

    /* A function can only return one value. How do we get two out?
     *
     */
    int smaller;
    int bigger = max_min(7, 3, &smaller);
    printf("bigger = %d, smaller = %d\n", bigger, smaller);

    printf("peek(&x) = %d\n\n", peek(&x));
}

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
    // char *const other_str = "hello";
    // other_str = "world";
    // printf("other_str = %s\n", other_str);

    /* Why are these two sizes different?
     *
     */
    printf("sizeof array = %zu, sizeof literal = %zu\n\n", sizeof array,
           sizeof literal);
}

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

void increment_family(void) {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr;
    int r;

    /* https://en.cppreference.com/c/language/operator_precedence
     * For each of the next four lines:
     *   What is `r`?
     *   Did the pointer move, or did the value change?
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

/* Why does this get a copy of the number?
 */
void half_by_value(int n) { n /= 2; }

void half_by_reference(int *p) { *p /= 2; }

/* Why would `swap(int a, int b)` not work?
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max_min(int a, int b, int *smaller) {
    if (a > b) {
        *smaller = b;
        return a;
    }
    *smaller = a;
    return b;
}

/* What does `const int *` promise?
 *
 * Can `p` itself still be reassigned?
 *
 * How is `int *const p` different?
 */
int peek(const int *p) { return *p + 1; }

int max_int(int a, int b) { return (a > b) ? a : b; }

int min_int(int a, int b) { return (a < b) ? a : b; }

int apply(int (*op)(int, int), int x, int y) { return op(x, y); }

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
    printf("nothing is %s\n\n", nothing == NULL ? "NULL" : "not NULL");
    // printf("%d\n", *nothing);

    // printf("String length: %zu\n", string_length("hello"));

    return 0;
}

/* Let's implement string length using only pointers
 */

/* What is an array in C?
 *
 * Does an array know its own length?
 *
 */
#include "arrays.h"
#include <stdio.h>

#define SIZE 5
#define ROWS 2

void define_and_initialize(void) {
    int full[SIZE] = {1, 2, 3, 4, 5};
    int partial[SIZE] = {1, 2};
    int inferred[] = {7, 8, 9};
    /* What would be inside this array if we printed it?
     *
     * Why is that a problem?
     */
    int uninitialized[SIZE];
    printf("uninit:   ");
    print_array(uninitialized, SIZE);

    printf("full:     ");
    print_array(full, SIZE);

    /* What will the last three elements of `partial` be?
     *
     * Would they be the same if there was no initializer at all?
     *
     */
    printf("partial:  ");
    print_array(partial, SIZE);

    /* How many elements does `inferred` have?
     *
     * How did the compiler know?
     */
    printf("inferred: ");
    print_array(inferred, sizeof inferred / sizeof inferred[0]);
    printf("\n");
}

void passing_arrays(void) {
    int scores[SIZE] = {90, 85, 70, 60, 100};

    /* What does `sum()` actually receive: the array, or something else?
     *
     * Why do we also have to pass the length?
     *
     */
    printf("sum: %d\n", sum(scores, SIZE));

    double_all(scores, SIZE);

    /* Why did `scores` change here, when an `int` passed to a function
     * would not have?
     *
     */
    printf("after double_all: ");
    print_array(scores, SIZE);
    printf("\n");
}

void out_of_bounds(void) {
    int arr[SIZE] = {1, 2, 3, 4, 5};

    printf("last valid element: %d\n", arr[SIZE - 1]);

    /* What happens if we uncomment the next line?
     *
     * Will it compile? Will it run?
     *
     * Does C throw an exception like Java would?
     */
    // printf("%d\n", arr[SIZE]);
    printf("\n");
}

int main(void) {
    define_and_initialize();
    passing_arrays();
    out_of_bounds();

    /* Why does `sizeof data / sizeof data[0]` get the correct number of
     * elements?
     */
    int data[] = {42, 7, 19, 3, 25};
    size_t len = sizeof data / sizeof data[0];

    printf("before sort: ");
    print_array(data, len);

    /* Why does `bubble_sort` not return anything?
     *
     * What would happen if we forgot to pass `len`?
     */
    bubble_sort(data, len);

    printf("after sort:  ");
    print_array(data, len);

    /* What does the -1 mean?
     *
     * Would binary search work on this array? Would it have worked before
     * the sort?
     */
    printf("index of 19: %d\n", linear_search(data, len, 19));
    printf("index of 99: %d\n\n", linear_search(data, len, 99));

    two_dimensional();

    // printf("index of 19(bsearch): %d\n", binary_search(data, len, 19));

    return 0;
}

void print_array(const int arr[], size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* What does `const` promise the caller here?
 */
int sum(const int arr[], size_t len) {
    /* What would `sizeof arr` give us in here?
     *
     * Why not the size of the whole array?
     */
    int total = 0;
    for (size_t i = 0; i < len; i++) {
        total += arr[i];
    }
    return total;
}

/* Why is there no `const` on this one?
 */
void double_all(int arr[], size_t len) {
    for (size_t i = 0; i < len; i++) {
        arr[i] *= 2;
    }
}

void two_dimensional(void) {
    /* What is in the last row?
     *
     * What is `grid[1][2]`?
     */
    int grid[ROWS][COLS] = {{1, 2, 3}, {4, 5}};

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    printf("sum of grid: %d\n\n", sum_grid(grid, ROWS));
}

/* Why do we have to write COLS in the parameter, but not the number of
 * rows?
 */
int sum_grid(const int grid[][COLS], int rows) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            total += grid[r][c];
        }
    }
    return total;
}

void bubble_sort(int arr[], size_t len) {
    for (size_t pass = 1; pass < len; pass++) {
        for (size_t i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                /* Why do we need a third variable to swap?
                 *
                 * What would happen with only two assignments?
                 */
                int hold = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = hold;
            }
        }
    }
}

int linear_search(const int arr[], size_t len, int key) {
    for (size_t i = 0; i < len; i++) {
        if (arr[i] == key) {
            return (int)i;
        }
    }
    return -1;
}

/* Let's implement binary search
 */

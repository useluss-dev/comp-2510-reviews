/* What is an array in C?
 *
 * Does an array know its own length?
 *
 */
#include <stdio.h>

// Constants
#define SIZE 5
#define COLS 3
#define ROWS 2

// Function declarations
void print_array(const int arr[], size_t len);
int sum(const int arr[], size_t len);
void double_all(int arr[], size_t len);
int sum_grid(const int grid[][COLS], size_t rows);

/**
 * Check your understanding on array initialization
 */
void define_and_initialize(void) {
    int full[SIZE] = {1, 2, 3, 4, 5};
    int partial[SIZE] = {1, 2};
    int inferred[] = {7, 8, 9};
    /* What would be inside this array if we printed it?
     *
     * Why is that a problem?
     *
     */
    int uninitialized[SIZE];
    // uncomment this and see what happens...
    // printf("uninit:   ");
    // print_array(uninitialized, SIZE);

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
     */
    printf("inferred: ");
    print_array(inferred, sizeof inferred / sizeof inferred[0]);
    printf("\n");
}

/**
 * Check your understanding on passing arrays
 */
void passing_arrays(void) {
    int scores[SIZE] = {90, 85, 70, 60, 100};

    /* When passing an array to funciton like `sum()` what does the fucking
     * actually receive: the array, or something else?
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

/**
 * Check your understanding on out of bounds indexing
 */
void out_of_bounds(void) {
    int arr[SIZE] = {1, 2, 3, 4, 5};

    printf("last valid element: %d\n", arr[SIZE - 1]);

    /* What happens if we uncomment the next line?
     *
     * Will it compile? Will it run?
     *
     * Does C throw an exception like Java would?
     *
     */
    // printf("%d\n", arr[SIZE]);
    printf("\n");
}

/**
 * Check your understanding on taking arrays as arguments
 */
int sum(const int arr[], size_t len) {
    /* What does `const int arr[]` promise the caller here?
     *
     */

    /* What would `sizeof arr` give us in here?
     *
     * Why not the size of the whole array?
     *
     */
    int total = 0;
    for (size_t i = 0; i < len; i++) {
        total += arr[i];
    }
    return total;
}

void double_all(int arr[], size_t len) {
    /* Will this change the actual values inside the array?
     *
     * Why?
     *
     */
    for (size_t i = 0; i < len; i++) {
        arr[i] *= 2;
    }
}

/**
 * Check your understanding on 2D arrays
 */
void two_dimensional(void) {
    /* What is in the last row?
     *
     * What is `grid[1][2]`?
     *
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

/**
 * Check your understanding on taking 2D arrays as arguments
 */
int sum_grid(const int grid[][COLS], size_t rows) {
    /* Why do we have to write COLS in the parameter, but not the number of
     * rows?
     *
     */
    int total = 0;
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < COLS; c++) {
            total += grid[r][c];
        }
    }
    return total;
}

/* Can you implement a function that takes an array of integers and its
 * length,and prints the highest value, lowest value, sum, and average of the
 * values?
 */
int print_array_stats(const int arr[], const size_t len) { return 0; }

int main(void) {
    define_and_initialize();
    passing_arrays();
    out_of_bounds();

    two_dimensional();
    printf("\n");

    int data[] = {42, 7, 19, 3, 25, 84, 99, 28, 74, 5, 12, 4};
    /* Why does `sizeof(data) / sizeof(data[0])` get the length of an array?
     *
     */
    print_array_stats(data, sizeof(data) / sizeof(data[0]));

    return 0;
}

void print_array(const int arr[], size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

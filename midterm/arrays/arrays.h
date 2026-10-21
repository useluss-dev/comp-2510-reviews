#ifndef ARRAYS_H
#define ARRAYS_H

#include <stddef.h>

#define COLS 3

void define_and_initialize(void);
void passing_arrays(void);
void out_of_bounds(void);
void two_dimensional(void);

/* Why do I use `size_t` instead of something like `int`?
 */
void print_array(const int arr[], size_t len);
int sum(const int arr[], size_t len);
void double_all(int arr[], size_t len);
int sum_grid(const int grid[][COLS], int rows);
void bubble_sort(int arr[], size_t len);
int linear_search(const int arr[], size_t len, int key);

int binary_search(const int arr[], size_t len, int key);

#endif

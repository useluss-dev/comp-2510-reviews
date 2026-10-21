#ifndef POINTERS_H
#define POINTERS_H

#include <stddef.h>

void address_and_dereference(void);
void pointer_arithmetic(void);
void pass_by_reference(void);
void arrays_vs_pointers(void);
void function_pointers(void);
void pointer_to_pointer(void);
void increment_family(void);

void half_by_value(int n);
void half_by_reference(int *p);
void swap(int *a, int *b);
int max_min(int a, int b, int *smaller);
int peek(const int *p);
int max_int(int a, int b);
int min_int(int a, int b);
int apply(int (*op)(int, int), int x, int y);

size_t string_length(const char *s);

#endif

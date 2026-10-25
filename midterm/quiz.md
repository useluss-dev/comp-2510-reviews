#### 1. Which of the following is not a function?
A. `strcmp()`
B. `scanf()`
C. `sizeof()`
D: `printf()`

#### 2. What is the SAFEST way to define an empty array?
A. `int nums[3]`
B. `int nums[0]`
C. `int nums[] = {0}`
D. `int nums[3] = {0}`

#### 3. What does the following code print?
```C
int main() {
	int a = 5, b = 10;
	int *p = &a;
    int *q = &b;

    *p = *q;
    q = p;
    *q = 20;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);

    return 0;
}
```
A. 
```
a = 5
b = 20
*p = 20
*q = 20
```
B.
```
a = 5
b = 10
*p = 5
*q = 20
```
C.
```
a = 20
b = 20
*p = 20
*q = 20
```
D.
```
a = 20
b = 10
*p = 20
*q = 20
```

#### 4. "C-Strings" are:
A. A raw character array ending with a null terminator.
B. A custom string data type defined in the `<string.h>` header.
C. A built in type in C called `string`.

#### 5. Given an array array: `int nums[] = {1, 2, 3};`, how would you get the arrays length?
A. `sizeof(nums[0]) / sizeof(nums)`
B. `sizeof(nums)`
C. `arrlen(nums)`
D. `sizeof(nums) / sizeof(nums[0])`

#### 6. The concept of array decay states that:
A. Initializing a pointer to an array (int *p = arr) will result in data in the array being lost.
B. `int *p = arr;` and `int *p = &arr[0];` are the same.
C. Arrays can be indexed using pointer arithmetic.
D. Arrays are pointers.

#### 7. What does this program print?
```C
#include <stdio.h>

void update(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] += i;
    }
}

int main(void) {
    int nums[3] = {2, 4, 6};
    update(nums, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
```
A. Nothing. You get a segmentation fault.
B. 2 5 8
C. 2 4 6
D. 4 8 12

#### 8. How would you make a function that redirects a pointer to a new address?
A.
```C
void redirect(int *p, int *q) {
    p = q;
}
```
B.
```C
void redirect(int **p, int q) {
    *p = &q;
}
```
C.
```C
void redirect(int p, int q) {
    p = q;
}
```
D.
```C
void redirect(int **p, int *q) {
    *p = q;
}
```

#### 9. `const char *var` is the same as `char *const var`.
A. True
B. False

#### 10. Which of these functions correctly return a pointer to the first array element?
A.
```C
int *first(int arr[]) {
    return arr[0];
}
```
B.
```C
int *first(int arr[]) {
    return &arr[0];
}
```
C.
```C
int *first(int arr[]) {
    int x = arr[0];
    return &x;
}
```
D.
```C
int *first(int arr[]) {
    return arr;
}
```

#### 11. Given `int arr[5]; int *p = arr;`, which correctly moves the pointer to the 3rd element?
A. `p = p + 2;`
B. `p = p + 3;`
C. `p = &arr[3];`
D. `p = arr[2];`

#### 12. What is the correct declaration for an array of `char *` strings?
A. `char arr*[10];`
B. `char *arr[10];`
C. `char **arr[10];`
D. `char arr[10]*;`

#### 13. Why can't we use == to compare the value of C-strings?
A. Because == is only for arithmetic in C. We need to use === for strings.
B. Because it compares their pointers not their values.
C. Because we can't be sure they are the same size.
D. We can.

#### 14. Which of these are a valid way of taking an array as a function parameter?
A. `void func(int arr[]);`
B. `void func(int *arr);`
C. `void func(int arr);`
D. `void func(int arr[10]);`

# C Practice Quiz: Find the Error

## Instructions

For each question:

- Identify the **line number** where a **compile error** occurs.
- If there is no compile error, answer **"logic error"**, **"run-time error"**, or **"no error"** as appropriate.
- When a comment says `Expect ...`, that is what the programmer *intended* the program to do.
- Try each one **without a compiler** first, then check the answer key.

Line numbers are shown at the left of each code block (they are not part of the code).

---

## Part 1: Syntax, Declarations & Types

### Question 1

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int count = 3;
5      printf("Count: %d\n", count)
6      return 0;
7  }
```

### Question 2

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int a = b = c = 0;
5
6      printf("%d\n", a);
7      return 0;
8  }
```

### Question 3

```c
1  #include <stdio.h>
2
3  int main(void) {
4      const int MAX_PLAYERS = 4;
5      MAX_PLAYERS = 6;
6      printf("%d\n", MAX_PLAYERS);
7      return 0;
8  }
```

### Question 4

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int original[3] = {1, 2, 3};
5      int copy[3];
6
7      copy = original;
8
9      printf("%d\n", copy[0]);
10     return 0;
11 }
```

### Question 5

```c
1  #include <stdio.h>
2
3  int main(void) {
4      double seconds = 125.5;
5      int minutes = seconds / 60;
6      double leftover = seconds % 60;
7
8      printf("%d min %.1f sec\n", minutes, leftover);
9      return 0;
10 }
```

### Question 6

```c
1  #include <stdio.h>
2
3  /* Expect to print 3.50 */
4  int main(void) {
5      int total = 7;
6      int count = 2;
7      double average = total / count;
8
9      printf("%.2f\n", average);
10     return 0;
11 }
```

### Question 7

```c
1  #include <stdio.h>
2  #include <math.h>
3
4  /* Expect to print the cube root of 8 (2.00) */
5  int main(void) {
6      double result = pow(8.0, 1 / 3);
7
8      printf("%.2f\n", result);
9      return 0;
10 }
```

---

## Part 2: Control Flow

### Question 8

```c
1  #include <stdio.h>
2
3  int main(void) {
4      for (int i = 0, i < 3, i++) {
5          printf("%d\n", i);
6      }
7      return 0;
8  }
```

### Question 9

```c
1  #include <stdio.h>
2
3  int main(void) {
4      for (int i = 0; i < 3; i++);
5      {
6          printf("%d\n", i);
7      }
8      return 0;
9  }
```

### Question 10

```c
1  #include <stdio.h>
2
3  int main(void) {
4      size_t i = 0;
5
6      for (; i < 3; ) {
7          printf("%zu\n", i);
8          i++;
9      }
10     return 0;
11 }
```

### Question 11

```c
1  #include <stdio.h>
2
3  /* Expect to print "Try again" */
4  int main(void) {
5      int score = 3;
6
7      if (score = 10) {
8          printf("Perfect\n");
9      } else {
10         printf("Try again\n");
11     }
12     return 0;
13 }
```

### Question 12

```c
1  #include <stdio.h>
2
3  /* Expect to print 3, 2, 1 (one per line) */
4  int main(void) {
5      int n = 3;
6
7      while (n > 0)
8          printf("%d\n", n);
9          n--;
10
11     return 0;
12 }
```

### Question 13

```c
1  #include <stdio.h>
2
3  /* Expect to print only "Silver" */
4  int main(void) {
5      int place = 2;
6
7      switch (place) {
8          case 1:
9              printf("Gold\n");
10             break;
11         case 2:
12             printf("Silver\n");
13         case 3:
14             printf("Bronze\n");
15             break;
16         default:
17             printf("No medal\n");
18     }
19     return 0;
20 }
```

### Question 14

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int level = 2;
5      int boss = 5;
6
7      switch (level) {
8          case 1:
9              printf("Easy\n");
10             break;
11         case boss:
12             printf("Boss fight\n");
13             break;
14         default:
15             printf("Normal\n");
16     }
17     return 0;
18 }
```

### Question 15

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int op = 2;
5
6      switch (op) {
7          case 1:
8              printf("Add\n");
9              break;
10         case 2:
11             printf("Subtract\n");
12             continue;
13         default:
14             printf("Unknown\n");
15     }
16     return 0;
17 }
```

### Question 16

```c
1  #include <stdio.h>
2
3  /* Expect to print 3, 2, 1, 0 and then stop */
4  int main(void) {
5      for (size_t i = 3; i >= 0; i--) {
6          printf("%zu\n", i);
7      }
8      return 0;
9  }
```

### Question 17

```c
1  #include <stdio.h>
2
3  /* Expect to print Code */
4  int main(void) {
5      char *word = "Code";
6      size_t i = 0;
7
8      while (i != '\0') {
9          printf("%c", word[i]);
10         i++;
11     }
12     return 0;
13 }
```

---

## Part 3: Functions & Scope

### Question 18

```c
1  #include <stdio.h>
2
3  int average(int a, int b);
4
5  int main(void) {
6      printf("%d\n", average(4, 9));
7      return 0;
8  }
9
10 double average(int a, int b) {
11     return (a + b) / 2.0;
12 }
```

### Question 19

```c
1  #include <stdio.h>
2
3  int cube(int n) {
4      return n * n * n;
5  }
6
7  int main(void) {
8      int result = cube(2, 3);
9
10     printf("%d\n", result);
11     return 0;
12 }
```

### Question 20

```c
1  #include <stdio.h>
2
3  int scale(int value) {
4      int value = value * 2;
5      return value;
6  }
7
8  int main(void) {
9      printf("%d\n", scale(5));
10     return 0;
11 }
```

### Question 21

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int level = 1;
5
6      {
7          int level = 5;
8          level++;
9          printf("inner: %d\n", level);
10     }
11
12     printf("outer: %d\n", level);
13     return 0;
14 }
```

### Question 22

```c
1  #include <stdio.h>
2
3  /* Expect to print 7 3 */
4  void swap(int a, int b) {
5      int temp = a;
6      a = b;
7      b = temp;
8  }
9
10 int main(void) {
11     int x = 3;
12     int y = 7;
13
14     swap(x, y);
15     printf("%d %d\n", x, y);
16     return 0;
17 }
```

---

## Part 4: Random Numbers & Recursion

### Question 23

```c
1  #include <stdio.h>
2  #include <stdlib.h>
3  #include <time.h>
4
5  int main(void) {
6      int roll = srand(time(NULL)) % 6 + 1;
7
8      printf("%d\n", roll);
9      return 0;
10 }
```

### Question 24

```c
1  #include <stdio.h>
2  #include <stdlib.h>
3  #include <time.h>
4
5  /* Expect a random integer from 5 to 15 inclusive,
6     different on each run */
7  int main(void) {
8      srand(time(NULL));
9
10     int number = rand() % 10 + 5;
11
12     printf("%d\n", number);
13     return 0;
14 }
```

### Question 25

```c
1  #include <stdio.h>
2  #include <stdlib.h>
3  #include <time.h>
4
5  /* Expect three different random numbers */
6  int main(void) {
7      for (int i = 0; i < 3; i++) {
8          srand(time(NULL));
9          printf("%d\n", rand());
10     }
11     return 0;
12 }
```

### Question 26

```c
1  #include <stdio.h>
2
3  int sumTo(int n) {
4      if (n == 0) {
5          return 0;
6      }
7      return n + sumTo(n + 1);
8  }
9
10 int main(void) {
11     printf("%d\n", sumTo(3));
12     return 0;
13 }
```

### Question 27

```c
1  #include <stdio.h>
2
3  /* Expect to print 8 (2 to the power of 3) */
4  int power(int base, int exponent) {
5      if (exponent == 0) {
6          return 0;
7      }
8      return base * power(base, exponent - 1);
9  }
10
11 int main(void) {
12     printf("%d\n", power(2, 3));
13     return 0;
14 }
```

### Question 28

```c
1  #include <stdio.h>
2
3  /* Expect to print 8 (the 6th Fibonacci number) */
4  int fib(int n) {
5      if (n <= 1) {
6          return n;
7      }
8      return fib(n - 1) + fib(n - 2);
9  }
10
11 int main(void) {
12     printf("%d\n", fib(6));
13     return 0;
14 }
```

---

## Part 5: printf, Strings & Pointers

### Question 29

```c
1  #include <stdio.h>
2
3  /* Expect to print the total and the average */
4  int main(void) {
5      int total = 90;
6      double average = total / 3.0;
7
8      printf("Total: %d, Average: %.1f\n", total);
9      return 0;
10 }
```

### Question 30

```c
1  #include <stdio.h>
2
3  /* Expect to print "   42|42   |" (width 5, right-aligned, then left-aligned) */
4  int main(void) {
5      int n = 42;
6
7      printf("%5d|%-5d|\n", n, n);
8      return 0;
9  }
```

### Question 31

```c
1  #include <stdio.h>
2
3  /* Expect to print C:\new\test */
4  int main(void) {
5      printf("C:\new\test\n");
6      return 0;
7  }
```

### Question 32

```c
1  #include <stdio.h>
2
3  /* Expect to print "Match" */
4  int main(void) {
5      char first[] = "hello";
6      char second[] = "hello";
7
8      if (first == second) {
9          printf("Match\n");
10     } else {
11         printf("No match\n");
12     }
13     return 0;
14 }
```

### Question 33

```c
1  #include <stdio.h>
2
3  int main(void) {
4      char *greeting = "hello";
5
6      greeting[0] = 'H';
7
8      printf("%s\n", greeting);
9      return 0;
10 }
```

### Question 34

```c
1  #include <stdio.h>
2
3  int main(void) {
4      int *ptr = NULL;
5
6      *ptr = 42;
7
8      printf("%d\n", *ptr);
9      return 0;
10 }
```

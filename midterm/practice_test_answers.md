# Answer Key

## How to classify an error

| Category | What it means | Typical examples |
|----------|---------------|------------------|
| **Compile error** | The compiler rejects the program. Answer with the line number. | Missing `;`, undeclared identifier, conflicting types, wrong argument count, invalid operands, assigning to a `const` or array |
| **Run-time error** | It compiles, but the program crashes or aborts while running. | Segmentation fault, stack overflow from runaway recursion, divide by zero |
| **Logic error** | It compiles and runs, but the behavior does not match the intent. | Wrong formula, off-by-one, missing `break`, infinite loop that does not crash |
| **No error** | It compiles and behaves as intended. | Legal but unusual code (shadowing, empty `for` clauses) |

**Convention for missing semicolons:** give the line of the statement that is missing its `;`, even though some compilers report the problem on the following line.

## Summary

| # | Answer | # | Answer |
|---|--------|---|--------|
| 1 | **5** | 18 | **10** |
| 2 | **4** | 19 | **8** |
| 3 | **5** | 20 | **4** |
| 4 | **7** | 21 | **no error** |
| 5 | **6** | 22 | **logic error** |
| 6 | **logic error** | 23 | **6** |
| 7 | **logic error** | 24 | **logic error** |
| 8 | **4** | 25 | **logic error** |
| 9 | **6** | 26 | **run-time error** |
| 10 | **no error** | 27 | **logic error** |
| 11 | **logic error** | 28 | **no error** |
| 12 | **logic error** | 29 | **logic error** |
| 13 | **logic error** | 30 | **no error** |
| 14 | **11** | 31 | **logic error** |
| 15 | **12** | 32 | **logic error** |
| 16 | **logic error** | 33 | **run-time error** |
| 17 | **logic error** | 34 | **run-time error** |


## Detailed Explanations

### Part 1: Syntax, Declarations & Types

**Q1: Line 5 (compile error).**
The `printf` statement on line 5 has no terminating semicolon. C statements must end with `;`, and the compiler only realizes something is wrong when it hits `return` on the next line and finds it cannot continue the expression. The typical message is `error: expected ';' before 'return'`. Fix: `printf("Count: %d\n", count);`

**Q2: Line 4 (compile error).**
`int a = b = c = 0;` looks like it declares three variables, but only `a` is declared. The statement parses as `int a = (b = (c = 0));`, which assigns to `b` and `c` without ever declaring them. The compiler reports `'b' undeclared (first use in this function)`. Note that line 6 only uses `a` here, so line 4 is the only location. Fix with either `int a = 0, b = 0, c = 0;` or `int a, b, c; a = b = c = 0;`.

**Q3: Line 5 (compile error).**
A `const` variable cannot be modified after initialization. Line 4 is legal because it *initializes* the constant. Line 5 tries to *assign* to it, giving `assignment of read-only variable 'MAX_PLAYERS'`.

**Q4: Line 7 (compile error).**
Arrays are not assignable in C. In the expression `copy = original`, the name `original` decays to a pointer, but `copy` is an array, which is not a modifiable lvalue (`assignment to expression with array type`). To copy an array, use a loop or `memcpy(copy, original, sizeof(original));` from `<string.h>`.

**Q5: Line 6 (compile error).**
The `%` (modulus) operator requires **integer** operands. `seconds` is a `double`, so `seconds % 60` is invalid (`invalid operands to binary %`). Line 5 is legal: assigning a `double` to an `int` silently truncates (`125.5 / 60` is about `2.09`, which becomes `2`). The correct way to get a floating-point remainder is `fmod(seconds, 60)` from `<math.h>`.

**Q6: logic error.**
Both `total` and `count` are `int`, so `total / count` performs **integer division** (`7 / 2` is `3`) *before* the result is stored in the `double`. The program prints `3.00` instead of `3.50`. Converting after the division is too late. Fix by making at least one operand floating point: `(double)total / count` or `total / 2.0`.

**Q7: logic error.**
`1 / 3` is integer division, which evaluates to `0`. So the call is `pow(8.0, 0)`, which is `1.0`, and the program prints `1.00` instead of `2.00`. Fix: `pow(8.0, 1.0 / 3)`, or use `cbrt(8.0)`. This is the same trap as Q6, hiding inside a function argument.

### Part 2: Control Flow

**Q8: Line 4 (compile error).**
The three parts of a `for` header are separated by **semicolons**, not commas. With commas, the compiler thinks `int i = 0, i < 3, ...` is a declaration list and chokes at the `<`. Fix: `for (int i = 0; i < 3; i++)`.

**Q9: Line 6 (compile error).**
The semicolon at the end of line 4 is an empty statement, which becomes the entire loop body. The `{ ... }` block on lines 5 to 7 is then just a standalone block that runs once *after* the loop. Since `i` was declared inside the `for` header, its scope is limited to the `for` statement, so on line 6 it is undeclared. (If `i` had been declared before the loop, this would instead be a logic error that prints `3` once.)

**Q10: no error.**
All three clauses of a `for` header are optional. Here the initialization lives on line 4 and the update on line 8. The empty condition would mean "always true", but this one is provided (`i < 3`). The program prints `0`, `1`, `2` on separate lines. Using `%zu` is the correct specifier for `size_t`.

**Q11: logic error.**
`score = 10` is an **assignment**, not a comparison. It stores `10` in `score`, and the value of an assignment expression is the assigned value (`10`), which is nonzero, so the condition is always true. The program prints `Perfect`. Even if the intent was `score == 10`, `3 == 10` is false and "Try again" would print. The code compiles (many compilers warn with `-Wall`). Fix: `if (score == 10)`.

**Q12: logic error.**
Without braces, a `while` loop's body is only the **single next statement**, which is the `printf` on line 8. The `n--;` on line 9 is outside the loop, so `n` never changes and the loop prints `3` forever. The indentation is misleading and the compiler ignores it. Fix: wrap both statements in `{ }`.

**Q13: logic error.**
`switch` cases **fall through** unless you `break`. For `place == 2`, execution enters `case 2`, prints `Silver`, has no `break`, and continues into `case 3`, printing `Bronze` as well. Add `break;` after line 12.

**Q14: Line 11 (compile error).**
A `case` label must be an **integer constant expression**, known at compile time. `boss` is a variable, so `case boss:` is rejected (`case label does not reduce to an integer constant`). In C, even `const int boss = 5;` does not count (this differs from C++). Use a literal, a `#define`, or an `enum`.

**Q15: Line 12 (compile error).**
`continue` is only valid inside a **loop**. A `switch` is not a loop, so `continue` there with no enclosing loop gives `continue statement not within a loop`. `break` works in both loops and switches. If this `switch` were inside a `for` or `while`, `continue` would be legal and would jump to the next iteration.

**Q16: logic error.**
`size_t` is an **unsigned** type, so `i >= 0` is *always true*. After printing `0`, `i--` wraps around to the maximum `size_t` value (18446744073709551615 on a 64-bit system), and the loop continues with huge numbers. It compiles (usually with a warning that the comparison is always true). Fixes: use a signed `int`, or restructure as `for (size_t i = 4; i-- > 0; )`.

**Q17: logic error.**
The loop compares the **index** `i` to `'\0'` instead of comparing the **character** `word[i]`. Since `'\0'` is just the integer `0` and `i` starts at `0`, the condition `i != '\0'` is false immediately, and nothing prints. Fix: `while (word[i] != '\0')`.

### Part 3: Functions & Scope

**Q18: Line 10 (compile error).**
The prototype on line 3 promises `int average(int, int)`, but the definition on line 10 returns `double`. The return type is part of a function's signature, so the compiler reports `conflicting types for 'average'` at the definition (and notes the earlier declaration on line 3). Parameter *names* may differ between prototype and definition, but types and return type must agree.

**Q19: Line 8 (compile error).**
`cube` takes one parameter, but the call passes two arguments. This is a constraint violation: `too many arguments to function 'cube'`. The error is reported at the call site, line 8.

**Q20: Line 4 (compile error).**
A function's parameters share the scope of the function body's outermost block. Declaring `int value` again on line 4 is a **redeclaration in the same scope**, which is illegal (`'value' redeclared as different kind of symbol`). Compare this with Q21, where the redeclaration is in a *nested* block.

**Q21: no error.**
Declaring a variable with the same name inside a nested block is legal and is called **shadowing**. The inner `level` (line 7) hides the outer one only inside the braces. The output is:

```
inner: 6
outer: 1
```

The outer `level` is untouched by the `level++` on line 8 because that increments the inner variable.

**Q22: logic error.**
C passes arguments **by value**. `swap` receives copies of `x` and `y`, swaps the copies, and discards them when it returns. `main`'s variables are unchanged, so the program prints `3 7`. To modify the caller's variables, pass pointers:

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* call as swap(&x, &y); */
```

### Part 4: Random Numbers & Recursion

**Q23: Line 6 (compile error).**
`srand` has return type `void`: it seeds the generator and returns nothing. Using it in an expression (`srand(...) % 6`) gives `invalid operands to binary % (have 'void' and 'int')`. The correct pattern is to call `srand(time(NULL));` as its own statement once, then use `rand() % 6 + 1`.

**Q24: logic error.**
`rand() % 10` produces `0` to `9`, so adding `5` gives `5` to `14`. The value `15` can never occur. The general formula for an inclusive range is:

```c
rand() % (max - min + 1) + min
```

For 5 to 15, that is `rand() % 11 + 5`. The seeding on line 8 is done correctly, so the only defect is the range.

**Q25: logic error.**
`time(NULL)` returns the current time in **whole seconds**. The loop runs in microseconds, so all three calls to `srand` receive the same seed, reset the generator to the same state, and `rand()` returns the **same number three times**. Seed once, before the loop.

**Q26: run-time error.**
The calls go `sumTo(3)`, `sumTo(4)`, `sumTo(5)`, ... and never reach the base case `n == 0` because `n` is moving *away* from it. Every call adds a stack frame, and eventually the call stack is exhausted (**stack overflow**), crashing the program with a segmentation fault. The root cause is a logic mistake (`n + 1` should be `n - 1`), but since the symptom is a crash, it is classified as a run-time error. This matches the style of the lab quiz item where the feedback said the function "never reaches the base case ... until the call stack is exhausted".

**Q27: logic error.**
The recursion structure is fine, but the base case returns `0`. Every chain of multiplications ends with `* 0`, so the result is `2 * 2 * 2 * 0 = 0`. The base case for multiplication must return the multiplicative identity, `1`. The program runs normally and prints `0` instead of `8`.

**Q28: no error.**
Two base cases (`fib(0) = 0` and `fib(1) = 1`) are handled by `n <= 1`. The sequence runs `0, 1, 1, 2, 3, 5, 8`, so `fib(6)` is `8`. It is not efficient (the same values are recomputed many times), but efficiency is not correctness.

### Part 5: printf, Strings & Pointers

**Q29: logic error.**
The format string has two conversion specifiers (`%d` and `%.1f`), but only one argument is supplied. `printf` will try to read a second argument that does not exist, so the value printed for the average is garbage. Strictly speaking this is undefined behavior, and compilers typically only **warn** (`format '%f' expects a matching 'double' argument`). In lab-quiz style, mismatches between the format string and its arguments count as logic errors. Fix: `printf("... %.1f\n", total, average);`

**Q30: no error.**
`%5d` prints the integer right-aligned in a field at least 5 characters wide, padding with spaces on the left. The `-` flag in `%-5d` left-aligns instead, padding on the right. The output is `   42|42   |`.

**Q31: logic error.**
Inside a string literal, `\n` is a newline and `\t` is a tab. It compiles without trouble because both are valid escape sequences, but the output is:

```
C:
ew	est
```

To print a literal backslash, escape it: `"C:\\new\\test\n"`.

**Q32: logic error.**
In `first == second`, both arrays decay to pointers to their first elements, so `==` compares **addresses**, not contents. These are two separate arrays at different addresses, so the comparison is false and `No match` prints. To compare contents, include `<string.h>` and use `strcmp(first, second) == 0`.

**Q33: run-time error.**
`char *greeting = "hello";` points at a **string literal**, which is usually stored in read-only memory. Writing to it on line 6 is undefined behavior and typically crashes with a segmentation fault. The code compiles (a `const char *` would have turned this into a compile error). To get a modifiable string, use an array: `char greeting[] = "hello";`.

**Q34: run-time error.**
`ptr` is `NULL`, which does not point to valid memory. Dereferencing it on line 6 (`*ptr = 42;`) crashes the program with a segmentation fault. The code compiles cleanly. Always make sure a pointer refers to valid storage before dereferencing it, for example `int value; int *ptr = &value;`.

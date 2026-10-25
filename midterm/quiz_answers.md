# Answer Key

| # | Answer | Why |
|---|--------|-----|
| 1 | **C** | `sizeof` is an operator, not a function. |
| 2 | **D** | `int nums[3] = {0}` sets every element to 0. `nums[0]` is zero-length (non-standard), `nums[3]` alone leaves values uninitialized, and `nums[] = {0}` only makes a 1-element array. |
| 3 | **D** | `*p = *q` sets `a = 10`. `q = p` makes `q` point at `a`. `*q = 20` sets `a = 20`. `b` stays 10. |
| 4 | **A** | A C-string is a `char` array ending in `'\0'`. |
| 5 | **D** | `sizeof(nums) / sizeof(nums[0])` is total bytes divided by element size. |
| 6 | **B** | In most expressions, `arr` decays to a pointer to its first element, so `arr` and `&arr[0]` are equivalent. Arrays are not pointers (D). |
| 7 | **B** | Each `arr[i]` gets `i` added: `2+0, 4+1, 6+2`, so it prints `2 5 8`. |
| 8 | **D** | You need an `int **p` to modify the caller's pointer, and `*p = q` reassigns it. B points at a local copy `q`, which is dangling. |
| 9 | **B (False)** | `const char *var` is a pointer to const data. `char *const var` is a const pointer to mutable data. |
| 10 | **B and D** | A returns an `int`, not an `int *`. C returns the address of a local variable. |
| 11 | **A** | The 3rd element is index 2, so `p + 2`. `&arr[3]` is the 4th element. |
| 12 | **B** | `char *arr[10];` is an array of 10 `char *`. |
| 13 | **B** | == compares addresses, not contents. Use `strcmp()`. |
| 14 | **A, B, D** | Array parameters decay to pointers, so `int arr[]`, `int *arr`, and `int arr[10]` are all equivalent. C takes a single `int`. |


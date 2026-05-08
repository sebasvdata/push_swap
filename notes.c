/*
Merge sort notes for sort_stack.c

1. Wrong left-half limit in recursive_merge:
   - Line 26 uses:
       i <= (end + start / 2)
   - Because / has priority before +, this means:
       i <= end + (start / 2)
   - It should use the same middle index as the rest of the function:
       i <= ((end + start) / 2)
   - This is the main bug that corrupts the result. Current test output is:
       -223 1 2 3 5 6 9 9 -223 6
     The correct output should be:
       -223 1 2 3 5 6 9 9 100 191919

2. No base-case return:
   - The function checks if (start < end), recurses, then always continues to
     merge.
   - For start == end, merging one value is harmless but unnecessary.
   - For invalid ranges, especially size == 0 from merge_sort, this can create
     a zero-size or invalid temporary array.
   - Safer structure:
       if (start >= end)
           return ;

3. merge_sort does not validate input:
   - merge_sort(tab, size) always calls recursive_merge(tab, 0, size - 1).
   - If tab == NULL, it can crash.
   - If size <= 0, end becomes -1 or lower and the VLA size is invalid.
   - If size == 1, sorting is unnecessary.
   - Safer guard:
       if (!tab || size <= 1)
           return ;

4. Possible integer overflow in middle calculation:
   - (end + start) can overflow an int for very large indexes.
   - Safer formula:
       mid = start + (end - start) / 2;

5. Temporary array uses VLA:
   - int tmptab[end - start + 1] is allocated on the stack.
   - Very large input can overflow the stack.
   - VLA may also be rejected by some 42/norm or compiler settings.
   - A malloc/free temporary buffer, or one shared buffer passed through
     recursion, is safer.

6. Variable declaration is not at the start of the function:
   - int tmptab[...] is declared after statements and after the recursive calls.
   - Norminette reports VAR_DECL_START_FUNC for this.

7. recursive_merge is longer than 25 lines:
   - Norminette reports TOO_MANY_LINES.
   - Split helper logic, for example copy/merge logic into another function.

8. Formatting is not norm-compliant:
   - Missing 42 header.
   - Missing spaces around operators and after keywords.
   - Spaces are used where tabs are expected.
   - Functions are not separated correctly.
   - There is mixed spacing in merge_sort.

9. Test main has an unused variable:
   - int size; is declared but never used.
   - Compiling with -Wall -Wextra -Werror fails because of this.

10. sort_stack.c currently includes a test main and stdio.h:
    - For the real push_swap project, sort_stack.c should not keep a debug
      printf test main if another main already exists in handel_input.c.
    - Keeping both mains will cause a multiple-definition linker error when
      compiling the whole project together.

11. No prototype in push_swap.h:
    - merge_sort and recursive_merge are not declared in push_swap.h.
    - If another file needs merge_sort, add its prototype.
    - recursive_merge should probably stay static inside sort_stack.c if it is
      only a helper.

12. Equal values are taken from the right side first:
    - if (tab[i] < tab[j]) takes the left value only when it is strictly lower.
    - For duplicate values this still sorts correctly, but it is not stable.
    - Use <= if you want stable merge sort behavior.
    - In push_swap, duplicates are invalid input, so this is only a general
      merge-sort note.

13. This merge sort only sorts an int array:
    - It does not operate on t_stack using push_swap operations.
    - That is fine if it is only for indexing/ranking values.
    - It is not a final push_swap sorting algorithm by itself.
*/

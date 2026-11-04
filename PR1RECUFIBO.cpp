#include <stdio.h>

int fib(int n) {
    if(n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}

int main() {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        printf("%d ", fib(i));

    return 0;
}



/*
======================== THEORY ========================

The Fibonacci sequence is a series of numbers in which
each number is the sum of the previous two numbers.

Mathematically, it is defined by the recurrence relation:

F(n) = F(n-1) + F(n-2)

Initial values:
F(0) = 0
F(1) = 1

Example:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34...

--------------------------------------------------------
1. RECURSIVE APPROACH:
--------------------------------------------------------

In the recursive approach, a function calls itself
to calculate Fibonacci numbers.

Base conditions:
If n == 0, return 0.
If n == 1, return 1.

Otherwise:
F(n) = F(n-1) + F(n-2)

--------------------------------------------------------
2. NON-RECURSIVE APPROACH:
--------------------------------------------------------

In the non-recursive approach, a loop is used to
calculate Fibonacci numbers.

The program takes the first two numbers (0 and 1).
It calculates the next number by adding the previous
two numbers and updates their values repeatedly.

--------------------------------------------------------
3. PROBLEM SOLUTION:
--------------------------------------------------------

1. Take the first two numbers of the series.
2. Accept the number of terms from the user.
3. Calculate the next number by adding the previous
   two numbers.
4. Print the Fibonacci series.
5. Repeat until all terms are printed.
6. Exit.

--------------------------------------------------------
4. FLOWCHART - RECURSIVE APPROACH:
--------------------------------------------------------

             +-------------+
             |    START    |
             +-------------+
                    |
                    v
             +-------------+
             |   Input n   |
             +-------------+
                    |
                    v
             +-------------+
             |  Call fib(n)|
             +-------------+
                    |
                    v
             +-------------+
             |   n <= 1 ?  |
             +-------------+
               /       \
             YES        NO
              |          |
              v          v
        +----------+  +------------------+
        | Return n |  | fib(n-1)+fib(n-2)|
        +----------+  +------------------+
              |          |
              +-----+----+
                    |
                    v
             +-------------+
             | Print Result|
             +-------------+
                    |
                    v
             +-------------+
             |    STOP     |
             +-------------+

--------------------------------------------------------
5. FLOWCHART - NON-RECURSIVE APPROACH:
--------------------------------------------------------

             +-------------+
             |    START    |
             +-------------+
                    |
                    v
             +-------------+
             |   Input n   |
             +-------------+
                    |
                    v
             +-------------+
             | a=0, b=1, i=0|
             +-------------+
                    |
                    v
             +-------------+
             |    i < n ?  |
             +-------------+
               /       \
             YES        NO
              |          |
              v          v
        +----------+  +----------+
        |  Print a |  |   STOP   |
        +----------+  +----------+
              |
              v
        +-------------+
        |   c = a+b   |
        +-------------+
              |
              v
        +-------------+
        |    a = b    |
        +-------------+
              |
              v
        +-------------+
        |    b = c    |
        +-------------+
              |
              v
        +-------------+
        |    i++      |
        +-------------+
              |
              +-----------> Back to i < n

--------------------------------------------------------
6. TIME COMPLEXITY:
--------------------------------------------------------

Recursive Approach: O(2^n)
Non-Recursive Approach: O(n)

7. AUXILIARY SPACE COMPLEXITY:

Recursive Approach: O(n)
Non-Recursive Approach: O(1)

g++ PR1NONFIBO.cpp -o PR1NONFIBO
.\PR1NONFIBO.exe
========================================================
*/
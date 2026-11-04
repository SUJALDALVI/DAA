
#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int profit[100], weight[100];

    cout << "Enter profits:\n";
    for(int i = 1; i <= n; i++)
        cin >> profit[i];

    cout << "Enter weights:\n";
    for(int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[101][101] = {0};

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {

            if(weight[i] <= w) {
                dp[i][w] = max(
                    profit[i] + dp[i-1][w-weight[i]],
                    dp[i-1][w]
                );
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "\nMaximum Profit = " << dp[n][W];

    return 0;
}

/*
====================== THEORY ======================

0/1 KNAPSACK PROBLEM:

The 0/1 Knapsack problem is an optimization problem
in which we are given items with their profits
and weights.

We have a knapsack with a fixed capacity.

The objective is to maximize the total profit
without exceeding the capacity of the knapsack.

In this problem, each item can either be selected
completely (1) or rejected (0).

Items cannot be divided into fractions.

DYNAMIC PROGRAMMING:

Dynamic Programming is a technique that solves
complex problems by dividing them into smaller
subproblems and storing their results.

It avoids solving the same subproblem repeatedly.

FORMULA:

If weight[i] <= w:

dp[i][w] = max(
    profit[i] + dp[i-1][w-weight[i]],
    dp[i-1][w]
)

Otherwise:

dp[i][w] = dp[i-1][w]

Here:
dp[i][w] = Maximum profit using first i items
           with capacity w.

----------------------------------------------------
ALGORITHM:
----------------------------------------------------

Step 1: Start.
Step 2: Enter number of items.
Step 3: Enter profits and weights.
Step 4: Enter knapsack capacity.
Step 5: Initialize the DP table with 0.
Step 6: Check each item and capacity.
Step 7: If item weight is less than or equal
        to capacity, choose maximum profit
        between including and excluding item.
Step 8: Otherwise, exclude the item.
Step 9: Store the maximum profit in DP table.
Step 10: Print maximum profit.
Step 11: Stop.

----------------------------------------------------
FLOWCHART:
----------------------------------------------------

              +-------------+
              |    START    |
              +-------------+
                     |
                     v
          +---------------------+
          | Enter Items, Profit |
          | Weight and Capacity |
          +---------------------+
                     |
                     v
          +---------------------+
          | Initialize DP Table |
          | with 0              |
          +---------------------+
                     |
                     v
          +---------------------+
          | Select Next Item    |
          +---------------------+
                     |
                     v
          +---------------------+
          | Check Item Weight   |
          | <= Capacity ?       |
          +---------------------+
                /          \
              YES           NO
               |             |
               v             v
       +----------------+  +----------------+
       | Calculate Max  |  | Exclude Item   |
       | Include/Exclude|  | dp[i][w]       |
       +----------------+  | = dp[i-1][w]   |
               |           +----------------+
               v                  |
       +----------------+         |
       | Store Maximum  |         |
       | Profit in DP   |         |
       +----------------+         |
               |                  |
               +--------+---------+
                        |
                        v
             +-------------------+
             | More Items or     |
             | Capacities Left?  |
             +-------------------+
                 /          \
               YES           NO
                |             |
                v             v
         +-------------+  +----------------+
         | Repeat Loop |  | Print Maximum  |
         +-------------+  | Profit         |
                |         +----------------+
                |                  |
                +----->            v
                             +-----------+
                             |   STOP    |
                             +-----------+

----------------------------------------------------
TIME COMPLEXITY:
----------------------------------------------------

O(n * W)

Where:
n = Number of items
W = Knapsack capacity

SPACE COMPLEXITY:

O(n * W)

The DP table stores results for all items
and possible capacities.

----------------------------------------------------
CONCLUSION:
----------------------------------------------------

Thus, we successfully implemented the 0/1
Knapsack problem using Dynamic Programming
to obtain maximum profit within the given
knapsack capacity.


g++ PR1NONFIBO.cpp -o PR1NONFIBO
.\PR1NONFIBO.exe
====================================================
*/

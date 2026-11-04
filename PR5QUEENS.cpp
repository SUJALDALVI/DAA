
#include <iostream>
using namespace std;

int board[20];
int n;

// Check whether queen can be placed safely
bool isSafe(int row, int col) {
    for(int i = 0; i < row; i++) {

        if(board[i] == col)
            return false;

        if(abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

// Solve N-Queens using Backtracking
bool solve(int row) {

    if(row == n)
        return true;

    for(int col = 0; col < n; col++) {

        if(isSafe(row, col)) {

            board[row] = col;

            if(solve(row + 1))
                return true;

            board[row] = -1;
        }
    }

    return false;
}

int main() {

    cout << "Enter number of queens: ";
    cin >> n;

    for(int i = 0; i < n; i++)
        board[i] = -1;

    if(solve(0)) {

        cout << "\nSolution:\n";

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i] == j)
                    cout << " Q ";
                else
                    cout << " . ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}

/*
====================== THEORY ======================

WHAT IS BACKTRACKING?

Backtracking is an algorithmic technique that
builds a solution step by step.

If a selected choice does not lead to a valid
solution, we go back and try another choice.

It explores all possible solutions and selects
the one that satisfies the given conditions.

WHAT IS N-QUEENS PROBLEM?

The N-Queens problem is a problem of placing
N queens on an N x N chessboard.

The objective is to place all queens such that
no two queens attack each other.

A queen can attack in three directions:

1. Same Row
2. Same Column
3. Diagonal

BACKTRACKING APPROACH:

1. Start from the first row.
2. Try placing a queen in each column.
3. Check whether the position is safe.
4. If safe, place the queen.
5. Move to the next row.
6. If no safe position is available,
   go back to the previous row.
7. Remove the previously placed queen.
8. Try another position.
9. Repeat until all queens are placed.

ALGORITHM:

Step 1: Start.
Step 2: Enter the number of queens N.
Step 3: Initialize the board.
Step 4: Call solve(0).
Step 5: Check whether the current position is safe.
Step 6: If safe, place the queen.
Step 7: Move to the next row using recursion.
Step 8: If placement fails, remove the queen.
Step 9: Try another column.
Step 10: If all queens are placed, print solution.
Step 11: Stop.

TIME COMPLEXITY:

O(N!)

SPACE COMPLEXITY:

O(N)

----------------------------------------------------
FLOWCHART:
----------------------------------------------------

              +-------------+
              |    START    |
              +-------------+
                     |
                     v
          +---------------------+
          | Enter Number of     |
          | Queens (N)          |
          +---------------------+
                     |
                     v
          +---------------------+
          | Initialize Board    |
          +---------------------+
                     |
                     v
          +---------------------+
          | Start from Row 0    |
          +---------------------+
                     |
                     v
          +---------------------+
          | Check Safe Position |
          +---------------------+
                     |
                     v
          +---------------------+
          | Is Position Safe?   |
          +---------------------+
                /         \
              YES          NO
               |            |
               v            v
        +-------------+  +-------------+
        | Place Queen |  | Try Next    |
        +-------------+  | Column      |
               |         +-------------+
               v
        +-------------+
        | Move to Next|
        | Row         |
        +-------------+
               |
               v
        +-------------+
        | All Queens  |
        | Placed?     |
        +-------------+
           /       \
         YES        NO
          |          |
          v          v
    +-----------+ +----------------+
    | Print     | | Backtrack and  |
    | Solution  | | Remove Queen   |
    +-----------+ +----------------+
          |              |
          v              |
    +-----------+        |
    |   STOP    | <------+
    +-----------+

----------------------------------------------------
CONCLUSION:
----------------------------------------------------

Thus, we successfully implemented the N-Queens
problem using Backtracking.

The program places N queens on an N x N chessboard
such that no two queens attack each other.

g++ PR1NONFIBO.cpp -o PR1NONFIBO
.\PR1NONFIBO.exe
====================================================
*/

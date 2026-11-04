
#include <iostream>
using namespace std;

struct Item {
    int profit, weight;
    float ratio;
};

int main() {
    Item a[100], temp;
    int n, capacity;
    float total = 0;

    cout << "Enter number of items: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter profit and weight: ";
        cin >> a[i].profit >> a[i].weight;

        a[i].ratio = (float)a[i].profit / a[i].weight;
    }

    // Sort items by profit/weight ratio
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i].ratio < a[j].ratio) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(capacity >= a[i].weight) {
            total += a[i].profit;
            capacity -= a[i].weight;
        }
        else {
            total += a[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "\nMaximum Profit = " << total;

    return 0;
}

/*
====================== THEORY ======================

WHAT IS GREEDY ALGORITHM?

Greedy is an algorithmic technique that builds a
solution piece by piece.

It always chooses the locally optimal choice at
each step to obtain the best possible solution.

FRACTIONAL KNAPSACK PROBLEM:

Fractional Knapsack is a problem in which we have
different items with their profits and weights.

We have a knapsack with a fixed capacity.

The objective is to maximize the total profit
without exceeding the capacity of the knapsack.

In this problem, we can take fractions of items.

GREEDY APPROACH:

1. Calculate the profit/weight ratio of each item.
2. Sort items in descending order of their ratio.
3. Select the item with the highest ratio first.
4. If the complete item fits, take the entire item.
5. Otherwise, take the fraction that fits.
6. Calculate the maximum total profit.

FORMULA:

Ratio = Profit / Weight

Fractional Profit = Ratio * Remaining Capacity

ALGORITHM:

Step 1: Start.
Step 2: Enter number of items and capacity.
Step 3: Enter profit and weight of each item.
Step 4: Calculate profit/weight ratio.
Step 5: Sort items in descending order of ratio.
Step 6: Select the item with the highest ratio.
Step 7: If the item fits, take the complete item.
Step 8: Otherwise, take the required fraction.
Step 9: Calculate total profit.
Step 10: Print maximum profit.
Step 11: Stop.

FLOWCHART:

             +-------------+
             |    START    |
             +-------------+
                    |
                    v
          +-------------------+
          | Enter Items and   |
          | Knapsack Capacity |
          +-------------------+
                    |
                    v
          +-------------------+
          | Calculate Profit/ |
          | Weight Ratio      |
          +-------------------+
                    |
                    v
          +-------------------+
          | Sort by Ratio     |
          | (Descending)      |
          +-------------------+
                    |
                    v
          +-------------------+
          | Select Next Item  |
          +-------------------+
                    |
                    v
             +-------------+
             | Item Fits ? |
             +-------------+
                /       \
              YES        NO
               |          |
               v          v
       +-------------+  +----------------+
       | Take Entire |  | Take Fraction  |
       | Item        |  | of Item        |
       +-------------+  +----------------+
               |          |
               v          v
       +-------------+  +----------------+
       | Add Profit  |  | Add Fractional |
       | and Update  |  | Profit         |
       | Capacity    |  +----------------+
       +-------------+          |
               |                |
               +-------+--------+
                       |
                       v
             +----------------+
             | Capacity Full  |
             | or Items End?  |
             +----------------+
                       |
                       v
             +----------------+
             | Print Maximum  |
             | Profit         |
             +----------------+
                       |
                       v
                +-----------+
                |   STOP    |
                +-----------+

TIME COMPLEXITY:

Sorting: O(n^2)
Selecting Items: O(n)

Overall Time Complexity: O(n^2)

AUXILIARY SPACE COMPLEXITY:

O(1) excluding the input array.

CONCLUSION:

Thus, we successfully implemented the Fractional
Knapsack problem using the Greedy Method to obtain
maximum profit within the given knapsack capacity.

g++ PR1NONFIBO.cpp -o PR1NONFIBO
.\PR1NONFIBO.exe
==================================================
*/

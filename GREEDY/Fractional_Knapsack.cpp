/*
====================================================================================================
                             FRACTIONAL KNAPSACK (GREEDY ALGORITHM)
====================================================================================================

PROBLEM:
GeeksforGeeks - Fractional Knapsack

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given two arrays

val[]

and

wt[]

representing the value and weight of items,

and an integer

capacity,

find the maximum value that can be placed inside the knapsack.

Unlike the 0/1 Knapsack,

an item can be taken either completely

or partially.

Return the maximum obtainable profit.

====================================================================================================
PREREQUISITES
====================================================================================================

• Arrays

• Sorting

• Greedy Algorithm

• Ratio Concept

====================================================================================================
INTUITION
====================================================================================================

Every item contributes

Value / Weight

profit per unit weight.

Therefore,

instead of selecting the highest value item,

select the item having the highest

Value / Weight Ratio.

If the remaining capacity becomes smaller than an item's weight,

take only the required fraction.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Always choosing the item with the highest

Value / Weight

ratio guarantees maximum profit.

If the current item cannot fit completely,

taking its fraction still gives the best possible profit.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Store every item as

(Value, Weight)

↓

Step 2

Sort all items in decreasing order of

Value / Weight Ratio.

↓

Step 3

Traverse the sorted items.

↓

Step 4

If item completely fits,

take it completely.

↓

Step 5

Otherwise,

take only the required fraction.

↓

Step 6

Return total profit.

====================================================================================================
ALGORITHM
====================================================================================================

Store Items

↓

Sort by

Value / Weight

↓

Capacity Available?

↓

YES

Take Complete Item

↓

NO

Take Fraction

↓

Capacity becomes 0

↓

Return Profit

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Functions Used

1.

comp()

Compares two items using

Value / Weight Ratio.

Higher ratio gets higher priority.

--------------------------------------------

2.

fractionalKnapsack()

Creates item list.

Sorts items.

Traverses every item.

Calculates maximum profit.

====================================================================================================
GREEDY CHOICE
====================================================================================================

Always choose

Highest Value per Unit Weight

instead of

Highest Value.

This produces the maximum possible profit.

====================================================================================================
DRY RUN
====================================================================================================

Value

60 100 120

Weight

10 20 30

Capacity

50

Ratios

6

5

4

Take Item 1

Profit = 60

Capacity = 40

↓

Take Item 2

Profit = 160

Capacity = 20

↓

Take

20/30

of Item 3

Profit

160 + 80

=

240

Answer = 240

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Sorting

O(N log N)

Traversal

O(N)

Overall

O(N log N)

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

O(N)

For storing items.

====================================================================================================
EDGE CASES
====================================================================================================

✓ Capacity smaller than every item.

✓ Capacity larger than total weight.

✓ Single item.

✓ Fraction required only once.

✓ All items fit completely.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why is Greedy valid here?

Because selecting the highest

Value / Weight Ratio

always maximizes the current profit.

--------------------------------------------

Q2.

Why doesn't this work for 0/1 Knapsack?

Because items cannot be broken into fractions.

Dynamic Programming is required there.

--------------------------------------------

Q3.

Why sort using ratio instead of value?

A high-value item may also have very high weight.

Ratio measures actual profit per unit weight.

====================================================================================================
APPLICATIONS
====================================================================================================

• Cargo Loading

• Resource Allocation

• Investment Optimization

• Budget Allocation

• Logistics Planning

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Greedy Algorithm.

✓ Sort by Value / Weight Ratio.

✓ Items may be taken partially.

✓ Different from 0/1 Knapsack.

✓ Fraction is taken only when capacity becomes insufficient.

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Activity Selection

• Job Sequencing

• Shop in Candy Store

• Minimum Number of Coins

• Assign Mice to Holes

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Sort according to Value / Weight Ratio.

✓ Take complete items whenever possible.

✓ Take fractional item if needed.

✓ Greedy gives the optimal solution.

✓ One of the most important Greedy interview problems.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;

        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
    {
        vector<pair<int,int>> items;

        // {value, weight}
        for(int i = 0; i < val.size(); i++)
            items.push_back({val[i], wt[i]});

        // Sort according to Value/Weight ratio
        sort(items.begin(), items.end(), comp);

        double profit = 0.0;

        for(int i = 0; i < items.size(); i++)
        {
            int value = items[i].first;
            int weight = items[i].second;

            // Take complete item
            if(capacity >= weight)
            {
                profit += value;
                capacity -= weight;
            }
            else
            {
                // Take fractional part
                profit += ((double)value / weight) * capacity;
                break;
            }
        }

        return profit;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> value(n), weight(n);

    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    int capacity;
    cout << "Enter Knapsack Capacity: ";
    cin >> capacity;

    cout << "\nMaximum Profit = "
         << obj.fractionalKnapsack(value, weight, capacity)
         << endl;

    return 0;
}

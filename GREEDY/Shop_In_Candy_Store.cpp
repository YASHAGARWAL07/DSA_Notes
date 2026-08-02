/*
====================================================================================================
                             SHOP IN CANDY STORE (GREEDY ALGORITHM)
====================================================================================================

PROBLEM:
GeeksforGeeks - Shop in Candy Store

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

A candy store offers the following scheme:

Whenever you buy one candy,

you can get at most K other candies for free.

Given the price of every candy,

find

1. Minimum amount of money required to buy all candies.

2. Maximum amount of money required to buy all candies.

Return both values.

====================================================================================================
PREREQUISITES
====================================================================================================

• Arrays

• Sorting

• Two Pointer Technique

• Greedy Algorithm

====================================================================================================
INTUITION
====================================================================================================

To minimize the total cost,

buy the cheapest candy first.

Since buying one candy allows taking K candies for free,

we should take the K most expensive candies for free.

------------------------------------------------------------

To maximize the total cost,

buy the most expensive candy first.

Then take the K cheapest candies for free.

Thus,

Greedy helps us minimize as well as maximize the total amount.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Minimum Cost

↓

Buy Cheapest

↓

Take Costliest for Free

↓

Repeat

--------------------------------------------

Maximum Cost

↓

Buy Costliest

↓

Take Cheapest for Free

↓

Repeat

====================================================================================================
APPROACH
====================================================================================================

Step 1

Sort the prices.

↓

Step 2

For Minimum Cost

Take smallest candy.

↓

Skip K largest candies.

↓

Repeat until all candies are considered.

--------------------------------------------

Step 3

For Maximum Cost

Take largest candy.

↓

Skip K smallest candies.

↓

Repeat until all candies are considered.

====================================================================================================
ALGORITHM
====================================================================================================

Sort Prices

↓

Minimum Cost

i = 0

j = n-1

↓

Buy prices[i]

↓

i++

↓

j -= k

↓

Repeat

--------------------------------------------

Maximum Cost

i = n-1

j = 0

↓

Buy prices[i]

↓

i--

↓

j += k

↓

Repeat

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Function Used

minMaxCandy()

--------------------------------------------

Step 1

Sort the price array.

--------------------------------------------

Step 2

Use

i = 0

j = n-1

to calculate

Minimum Cost.

--------------------------------------------

Step 3

Reset pointers.

Use

i = n-1

j = 0

to calculate

Maximum Cost.

--------------------------------------------

Return

{Minimum Cost, Maximum Cost}

====================================================================================================
GREEDY CHOICE
====================================================================================================

Minimum Cost

Always buy

Cheapest Candy.

Take

Most Expensive

candies for free.

--------------------------------------------

Maximum Cost

Always buy

Most Expensive Candy.

Take

Cheapest

candies for free.

====================================================================================================
DRY RUN
====================================================================================================

Prices

3 2 1 4

K = 2

After Sorting

1 2 3 4

--------------------------------------------

Minimum Cost

Buy 1

Free

4 3

Remaining

2

Buy 2

Answer = 3

--------------------------------------------

Maximum Cost

Buy 4

Free

1 2

Remaining

3

Buy 3

Answer = 7

Return

{3,7}

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

O(1)

Ignoring output vector.

====================================================================================================
EDGE CASES
====================================================================================================

✓ Only one candy.

--------------------------------------------

✓ K = 0

Need to buy every candy.

--------------------------------------------

✓ K >= N

Only one candy needs to be bought.

--------------------------------------------

✓ All candies have same price.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why do we sort the prices?

Sorting helps us easily access

Cheapest

and

Costliest

candies using two pointers.

--------------------------------------------

Q2.

Why use Greedy?

Because every purchase should maximize the benefit

obtained from the free candies.

--------------------------------------------

Q3.

Can this be solved without sorting?

Not efficiently.

Sorting makes selecting the cheapest and costliest candies easy.

====================================================================================================
APPLICATIONS
====================================================================================================

• Shopping Discount Problems

• Offer Optimization

• Resource Allocation

• Cost Minimization

• Coupon Based Purchasing

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Greedy Problem.

✓ Uses Sorting.

✓ Uses Two Pointers.

✓ Buy Cheapest → Free Costliest.

✓ Buy Costliest → Free Cheapest.

✓ Same algorithm computes both answers.

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Activity Selection

• Fractional Knapsack

• Minimum Number of Coins

• Job Sequencing

• Assign Mice to Holes

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Greedy minimizes and maximizes cost.

✓ Sorting is mandatory.

✓ Two pointers make implementation simple.

✓ Buy one candy and utilize the free candies optimally.

✓ One of the most common Greedy interview problems.

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
    vector<int> minMaxCandy(vector<int>& prices, int k) {

        // Sort the prices
        sort(prices.begin(), prices.end());

        int i = 0;
        int j = prices.size() - 1;

        int min_amount = 0;
        int max_amount = 0;

        // Calculate Minimum Cost
        while(i <= j){
            min_amount += prices[i];
            i++;
            j -= k;
        }

        // Reset pointers
        i = prices.size() - 1;
        j = 0;

        // Calculate Maximum Cost
        while(i >= j){
            max_amount += prices[i];
            i--;
            j += k;
        }

        return {min_amount, max_amount};
    }
};

int main() {

    Solution obj;

    int n, k;

    cout << "Enter number of candies: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter prices: ";
    for(int i = 0; i < n; i++)
        cin >> prices[i];

    cout << "Enter K: ";
    cin >> k;

    vector<int> ans = obj.minMaxCandy(prices, k);

    cout << "\nMinimum Cost = " << ans[0] << endl;
    cout << "Maximum Cost = " << ans[1] << endl;

    return 0;
}

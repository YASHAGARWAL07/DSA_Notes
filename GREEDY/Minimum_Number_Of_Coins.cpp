/*
====================================================================================================
                               MINIMUM NUMBER OF COINS (GREEDY)
====================================================================================================

PROBLEM:
GeeksforGeeks - Minimum Number of Coins

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given an infinite supply of Indian currency denominations

{10, 5, 2, 1}

and an integer n,

find the minimum number of coins required to make the value n.

====================================================================================================
PREREQUISITES
====================================================================================================

• Arrays
• Greedy Algorithm

====================================================================================================
INTUITION
====================================================================================================

To minimize the number of coins,

always choose the largest denomination that is less than or equal
to the remaining amount.

Why?

A larger denomination covers more value using fewer coins.

After taking as many of that denomination as possible,

repeat the same process for the remaining amount.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Indian currency denominations

10, 5, 2, 1

form a Canonical Coin System.

Choosing the largest available denomination always produces
the minimum number of coins.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Store the denominations

{10,5,2,1}

↓

Step 2

Start from the largest denomination.

↓

Step 3

Take as many coins as possible.

↓

Step 4

Update the remaining amount.

↓

Step 5

Move to the next denomination.

↓

Repeat until the amount becomes zero.

====================================================================================================
ALGORITHM
====================================================================================================

Amount = n

↓

Coin = 10

↓

Take n / 10 coins

↓

Remaining = n % 10

↓

Coin = 5

↓

Repeat

↓

Coin = 2

↓

Repeat

↓

Coin = 1

↓

Done

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Functions Used

findMin()

Stores the denominations

{10,5,2,1}

↓

Calculates

coin = n / denomination

↓

Counts those coins

↓

Updates

n = n % denomination

↓

Moves to the next denomination.

====================================================================================================
DRY RUN
====================================================================================================

n = 39

Coin = 10

39 / 10 = 3

Answer = 3

Remaining = 9

↓

Coin = 5

9 / 5 = 1

Answer = 4

Remaining = 4

↓

Coin = 2

4 / 2 = 2

Answer = 6

Remaining = 0

Final Answer = 6

====================================================================================================
/*
====================================================================================================
                             MINIMUM NUMBER OF COINS (GREEDY ALGORITHM)
====================================================================================================

PROBLEM:
GFG - Minimum Number of Coins

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given an infinite supply of Indian currency denominations

{10, 5, 2, 1}

and an integer N,

find the minimum number of coins required to make the value N.

====================================================================================================
PREREQUISITES
====================================================================================================

• Greedy Algorithm
• Arrays
• Basic Mathematics

====================================================================================================
INTUITION
====================================================================================================

To minimize the number of coins,

always choose the largest possible denomination first.

Since Indian currency denominations

{10,5,2,1}

are canonical,

taking the largest possible coin always gives the optimal answer.

Example

N = 39

Take 10 → Remaining 29

Take 10 → Remaining 19

Take 10 → Remaining 9

Take 5  → Remaining 4

Take 2  → Remaining 2

Take 2  → Remaining 0

Total Coins = 6

====================================================================================================
APPROACH
====================================================================================================

Step 1

Store denominations

10, 5, 2, 1

↓

Step 2

Start from the largest denomination.

↓

Step 3

Find how many times it fits.

coin = n / denomination

↓

Step 4

Add those coins to answer.

↓

Step 5

Update remaining value.

n = n % denomination

↓

Step 6

Move to the next smaller denomination.

↓

Step 7

Repeat until remaining value becomes 0.

====================================================================================================
ALGORITHM
====================================================================================================

Remaining Amount

↓

Largest Coin Available

↓

Take Maximum Possible Coins

↓

Update Remaining Amount

↓

Move to Smaller Coin

↓

Repeat

↓

Amount becomes 0

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Variables Used

arr[]

Stores denominations

{10,5,2,1}

------------------------------------

coin

Number of current denomination coins.

------------------------------------

ans

Stores total coins required.

------------------------------------

i

Moves through denominations.

====================================================================================================
DRY RUN
====================================================================================================

Input

39

Coin = 10

39/10 = 3

Answer = 3

Remaining = 9

↓

Coin = 5

9/5 = 1

Answer = 4

Remaining = 4

↓

Coin = 2

4/2 = 2

Answer = 6

Remaining = 0

Final Answer = 6

====================================================================================================
GREEDY CHOICE
====================================================================================================

Always select the largest denomination first.

Because every larger coin reduces the number of total coins required.

No smaller denomination combination can beat this choice.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

For denominations

{10,5,2,1}

every larger denomination is always more beneficial than replacing it
with multiple smaller coins.

Hence the greedy choice is always optimal.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

O(1)

Only four denominations are checked.

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

O(1)

====================================================================================================
EDGE CASES
====================================================================================================

✓ N = 1

✓ N = 2

✓ N = 5

✓ N = 10

✓ Large values of N

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1. Why Greedy?

Choosing the largest denomination first minimizes the number of coins.

------------------------------------

Q2. Will Greedy always work?

No.

It works only for certain coin systems like

{10,5,2,1}.

Example where it fails

Coins = {1,3,4}

Amount = 6

Greedy → 4 + 1 + 1 = 3 coins

Optimal → 3 + 3 = 2 coins

------------------------------------

Q3. What if denominations are arbitrary?

Use Dynamic Programming instead of Greedy.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Greedy Problem

✓ Largest denomination first

✓ No recursion

✓ No DP required

✓ Constant extra space

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Fractional Knapsack

• Activity Selection

• Shop in Candy Store

• Assign Mice to Holes

• Job Sequencing Problem

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Greedy chooses the locally optimal choice.

✓ Largest denomination is selected first.

✓ Remaining amount is updated after every choice.

✓ Works because the Indian coin system is canonical.

✓ Runs in constant time.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(int n) {
        int arr[4] = {10, 5, 2, 1};
        int ans = 0;
        int coin = 0;
        int i = 0;

        while (n) {
            coin = n / arr[i];

            while (coin--)
                ans++;

            n = n % arr[i];
            i++;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter Amount: ";
    cin >> n;

    cout << "Minimum Coins Required = " << obj.findMin(n) << endl;

    return 0;
}


/*
====================================================================================================
                             ASSIGN MICE TO HOLES (GREEDY ALGORITHM)
====================================================================================================

PROBLEM:
GeeksforGeeks - Assign Mice to Holes

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

There are N mice and N holes placed on a number line.

Each mouse can move either left or right.

Moving one unit takes one minute.

Each hole can accommodate exactly one mouse.

Assign every mouse to a unique hole such that

the time taken by the last mouse to reach its hole

is minimized.

Return the minimum possible time.

====================================================================================================
PREREQUISITES
====================================================================================================

• Arrays

• Sorting

• Greedy Algorithm

• Mathematics

====================================================================================================
INTUITION
====================================================================================================

If mice and holes are assigned randomly,

some mice may travel unnecessarily long distances.

Instead,

sort both arrays.

Now assign

Smallest Mouse

↓

Smallest Hole

Second Smallest Mouse

↓

Second Smallest Hole

...

This minimizes the maximum travel distance.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

After sorting,

cross assignments only increase the maximum distance.

Matching elements in the same order

always produces the minimum possible answer.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Sort mice positions.

↓

Step 2

Sort hole positions.

↓

Step 3

Assign

ith Mouse

↓

ith Hole

↓

Step 4

Compute

abs(mouse - hole)

↓

Step 5

Keep updating

Maximum Distance

↓

Step 6

Return Maximum Distance.

====================================================================================================
ALGORITHM
====================================================================================================

Sort Mice

↓

Sort Holes

↓

For every i

Compute

abs(mice[i]-holes[i])

↓

Take Maximum

↓

Return Answer

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Function Used

assignHole()

--------------------------------------------

Sort both arrays.

--------------------------------------------

Initialize

min_time = 0

--------------------------------------------

Traverse both arrays together.

--------------------------------------------

Update

min_time = max(min_time,
               abs(mice[i]-holes[i]))

--------------------------------------------

Return min_time.

====================================================================================================
GREEDY CHOICE
====================================================================================================

Always pair

Smallest Mouse

with

Smallest Hole.

Likewise,

Largest Mouse

with

Largest Hole.

This minimizes the worst-case travel time.

====================================================================================================
DRY RUN
====================================================================================================

Mice

[-4,2,4]

Holes

[0,4,5]

After Sorting

Mice

[-4,2,4]

Holes

[0,4,5]

Distances

|-4-0| = 4

|2-4| = 2

|4-5| = 1

Maximum

= 4

Answer = 4

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

Ignoring sorting space.

====================================================================================================
EDGE CASES
====================================================================================================

✓ One mouse

✓ Already matched positions

✓ Negative coordinates

✓ Large coordinates

✓ Same positions

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why do we sort both arrays?

Sorting ensures the closest possible matching
without unnecessary crossings.

--------------------------------------------

Q2.

Why take the maximum distance?

Because the answer asks for

the last mouse

to reach its assigned hole.

--------------------------------------------

Q3.

Can we pair randomly?

No.

Random pairing may increase
the maximum travel time.

====================================================================================================
APPLICATIONS
====================================================================================================

• Resource Allocation

• Task Assignment

• Worker-Job Matching

• Scheduling Problems

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Greedy Matching Problem.

✓ Sort both arrays.

✓ Pair corresponding elements.

✓ Track maximum absolute difference.

✓ No recursion or dynamic programming.

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Activity Selection

• Job Sequencing

• Fractional Knapsack

• Shop in Candy Store

• Minimum Number of Coins

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Sorting is the key observation.

✓ Pair ith mouse with ith hole.

✓ Answer is the maximum travel distance.

✓ Greedy gives the optimal solution.

✓ Very common interview problem.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int assignHole(vector<int>& mices, vector<int>& holes) {

        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int min_time = 0;

        for (int i = 0; i < mices.size(); i++) {
            min_time = max(min_time, abs(mices[i] - holes[i]));
        }

        return min_time;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter number of mice and holes: ";
    cin >> n;

    vector<int> mices(n), holes(n);

    cout << "Enter mice positions: ";
    for (int i = 0; i < n; i++)
        cin >> mices[i];

    cout << "Enter hole positions: ";
    for (int i = 0; i < n; i++)
        cin >> holes[i];

    cout << "\nMinimum Time Required = "
         << obj.assignHole(mices, holes) << endl;

    return 0;
}

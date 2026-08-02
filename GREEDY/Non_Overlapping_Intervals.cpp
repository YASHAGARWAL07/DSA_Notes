/*
====================================================================================================
                         NON-OVERLAPPING INTERVALS (GREEDY ALGORITHM)
====================================================================================================

PROBLEM:
LeetCode 435 - Non-Overlapping Intervals

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given an array of intervals where

interval[i] = [starti, endi],

return the minimum number of intervals

that must be removed

so that the remaining intervals

become non-overlapping.

Intervals touching at endpoints

are considered non-overlapping.

====================================================================================================
PREREQUISITES
====================================================================================================

• Arrays

• Sorting

• Greedy Algorithm

• Intervals

====================================================================================================
INTUITION
====================================================================================================

Instead of deciding

which interval to remove,

think about

which interval should be kept.

Always keep the interval

that finishes earliest.

Because

it leaves maximum space

for future intervals.

Every overlapping interval

must be removed.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Keeping the interval

with the smallest ending time

gives the highest chance

to accommodate future intervals.

Any interval ending later

can only increase future overlaps.

Hence,

sorting by ending time

always produces the optimal answer.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Sort all intervals

according to ending time.

↓

Step 2

Initialize

end = -∞

↓

Step 3

Traverse every interval.

↓

Step 4

If

Current Start >= end

Keep this interval.

Update

end = Current End

↓

Else

Overlap found.

Remove current interval.

Increase answer.

====================================================================================================
ALGORITHM
====================================================================================================

Sort by End Time

↓

Traverse Intervals

↓

Overlap?

↓

NO

Keep Interval

↓

Update End

↓

YES

Remove Interval

↓

Continue

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Functions Used

comp()

Sorts intervals

according to

ending time.

--------------------------------------------

eraseOverlapIntervals()

Sorts intervals.

Traverses every interval.

Counts

how many intervals

must be removed.

====================================================================================================
GREEDY CHOICE
====================================================================================================

Always keep

the interval

having the earliest ending time.

Remove

every interval

that overlaps with it.

====================================================================================================
DRY RUN
====================================================================================================

Intervals

[1,2]

[2,3]

[3,4]

[1,3]

Sorted

↓

[1,2]

[2,3]

[1,3]

[3,4]

Keep

[1,2]

End = 2

↓

Keep

[2,3]

End = 3

↓

[1,3]

Overlaps

Remove++

↓

Keep

[3,4]

Answer = 1

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

✓ Single interval

✓ Already non-overlapping

✓ All intervals overlap

✓ Same ending times

✓ Touching intervals

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why sort according to ending time?

Because it leaves

maximum room

for future intervals.

--------------------------------------------

Q2.

Why not sort according to starting time?

Sorting by starting time

cannot guarantee

minimum removals.

--------------------------------------------

Q3.

Why count removals

instead of selected intervals?

Because the problem

directly asks

minimum intervals

to remove.

====================================================================================================
APPLICATIONS
====================================================================================================

• Meeting Scheduling

• Calendar Management

• Resource Allocation

• CPU Scheduling

• Event Planning

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Interval Greedy Problem.

✓ Sort by ending time.

✓ Keep earliest finishing interval.

✓ Remove overlapping intervals.

✓ Similar to Activity Selection.

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Activity Selection

• Meeting Rooms

• Merge Intervals

• Insert Interval

• Minimum Number of Arrows

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Earliest ending interval is always optimal.

✓ Sorting is the key observation.

✓ Greedy ensures minimum removals.

✓ Overlap occurs when

Current Start < Previous End.

✓ One of the most important Interval Greedy problems.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), comp);

        int end = INT_MIN;
        int remove = 0;

        for(int i = 0; i < intervals.size(); i++)
        {
            if(end <= intervals[i][0])
                end = intervals[i][1];
            else
                remove++;
        }

        return remove;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):\n";
    for(int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    cout << "\nMinimum Intervals to Remove = "
         << obj.eraseOverlapIntervals(intervals)
         << endl;

    return 0;
}

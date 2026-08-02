/*
====================================================================================================
                                  ACTIVITY SELECTION PROBLEM
====================================================================================================

PROBLEM:
GeeksforGeeks - Activity Selection

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given two arrays

start[]

finish[]

where

start[i] = starting time of ith activity

finish[i] = ending time of ith activity

A person can perform only one activity at a time.

Two activities cannot overlap.

Find the maximum number of activities that can be performed.

====================================================================================================
PREREQUISITES
====================================================================================================

• Sorting
• Greedy Algorithm
• Pair STL

====================================================================================================
INTUITION
====================================================================================================

Suppose we have many activities.

If we always perform the activity that finishes earliest,

then

maximum remaining time is available

for future activities.

This leaves the maximum possible space

for upcoming activities.

Therefore,

always choose

the activity with the smallest finishing time.

This is the Greedy Choice.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Earliest finishing activity

↓

Leaves maximum free time

↓

Allows more activities later

↓

Maximum answer.

Choosing an activity that finishes later

may block several future activities.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Store every activity as

(start, finish)

pair.

↓

Step 2

Sort according to

finish time.

↓

Step 3

Select first activity.

↓

Step 4

Traverse remaining activities.

↓

If

currentStart > previousFinish

Choose it.

Else

Skip it.

====================================================================================================
ALGORITHM
====================================================================================================

Create Pair Array

↓

Sort by Finish Time

↓

Take First Activity

↓

For every remaining activity

↓

Start > Ending ?

↓

YES

Take Activity

Update Ending Time

↓

NO

Ignore

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Functions Used

comp()

Comparator

Sorts activities according to finishing time.

--------------------------------------------

activitySelection()

Creates pair vector

↓

Sorts activities

↓

Traverses once

↓

Returns maximum count.

====================================================================================================
YOUR GREEDY CHOICE
====================================================================================================

Your comparator

return a.second < b.second;

means

Sort according to finish time.

After sorting,

the activity finishing earliest

always comes first.

This is the core Greedy strategy.

====================================================================================================
DRY RUN
====================================================================================================

Start

1 3 0 5 8 5

Finish

2 4 6 7 9 9

After Sorting

(1,2)

(3,4)

(0,6)

(5,7)

(8,9)

(5,9)

Take

(1,2)

Ending = 2

↓

(3,4)

3 > 2

Take

Ending = 4

↓

(0,6)

0 <= 4

Skip

↓

(5,7)

5 > 4

Take

Ending = 7

↓

(8,9)

8 > 7

Take

Answer = 4

====================================================================================================
/*
====================================================================================================
TIME COMPLEXITY
====================================================================================================

Sorting

O(N log N)

Traversing all activities

O(N)

Overall

O(N log N)

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

Vector of pairs

O(N)

Ignoring output vector,

Auxiliary Space

O(N)

====================================================================================================
EDGE CASES
====================================================================================================

✓ Only one activity

Answer = 1

----------------------------------------

✓ All activities overlap

Answer = 1

----------------------------------------

✓ No activities overlap

Answer = Total number of activities

----------------------------------------

✓ Activities already sorted

Still works correctly.

====================================================================================================
CORRECTNESS OF GREEDY APPROACH
====================================================================================================

Greedy Choice

Always choose the activity

that finishes earliest.

Why?

Because it leaves the maximum remaining time

for future activities.

Choosing an activity with a later finishing time

can reduce the number of activities

that can be selected later.

Hence,

sorting by finishing time

always gives the maximum number of non-overlapping activities.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why do we sort according to finishing time?

Because finishing earlier leaves more time
for future activities.

--------------------------------------------

Q2.

Can we sort according to starting time?

No.

Sorting by starting time
does not always give the optimal answer.

--------------------------------------------

Q3.

Why is this a Greedy problem?

Because every step makes the locally optimal choice

(earliest finishing activity)

hoping to obtain the globally optimal answer.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Greedy Algorithm.

✓ Always sort by finishing time.

✓ First activity is always selected.

✓ Compare

Current Start > Previous Finish

✓ Works for maximizing the number of activities.

====================================================================================================
APPLICATIONS
====================================================================================================

• CPU Scheduling

• Event Scheduling

• Meeting Room Allocation

• Interview Scheduling

• Resource Allocation

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Job Sequencing Problem

• Fractional Knapsack

• Minimum Platforms

• Non-overlapping Intervals

• Merge Intervals

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Sort activities by finishing time.

✓ Always pick the earliest finishing activity.

✓ Update the last selected finishing time.

✓ Ignore overlapping activities.

✓ One of the most important Greedy Algorithms.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================

(Place your own implementation below this comment and add a main() function
for local testing.)

====================================================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second < b.second;
}

class Solution {
public:

    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        vector<pair<int,int>> timer;

        for(int i = 0; i < start.size(); i++)
            timer.push_back({start[i], finish[i]});

        sort(timer.begin(), timer.end(), comp);

        int total = 0;
        int ending = -1;

        for(int i = 0; i < timer.size(); i++)
        {
            if(timer[i].first > ending)
            {
                total++;
                ending = timer[i].second;
            }
        }

        return total;
    }
};

int main()
{
    Solution obj;

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    cout << "Maximum Activities = "
         << obj.activitySelection(start, finish) << endl;

    return 0;
}

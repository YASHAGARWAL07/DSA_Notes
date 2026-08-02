/*
====================================================================================================
                                  INSERT INTERVAL
====================================================================================================

PROBLEM:
LeetCode 57 - Insert Interval

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

You are given a list of non-overlapping intervals sorted according to their
starting time.

Each interval is represented as

[start, end]

You are also given another interval

newInterval = [start, end]

Insert the new interval into the existing intervals such that

• Intervals remain sorted.

• No two intervals overlap.

Merge overlapping intervals whenever necessary.

Return the final list of intervals.

====================================================================================================
PREREQUISITES
====================================================================================================

• Arrays

• Intervals

• Greedy Thinking

• Merging Intervals

====================================================================================================
INTUITION
====================================================================================================

There are only three possibilities.

Case 1

Current interval lies completely before
the new interval.

No overlap.

Simply copy it.

--------------------------------------------

Case 2

Current interval overlaps with
the new interval.

Merge both intervals.

--------------------------------------------

Case 3

Current interval lies completely after
the merged interval.

Simply append remaining intervals.

Instead of checking every possible condition,

we divide the problem into these three phases.

====================================================================================================
APPROACH
====================================================================================================

Phase 1

Copy every interval

whose ending time is smaller than

newInterval.start

↓

These intervals never overlap.

--------------------------------------------

Phase 2

Merge all overlapping intervals.

Update

Start = minimum start

End = maximum end

Continue until overlap ends.

--------------------------------------------

Phase 3

Insert the merged interval.

Then append every remaining interval.

====================================================================================================
ALGORITHM
====================================================================================================

Copy Left Intervals

↓

Overlap Exists?

↓

YES

Merge

↓

Update

newInterval

↓

Continue

↓

Insert merged interval

↓

Copy Remaining Intervals

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Variables

ans

Stores final answer.

--------------------------------------------

i

Traverses intervals.

--------------------------------------------

n

Number of intervals.

--------------------------------------------

newInterval

Continuously updated after merging.

====================================================================================================
WORKING OF YOUR CODE
====================================================================================================

Step 1

Copy all intervals

whose

newInterval.start

>

current interval end

--------------------------------------------

while(i<n && newInterval[0]>intervals[i][1])

Copy interval.

--------------------------------------------

Step 2

If every interval gets copied,

simply insert newInterval.

--------------------------------------------

if(i==n)

Push newInterval

Return answer.

--------------------------------------------

Step 3

Merge every overlapping interval.

Condition

newInterval.end >= intervals[i].start

Update

newInterval.start

=

minimum start

Update

newInterval.end

=

maximum end

Continue.

--------------------------------------------

Step 4

Push merged interval.

--------------------------------------------

Step 5

Copy remaining intervals.

====================================================================================================
DRY RUN
====================================================================================================

Intervals

[1,2]

[3,5]

[6,7]

[8,10]

[12,16]

Insert

[4,8]

--------------------------------------------

Phase 1

Copy

[1,2]

--------------------------------------------

Phase 2

Merge

[4,8]

with

[3,5]

↓

[3,8]

Merge

[3,8]

with

[6,7]

↓

[3,8]

Merge

[3,8]

with

[8,10]

↓

[3,10]

--------------------------------------------

Push

[3,10]

--------------------------------------------

Copy

[12,16]

Final Answer

[1,2]

[3,10]

[12,16]

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Intervals are already sorted.

Once an interval no longer overlaps,

no future interval can overlap with previous ones.

Therefore,

we process intervals exactly once.

No backtracking is required.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

O(N)

Each interval is visited only once.

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

O(N)

Answer vector stores final intervals.

====================================================================================================
EDGE CASES
====================================================================================================

✓ Empty interval list.

✓ Insert at beginning.

✓ Insert at end.

✓ No overlap.

✓ Overlap with one interval.

✓ Overlap with multiple intervals.

✓ New interval covers every interval.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why does this work in O(N)?

Because every interval is processed only once.

--------------------------------------------

Q2.

Why don't we sort?

Intervals are already sorted according to
their starting time.

--------------------------------------------

Q3.

Why merge using

min()

and

max()?

To expand the merged interval so that
it contains every overlapping interval.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Interval Problem.

✓ Uses Greedy Thinking.

✓ Three Phase Solution.

✓ No Nested Loops.

✓ Linear Time Complexity.

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Merge Intervals

• Non-overlapping Intervals

• Meeting Rooms

• Minimum Platforms

• Employee Free Time

• Interval List Intersections

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Divide the problem into

Copy

Merge

Copy

✓ Merge overlapping intervals immediately.

✓ Intervals remain sorted.

✓ Only one traversal is needed.

✓ One of the most frequently asked interval problems.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;

        int i = 0;
        int n = intervals.size();

        // Copy all non-overlapping intervals before newInterval
        while (i < n && newInterval[0] > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // If newInterval comes after all intervals
        if (i == n) {
            ans.push_back(newInterval);
            return ans;
        }

        // Merge overlapping intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        // Copy remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);

    cout << "Enter new interval: ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans = obj.insert(intervals, newInterval);

    cout << "\nIntervals after insertion:\n";

    for (auto &interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}
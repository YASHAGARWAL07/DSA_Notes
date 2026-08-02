/*
====================================================================================================
                           SINGLE THREADED CPU (PRIORITY QUEUE + GREEDY)
====================================================================================================

PROBLEM:
LeetCode 1834 - Single-Threaded CPU

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

A CPU can execute only one task at a time.

Each task has

• Enqueue Time
• Processing Time

If multiple tasks are available,

the CPU always chooses

1. Smallest Processing Time

2. If processing time is same,
   choose the smallest index.

Return the order in which tasks are processed.

====================================================================================================
PREREQUISITES
====================================================================================================

• Sorting

• Priority Queue (Min Heap)

• Greedy Algorithm

• Simulation

====================================================================================================
INTUITION
====================================================================================================

Tasks become available at different times.

So,

first sort all tasks according to

Enqueue Time.

As time progresses,

insert every available task into a

Min Heap.

The heap always keeps

the task having

minimum processing time

at the top.

If two tasks have the same processing time,

smaller index gets priority.

====================================================================================================
WHY GREEDY WORKS
====================================================================================================

Whenever CPU becomes free,

the best decision is

to execute the task

having the

minimum processing time.

This minimizes waiting time

while satisfying the problem constraints.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Append original index with every task.

↓

Step 2

Sort all tasks by

Enqueue Time.

↓

Step 3

Maintain a timer.

↓

Step 4

Insert every task whose

Enqueue Time <= timer

into a Min Heap.

↓

Step 5

If heap is empty,

jump timer to next task's enqueue time.

↓

Step 6

Otherwise,

remove the smallest processing-time task.

↓

Step 7

Update timer

and store its index.

↓

Repeat until

all tasks are processed.

====================================================================================================
ALGORITHM
====================================================================================================

Sort Tasks

↓

Timer

↓

Push Available Tasks

↓

Min Heap

↓

Pop Best Task

↓

Update Timer

↓

Store Answer

↓

Repeat

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Variables Used

tasks

Stores

{enqueueTime,
 processingTime,
 index}

--------------------------------------------

timer

Current CPU time.

--------------------------------------------

priority_queue

Stores

{processingTime,
 index}

using Min Heap.

--------------------------------------------

ans

Stores processing order.

--------------------------------------------

i

Traverses sorted tasks.

====================================================================================================
GREEDY CHOICE
====================================================================================================

Whenever CPU is free,

execute the task

having the smallest processing time.

If multiple tasks have equal processing time,

choose smaller index.

====================================================================================================
DRY RUN
====================================================================================================

Tasks

[[1,2],[2,4],[3,2],[4,1]]

Sorted by Enqueue Time

↓

Time = 1

Available

Task 0

Execute

Task 0

Time = 3

--------------------------------------------

Available

Task 1

Task 2

Choose Task 2

(smaller processing time)

Time = 5

--------------------------------------------

Available

Task 3

Task 1

Choose Task 3

Time = 6

--------------------------------------------

Execute

Task 1

Answer

0 2 3 1

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Sorting

O(N log N)

Every task is inserted once

O(N log N)

Every task is removed once

O(N log N)

Overall

O(N log N)

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

Priority Queue

O(N)

Answer Array

O(N)

Overall

O(N)

====================================================================================================
EDGE CASES
====================================================================================================

✓ CPU remains idle.

✓ Multiple tasks arrive together.

✓ Same processing time.

✓ Single task.

✓ Large enqueue times.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why do we sort by enqueue time?

Because tasks become available
at different moments.

--------------------------------------------

Q2.

Why use a Min Heap?

To efficiently obtain

the task having

minimum processing time.

--------------------------------------------

Q3.

Why store original indices?

Because the answer requires

the original order of tasks.

====================================================================================================
APPLICATIONS
====================================================================================================

• CPU Scheduling

• Operating Systems

• Job Scheduling

• Task Management

• Cloud Computing

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Combination of Greedy + Heap.

✓ Sort according to arrival time.

✓ Heap stores available tasks only.

✓ Idle CPU jumps to next arrival time.

✓ Original indices must be preserved.

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Task Scheduler

• Meeting Rooms

• Job Sequencing

• Activity Selection

• Process Scheduling

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Sort tasks by enqueue time.

✓ Push available tasks into Min Heap.

✓ Execute minimum processing time task.

✓ Maintain current timer.

✓ Heap makes scheduling efficient.

✓ Classic Priority Queue interview problem.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // Put the task index along with each task
        for(int i = 0; i < n; i++)
            tasks[i].push_back(i);

        vector<int> ans;

        // Sort the tasks on the basis of enqueue time
        sort(tasks.begin(), tasks.end());

        long long timer = tasks[0][0];
        int i = 0;

        // Min Heap {processing time, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        while(!pq.empty() || i < n)
        {
            // Put all tasks whose enqueue time <= timer
            while(i < n && timer >= tasks[i][0])
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // CPU is idle
            if(pq.empty())
            {
                timer = tasks[i][0];
            }
            else
            {
                ans.push_back(pq.top().second);
                timer += pq.top().first;
                pq.pop();
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<vector<int>> tasks(n, vector<int>(2));

    cout << "Enter Enqueue Time and Processing Time:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> tasks[i][0] >> tasks[i][1];
    }

    vector<int> ans = obj.getOrder(tasks);

    cout << "\nProcessing Order:\n";
    for(int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}

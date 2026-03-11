/*
============================================================
LEETCODE 2073 : TIME NEEDED TO BUY TICKETS
QUEUE SIMULATION
============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

There are n people standing in a queue.

Each person wants to buy a certain number
of tickets.

tickets[i] = number of tickets person i wants.

Rules:

• Each second a person at the front buys
  exactly ONE ticket.

• If they still need tickets,
  they go to the end of the queue.

• If they bought all tickets,
  they leave the queue.

Goal:

Return the time required for the person
at index k to finish buying tickets.
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We simulate the real queue process.

1. Store indices of people in queue.

2. The front person buys one ticket.

3. If they still need tickets,
   they go back to the end.

4. Stop when person k finishes buying tickets.
*/


class Solution {
public:

    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        queue<int> q;

        int n = tickets.size();

        // push all people indices
        for(int i = 0; i < n; i++)
            q.push(i);

        int time = 0;

        while(tickets[k] != 0)
        {

            // front person buys ticket
            tickets[q.front()]--;
            time++;

            // if person still needs tickets
            if(tickets[q.front()] > 0)
                q.push(q.front());

            // remove from front
            q.pop();
        }

        return time;
    }
};


/*
------------------------------------------------------------
3. DRY RUN
------------------------------------------------------------

tickets = [2,3,2]
k = 2

Queue = [0,1,2]

Step 1
person 0 buys ticket
tickets = [1,3,2]
queue = [1,2,0]

Step 2
person 1 buys ticket
tickets = [1,2,2]
queue = [2,0,1]

Step 3
person 2 buys ticket
tickets = [1,2,1]
queue = [0,1,2]

Continue until tickets[2] = 0

Total time = 6
*/


/*
------------------------------------------------------------
4. TIME COMPLEXITY
------------------------------------------------------------

Worst case:

Each ticket purchase takes 1 operation.

Total operations = total tickets

Time Complexity:

O(sum of tickets)
*/


/*
------------------------------------------------------------
5. SPACE COMPLEXITY
------------------------------------------------------------

Queue stores n indices

Space Complexity:

O(n)
*/


/*
------------------------------------------------------------
6. IMPORTANT OBSERVATION (OPTIMIZED IDEA)
------------------------------------------------------------

Instead of simulation,
we can directly compute:

For every person i:

If i <= k:
   contribute min(tickets[i], tickets[k])

If i > k:
   contribute min(tickets[i], tickets[k] - 1)

Total time = sum of contributions

This reduces space complexity to O(1).
*/


/*
============================================================
END OF FILE
============================================================
*/
/*
============================================================
QUEUE REVERSAL
(REVERSE A QUEUE USING STACK)
============================================================
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a queue containing integers,
reverse the order of elements.

Example:

Input Queue:
Front -> 5 10 15 20 25 -> Rear

Output Queue:
Front -> 25 20 15 10 5 -> Rear
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

Queue follows FIFO
First In First Out

Stack follows LIFO
Last In First Out

If we move all queue elements
into a stack, the order reverses.

Then pushing them back to queue
gives the reversed queue.
*/


/*
------------------------------------------------------------
3. ALGORITHM
------------------------------------------------------------

Step 1:
Create a stack

Step 2:
Remove elements from queue
and push them into stack

Step 3:
Pop elements from stack
and push them back into queue

Queue becomes reversed
*/


class Solution {
public:

    void reverseQueue(queue<int> &q)
    {
        stack<int> st;

        // Move queue elements to stack
        while(!q.empty())
        {
            st.push(q.front());
            q.pop();
        }

        // Move stack elements back to queue
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
    }
};


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

Queue:

Front -> 1 2 3 4 5 -> Rear


STEP 1
Move to stack

Stack:
Top -> 5 4 3 2 1


STEP 2
Push back to queue

Queue:
Front -> 5 4 3 2 1 -> Rear
*/


/*
------------------------------------------------------------
5. TIME COMPLEXITY
------------------------------------------------------------

Let n = number of elements

Moving to stack → O(n)
Moving back → O(n)

Total:

O(n)
*/


/*
------------------------------------------------------------
6. SPACE COMPLEXITY
------------------------------------------------------------

Stack stores n elements

Space Complexity:

O(n)
*/


/*
------------------------------------------------------------
7. INTERVIEW FOLLOW UPS
------------------------------------------------------------

1. Reverse queue using recursion

2. Reverse first K elements of queue

3. Implement queue using stack

4. Implement stack using queue
*/


/*
------------------------------------------------------------
8. REVERSE QUEUE USING RECURSION (BONUS)
------------------------------------------------------------
*/

void reverseQueueRec(queue<int> &q)
{
    if(q.empty())
        return;

    int x = q.front();
    q.pop();

    reverseQueueRec(q);

    q.push(x);
}


/*
============================================================
END OF FILE
============================================================
*/
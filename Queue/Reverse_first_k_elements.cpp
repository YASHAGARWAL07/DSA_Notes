/*
============================================================
REVERSE FIRST K ELEMENTS OF A QUEUE
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

Given a queue and an integer k,
reverse the order of the first k elements
of the queue while keeping the remaining
elements in the same relative order.

Example:

Input:
Queue = [1,2,3,4,5]
k = 3

Output:
[3,2,1,4,5]
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We only need to reverse the first k elements.

Steps:

1. Push first k elements into stack
   (this reverses their order)

2. Push stack elements back into queue

3. Move remaining (n-k) elements
   from front to back to maintain order
*/


class Solution {
public:

    queue<int> reverseFirstK(queue<int> q, int k)
    {

        if(k > q.size())
            return q;

        stack<int> st;

        // Step 1: Push first k elements into stack
        for(int i = 0; i < k; i++)
        {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back into queue
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        int n = q.size();

        // Step 3: Move remaining elements to back
        for(int i = 0; i < n - k; i++)
        {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};


/*
------------------------------------------------------------
3. DRY RUN
------------------------------------------------------------

Queue = [1,2,3,4,5]
k = 3


Step 1: Push first k elements to stack

Stack:
Top -> 3 2 1


Remaining Queue:
[4,5]


Step 2: Push stack elements back

Queue:
[4,5,3,2,1]


Step 3: Rotate remaining elements

Queue:
[3,2,1,4,5]
*/


/*
------------------------------------------------------------
4. TIME COMPLEXITY
------------------------------------------------------------

Push k elements → O(k)
Push back → O(k)
Rotate queue → O(n-k)

Total:

O(n)
*/


/*
------------------------------------------------------------
5. SPACE COMPLEXITY
------------------------------------------------------------

Stack stores k elements

Space Complexity:

O(k)
*/


/*
------------------------------------------------------------
6. EDGE CASES
------------------------------------------------------------

1. k = 0 → queue remains same
2. k = queue size → whole queue reversed
3. k > queue size → return original queue
*/


/*
------------------------------------------------------------
7. INTERVIEW FOLLOW UPS
------------------------------------------------------------

1. Reverse entire queue
2. Reverse first k elements using recursion
3. Interleave first half of queue
4. Implement queue using stacks
*/


/*
============================================================
END OF FILE
============================================================
*/
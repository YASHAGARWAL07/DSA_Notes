/*
============================================================
STACK IMPLEMENTATION USING TWO QUEUES
(QUEUE SIMULATION OF STACK)
============================================================
*/

#include <iostream>
#include <queue>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Implement a Stack using only Queue operations.

Stack follows:

LIFO → Last In First Out

Queue follows:

FIFO → First In First Out

Allowed queue operations:

push(x)
pop()
front()
size()
empty()
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

Stack removes the LAST inserted element.

Queue removes the FIRST inserted element.

To simulate stack behavior,
we transfer elements between two queues
so that the last element remains at front
before popping.
*/


class MyStack {
public:

    queue<int> q1;
    queue<int> q2;


    MyStack() {}


/*
------------------------------------------------------------
3. CHECK EMPTY
------------------------------------------------------------
*/

    bool empty()
    {
        return q1.empty() && q2.empty();
    }


/*
------------------------------------------------------------
4. PUSH OPERATION
------------------------------------------------------------

Insert element into non-empty queue.

If both empty → push into q1.
*/

    void push(int x)
    {
        if(empty())
            q1.push(x);

        else if(q1.empty())
            q2.push(x);

        else
            q1.push(x);
    }


/*
------------------------------------------------------------
5. POP OPERATION
------------------------------------------------------------

Goal:
Remove last inserted element.

Steps:

1. Move all elements except last
   to the other queue.

2. Remove last element.
*/

    int pop()
    {
        if(empty())
            return 0;

        // Case 1: q1 empty
        if(q1.empty())
        {
            while(q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }

            int element = q2.front();
            q2.pop();
            return element;
        }

        // Case 2: q2 empty
        else
        {
            while(q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            int element = q1.front();
            q1.pop();
            return element;
        }
    }


/*
------------------------------------------------------------
6. TOP OPERATION
------------------------------------------------------------

Return last inserted element.

Queue back() gives latest element.
*/

    int top()
    {
        if(empty())
            return 0;

        if(q1.empty())
            return q2.back();
        else
            return q1.back();
    }

};


/*
------------------------------------------------------------
7. DRY RUN
------------------------------------------------------------

push(1)
q1 = [1]

push(2)
q1 = [1,2]

push(3)
q1 = [1,2,3]

pop()

Move:
1,2 → q2

Remove:
3

Result:
Stack = [1,2]
*/


/*
------------------------------------------------------------
8. TIME COMPLEXITY
------------------------------------------------------------

push()  → O(1)

pop()   → O(n)
(transfer elements)

top()   → O(1)

empty() → O(1)
*/


/*
------------------------------------------------------------
9. SPACE COMPLEXITY
------------------------------------------------------------

Queues store n elements.

Space Complexity:

O(n)
*/


/*
------------------------------------------------------------
10. INTERVIEW FOLLOW UPS
------------------------------------------------------------

1. Stack using one queue
2. Queue using two stacks
3. Min Stack
4. Implement stack using array
*/


/*
============================================================
END OF FILE
============================================================
*/
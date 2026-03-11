/*
============================================================
QUEUE IMPLEMENTATION USING TWO STACKS
============================================================
*/

#include <iostream>
#include <stack>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Implement a Queue using Stack operations.

Queue follows:

FIFO → First In First Out

Stack follows:

LIFO → Last In First Out

Allowed stack operations:

push()
pop()
top()
empty()
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We use TWO stacks:

s1 → used for insertion
s2 → used for deletion

Idea:

Newest elements go into s1.

When we need to remove element
from queue front, we move all
elements from s1 → s2.

This reverses order so the
oldest element appears on top.
*/


class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {}


/*
------------------------------------------------------------
3. CHECK IF QUEUE IS EMPTY
------------------------------------------------------------
*/

    bool empty()
    {
        return s1.empty() && s2.empty();
    }


/*
------------------------------------------------------------
4. PUSH OPERATION
------------------------------------------------------------

Push element into s1.

Time Complexity → O(1)
*/

    void push(int x)
    {
        s1.push(x);
    }


/*
------------------------------------------------------------
5. POP OPERATION
------------------------------------------------------------

Case 1:
If s2 has elements → pop from s2

Case 2:
If s2 empty → transfer elements
from s1 to s2 then pop

Time Complexity:

Worst case → O(n)
Amortized → O(1)
*/

    int pop()
    {
        if(empty())
            return 0;

        if(!s2.empty())
        {
            int element = s2.top();
            s2.pop();
            return element;
        }

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        int element = s2.top();
        s2.pop();

        return element;
    }


/*
------------------------------------------------------------
6. PEEK OPERATION
------------------------------------------------------------

Return front element of queue.

Logic same as pop
but without removing element.
*/

    int peek()
    {
        if(empty())
            return 0;

        if(!s2.empty())
            return s2.top();

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
};


/*
------------------------------------------------------------
7. DRY RUN
------------------------------------------------------------

push(1)
s1 = [1]

push(2)
s1 = [1,2]

push(3)
s1 = [1,2,3]


pop()

Move s1 → s2

s2 = [3,2,1]

pop → 1

Queue now:
[2,3]
*/


/*
------------------------------------------------------------
8. TIME COMPLEXITY
------------------------------------------------------------

push() → O(1)

pop() → O(1) amortized
       O(n) worst case

peek() → O(1) amortized
        O(n) worst case

empty() → O(1)
*/


/*
------------------------------------------------------------
9. SPACE COMPLEXITY
------------------------------------------------------------

Two stacks store n elements.

Space Complexity:

O(n)
*/


/*
------------------------------------------------------------
10. IMPORTANT INTERVIEW POINT
------------------------------------------------------------

Although pop() can be O(n),
each element moves between
stacks only once.

Therefore amortized complexity
remains O(1).
*/


/*
============================================================
END OF FILE
============================================================
*/

/*
============================================================
DEQUE (DOUBLE ENDED QUEUE)
============================================================
*/

#include <iostream>
#include <deque>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION
------------------------------------------------------------

Deque stands for:

Double Ended Queue

It is a data structure where insertion
and deletion can happen from BOTH ends.

Front  ←→  Rear

Unlike queue:
Insertion and deletion only from one side.

Deque allows operations at both ends.
*/


/*
------------------------------------------------------------
2. TYPES OF DEQUE
------------------------------------------------------------

1) Input Restricted Deque

Insertion → only at rear
Deletion  → both ends


2) Output Restricted Deque

Insertion → both ends
Deletion  → only from front
*/


/*
------------------------------------------------------------
3. BASIC OPERATIONS
------------------------------------------------------------

push_front(x)
push_back(x)

pop_front()
pop_back()

front()
back()

empty()
size()
*/


/*
------------------------------------------------------------
4. BASIC IMPLEMENTATION USING STL
------------------------------------------------------------
*/

int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque elements:\n";

    for(int x : dq)
        cout << x << " ";

    cout << endl;

    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "After popping from both ends:\n";

    for(int x : dq)
        cout << x << " ";

    return 0;
}


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

push_back(10)
Deque = [10]

push_back(20)
Deque = [10,20]

push_front(5)
Deque = [5,10,20]

push_front(1)
Deque = [1,5,10,20]

pop_front()

Deque = [5,10,20]

pop_back()

Deque = [5,10]
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

push_front() → O(1)
push_back()  → O(1)

pop_front()  → O(1)
pop_back()   → O(1)

front()      → O(1)
back()       → O(1)
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(n)

n = number of elements stored
*/


/*
------------------------------------------------------------
8. IMPORTANT APPLICATIONS
------------------------------------------------------------

1. Sliding Window Maximum

2. Palindrome checking

3. First negative number in window

4. Task scheduling

5. LRU Cache implementation
*/


/*
------------------------------------------------------------
9. DEQUE VS QUEUE
------------------------------------------------------------

Queue:

Front → deletion
Rear  → insertion


Deque:

Front → insertion + deletion
Rear  → insertion + deletion
*/


/*
============================================================
END OF FILE
============================================================
*/

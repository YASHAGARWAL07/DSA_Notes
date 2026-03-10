/*
============================================================
CIRCULAR QUEUE – COMPLETE NOTES
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION
------------------------------------------------------------

Circular Queue is an improved version of a normal queue.

Problem in Linear Queue (Array Queue):

Example:

Index: 0 1 2 3 4

Push:
10 20 30 40 50

Front = 0
Rear  = 4

Now pop 3 elements:

_ _ _ 40 50

Front = 3
Rear  = 4

Even though empty space exists,
we cannot insert new elements.

This is called:

FALSE OVERFLOW


Circular Queue solves this problem.
*/


/*
------------------------------------------------------------
2. IDEA OF CIRCULAR QUEUE
------------------------------------------------------------

Instead of moving in straight line,
rear wraps around.

rear = (rear + 1) % size

Example:

Index: 0 1 2 3 4

After wrap around:

Rear goes back to index 0.
*/


/*
------------------------------------------------------------
3. CONDITIONS
------------------------------------------------------------

QUEUE EMPTY

front == -1


QUEUE FULL

(front == 0 && rear == size-1)
OR
(front == rear + 1)
*/


class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }


/*
------------------------------------------------------------
4. ENQUEUE (PUSH)
------------------------------------------------------------
*/

    void push(int x)
    {

        // Queue Full
        if((front == 0 && rear == size-1) || (front == rear+1))
        {
            cout << "Queue Overflow\n";
            return;
        }

        // First element
        if(front == -1)
        {
            front = rear = 0;
        }

        // Wrap around
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
        }

        // Normal insert
        else
        {
            rear++;
        }

        arr[rear] = x;
    }


/*
------------------------------------------------------------
5. DEQUEUE (POP)
------------------------------------------------------------
*/

    void pop()
    {
        if(front == -1)
        {
            cout << "Queue Underflow\n";
            return;
        }

        // Only one element
        if(front == rear)
        {
            front = rear = -1;
        }

        // Wrap around
        else if(front == size-1)
        {
            front = 0;
        }

        else
        {
            front++;
        }
    }


/*
------------------------------------------------------------
6. GET FRONT ELEMENT
------------------------------------------------------------
*/

    int Front()
    {
        if(front == -1)
            return -1;

        return arr[front];
    }


/*
------------------------------------------------------------
7. PRINT QUEUE
------------------------------------------------------------
*/

    void display()
    {
        if(front == -1)
        {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Queue Elements: ";

        if(rear >= front)
        {
            for(int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else
        {
            for(int i = front; i < size; i++)
                cout << arr[i] << " ";

            for(int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }

        cout << endl;
    }
};


/*
------------------------------------------------------------
8. TIME COMPLEXITY
------------------------------------------------------------

Push     → O(1)
Pop      → O(1)
Front    → O(1)

All operations are constant time.
*/


/*
------------------------------------------------------------
9. SPACE COMPLEXITY
------------------------------------------------------------

O(n)
*/


/*
------------------------------------------------------------
10. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Circular Queue prevents false overflow.

2) Uses modulo arithmetic.

3) rear = (rear + 1) % size

4) Used in:

Operating Systems
CPU Scheduling
Streaming buffers
Networking
*/


/*
------------------------------------------------------------
11. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{

    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    q.pop();
    q.pop();

    q.display();

    q.push(50);
    q.push(60);

    q.display();

    cout << "Front element: " << q.Front() << endl;

    return 0;
}


/*
============================================================
SUMMARY
============================================================

Linear Queue Problem:
False Overflow

Solution:
Circular Queue

Key Formula:
rear = (rear + 1) % size

Advantages:
Efficient memory usage

============================================================
END
============================================================
*/
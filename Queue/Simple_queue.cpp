/*
============================================================
QUEUE DATA STRUCTURE – COMPLETE NOTES
============================================================
*/

#include <iostream>
#include <queue>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION TO QUEUE
------------------------------------------------------------

Queue is a linear data structure that follows:

FIFO Principle
(FIRST IN FIRST OUT)

Meaning:
The element inserted first will be removed first.

Example:

Insert (enqueue):
10 -> 20 -> 30 -> 40

Front = 10
Rear  = 40

Remove (dequeue):
10 will be removed first


Real Life Examples:

1) Ticket booking line
2) CPU scheduling
3) Printer queue
4) BFS traversal in graphs
*/


/*
------------------------------------------------------------
2. BASIC OPERATIONS
------------------------------------------------------------

enqueue(x) → Insert element at rear

dequeue()  → Remove element from front

front()    → Get front element

isEmpty()  → Check if queue is empty

isFull()   → Check if queue is full (array case)

size()     → Number of elements
*/


/*
============================================================
3. QUEUE IMPLEMENTATION USING ARRAY
============================================================

We maintain:

front → first element
rear  → last element

Initial State:

front = -1
rear  = -1

Conditions:

Queue Empty:
front == -1

Queue Full:
rear == size - 1
*/


class QueueArray
{
    int *arr;
    int front;
    int rear;
    int size;

public:

    QueueArray(int n)
    {
        arr = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }


    /*
    ------------------------------------------------------------
    CHECK EMPTY
    ------------------------------------------------------------
    */

    bool isEmpty()
    {
        return front == -1;
    }


    /*
    ------------------------------------------------------------
    CHECK FULL
    ------------------------------------------------------------
    */

    bool isFull()
    {
        return rear == size - 1;
    }


    /*
    ------------------------------------------------------------
    ENQUEUE (PUSH)
    ------------------------------------------------------------
    */

    void push(int x)
    {
        // Queue Empty
        if(isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }

        // Queue Full
        if(isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }

        // Insert element
        rear++;
        arr[rear] = x;
    }


    /*
    ------------------------------------------------------------
    DEQUEUE (POP)
    ------------------------------------------------------------
    */

    void pop()
    {
        if(isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        // Only one element
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }


    /*
    ------------------------------------------------------------
    GET FRONT
    ------------------------------------------------------------
    */

    int Front()
    {
        if(isEmpty())
            return -1;

        return arr[front];
    }
};



/*
============================================================
4. QUEUE IMPLEMENTATION USING LINKED LIST
============================================================

We maintain two pointers:

front → first node
rear  → last node

Insertion → rear
Deletion  → front
*/

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class QueueLL
{
    Node* front;
    Node* rear;

public:

    QueueLL()
    {
        front = rear = NULL;
    }


    void push(int x)
    {
        Node* temp = new Node(x);

        if(front == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }


    void pop()
    {
        if(front == NULL)
        {
            cout << "Queue Empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if(front == NULL)
            rear = NULL;
    }


    int Front()
    {
        if(front == NULL)
            return -1;

        return front->data;
    }
};



/*
============================================================
5. QUEUE USING STL
============================================================

C++ provides built-in queue container.
*/

void STLQueueDemo()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;
}



/*
============================================================
6. TIME COMPLEXITY
============================================================

Operation       Time

Push            O(1)
Pop             O(1)
Front           O(1)
Empty           O(1)

Queue operations are constant time.
*/


/*
============================================================
7. IMPORTANT APPLICATIONS
============================================================

1) Breadth First Search (BFS)

2) CPU Scheduling

3) Producer Consumer Problem

4) Level Order Traversal (Binary Tree)

5) Networking packet queues
*/


/*
============================================================
8. COMMON INTERVIEW QUESTIONS
============================================================

1) Implement Queue using Stack

2) Implement Stack using Queue

3) Circular Queue

4) Deque (Double ended queue)

5) Sliding Window Maximum
*/


/*
============================================================
9. MAIN FUNCTION
============================================================
*/

int main()
{
    cout << "Queue using Array\n";

    QueueArray q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.Front() << endl;

    q.pop();

    cout << "Front after pop: " << q.Front() << endl;



    cout << "\nQueue using Linked List\n";

    QueueLL q2;

    q2.push(5);
    q2.push(15);
    q2.push(25);

    cout << "Front: " << q2.Front() << endl;

    q2.pop();

    cout << "Front after pop: " << q2.Front() << endl;



    cout << "\nQueue using STL\n";

    STLQueueDemo();


    return 0;
}



/*
============================================================
SUMMARY
============================================================

Queue follows FIFO principle.

Three implementations:

1) Array
2) Linked List
3) STL queue

Queues are widely used in:

Graphs
Trees
Scheduling
Networking

============================================================
END
============================================================
*/
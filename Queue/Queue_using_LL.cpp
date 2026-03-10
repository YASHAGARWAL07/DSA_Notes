/*
============================================================
QUEUE USING LINKED LIST
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION
------------------------------------------------------------

Queue follows FIFO principle:

First In First Out

Example:

Push: 10 20 30

Queue:
Front -> 10 -> 20 -> 30 -> NULL
Rear  -> 30

Pop operation removes from FRONT.


OPERATIONS:

1. Push (Enqueue)
2. Pop (Dequeue)
3. Peek / Start
4. IsEmpty
*/


/*
------------------------------------------------------------
2. NODE STRUCTURE
------------------------------------------------------------
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


/*
------------------------------------------------------------
3. QUEUE CLASS
------------------------------------------------------------

Queue using Linked List maintains:

front → first element
rear  → last element

Insertion happens at rear
Deletion happens at front
*/

class Queue
{
    Node* front;
    Node* rear;

public:

    Queue()
    {
        front = rear = NULL;
    }


/*
------------------------------------------------------------
4. CHECK IF QUEUE IS EMPTY
------------------------------------------------------------
*/

    bool IsEmpty()
    {
        return front == NULL;
    }


/*
------------------------------------------------------------
5. PUSH / ENQUEUE
------------------------------------------------------------

Insert element at REAR.

Case 1: Queue empty
Case 2: Queue already has elements

Time Complexity: O(1)
*/

    void push(int x)
    {
        Node* temp = new Node(x);

        // Queue empty
        if(IsEmpty())
        {
            front = rear = temp;
            return;
        }

        // Insert at rear
        rear->next = temp;
        rear = temp;
    }


/*
------------------------------------------------------------
6. POP / DEQUEUE
------------------------------------------------------------

Remove element from FRONT.

Time Complexity: O(1)
*/

    void pop()
    {
        if(IsEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        delete temp;

        // If queue becomes empty
        if(front == NULL)
            rear = NULL;
    }


/*
------------------------------------------------------------
7. GET FRONT ELEMENT
------------------------------------------------------------
*/

    int start()
    {
        if(IsEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }


/*
------------------------------------------------------------
8. DISPLAY QUEUE
------------------------------------------------------------
*/

    void display()
    {
        if(IsEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        cout << "Queue: ";

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

};


/*
------------------------------------------------------------
9. TIME COMPLEXITY
------------------------------------------------------------

Push      → O(1)
Pop       → O(1)
Peek      → O(1)
IsEmpty   → O(1)

Traversal → O(n)
*/


/*
------------------------------------------------------------
10. SPACE COMPLEXITY
------------------------------------------------------------

O(n)

Memory used for nodes.
*/


/*
------------------------------------------------------------
11. ADVANTAGES OVER ARRAY QUEUE
------------------------------------------------------------

1. No fixed size
2. No overflow until memory exists
3. No false overflow
4. Dynamic memory allocation
*/


/*
------------------------------------------------------------
12. DRY RUN
------------------------------------------------------------

push(10)
Front -> 10
Rear  -> 10

push(20)
Front -> 10 -> 20
Rear  -> 20

push(30)
Front -> 10 -> 20 -> 30
Rear  -> 30

pop()

Front -> 20 -> 30
Rear  -> 30
*/


/*
------------------------------------------------------------
13. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    cout << "Front Element: " << q.start() << endl;

    q.pop();

    q.display();

    q.push(40);
    q.push(50);

    q.display();

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/

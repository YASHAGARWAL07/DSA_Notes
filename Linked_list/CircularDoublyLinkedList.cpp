/*
====================================================
CIRCULAR DOUBLY LINKED LIST
====================================================
*/

#include <iostream>
using namespace std;

/*
----------------------------------------------------
1. INTRODUCTION
----------------------------------------------------

Each node has:
prev & next

Head's prev points to last.
Last's next points to head.

✔ 360° traversal possible
✔ Used in advanced data structures
*/

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

/*
----------------------------------------------------
2. INSERT
----------------------------------------------------
*/

void insert(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;
}

/*
----------------------------------------------------
3. TRAVERSAL
----------------------------------------------------
*/

void printList(Node* head)
{
    if(head == NULL) return;

    Node* temp = head;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while(temp != head);

    cout << "(Back to Head)" << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 5);
    insert(head, 10);
    insert(head, 15);

    printList(head);

    return 0;
}
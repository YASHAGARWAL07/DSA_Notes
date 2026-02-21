/*
====================================================
DOUBLY LINKED LIST
====================================================
*/

#include <iostream>
using namespace std;

/*
----------------------------------------------------
1. INTRODUCTION
----------------------------------------------------

Each node contains:
1) Data
2) Pointer to next
3) Pointer to previous

Structure:
NULL <- [prev|data|next] <-> [prev|data|next] -> NULL

✔ Forward & Backward traversal
✘ Extra memory for prev pointer
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
2. INSERT AT HEAD
----------------------------------------------------
*/

void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head != NULL)
        head->prev = newNode;

    newNode->next = head;
    head = newNode;
}

/*
----------------------------------------------------
3. TRAVERSAL
----------------------------------------------------
*/

void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/*
----------------------------------------------------
4. TIME COMPLEXITY
----------------------------------------------------

Insertion : O(1)
Deletion  : O(1) (if pointer known)
Traversal : O(n)
*/

int main()
{
    Node* head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 5);

    printList(head);

    return 0;
}
/*
====================================================
SINGLY LINKED LIST
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
2) Pointer to next node

Structure:
[data | next] -> [data | next] -> NULL

✔ Dynamic size
✘ No backward traversal
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
----------------------------------------------------
2. INSERTION AT HEAD
----------------------------------------------------
*/

void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

/*
----------------------------------------------------
3. INSERTION AT TAIL
----------------------------------------------------
*/

void insertAtTail(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/*
----------------------------------------------------
4. DELETION
----------------------------------------------------
*/

void deleteHead(Node* &head)
{
    if(head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

/*
----------------------------------------------------
5. TRAVERSAL
----------------------------------------------------
*/

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/*
----------------------------------------------------
6. TIME COMPLEXITY
----------------------------------------------------

Insertion at head : O(1)
Insertion at tail : O(n)
Deletion at head  : O(1)
Traversal         : O(n)
*/

int main()
{
    Node* head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertAtTail(head, 20);

    printList(head);

    return 0;
}
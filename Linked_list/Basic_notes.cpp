/*
====================================================
LINKED LIST (SINGLY LINKED LIST)
====================================================
*/

#include <iostream>
using namespace std;


/*
----------------------------------------------------
1. INTRODUCTION
----------------------------------------------------

Linked List is a linear data structure where
elements are stored in non-contiguous memory.

Each element (Node) contains:
1) Data
2) Pointer to next node

Unlike arrays:
✔ Dynamic size
✔ Efficient insertion/deletion
✘ No random access (no indexing)

Structure:
[data | next] -> [data | next] -> NULL
*/


/*
----------------------------------------------------
2. NODE STRUCTURE
----------------------------------------------------
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
3. BASIC OPERATIONS
----------------------------------------------------

1) Insertion
   - At beginning
   - At end
   - At position

2) Deletion
   - From beginning
   - From end
   - By value

3) Traversal
4) Search
*/


/*
----------------------------------------------------
4. INSERTION OPERATIONS
----------------------------------------------------
*/

// Insert at Head
void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


// Insert at Tail
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
    {
        temp = temp->next;
    }

    temp->next = newNode;
}


// Insert at Position (1-based index)
void insertAtPosition(Node* &head, int val, int pos)
{
    if(pos == 1)
    {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}



/*
----------------------------------------------------
5. DELETION OPERATIONS
----------------------------------------------------
*/

// Delete Head
void deleteHead(Node* &head)
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
}


// Delete by Value
void deleteByValue(Node* &head, int val)
{
    if(head == NULL)
        return;

    if(head->data == val)
    {
        deleteHead(head);
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
        return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}



/*
----------------------------------------------------
6. TRAVERSAL
----------------------------------------------------
*/

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}



/*
----------------------------------------------------
7. SEARCHING
----------------------------------------------------
*/

bool search(Node* head, int key)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
            return true;

        temp = temp->next;
    }

    return false;
}



/*
----------------------------------------------------
8. TIME COMPLEXITY
----------------------------------------------------

Insertion:
- At head  : O(1)
- At tail  : O(n)
- At pos   : O(n)

Deletion:
- Head     : O(1)
- By value : O(n)

Search:
O(n)

Traversal:
O(n)
*/


/*
----------------------------------------------------
9. SPACE COMPLEXITY
----------------------------------------------------

Each node stores:
- Data
- Pointer

Total Space:
O(n)

Extra Space:
O(1)
*/


/*
----------------------------------------------------
10. IMPORTANT INTERVIEW CONCEPTS
----------------------------------------------------

✔ Reverse a Linked List
✔ Detect Cycle (Floyd’s Cycle Detection)
✔ Find Middle (Slow-Fast Pointer)
✔ Merge Two Sorted Lists
✔ Remove Nth Node from End

Very Important Pattern:
Two Pointer Technique
*/


/*
----------------------------------------------------
11. MAIN FUNCTION (TEST)
----------------------------------------------------
*/

int main()
{
    Node* head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtTail(head, 5);
    insertAtPosition(head, 4, 3);

    printList(head);

    deleteByValue(head, 3);

    printList(head);

    if(search(head, 5))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
/*
============================================================
INSERT IN MIDDLE USING RECURSION
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Insert a node at a given position in a singly linked list
using recursion.

Example:

Original:
2 -> 4 -> 6 -> 8 -> NULL

Insert 100 at position 2 (0-based indexing)

Result:
2 -> 4 -> 100 -> 6 -> 8 -> NULL

Position Meaning (0-based):
pos = 0  -> Insert at beginning
pos = 1  -> After first node
pos = 2  -> After second node
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
3. CORE RECURSIVE IDEA
------------------------------------------------------------

Function:
Node* insertAtPosition(Node* head, int pos, int value)

Logic:

Base Case 1:
If head == NULL
Return NULL

Base Case 2:
If pos == 0
Create new node
newNode->next = head
Return newNode

Recursive Case:
Move one step forward:
head->next = insertAtPosition(head->next, pos - 1, value)

Return head

This shifts the insertion responsibility
down the recursive calls.
*/


Node* insertAtPosition(Node* head, int pos, int value)
{
    // If position is 0, insert here
    if(pos == 0)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    // If list ends before position
    if(head == NULL)
    {
        return NULL;
    }

    // Recursive step
    head->next = insertAtPosition(head->next, pos - 1, value);

    return head;
}


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

List:
2 -> 4 -> 6 -> 8

Insert 100 at position 2

Call Stack:

insert(2, pos=2)
    head->next = insert(4, pos=1)

insert(4, pos=1)
    head->next = insert(6, pos=0)

insert(6, pos=0)
    Create newNode(100)
    newNode->next = 6
    return newNode

Unwinding:

4->next = 100
2->next = 4

Final List:
2 -> 4 -> 100 -> 6 -> 8
*/


/*
------------------------------------------------------------
5. PRINT FUNCTION
------------------------------------------------------------
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
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Worst Case:
Traverse entire list once

Time Complexity: O(n)


------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth:
O(n)

Auxiliary Space: O(n)


------------------------------------------------------------
8. IMPORTANT NOTES
------------------------------------------------------------

[IMPORTANT]
Insertion happens when pos becomes 0.

[IMPORTANT]
Each recursive call reduces pos by 1.

[COMMON MISTAKE]
Forgetting to return head after recursive call.

[EDGE CASE]
If pos is greater than list length,
function returns unchanged list.


------------------------------------------------------------
9. COMPARISON WITH ITERATIVE
------------------------------------------------------------

Recursive:
- Cleaner logic
- Uses recursion stack

Iterative:
- No stack overhead
- More control over pointer handling


------------------------------------------------------------
10. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    // Creating initial list manually
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);

    cout << "Original List:" << endl;
    printList(head);

    head = insertAtPosition(head, 2, 100);

    cout << "After Insertion:" << endl;
    printList(head);

    return 0;
}
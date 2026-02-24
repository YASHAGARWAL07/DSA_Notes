/*
============================================================
MIDDLE OF LINKED LIST – 2 METHODS
1) Counting Method (Two Traversals)
2) Optimal Method (Slow & Fast Pointer)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
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
============================================================
METHOD 1: COUNT TOTAL NODES (TWO PASS)
============================================================

Idea:
1. First traversal → count total nodes.
2. Second traversal → move to count/2 index.

If n is even:
This returns second middle element.

Time Complexity: O(n) + O(n) = O(n)
Space Complexity: O(1)
*/


Node* findMiddleCountMethod(Node* head)
{
    if(head == NULL)
        return NULL;

    int count = 0;
    Node* temp = head;

    // First pass: Count nodes
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;

    // Second pass: Move to middle
    temp = head;
    for(int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }

    return temp;
}


/*
------------------------------------------------------------
DRY RUN (COUNT METHOD)
------------------------------------------------------------

List:
2 -> 4 -> 6 -> 8 -> 10

Count = 5
mid = 5/2 = 2

Move 2 steps:
Index 0 → 2
Index 1 → 4
Index 2 → 6  (Middle)

Return 6
*/


/*
============================================================
METHOD 2: SLOW & FAST POINTER (OPTIMAL)
============================================================

Idea:
Use two pointers:

slow → moves 1 step
fast → moves 2 steps

When fast reaches end,
slow will be at middle.

Time Complexity: O(n)
Space Complexity: O(1)
Single traversal
*/


Node* findMiddleOptimal(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps
    }

    return slow;
}


/*
------------------------------------------------------------
DRY RUN (SLOW FAST METHOD)
------------------------------------------------------------

List:
2 -> 4 -> 6 -> 8 -> 10

Initial:
slow = 2
fast = 2

Step 1:
slow = 4
fast = 6

Step 2:
slow = 6
fast = 10

Step 3:
fast->next = NULL → stop

slow = 6 (Middle)
*/


/*
------------------------------------------------------------
EVEN LENGTH CASE
------------------------------------------------------------

List:
2 -> 4 -> 6 -> 8

slow = 2
fast = 2

Step 1:
slow = 4
fast = 6

Step 2:
slow = 6
fast = NULL

Returns:
6 (Second middle element)

If first middle required:
Initialize fast = head->next
*/


/*
============================================================
PRINT FUNCTION
============================================================
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
============================================================
MAIN FUNCTION
============================================================
*/

int main()
{
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);

    cout << "List:" << endl;
    printList(head);

    Node* mid1 = findMiddleCountMethod(head);
    cout << "Middle (Count Method): " << mid1->data << endl;

    Node* mid2 = findMiddleOptimal(head);
    cout << "Middle (Optimal Method): " << mid2->data << endl;

    return 0;
}


/*
============================================================
COMPARISON SUMMARY
============================================================

Count Method:
- Two traversals
- Simple logic
- O(n) time

Slow & Fast Pointer:
- One traversal
- Optimal
- Standard interview solution

============================================================
END
============================================================
*/
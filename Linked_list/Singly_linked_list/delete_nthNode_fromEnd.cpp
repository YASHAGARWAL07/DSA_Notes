/*
============================================================
REMOVE NTH NODE FROM END OF LIST
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the head of a singly linked list,
remove the nth node from the end of the list
and return the head of the modified list.

Example 1:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> NULL
n = 2

Output:
1 -> 2 -> 3 -> 5 -> NULL


Example 2:

Input:
1 -> NULL
n = 1

Output:
NULL


Example 3:

Input:
1 -> 2 -> NULL
n = 1

Output:
1 -> NULL
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
3. APPROACH 1 (TWO PASS METHOD)
------------------------------------------------------------

Step 1:
Count total nodes (length = n).

Step 2:
Position to delete from start =
length - given_n.

Step 3:
Traverse to that position and remove node.

Time Complexity: O(n)
Space Complexity: O(1)
*/


Node* removeNthTwoPass(Node* head, int n)
{
    if(head == NULL)
        return NULL;

    int length = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    int position = length - n;

    // If removing first node
    if(position == 0)
    {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }

    temp = head;
    Node* prev = NULL;

    for(int i = 0; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}


/*
------------------------------------------------------------
4. APPROACH 2 (OPTIMAL ONE PASS METHOD)
------------------------------------------------------------

Use two pointers:
fast and slow.

Step 1:
Move fast pointer n steps ahead.

Step 2:
Move both fast and slow together
until fast reaches last node.

Step 3:
Slow will be just before the node
that needs to be deleted.

Special Case:
If fast becomes NULL after initial movement,
remove head.
*/


Node* removeNthOptimal(Node* head, int n)
{
    if(head == NULL)
        return NULL;

    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead
    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // If deleting first node
    if(fast == NULL)
    {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }

    // Move both until fast reaches last node
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    return head;
}


/*
------------------------------------------------------------
5. DRY RUN (OPTIMAL METHOD)
------------------------------------------------------------

Example:
1 -> 2 -> 3 -> 4 -> 5
n = 2

Step 1:
Move fast 2 steps

fast = 3
slow = 1

Step 2:
Move both until fast->next is NULL

Iteration 1:
fast = 4
slow = 2

Iteration 2:
fast = 5
slow = 3

Now fast->next = NULL

Node to delete = slow->next = 4

After deletion:
1 -> 2 -> 3 -> 5
*/


/*
------------------------------------------------------------
6. PRINT FUNCTION
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
7. TIME COMPLEXITY
------------------------------------------------------------

Two Pass:
O(n)

Optimal One Pass:
O(n)


------------------------------------------------------------
8. SPACE COMPLEXITY
------------------------------------------------------------

Both approaches:
Auxiliary Space = O(1)


------------------------------------------------------------
9. IMPORTANT NOTES
------------------------------------------------------------

[IMPORTANT]
Always handle the case when deleting head.

[IMPORTANT]
In optimal method,
after moving fast n steps,
if fast becomes NULL,
remove first node.

[COMMON MISTAKE]
Using while(fast != NULL)
instead of while(fast->next != NULL)
may cause null pointer error.

[EDGE CASE]
Single node list.
*/


/*
------------------------------------------------------------
10. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:" << endl;
    printList(head);

    head = removeNthOptimal(head, 2);

    cout << "\nAfter Removing 2nd Node From End:" << endl;
    printList(head);

    return 0;
}
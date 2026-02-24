/*
============================================================
REMOVE EVERY Kth NODE FROM LINKED LIST
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a singly linked list, remove every kth node
from the linked list.

Example 1:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
k = 2

Output:
1 -> 3 -> 5 -> 7


Example 2:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
k = 3

Output:
1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10


If k = 1:
All nodes are removed.
Return NULL.
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
3. CREATE LINKED LIST USING LOOP
------------------------------------------------------------

This method builds the linked list from an array.

Time Complexity: O(n)
*/

Node* createList(int arr[], int size)
{
    if(size == 0)
        return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < size; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}


/*
------------------------------------------------------------
4. CORE IDEA
------------------------------------------------------------

Traverse the list while maintaining a counter.

If counter == k:
    Delete current node
    Reset counter to 1
Else:
    Move forward and increment counter

Important:
We must maintain a previous pointer
to reconnect links safely.

Special Case:
If k == 1 → return NULL.
*/


Node* deleteK(Node* head, int k)
{
    if(head == NULL)
        return NULL;

    if(k == 1)
        return NULL;

    int count = 1;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL)
    {
        if(count == k)
        {
            // Remove current node
            prev->next = curr->next;

            Node* temp = curr;
            curr = curr->next;
            delete temp;

            count = 1;
        }
        else
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }

    return head;
}


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Example:
1 -> 2 -> 3 -> 4 -> 5 -> 6
k = 2

Initial:
count = 1
curr = 1

Step 1:
count != 2
prev = 1
curr = 2
count = 2

Step 2:
count == 2
Remove node 2
List becomes:
1 -> 3 -> 4 -> 5 -> 6
Reset count = 1

Continue:

Remove 4
Remove 6

Final:
1 -> 3 -> 5
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Each node is visited once.

Time Complexity: O(n)


------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

No extra data structures used.

Auxiliary Space: O(1)
*/


/*
------------------------------------------------------------
8. IMPORTANT NOTES
------------------------------------------------------------

1. When deleting a node,
   always store it in a temporary pointer before deleting.

2. Do not move prev after deletion.

3. Always reset counter after removing kth node.

4. Handle k == 1 separately.

5. Assumption:
   k will always be <= size of linked list.
*/


/*
------------------------------------------------------------
9. PRINT FUNCTION
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
10. FREE MEMORY FUNCTION
------------------------------------------------------------
*/

void freeList(Node* head)
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


/*
------------------------------------------------------------
11. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, size);

    cout << "Original List:" << endl;
    printList(head);

    int k = 2;

    head = deleteK(head, k);

    cout << "\nAfter Removing Every " << k << "th Node:" << endl;
    printList(head);

    freeList(head);

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/
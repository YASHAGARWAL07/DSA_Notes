/*
============================================================
REVERSE LINKED LIST – 3 METHODS
1) Using Array
2) Using Iterative (prev, curr, next)
3) Using Recursion
============================================================
*/

#include <iostream>
#include <vector>
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
METHOD 1: REVERSE USING ARRAY
============================================================

Idea:
1. Store all node values in array/vector.
2. Traverse again and overwrite values in reverse order.

This does NOT change structure.
Only changes data.

Time Complexity: O(n)
Space Complexity: O(n)
*/


Node* reverseUsingArray(Node* head)
{
    if(head == NULL)
        return NULL;

    vector<int> arr;
    Node* temp = head;

    // Step 1: Store values
    while(temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // Step 2: Rewrite values in reverse
    temp = head;
    int i = arr.size() - 1;

    while(temp != NULL)
    {
        temp->data = arr[i--];
        temp = temp->next;
    }

    return head;
}


/*
============================================================
METHOD 2: ITERATIVE (prev, curr, next)
============================================================

Most important method for interviews.

Idea:
Reverse pointers one by one.

prev  -> initially NULL
curr  -> head
next  -> temporary storage

Process:
1. Store curr->next in next
2. Reverse pointer (curr->next = prev)
3. Move prev and curr forward

Time Complexity: O(n)
Space Complexity: O(1)
*/


Node* reverseIterative(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;     // Step 1
        curr->next = prev;     // Step 2
        prev = curr;           // Step 3
        curr = next;           // Step 4
    }

    return prev;
}


/*
------------------------------------------------------------
DRY RUN (ITERATIVE METHOD)
------------------------------------------------------------

Original:
2 -> 4 -> 6 -> NULL

Step 1:
prev = NULL
curr = 2

After first iteration:
2 -> NULL
prev = 2
curr = 4

After second iteration:
4 -> 2 -> NULL
prev = 4
curr = 6

After third iteration:
6 -> 4 -> 2 -> NULL

Return prev (6)
*/


/*
============================================================
METHOD 3: RECURSION (prev, curr)
============================================================

Function:
reverseRecursive(curr, prev)

Base Case:
If curr == NULL
Return prev

Recursive Steps:
1. Store next node
2. Reverse pointer
3. Recurse for next node

Time Complexity: O(n)
Space Complexity: O(n) (recursive stack)
*/


Node* reverseRecursive(Node* curr, Node* prev)
{
    if(curr == NULL)
        return prev;

    Node* next = curr->next;
    curr->next = prev;

    return reverseRecursive(next, curr);
}


/*
------------------------------------------------------------
ALTERNATIVE RECURSIVE STYLE (Single Parameter)
------------------------------------------------------------

Classic recursive pattern:

1. Reach last node
2. Reverse links while returning
*/

Node* reverseRecursiveAlt(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverseRecursiveAlt(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}


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
    // Creating list manually
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);

    cout << "Original List:" << endl;
    printList(head);

    // Method 1
    head = reverseUsingArray(head);
    cout << "Reversed Using Array:" << endl;
    printList(head);

    // Method 2
    head = reverseIterative(head);
    cout << "Reversed Using Iterative:" << endl;
    printList(head);

    // Method 3
    head = reverseRecursive(head, NULL);
    cout << "Reversed Using Recursion:" << endl;
    printList(head);

    return 0;
}


/*
============================================================
COMPARISON SUMMARY
============================================================

Method 1 (Array):
- Easy
- Uses extra space
- Does not change structure

Method 2 (Iterative):
- Most efficient
- O(1) space
- Interview standard

Method 3 (Recursion):
- Elegant
- Uses stack space
- Good for conceptual understanding

============================================================
END
============================================================
*/
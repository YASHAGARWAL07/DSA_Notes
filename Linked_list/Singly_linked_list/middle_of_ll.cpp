/*
============================================================
MIDDLE OF THE LINKED LIST
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the head of a singly linked list,
return the middle node of the list.

If there are two middle nodes,
return the second middle node.

Example 1:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> NULL

Output:
3 -> 4 -> 5 -> NULL

Explanation:
List length = 5 (odd)
Middle index = 5 / 2 = 2
Node at index 2 = 3


Example 2:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

Output:
4 -> 5 -> 6 -> NULL

Explanation:
List length = 6 (even)
Middle indices = 2 and 3
Return second middle -> index 3 -> value 4
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
Traverse entire list and count number of nodes (n).

Step 2:
Compute mid = n / 2

Step 3:
Traverse again and move mid steps from head.

Return that node.

Why n/2 works?

If n is odd:
Example: n = 5
5/2 = 2
Index 2 is correct middle.

If n is even:
Example: n = 6
6/2 = 3
Index 3 gives second middle.
*/


Node* findMiddleTwoPass(Node* head)
{
    if(head == NULL)
        return NULL;

    int count = 0;
    Node* temp = head;

    // First Pass: Count nodes
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;

    temp = head;

    // Second Pass: Move to middle
    for(int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }

    return temp;
}


/*
------------------------------------------------------------
4. APPROACH 2 (SLOW AND FAST POINTER)
------------------------------------------------------------

This is the optimal method.

Idea:

Use two pointers:
slow -> moves 1 step
fast -> moves 2 steps

When fast reaches end,
slow will be at middle.

Why does it work?

For every 2 steps of fast,
slow moves 1 step.

So when fast completes traversal,
slow completes half traversal.

If length is even:
slow naturally lands on second middle.
*/


Node* findMiddleOptimal(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


/*
------------------------------------------------------------
5. DRY RUN (SLOW FAST METHOD)
------------------------------------------------------------

Example:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Initial:
slow = 1
fast = 1

Iteration 1:
slow = 2
fast = 3

Iteration 2:
slow = 3
fast = 5

Iteration 3:
slow = 4
fast = NULL (after moving 2 steps)

Loop stops.

slow = 4
Correct second middle.
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

Two Pass Method:
First traversal  -> O(n)
Second traversal -> O(n)
Total            -> O(n)

Slow-Fast Method:
Single traversal -> O(n)

Overall:
O(n)


------------------------------------------------------------
8. SPACE COMPLEXITY
------------------------------------------------------------

No extra data structures used.

Auxiliary Space: O(1)


------------------------------------------------------------
9. IMPORTANT NOTES
------------------------------------------------------------

[IMPORTANT]
For even length list,
slow-fast automatically returns second middle.

[COMMON MISTAKE]
Using while(fast->next != NULL)
instead of
while(fast != NULL && fast->next != NULL)

This may cause segmentation fault.

[EDGE CASE]
If list has only one node,
that node is the middle.


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
    head->next->next->next->next->next = new Node(6);

    cout << "Original List:" << endl;
    printList(head);

    Node* middle1 = findMiddleTwoPass(head);
    cout << "\nMiddle (Two Pass Method):" << endl;
    printList(middle1);

    Node* middle2 = findMiddleOptimal(head);
    cout << "\nMiddle (Slow-Fast Method):" << endl;
    printList(middle2);

    return 0;
}
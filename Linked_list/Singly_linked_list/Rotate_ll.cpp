/*
============================================================
ROTATE LIST TO THE RIGHT BY K PLACES
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Rotate a singly linked list to the right by k places.

Example 1:

Original:
1 -> 2 -> 3 -> 4 -> 5 -> NULL
k = 2

Result:
4 -> 5 -> 1 -> 2 -> 3 -> NULL

Example 2:

Original:
0 -> 1 -> 2 -> NULL
k = 4

Result:
2 -> 0 -> 1 -> NULL

Explanation:

Rotating right means:
Take the last k nodes and move them to the front.
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
3. CORE IDEA
------------------------------------------------------------

Steps:

1. Find length of list (n).
2. Reduce k using: k = k % n.
3. If k == 0, return head.
4. Find new tail at position (n - k - 1).
5. New head will be (n - k)th node.
6. Break the list at new tail.
7. Attach old tail to old head.

Key Observation:

After rotation:
New Head Index = n - k
New Tail Index = n - k - 1

This converts the problem into
finding a breaking point in the list.
*/


Node* rotateRight(Node* head, int k)
{
    // Edge Cases
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length
    int length = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    // Step 2: Reduce k
    k = k % length;

    if(k == 0)
        return head;

    // Step 3: Find new tail position
    int move = length - k;

    Node* curr = head;
    Node* prev = NULL;

    while(move--)
    {
        prev = curr;
        curr = curr->next;
    }

    // Now:
    // curr  -> new head
    // prev  -> new tail

    // Step 4: Break link
    prev->next = NULL;

    // Step 5: Move to old tail
    Node* tail = curr;

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    // Step 6: Connect old tail to old head
    tail->next = head;

    return curr;
}


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

List:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Length = 5

k = 2 % 5 = 2

move = 5 - 2 = 3

Traverse 3 steps:

Step 1:
prev = 1
curr = 2

Step 2:
prev = 2
curr = 3

Step 3:
prev = 3
curr = 4

Now:
prev = 3 (new tail)
curr = 4 (new head)

Break:
3 -> NULL

Remaining:
4 -> 5

Find tail:
5

Attach:
5 -> 1

Final:
4 -> 5 -> 1 -> 2 -> 3
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

Finding length: O(n)
Finding new tail: O(n)
Finding old tail: O(n)

Total:
O(n)


------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

No extra data structures used.

Auxiliary Space: O(1)


------------------------------------------------------------
8. IMPORTANT NOTES
------------------------------------------------------------

[IMPORTANT]
Always reduce k using k = k % length.

[IMPORTANT]
Be careful with (length - k).

[COMMON MISTAKE]
Off-by-one error while locating new tail.

[EDGE CASE]
If k is multiple of length,
list remains unchanged.


------------------------------------------------------------
9. COMPARISON WITH BRUTE FORCE
------------------------------------------------------------

Brute Force:
Rotate one step at a time.
Time Complexity: O(n * k)

Optimal Approach:
Break once and reconnect.
Time Complexity: O(n)


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

    head = rotateRight(head, 2);

    cout << "After Rotation:" << endl;
    printList(head);

    return 0;
}
/*
============================================================
PALINDROME LINKED LIST
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the head of a singly linked list,
return true if it is a palindrome,
otherwise return false.

A palindrome means:
The list reads the same forward and backward.

Example 1:

Input:
1 -> 2 -> 2 -> 1 -> NULL

Output:
true


Example 2:

Input:
1 -> 2 -> NULL

Output:
false


Follow-up:
Solve in O(n) time and O(1) space.
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
3. CORE IDEA (OPTIMAL APPROACH)
------------------------------------------------------------

Step 1:
Find the middle of the list using slow and fast pointers.

Step 2:
If length is odd, skip the middle node.

Step 3:
Reverse the second half of the list.

Step 4:
Compare first half and reversed second half.

Step 5:
If all values match, it is a palindrome.

Why this works:

If the list is palindrome,
first half == reverse(second half).
*/


bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Find middle
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: If odd length, skip middle
    if(fast != NULL)
        slow = slow->next;

    // Step 3: Reverse second half
    Node* prev = NULL;
    while(slow != NULL)
    {
        Node* nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }

    // Step 4: Compare both halves
    Node* left = head;
    Node* right = prev;

    while(right != NULL)
    {
        if(left->data != right->data)
            return false;

        left = left->next;
        right = right->next;
    }

    return true;
}


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

Example:
1 -> 2 -> 2 -> 1

Step 1:
Find middle

slow = 1, fast = 1
slow = 2, fast = 2
slow = 2, fast = NULL

Middle reached.

Step 2:
Even length, no skipping.

Step 3:
Reverse second half:

2 -> 1
becomes
1 -> 2

Step 4:
Compare:

1 == 1
2 == 2

All matched -> Palindrome.


Example:
1 -> 2

Middle:
slow = 2

Reverse second half:
2

Compare:
1 != 2

Not palindrome.
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

Finding middle: O(n)
Reversing half: O(n)
Comparing: O(n)

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
For odd length list,
skip the exact middle node.

[IMPORTANT]
Slow-fast pointer ensures second half starts correctly.

[COMMON MISTAKE]
Forgetting condition:
while(fast != NULL && fast->next != NULL)

[EDGE CASE]
Single node is always palindrome.


------------------------------------------------------------
9. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << "List:" << endl;
    printList(head);

    if(isPalindrome(head))
        cout << "\nResult: Palindrome" << endl;
    else
        cout << "\nResult: Not Palindrome" << endl;

    return 0;
}
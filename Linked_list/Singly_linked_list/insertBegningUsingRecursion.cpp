/*
============================================================
INSERT AT BEGINNING USING RECURSION
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Insert elements at the beginning of a linked list
using recursion.

Given:
arr[] = {2, 4, 6, 8, 10}

If inserted normally (forward recursion):
2 -> 4 -> 6 -> 8 -> 10 -> NULL

If inserted at beginning recursively:
10 -> 8 -> 6 -> 4 -> 2 -> NULL

This happens because each new node is attached
before the previous one.
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

Function Signature:
Node* CreateLinkedList(int arr[], int index, int size, Node* prev)

Logic:

Base Case:
If index == size
Return prev

Recursive Case:
1. Create new node with arr[index]
2. Point newNode->next to prev
3. Recursively call for next index
4. Return result of recursive call

This effectively inserts every new node
at the beginning of the already formed list.
*/


Node* CreateLinkedList(int arr[], int index, int size, Node* prev)
{
    // Base Case
    if(index == size)
    {
        return prev;
    }

    // Step 1: Create new node
    Node* temp = new Node(arr[index]);

    // Step 2: Insert at beginning
    temp->next = prev;

    // Step 3: Recursive call
    return CreateLinkedList(arr, index + 1, size, temp);
}


/*
------------------------------------------------------------
4. DRY RUN (STEP BY STEP)
------------------------------------------------------------

arr = {2, 4, 6}
size = 3

Initial call:
CreateLinkedList(arr, 0, 3, NULL)

Call 1:
index = 0
temp = Node(2)
temp->next = NULL
Call next with prev = Node(2)

Call 2:
index = 1
temp = Node(4)
temp->next = Node(2)
Call next with prev = Node(4)

Call 3:
index = 2
temp = Node(6)
temp->next = Node(4)
Call next with prev = Node(6)

Call 4:
index == size
Return Node(6)

Final List:
6 -> 4 -> 2 -> NULL
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

Each element processed once.

Time Complexity: O(n)


------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth = n

Auxiliary Space: O(n)


------------------------------------------------------------
8. IMPORTANT DIFFERENCE FROM NORMAL RECURSIVE CREATION
------------------------------------------------------------

Normal Recursive Creation:
temp->next = recursive_call

Insert at Beginning:
temp->next = prev
return recursive_call(..., temp)

Key Difference:
We pass previous node instead of attaching later.


------------------------------------------------------------
9. INTERVIEW POINTS
------------------------------------------------------------

[IMPORTANT]
Passing a "prev" pointer allows building the list in reverse.

[IMPORTANT]
This technique is similar to reversing a linked list
using recursion.

[COMMON MISTAKE]
Forgetting to pass updated temp in recursive call.

[INTERVIEW QUESTION]
What is the difference between:
- Forward recursive creation
- Backward recursive insertion?


------------------------------------------------------------
10. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    Head = CreateLinkedList(arr, 0, size, Head);

    printList(Head);

    return 0;
}

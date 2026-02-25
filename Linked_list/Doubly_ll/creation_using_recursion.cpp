/*
============================================================
DOUBLY LINKED LIST USING RECURSION
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Create a Doubly Linked List (DLL) using recursion.

Each node contains:
- data
- pointer to next node
- pointer to previous node

Example:

Input Array:
1 2 3 4

Output DLL:
NULL <- 1 <-> 2 <-> 3 <-> 4 -> NULL
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
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


/*
------------------------------------------------------------
3. CORE RECURSIVE IDEA
------------------------------------------------------------

Function:
Node* createDLL(int arr[], int index, int size, Node* back)

Parameters:
arr   -> input array
index -> current position
size  -> total elements
back  -> previous node pointer

Logic:

Base Case:
If index == size
    return NULL

Recursive Case:
1. Create new node with arr[index]
2. Set temp->prev = back
3. Set temp->next = recursive call
4. Return temp

This builds list forward
while linking backward using 'back'.
*/


Node* createDLL(int arr[], int index, int size, Node* back)
{
    // Base Case
    if(index == size)
        return NULL;

    // Step 1: Create node
    Node* temp = new Node(arr[index]);

    // Step 2: Link backward pointer
    temp->prev = back;

    // Step 3: Recursive call for next node
    temp->next = createDLL(arr, index + 1, size, temp);

    return temp;
}


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

Array:
1 2 3

Call:
createDLL(arr, 0, 3, NULL)

Step 1:
index = 0
Create node 1
prev = NULL
next = createDLL(1, 3, node1)

Step 2:
index = 1
Create node 2
prev = node1
next = createDLL(2, 3, node2)

Step 3:
index = 2
Create node 3
prev = node2
next = createDLL(3, 3, node3)

Step 4:
index = 3 == size
Return NULL

Final Structure:

NULL <- 1 <-> 2 <-> 3 -> NULL
*/


/*
------------------------------------------------------------
5. TIME COMPLEXITY
------------------------------------------------------------

Each element processed once.

Time Complexity: O(n)


------------------------------------------------------------
6. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth = n

Auxiliary Space: O(n)
*/


/*
------------------------------------------------------------
7. IMPORTANT NOTES
------------------------------------------------------------

1. The 'back' pointer maintains previous node link.
2. Forward linking happens via recursive return.
3. Base case must return NULL.
4. Do not forget to pass current node as back in recursion.
*/


/*
------------------------------------------------------------
8. PRINT FORWARD
------------------------------------------------------------
*/

void printForward(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


/*
------------------------------------------------------------
9. PRINT BACKWARD
------------------------------------------------------------
*/

void printBackward(Node* head)
{
    if(head == NULL)
        return;

    // Move to last node
    while(head->next != NULL)
    {
        head = head->next;
    }

    while(head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->prev;
    }
    cout << "NULL" << endl;
}


/*
------------------------------------------------------------
10. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createDLL(arr, 0, size, NULL);

    cout << "Forward Traversal:" << endl;
    printForward(head);

    cout << "Backward Traversal:" << endl;
    printBackward(head);

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/
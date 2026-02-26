/*
============================================================
DOUBLY LINKED LIST – DELETION OPERATIONS
1) Delete at Beginning
2) Delete at End
3) Delete at Given Position
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
2. CREATE DLL USING LOOP
------------------------------------------------------------
*/

Node* createDLL(int arr[], int size)
{
    if(size == 0)
        return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < size; i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;
}


/*
------------------------------------------------------------
3. DELETE AT BEGINNING
------------------------------------------------------------

Cases:
1. Empty list
2. Only one node
3. More than one node
*/

Node* deleteAtBeginning(Node* head)
{
    if(head == NULL)
        return NULL;

    // Only one node
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node* temp = head;
    head = head->next;

    head->prev = NULL;
    delete temp;

    return head;
}


/*
------------------------------------------------------------
4. DELETE AT END
------------------------------------------------------------

Cases:
1. Empty list
2. Only one node
3. More than one node
*/

Node* deleteAtEnd(Node* head)
{
    if(head == NULL)
        return NULL;

    // Only one node
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;

    return head;
}


/*
------------------------------------------------------------
5. DELETE AT GIVEN POSITION (1-based indexing)
------------------------------------------------------------

Steps:
1. If position = 1 → delete at beginning
2. Traverse to that position
3. Reconnect prev and next
4. Delete node
*/

Node* deleteAtPosition(Node* head, int pos)
{
    if(head == NULL)
        return NULL;

    if(pos == 1)
        return deleteAtBeginning(head);

    Node* temp = head;
    int count = 1;

    while(temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }

    if(temp == NULL)
        return head; // position out of range

    if(temp->next == NULL)
        return deleteAtEnd(head);

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    return head;
}


/*
------------------------------------------------------------
6. PRINT FUNCTION (FORWARD)
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
7. PRINT FUNCTION (BACKWARD)
------------------------------------------------------------
*/

void printBackward(Node* head)
{
    if(head == NULL)
        return;

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
8. TIME COMPLEXITY
------------------------------------------------------------

Delete at Beginning → O(1)
Delete at End       → O(n)
Delete at Position  → O(n)


------------------------------------------------------------
9. SPACE COMPLEXITY
------------------------------------------------------------

Auxiliary Space: O(1)
*/


/*
------------------------------------------------------------
10. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createDLL(arr, size);

    cout << "Original DLL:" << endl;
    printForward(head);

    head = deleteAtBeginning(head);
    cout << "\nAfter Deleting at Beginning:" << endl;
    printForward(head);

    head = deleteAtEnd(head);
    cout << "\nAfter Deleting at End:" << endl;
    printForward(head);

    head = deleteAtPosition(head, 2);
    cout << "\nAfter Deleting at Position 2:" << endl;
    printForward(head);

    cout << "\nBackward Traversal:" << endl;
    printBackward(head);

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/
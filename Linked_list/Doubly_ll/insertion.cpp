/*
============================================================
DOUBLY LINKED LIST – INSERTION OPERATIONS
1) Insert at Beginning
2) Insert at End
3) Insert at Given Position
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
3. INSERT AT BEGINNING
------------------------------------------------------------

Steps:
1. Create new node
2. newNode->next = head
3. head->prev = newNode
4. Update head
*/

Node* insertAtBeginning(Node* head, int value)
{
    Node* newNode = new Node(value);

    if(head == NULL)
        return newNode;

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}


/*
------------------------------------------------------------
4. INSERT AT END
------------------------------------------------------------

Steps:
1. Traverse to last node
2. Attach new node
3. Set prev pointer properly
*/

Node* insertAtEnd(Node* head, int value)
{
    Node* newNode = new Node(value);

    if(head == NULL)
        return newNode;

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}


/*
------------------------------------------------------------
5. INSERT AT GIVEN POSITION (1-based indexing)
------------------------------------------------------------

Cases:
1. Position = 1 → Insert at beginning
2. Insert in middle
3. Insert at end

Steps:
1. Traverse to (pos-1)
2. Adjust four links:
   prev->next
   newNode->prev
   newNode->next
   next->prev
*/

Node* insertAtPosition(Node* head, int value, int pos)
{
    if(pos <= 1 || head == NULL)
        return insertAtBeginning(head, value);

    Node* temp = head;
    int count = 1;

    while(temp->next != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL)
        return insertAtEnd(head, value);

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}


/*
------------------------------------------------------------
6. PRINT FORWARD
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
7. PRINT BACKWARD
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

Insert at Beginning → O(1)
Insert at End       → O(n)
Insert at Position  → O(n)


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
    int arr[] = {2, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createDLL(arr, size);

    cout << "Original DLL:" << endl;
    printForward(head);

    head = insertAtBeginning(head, 1);
    cout << "\nAfter Insert at Beginning:" << endl;
    printForward(head);

    head = insertAtEnd(head, 8);
    cout << "\nAfter Insert at End:" << endl;
    printForward(head);

    head = insertAtPosition(head, 5, 3);
    cout << "\nAfter Insert 5 at Position 3:" << endl;
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
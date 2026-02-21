/*
====================================================
CIRCULAR SINGLY LINKED LIST
====================================================
*/

#include <iostream>
using namespace std;

/*
----------------------------------------------------
1. INTRODUCTION
----------------------------------------------------

Last node points back to head.

Structure:
[data|next] -> [data|next]
      ^             |
      |_____________|

✔ No NULL pointer
✔ Useful in round-robin scheduling
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
----------------------------------------------------
2. INSERT AT END
----------------------------------------------------
*/

void insert(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

/*
----------------------------------------------------
3. TRAVERSAL
----------------------------------------------------
*/

void printList(Node* head)
{
    if(head == NULL) return;

    Node* temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != head);

    cout << "(Back to Head)" << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    printList(head);

    return 0;
}
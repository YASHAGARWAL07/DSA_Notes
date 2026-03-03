/*
============================================================
LINKED LIST CYCLE DETECTION AND REMOVAL
(FLOYD’S CYCLE DETECTION ALGORITHM)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

1) Detect whether a linked list contains a cycle.
2) If a cycle exists, remove it.

A cycle exists if a node’s next pointer
points to a previous node instead of NULL.

Example:

1 -> 2 -> 3 -> 4 -> 5
              ^     |
              |_____|

The last node points back to node 3.
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
3. DETECT CYCLE (FLOYD’S ALGORITHM)
------------------------------------------------------------

Use two pointers:

slow -> moves 1 step
fast -> moves 2 steps

If cycle exists:
They will eventually meet.

If fast reaches NULL:
No cycle exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool detectCycle(Node* head)
{
    if(head == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}


/*
------------------------------------------------------------
4. FIND STARTING NODE OF CYCLE
------------------------------------------------------------

After slow and fast meet:

1. Move slow to head.
2. Move both one step at a time.
3. Meeting point is start of cycle.

Why this works?

Distance from head to cycle start
equals distance from meeting point
to cycle start.
*/

Node* findCycleStart(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    bool hasCycle = false;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            hasCycle = true;
            break;
        }
    }

    if(!hasCycle)
        return NULL;

    slow = head;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


/*
------------------------------------------------------------
5. REMOVE CYCLE
------------------------------------------------------------

Steps:

1. Find cycle start node.
2. Traverse cycle until reaching node
   whose next points to cycle start.
3. Set its next to NULL.
*/

void removeCycle(Node* head)
{
    Node* start = findCycleStart(head);

    if(start == NULL)
        return;

    Node* temp = start;

    while(temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}


/*
------------------------------------------------------------
6. DRY RUN (IMPORTANT CONCEPT)
------------------------------------------------------------

Let:

Distance from head to cycle start = a
Cycle length = b
Distance from cycle start to meeting point = c

When slow and fast meet:

2(a + c) = a + c + k*b

Solving:
a = k*b - c

This proves that moving slow to head
and moving both one step
will meet at cycle start.
*/


/*
------------------------------------------------------------
7. PRINT FUNCTION
------------------------------------------------------------
*/

void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


/*
------------------------------------------------------------
8. CREATE SAMPLE LIST WITH CYCLE
------------------------------------------------------------
*/

Node* createListWithCycle()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    return head;
}


/*
------------------------------------------------------------
9. TIME COMPLEXITY
------------------------------------------------------------

Detection: O(n)
Finding start: O(n)
Removal: O(n)

Overall: O(n)


------------------------------------------------------------
10. SPACE COMPLEXITY
------------------------------------------------------------

Only pointers used.

Auxiliary Space: O(1)
*/


/*
------------------------------------------------------------
11. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* head = createListWithCycle();

    if(detectCycle(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    Node* start = findCycleStart(head);

    if(start != NULL)
        cout << "Cycle starts at node with value: " 
             << start->data << endl;

    removeCycle(head);

    cout << "After Removing Cycle:" << endl;
    printList(head);

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/
/*
============================================================
LINKED LIST CYCLE DETECTION – 3 METHODS
1) Using Visited Array (Brute Force)
2) Using HashMap / Unordered_Map
3) Using Floyd’s Cycle Detection (Optimal)
============================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
METHOD 1: USING VISITED ARRAY (BRUTE FORCE)
============================================================

Idea:
Store every visited node in a vector.
Before visiting next node,
check whether it already exists in vector.

If yes → cycle exists
If traversal ends → no cycle

Time Complexity:
Worst case O(n^2)

Space Complexity:
O(n)
*/

bool detectCycleUsingVector(Node* head)
{
    vector<Node*> visited;
    Node* temp = head;

    while(temp != NULL)
    {
        // Check if already visited
        for(int i = 0; i < visited.size(); i++)
        {
            if(visited[i] == temp)
                return true;
        }

        visited.push_back(temp);
        temp = temp->next;
    }

    return false;
}


/*
============================================================
METHOD 2: USING HASH MAP (BETTER BRUTE)
============================================================

Idea:
Use unordered_map to store visited nodes.

If node already present → cycle.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

bool detectCycleUsingHash(Node* head)
{
    unordered_map<Node*, bool> mp;
    Node* temp = head;

    while(temp != NULL)
    {
        if(mp[temp] == true)
            return true;

        mp[temp] = true;
        temp = temp->next;
    }

    return false;
}


/*
============================================================
METHOD 3: FLOYD'S CYCLE DETECTION (TORTOISE & HARE)
============================================================

Idea:
Slow pointer → 1 step
Fast pointer → 2 steps

If cycle exists:
They must meet.

If fast reaches NULL:
No cycle.

Time Complexity:
O(n)

Space Complexity:
O(1)

This is the optimal method.
*/

bool detectCycleFloyd(Node* head)
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
DRY RUN (FLOYD METHOD)
------------------------------------------------------------

1 -> 2 -> 3 -> 4 -> 5
           ^         |
           |_________|

Slow moves 1 step
Fast moves 2 steps

Eventually both meet inside cycle.
*/


/*
------------------------------------------------------------
COMPLEXITY ANALYSIS SUMMARY
------------------------------------------------------------

METHOD 1 (Vector):
Time  : O(n^2)
Space : O(n)

METHOD 2 (HashMap):
Time  : O(n)
Space : O(n)

METHOD 3 (Floyd):
Time  : O(n)
Space : O(1)

Best for Interviews:
Floyd’s Algorithm
*/


/*
------------------------------------------------------------
UTILITY FUNCTION TO CREATE LIST WITH CYCLE
------------------------------------------------------------
*/

Node* createCycleList()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating cycle (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    return head;
}


/*
------------------------------------------------------------
MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* head = createCycleList();

    cout << "Using Vector: ";
    if(detectCycleUsingVector(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    cout << "Using HashMap: ";
    if(detectCycleUsingHash(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    cout << "Using Floyd: ";
    if(detectCycleFloyd(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/
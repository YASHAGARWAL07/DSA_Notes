/*
============================================================
REMOVE LOOP IN LINKED LIST
(FLOYD’S CYCLE DETECTION – OPTIMAL O(1) SPACE)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
------------------------------------------------------------
*/

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Given the head of a singly linked list,
remove the loop if it exists.

If no loop is present, do nothing.

Important:
- Do not use extra space
- Time complexity should be O(n)
*/


/*
------------------------------------------------------------
3. COMPLETE LOGIC FLOW
------------------------------------------------------------

PHASE 1: Detect Cycle (Floyd’s Algorithm)

    slow moves 1 step
    fast moves 2 steps

If they meet → loop exists
If fast reaches NULL → no loop


PHASE 2: Find Start of Loop

    Move slow to head
    Move both one step at a time
    They meet at starting node of loop


PHASE 3: Remove Loop

    From loop start, traverse until
    node whose next == loop start

    Break by:
    temp->next = NULL
*/


class Solution {
public:

    void removeLoop(Node* head) {

        if(head == NULL || head->next == NULL)
            return;

        Node* slow = head;
        Node* fast = head;

        // STEP 1: Detect loop
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        // STEP 2: If no loop
        if(fast == NULL || fast->next == NULL)
            return;

        // STEP 3: Move slow to head
        slow = head;

        // STEP 4: Find starting node of loop
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow == fast == start of loop

        // STEP 5: Find last node of loop
        Node* temp = slow;
        while(temp->next != slow) {
            temp = temp->next;
        }

        // STEP 6: Break the loop
        temp->next = NULL;
    }
};


/*
------------------------------------------------------------
4. WHY THIS WORKS (INTUITION)
------------------------------------------------------------

Let:

a = distance from head to loop start
b = length of loop
c = distance from loop start to meeting point

When slow and fast meet:

2(a + c) = a + c + k*b

Solving:
a = k*b - c

This proves:

Distance from head to loop start
equals
Distance from meeting point to loop start

Therefore:
Reset slow to head
Move both one step
They meet at loop start.
*/


/*
------------------------------------------------------------
5. SPECIAL EDGE CASES ANALYSIS
------------------------------------------------------------

CASE 1: No loop
Fast reaches NULL → function returns safely.

CASE 2: Loop starts at head
Example:
1 -> 2 -> 3 -> 1

After detection:
slow reset to head.
They meet at head.
Loop removed correctly.

CASE 3: Single node with loop
1 -> 1

Works correctly because:
slow == fast immediately.
Loop start found.
temp->next set to NULL.

CASE 4: Entire list forms a cycle
Still works correctly.
*/


/*
------------------------------------------------------------
6. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Never check only fast != NULL
   Always check fast->next also.

2) Do NOT modify head pointer.

3) Do not use unordered_map (unless asked).

4) Floyd’s algorithm is optimal.


Common Mistake:
Breaking loop at meeting point instead of loop start.
That is incorrect.
*/


/*
------------------------------------------------------------
7. COMPLEXITY ANALYSIS
------------------------------------------------------------

Detection Phase        → O(n)
Finding loop start     → O(n)
Finding last node      → O(n)

Worst Case             → O(n)

Auxiliary Space        → O(1)

This is optimal.
*/


/*
------------------------------------------------------------
8. COMPARISON WITH OTHER METHODS
------------------------------------------------------------

Using HashMap:
Time  → O(n)
Space → O(n)

Using Vector:
Time  → O(n^2)
Space → O(n)

Floyd’s Algorithm:
Time  → O(n)
Space → O(1)  ← BEST
*/


/*
============================================================
END OF FILE
============================================================
*/
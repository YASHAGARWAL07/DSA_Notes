/*
============================================================
CHECK IF TWO BINARY TREES ARE MIRROR OF EACH OTHER
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
------------------------------------------------------------
*/

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Given two binary trees, check whether they are
mirror images of each other.

Two trees are mirror if:

Left subtree of first tree == Right subtree of second
Right subtree of first tree == Left subtree of second


Example:

Tree A:              Tree B:

    1                    1
   / \                  / \
  2   3                3   2

Output: TRUE
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

At every node:

1. Values must be equal
2. Left of tree A == Right of tree B
3. Right of tree A == Left of tree B

This is a recursive mirror comparison.
*/


/*
------------------------------------------------------------
4. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If both nodes are NULL → return true

Step 2:
If one is NULL → return false

Step 3:
If values differ → return false

Step 4:
Recursively check:
left(A) with right(B)
right(A) with left(B)
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION
------------------------------------------------------------
*/

bool areMirror(Node* a, Node* b)
{
    if(!a && !b)
        return true;

    if(!a || !b)
        return false;

    if(a->data != b->data)
        return false;

    return areMirror(a->left, b->right) &&
           areMirror(a->right, b->left);
}


/*
------------------------------------------------------------
6. CREATE SAMPLE TREES
------------------------------------------------------------
*/

Node* createTreeA()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return root;
}

Node* createTreeB()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    return root;
}


/*
------------------------------------------------------------
7. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* a = createTreeA();
    Node* b = createTreeB();

    if(areMirror(a, b))
        cout << "Trees are mirror\n";
    else
        cout << "Trees are NOT mirror\n";

    return 0;
}


/*
------------------------------------------------------------
8. DRY RUN
------------------------------------------------------------

Compare:

(1,1) → equal

Check:
(2,2) → via left-right comparison
(3,3) → via right-left comparison

All match → TRUE
*/


/*
------------------------------------------------------------
9. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
10. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
11. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Key idea:
   Cross comparison (left ↔ right)

2. Base cases are critical

3. Very similar to:
   - Same Tree
   - Symmetric Tree

4. If both trees are identical and symmetric,
   they will also be mirror

5. Common mistake:
   comparing left-left instead of left-right
*/


/*
============================================================
END OF FILE
============================================================
*/
/*
============================================================
SEARCH IN BINARY SEARCH TREE (BST)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a Binary Search Tree (BST) and a key,
check whether the key is present in the BST or not.

Return:

true  → if key exists
false → if key does not exist

Example:

        6
       / \
      2   8
         / \
        7   9

Search key = 8

Output: TRUE
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

BST property helps us:

• If key == root → found
• If key < root → go LEFT
• If key > root → go RIGHT

So we don’t need to check entire tree,
just follow one path.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
If root is NULL → return false

STEP 2:
If root->data == key → return true

STEP 3:
If key < root->data:
    search in left subtree

STEP 4:
If key > root->data:
    search in right subtree

STEP 5:
Return result
*/


/*
============================================================
4. C++ IMPLEMENTATION
============================================================
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
public:

    bool search(Node* root, int key) {

        // Base case
        if (!root)
            return false;

        // Found
        if (root->data == key)
            return true;

        // Go left
        if (root->data > key)
            return search(root->left, key);

        // Go right
        return search(root->right, key);
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        6
       / \
      2   8
         / \
        7   9

Search key = 8

Step 1:
8 > 6 → go right

Step 2:
Node = 8 → found → TRUE
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Average: O(log n)

Worst case (skewed tree):
O(n)
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

h = height of tree

Worst case:
O(n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) BST property reduces search space

2) Only one path is explored

3) Recursive + Iterative both possible

4) Very efficient compared to normal tree

5) Base of many BST operations:

   • Insert
   • Delete
   • Search

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
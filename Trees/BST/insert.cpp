/*
============================================================
INSERT INTO BINARY SEARCH TREE (BST)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a Binary Search Tree (BST) and a value key,
insert the key into the BST and return the updated root.

Note:

• All values in BST are unique
• BST property must be maintained

BST Property:

Left subtree  → values < root
Right subtree → values > root

Example:

        2
       / \
      1   3

Insert: 4

Result:

        2
       / \
      1   3
             \
              4
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

BST gives us direction:

• If key < root → go LEFT
• If key > root → go RIGHT

We keep moving until we find NULL,
then insert new node there.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
If root is NULL → create new node

STEP 2:
If key < root->data:
    insert in left subtree

STEP 3:
If key > root->data:
    insert in right subtree

STEP 4:
Return root
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

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
public:

    Node* insert(Node* root, int key) {

        // If tree empty → create node
        if (!root)
            return new Node(key);

        // Go left
        if (root->data > key)
            root->left = insert(root->left, key);

        // Go right
        else
            root->right = insert(root->right, key);

        return root;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        2
       / \
      1   3

Insert key = 4

Step 1:
4 > 2 → go right

Step 2:
4 > 3 → go right

Step 3:
NULL → insert 4

Final tree:

        2
       / \
      1   3
             \
              4
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

1) BST property guides traversal

2) Always insert at leaf position

3) Recursive approach is clean

4) Iterative approach also possible

5) Worst case occurs when tree is skewed

6) Important for building BST operations:

   • Search
   • Delete
   • Insert

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
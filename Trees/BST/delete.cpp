/*
============================================================
DELETE A NODE IN BINARY SEARCH TREE (BST)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a Binary Search Tree (BST) and a value x,
delete the node with value x and return the updated root.

If the value does not exist, the tree remains unchanged.

BST Property:

Left subtree  → values < root
Right subtree → values > root
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

Deletion in BST has 3 important cases:

CASE 1: Leaf Node
• Node has no children
• Simply delete it

CASE 2: Node with One Child
• Replace node with its child

CASE 3: Node with Two Children
• Replace node with:
  - Inorder Predecessor (maximum in left subtree)
  OR
  - Inorder Successor (minimum in right subtree)

In this implementation, we use the maximum from the left subtree.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Search for the node using BST property

STEP 2:
If node is found:

CASE 1:
If leaf node → delete and return NULL

CASE 2:
If only one child → return that child

CASE 3:
If two children:
  • Find maximum in left subtree
  • Replace root with that node
  • Fix pointers accordingly

STEP 3:
Return updated root
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

    Node* delNode(Node* root, int x) {

        // Base case
        if (!root)
            return NULL;

        // Search node
        if (root->data > x) {
            root->left = delNode(root->left, x);
            return root;
        }
        else if (root->data < x) {
            root->right = delNode(root->right, x);
            return root;
        }

        // Node found

        // CASE 1: Leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // CASE 2: Only left child
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // CASE 2: Only right child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // CASE 3: Both children exist
        else {

            // Find rightmost node in left subtree
            Node* child = root->left;
            Node* parent = root;

            while (child->right) {
                parent = child;
                child = child->right;
            }

            // Replace root with child
            if (parent != root) {
                parent->right = child->left;

                child->left = root->left;
                child->right = root->right;

                delete root;
                return child;
            }
            else {
                child->right = root->right;

                delete root;
                return child;
            }
        }
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        20
       /  \
     10    50
       \
       18

Delete 20

Step 1:
Node has two children

Step 2:
Find maximum in left subtree → 18

Step 3:
Replace 20 with 18

New Tree:

        18
       /  \
     10    50
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Average: O(log n)

Worst case:
O(n)
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

h = height of tree
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Three cases must be handled properly

2) Two children case is most important

3) Can use either:
   • Inorder predecessor (left max)
   • Inorder successor (right min)

4) Pointer handling is critical

5) Very commonly asked BST problem

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
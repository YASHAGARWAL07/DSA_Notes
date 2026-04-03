/*
============================================================
LOWEST COMMON ANCESTOR (LCA) IN BINARY TREE
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a binary tree and two nodes p and q,
find their Lowest Common Ancestor (LCA).

Definition:

LCA is the lowest node in the tree that has
both p and q as descendants.

Note:
A node can be a descendant of itself.

Example:

        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

p = 5, q = 1

Output: 3
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We use recursion (DFS).

Key idea:

• If current node is p or q → return it
• Check left subtree
• Check right subtree

Cases:

1) If both left and right return non-null
   → current node is LCA

2) If only one side returns non-null
   → return that side

3) If both null → return null
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
If root is NULL → return NULL

STEP 2:
If root == p OR root == q → return root

STEP 3:
Recurse left and right

STEP 4:
If both left and right are NOT NULL
→ return root (LCA found)

STEP 5:
If only one is NOT NULL
→ return that one

STEP 6:
Else return NULL
*/


/*
============================================================
4. C++ IMPLEMENTATION
============================================================
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (!root)
            return NULL;

        // If current node is p or q
        if (root == p || root == q)
            return root;

        // Search in left and right
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null → LCA
        if (leftLCA && rightLCA)
            return root;

        // Otherwise return non-null side
        if (leftLCA)
            return leftLCA;
        else
            return rightLCA;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        3
       / \
      5   1

p = 5, q = 1

Step 1:
At root (3)

Step 2:
Left returns 5
Right returns 1

Step 3:
Both non-null → return 3

Answer = 3
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n)

Visit all nodes once
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

Recursive stack

Worst case:
O(n)

Balanced:
O(log n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Works for general Binary Tree (not BST)

2) Node itself can be LCA

3) Post-order traversal concept

4) Very important recursion pattern

5) Variation:

   • LCA in BST (optimized using BST property)

6) Key logic:

   left != NULL AND right != NULL → LCA

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/

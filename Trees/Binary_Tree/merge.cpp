/*
============================================================
MERGE TWO BINARY TREES
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given two binary trees root1 and root2,
merge them into a single binary tree.

Rules:

1) If both nodes exist → add their values
2) If only one node exists → take that node
3) If both are NULL → return NULL

Example:

Tree 1:              Tree 2:

    1                    2
   / \                  / \
  3   2                1   3
 /                      \   \
5                        4   7

Merged Tree:

        3
       / \
      4   5
     / \   \
    5   4   7
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We traverse both trees simultaneously.

At each node:

• Add values if both nodes exist
• If one is NULL → use the other node
• Recursively merge left and right children

This is a classic DFS recursion problem.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
If both nodes are NULL → return NULL

STEP 2:
Calculate value:
val = (root1 ? root1->val : 0) +
      (root2 ? root2->val : 0)

STEP 3:
Create new node with this value

STEP 4:
Recursively merge left subtree

STEP 5:
Recursively merge right subtree

STEP 6:
Return merged root
*/


/*
============================================================
4. C++ IMPLEMENTATION
============================================================
*/

/**
 * Definition for a binary tree node.
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

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // Base case
        if (!root1 && !root2)
            return NULL;

        // Calculate value
        int val = 0;

        if (root1)
            val += root1->val;

        if (root2)
            val += root2->val;

        // Create new node
        TreeNode* root = new TreeNode(val);

        // Merge left subtree
        root->left = mergeTrees(
            root1 ? root1->left : NULL,
            root2 ? root2->left : NULL
        );

        // Merge right subtree
        root->right = mergeTrees(
            root1 ? root1->right : NULL,
            root2 ? root2->right : NULL
        );

        return root;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree 1:        Tree 2:

    1              2
   /              /
  3              1

Step 1:
1 + 2 = 3 → root

Step 2:
3 + 1 = 4 → left child

Step 3:
Remaining nodes handled recursively

Final Tree:

    3
   /
  4
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n)

Where n = number of nodes

We visit each node once
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

h = height of tree

Worst case (skewed):
O(n)

Balanced tree:
O(log n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Classic DFS recursion problem

2) Handle NULL carefully

3) Ternary operator helps simplify code:
   (root1 ? root1->left : NULL)

4) Can also be solved IN-PLACE
   (modify root1 instead of creating new tree)

5) Common variations:

   • Merge k trees
   • Sum of two trees
   • Tree transformation problems

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
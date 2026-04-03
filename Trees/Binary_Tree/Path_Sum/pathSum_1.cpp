/*
============================================================
PATH SUM IN BINARY TREE
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a binary tree and an integer targetSum,
determine if the tree has a root-to-leaf path such that
adding up all the values along the path equals targetSum.

Important:

• Path must start from ROOT
• Path must end at a LEAF node

Example:

            5
          /   \
         4     8
        /     / \
       11    13  4
      /  \        \
     7    2        1

targetSum = 22

Valid Path:
5 → 4 → 11 → 2 = 22

Output: TRUE
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We traverse from root to leaf using DFS.

At each node:

• Subtract node value from targetSum
• Pass remaining sum to children

At leaf node:

• If remaining sum equals node value → path exists
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
If root is NULL → return false

STEP 2:
If leaf node:
check targetSum == root->val

STEP 3:
Reduce targetSum:
targetSum = targetSum - root->val

STEP 4:
Recurse on left and right subtree

STEP 5:
Return true if any path is valid
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

    bool hasPathSum(TreeNode* root, int targetSum) {

        if (!root)
            return false;

        if (!root->left && !root->right)
            return (targetSum == root->val);

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        1
       / \
      2   3

targetSum = 3

Step 1:
root = 1 → remaining = 3 - 1 = 2

Step 2:
Go left (2) → remaining = 2 - 2 = 0

Leaf reached:
0 == 0 → TRUE

Final Answer: TRUE
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n)

We visit every node once
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

Worst case (skewed tree):
O(n)

Balanced tree:
O(log n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Path must be ROOT → LEAF

2) Do NOT check sum at non-leaf nodes

3) Always subtract current node value

4) Leaf node condition is critical

5) DFS recursion pattern problem

6) Edge case:
   Empty tree → false

7) Variations:

   • Path Sum II
   • Path Sum III
   • Maximum Path Sum

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
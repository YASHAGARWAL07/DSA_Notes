/*
============================================================
MAXIMUM DEPTH OF BINARY TREE
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a binary tree, find its maximum depth.

Maximum depth = number of nodes along the
longest path from root to any leaf node.


Example:

        1
       / \
      2   3
     /
    4

Maximum depth = 3 (path: 1 → 2 → 4)
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

At each node:

Depth = 1 + max(left subtree depth,
                right subtree depth)

We recursively compute depth
for left and right children.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return 0

Step 2:
Recursively find:
leftDepth = maxDepth(root->left)
rightDepth = maxDepth(root->right)

Step 3:
Return:
1 + max(leftDepth, rightDepth)
*/


/*
------------------------------------------------------------
4. C++ IMPLEMENTATION
------------------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        return max(maxDepth(root->left),
                   maxDepth(root->right)) + 1;
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
     /
    4

Node 4 → depth = 1

Node 2:
max(1,0) + 1 = 2

Node 3:
depth = 1

Node 1:
max(2,1) + 1 = 3

Final Answer: 3
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case (skewed tree): O(n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Classic recursion problem

2. Base condition:
   return 0 for NULL

3. Very important pattern:
   height of tree

4. Used in:
   - Balanced tree
   - Diameter of tree
   - Path problems

5. Easy but frequently asked
*/


/*
------------------------------------------------------------
9. COMPARISON WITH MIN DEPTH
------------------------------------------------------------

Max Depth:
max(left, right)

Min Depth:
special handling of NULL child

Key difference:
Min depth cannot blindly use min()
*/


/*
============================================================
END OF FILE
============================================================
*/
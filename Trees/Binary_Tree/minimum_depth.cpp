/*
============================================================
MINIMUM DEPTH OF BINARY TREE
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a binary tree, find its minimum depth.

Minimum depth = number of nodes along the
shortest path from root node to the nearest leaf node.

Note:
A leaf node is a node with NO children.


Example:

        1
       / \
      2   3
     /
    4

Minimum depth = 2 (path: 1 → 3)
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We need the shortest path to a leaf.

Important observation:

If a node has only ONE child,
we cannot take min of both sides blindly.

Because one side might be NULL (depth = 0),
which gives wrong answer.

So:
We must handle single-child cases separately.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return 0

Step 2:
If left subtree is NULL →
return depth of right subtree + 1

Step 3:
If right subtree is NULL →
return depth of left subtree + 1

Step 4:
If both exist →
return min(left, right) + 1
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
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        // If left is NULL → must go right
        if(root->left == NULL)
            return minDepth(root->right) + 1;

        // If right is NULL → must go left
        if(root->right == NULL)
            return minDepth(root->left) + 1;

        // Both exist → take minimum
        return min(minDepth(root->left),
                   minDepth(root->right)) + 1;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        1
       /
      2
     /
    3

Wrong logic (if using min blindly):
min(0, depth) → wrong

Correct logic:

Node 3 → depth = 1

Node 2:
left exists → depth = 2

Node 1:
left exists → depth = 3


Example 2:

        1
       / \
      2   3

min(1,1) + 1 = 2
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

Worst case: O(n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Do NOT use:
   min(left, right) directly

2. Always handle:
   - left NULL
   - right NULL

3. This is a classic trick question

4. Very common in interviews

5. Similar problems:
   - Maximum depth
   - Diameter of tree
*/


/*
============================================================
END OF FILE
============================================================
*/
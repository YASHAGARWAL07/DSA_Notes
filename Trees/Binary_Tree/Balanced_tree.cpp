/*
============================================================
BALANCED BINARY TREE (HEIGHT BASED APPROACH)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a binary tree, determine whether it is
height-balanced.

A binary tree is balanced if:

For every node,
|height(left) - height(right)| <= 1


Example:

        1
       / \
      2   3
     / \
    4   5

Balanced → YES
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We need to check height difference at every node.

Naive approach:
→ Calculate height separately for each node → O(n^2)

Optimized approach:
→ Calculate height + check balance in one recursion
→ Use a flag to track imbalance
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
Create a function height()

Step 2:
Recursively find:
    left height (L)
    right height (R)

Step 3:
If abs(L - R) > 1 → tree is NOT balanced

Step 4:
Return height = 1 + max(L, R)

Step 5:
Use a reference variable "valid" to track result
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


int height(TreeNode* root, int &valid){
    if(!root)
        return 0;

    int L = height(root->left, valid);
    int R = height(root->right, valid);

    // check balance condition
    if(abs(L - R) > 1)
        valid = 0;

    return 1 + max(L, R);
}


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int valid = 1;
        height(root, valid);
        return valid;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Example:

        1
       / \
      2   3
     /
    4

Node 4 → height = 1

Node 2:
L = 1, R = 0 → diff = 1 → OK

Node 1:
L = 2, R = 1 → diff = 1 → OK

Result → Balanced


Unbalanced Example:

        1
       /
      2
     /
    3

Node 1:
L = 2, R = 0 → diff = 2 → NOT balanced
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

Recursive stack height

Space Complexity: O(h)

Worst case (skewed tree): O(n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. This is optimized approach (single traversal)

2. Avoid O(n^2) approach (recomputing height)

3. Combine:
   → height calculation
   → balance checking

4. Using reference variable avoids extra work

5. Very frequently asked question (LeetCode Easy)
*/


/*
============================================================
END OF FILE
============================================================
*/
/*
============================================================
MINIMUM DISTANCE BETWEEN BST NODES
============================================================
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a Binary Search Tree (BST),
find the minimum difference between values
of any two different nodes.

Example:

        4
       / \
      2   6
     / \
    1   3

Output: 1
(Because minimum difference is between 2 & 3 or 3 & 4)
*/


/*
------------------------------------------------------------
2. KEY OBSERVATION (VERY IMPORTANT)
------------------------------------------------------------

Inorder Traversal of BST gives SORTED ORDER.

Example:

Inorder → 1 2 3 4 6

Now minimum difference will ALWAYS be between
ADJACENT elements in sorted array.

So instead of checking all pairs,
we only check consecutive elements.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Perform inorder traversal

STEP 2:
Store values in array

STEP 3:
Traverse array and compute:

diff = nodes[i+1] - nodes[i]

STEP 4:
Take minimum of all differences

STEP 5:
Return answer
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

    // Inorder traversal
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root)
            return;

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    int minDiffInBST(TreeNode* root) {

        vector<int> nodes;

        // Step 1: Get sorted values
        inorder(root, nodes);

        // Step 2: Find minimum difference
        int minDiff = INT_MAX;

        for (int i = 0; i < nodes.size() - 1; i++) {
            int diff = nodes[i+1] - nodes[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        4
       / \
      2   6
     / \
    1   3

Inorder → 1 2 3 4 6

Differences:
2-1 = 1
3-2 = 1
4-3 = 1
6-4 = 2

Minimum = 1
*/


/*
------------------------------------------------------------
6. OPTIMIZED APPROACH (IMPORTANT FOR INTERVIEW)
------------------------------------------------------------

Instead of storing array:

• Keep track of previous node
• Calculate difference on the fly

This reduces space complexity
*/


/*
------------------------------------------------------------
7. OPTIMIZED CODE (NO EXTRA ARRAY)
------------------------------------------------------------
*/

class OptimizedSolution {
public:

    int minDiff = INT_MAX;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }

        prev = root;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};


/*
------------------------------------------------------------
8. TIME COMPLEXITY
------------------------------------------------------------

O(n)

We visit each node once
*/


/*
------------------------------------------------------------
9. SPACE COMPLEXITY
------------------------------------------------------------

Using array → O(n)

Optimized → O(h)
(h = height of tree)
*/


/*
------------------------------------------------------------
10. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Inorder traversal of BST = sorted order

2) Minimum difference always between adjacent elements

3) Optimized solution avoids extra space

4) Classic BST + traversal problem

------------------------------------------------------------
END
------------------------------------------------------------
*/

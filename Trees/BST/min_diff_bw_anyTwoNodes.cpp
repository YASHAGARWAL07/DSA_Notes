/*
============================================================
MINIMUM DIFFERENCE BETWEEN BST NODES
============================================================
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM
------------------------------------------------------------

Given a Binary Search Tree (BST), find the minimum
difference between values of any two different nodes.
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

Inorder traversal of BST gives values in sorted order.

So minimum difference will always be between
adjacent elements in this sorted order.
*/


/*
------------------------------------------------------------
3. APPROACH
------------------------------------------------------------

1) Perform inorder traversal
2) Store values in vector
3) Compare adjacent elements
4) Return minimum difference
*/


/*
------------------------------------------------------------
4. TREE NODE DEFINITION
------------------------------------------------------------
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};


/*
------------------------------------------------------------
5. CODE
------------------------------------------------------------
*/

void inorder(TreeNode* root, vector<int>& nodes) {
    if (!root)
        return;

    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

class Solution {
public:
    int minDiffInBST(TreeNode* root) {

        vector<int> nodes;

        inorder(root, nodes);

        int minm = INT_MAX;

        for (int i = 0; i < nodes.size() - 1; i++) {
            int diff = nodes[i+1] - nodes[i];
            minm = min(minm, diff);
        }

        return minm;
    }
};


/*
------------------------------------------------------------
6. DRY RUN
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

Minimum difference = 1
*/


/*
------------------------------------------------------------
7. OPTIMIZED CODE
------------------------------------------------------------

Instead of using vector, we track previous node
*/

class Solution2 {
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
8. COMPLEXITY
------------------------------------------------------------

Time  → O(n)

Space → O(n) using vector
        O(h) optimized (recursion stack)
*/
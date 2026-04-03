/*
============================================================
BINARY TREE PATHS
============================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a binary tree, return all root-to-leaf
paths in any order.

A leaf node is a node with no children.

Example:

        1
       / \
      2   3
       \
        5

Output:

["1->2->5", "1->3"]
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We need to generate paths from ROOT to every LEAF.

Idea:

• Use DFS traversal
• Maintain a string (path)
• Add current node value to path
• When leaf is reached → store path

Key idea:
Build path while going down the tree
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Start from root

STEP 2:
Keep adding node values to path string

STEP 3:
If leaf node:
store path in answer

STEP 4:
Recurse left and right

STEP 5:
Return all paths
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


void allPaths(TreeNode* root, string path, vector<string>& ans)
{
    // Leaf node
    if (!root->left && !root->right)
    {
        ans.push_back(path);
        return;
    }

    // Go left
    if (root->left)
        allPaths(root->left, path + "->" + to_string(root->left->val), ans);

    // Go right
    if (root->right)
        allPaths(root->right, path + "->" + to_string(root->right->val), ans);
}


class Solution {
public:

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        if (!root)
            return ans;

        string path = to_string(root->val);

        allPaths(root, path, ans);

        return ans;
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
       \
        5

Start:

path = "1"

Go left:
path = "1->2"

Go right:
path = "1->2->5" → leaf → store

Go right of root:
path = "1->3" → leaf → store

Final Answer:

["1->2->5", "1->3"]
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

h = height of tree

Extra space for storing paths
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Path must be ROOT → LEAF

2) Use DFS traversal

3) Use string to store path

4) No need for explicit backtracking
   (string is passed by value)

5) Similar problems:

   • Path Sum I (boolean)
   • Path Sum II (store paths with sum)
   • Path Sum III (count paths)

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
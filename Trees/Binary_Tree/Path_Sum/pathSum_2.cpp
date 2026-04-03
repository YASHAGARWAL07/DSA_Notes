/*
============================================================
PATH SUM II (ALL ROOT TO LEAF PATHS)
============================================================
*/

#include <iostream>
#include <vector>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a binary tree and an integer targetSum,
return ALL root-to-leaf paths where the sum of node values
equals targetSum.

Important:

• Path must start from ROOT
• Path must end at a LEAF node
• Return all valid paths

Example:

            5
          /   \
         4     8
        /     / \
       11    13  4
      /  \        \
     7    2        1

targetSum = 22

Output:

[5,4,11,2]
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

This is an extension of Path Sum I.

Instead of just checking TRUE/FALSE:

• We store the entire path
• Use backtracking to explore all paths

Key idea:

• Keep a temporary vector (path)
• Add node while going down
• Remove node while backtracking
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Start from root with empty path

STEP 2:
Add current node to path

STEP 3:
If leaf node AND sum matches:
store path in answer

STEP 4:
Recurse left and right

STEP 5:
Backtrack (remove last node)

STEP 6:
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


void sum(TreeNode *root, int targetSum,
         vector<vector<int>>& ans,
         vector<int> temp)
{
    if (!root)
        return;

    // Add current node
    temp.push_back(root->val);

    // Check leaf node and sum
    if (!root->left && !root->right && targetSum == root->val)
        ans.push_back(temp);

    // Recurse
    sum(root->left, targetSum - root->val, ans, temp);
    sum(root->right, targetSum - root->val, ans, temp);

    // Backtracking (not required here due to pass-by-value,
    // but kept for clarity)
    temp.pop_back();
}


class Solution {
public:

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> temp;

        sum(root, targetSum, ans, temp);

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

targetSum = 3

Path 1:
1 → 2 = 3 → valid

Path 2:
1 → 3 = 4 → invalid

Output:

[1,2]
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n)

Each node is visited once

In worst case:
copying path adds extra cost
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

h = height of tree

Recursive stack space

Worst case:
O(n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Backtracking problem

2) Difference from Path Sum I:
   • Return all paths instead of boolean

3) temp vector stores current path

4) Pass-by-value makes code simpler
   (no manual backtracking needed)

5) Optimization:
   Pass temp by reference for better performance

6) Classic DFS + Backtracking pattern

7) Variations:

   • Path Sum I → boolean
   • Path Sum III → any path (not root only)

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
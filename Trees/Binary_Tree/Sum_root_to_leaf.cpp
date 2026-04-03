 /*
============================================================
SUM ROOT TO LEAF NUMBERS
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a binary tree where each node contains digits (0–9),
each root-to-leaf path represents a number.

Return the total sum of all root-to-leaf numbers.

Example:

        1
       / \
      2   3

Paths:

1 → 2 = 12
1 → 3 = 13

Answer = 12 + 13 = 25
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We build numbers while moving from root to leaf.

At each node:

• Multiply current number by 10
• Add current node value

Example:

Path: 1 → 2 → 3

Steps:
1 → 1
1 → 2 → 12
12 → 3 → 123

At leaf → add number to final sum
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Start from root with curr = 0

STEP 2:
At each node:
curr = curr * 10 + node->val

STEP 3:
If leaf node:
add curr to total sum

STEP 4:
Recurse left and right

STEP 5:
Return total sum
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


void totalSum(TreeNode* root, int &sum, int curr)
{
    if (!root)
        return;

    // Build number
    curr = curr * 10 + root->val;

    // If leaf node → add to sum
    if (!root->left && !root->right)
    {
        sum += curr;
        return;
    }

    // Recurse
    totalSum(root->left, sum, curr);
    totalSum(root->right, sum, curr);
}


class Solution {
public:

    int sumNumbers(TreeNode* root) {

        int curr = 0;
        int sum = 0;

        totalSum(root, sum, curr);

        return sum;
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

Start:

curr = 0

At 1:
curr = 1

Go left (2):
curr = 12 → leaf → sum = 12

Go right (3):
curr = 13 → leaf → sum = 12 + 13 = 25

Final Answer = 25
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n)

Each node is visited once
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

h = height of tree

Worst case:
O(n)

Balanced tree:
O(log n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Build number using:
   curr = curr * 10 + val

2) Only add at LEAF nodes

3) No need for backtracking
   (curr passed by value)

4) Classic DFS pattern

5) Similar problems:

   • Binary Tree Paths
   • Path Sum I / II
   • Sum of left leaves

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
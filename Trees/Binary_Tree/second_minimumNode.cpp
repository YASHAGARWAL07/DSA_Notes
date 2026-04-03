/*
============================================================
SECOND MINIMUM NODE IN A BINARY TREE
============================================================
*/

#include <iostream>
#include <climits>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a special binary tree:

• Each node has either 0 or 2 children
• If a node has 2 children:
  root->val = min(left->val, right->val)

Find the SECOND MINIMUM value in the tree.

If it does not exist, return -1.

Example:

        2
       / \
      2   5
         / \
        5   7

Output: 5
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

Important property:

👉 Root always has the SMALLEST value

So:

• First minimum = root->val
• We need the smallest value GREATER than root

Idea:

Traverse entire tree and track:

• min1 → smallest (root value)
• min2 → second smallest
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Initialize:

min1 = root->val
min2 = infinity

STEP 2:
Traverse the tree

STEP 3:
For each node:

if (node->val > min1 AND node->val < min2)
    update min2

STEP 4:
Traverse left and right

STEP 5:
If min2 unchanged → return -1
Else return min2
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


void secMin(TreeNode *root, long min1, long &min2)
{
    if (!root)
        return;

    // Update second minimum
    if (root->val > min1 && root->val < min2)
        min2 = root->val;

    // Traverse
    secMin(root->left, min1, min2);
    secMin(root->right, min1, min2);
}


class Solution {
public:

    int findSecondMinimumValue(TreeNode* root) {

        long min1 = root->val;
        long min2 = LONG_MAX;

        secMin(root, min1, min2);

        return (min2 == LONG_MAX) ? -1 : min2;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        2
       / \
      2   5
         / \
        5   7

Step 1:
min1 = 2

Step 2:
Traverse:

Node 2 → ignore
Node 5 → min2 = 5
Node 7 → ignore (7 > 5)

Final Answer = 5
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n)

Visit all nodes once
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

O(h)

Recursive stack

Worst case:
O(n)

Balanced:
O(log n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Root always contains minimum value

2) Find smallest value greater than root

3) Use LONG_MAX for safe comparison

4) Traversal required (DFS)

5) If all values same → return -1

6) Can be optimized using tree property
   (skip unnecessary branches)

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
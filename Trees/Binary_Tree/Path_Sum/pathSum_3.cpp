/*
============================================================
PATH SUM III
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a binary tree and an integer targetSum,
return the number of paths where the sum of values equals
targetSum.

Important:

• Path can start from ANY node
• Path must go DOWNWARD (parent → child)
• Path does NOT need to end at leaf

Example:

        10
       /  \
      5   -3
     / \    \
    3   2    11

targetSum = 8

Valid Paths:

5 → 3 = 8
5 → 2 → 1 = 8
-3 → 11 = 8

Output: 3
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

At every node, we try to find all paths starting from that node.

Idea:

• Start a path from current node
• Keep adding values (currSum)
• If currSum == targetSum → count++

But we must also try starting from EVERY node,
not just the root.

So:

1) Count paths starting from current node
2) Move to left subtree
3) Move to right subtree
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
Create a helper function (findSum)

STEP 2:
In helper:
• Add current node value to currSum
• If currSum == targetSum → increase count
• Recurse left and right

STEP 3:
In main function:

• Call helper for current node
• Recursively call for left subtree
• Recursively call for right subtree

STEP 4:
Return total count
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


void findSum(TreeNode *root, int targetSum, long currSum, int &total)
{
    if (!root)
        return;

    // Add current node value
    currSum += root->val;

    // Check if path sum matches
    if (currSum == targetSum)
        total++;

    // Continue path
    findSum(root->left, targetSum, currSum, total);
    findSum(root->right, targetSum, currSum, total);
}


class Solution {
public:

    int pathSum(TreeNode* root, int targetSum) {

        if (!root)
            return 0;

        int total = 0;

        // Start path from current node
        findSum(root, targetSum, 0, total);

        // Try starting from left and right
        total += pathSum(root->left, targetSum);
        total += pathSum(root->right, targetSum);

        return total;
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

Paths:

Start from 1:
1 → 2 = 3 → valid

Start from 2:
2 ≠ 3 → invalid

Start from 3:
3 = 3 → valid

Total paths = 2
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

O(n²)

At each node we traverse subtree again

Worst case: skewed tree
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

1) Path can start from ANY node

2) Path must go downward only

3) Two recursive functions:

   • findSum → paths from one node
   • pathSum → try all nodes

4) This increases time complexity to O(n²)

5) Optimized solution exists using Prefix Sum (O(n))

6) Very important problem pattern:
   DFS + restart from every node

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
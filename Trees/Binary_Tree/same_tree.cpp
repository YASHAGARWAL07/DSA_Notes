/*
============================================================
SAME TREE (CHECK IF TWO BINARY TREES ARE IDENTICAL)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given two binary trees p and q,
check whether they are the same.

Two trees are considered identical if:

1. Their structure is same
2. Their corresponding node values are same


Example:

Tree 1:          Tree 2:

    1                1
   / \              / \
  2   3            2   3

Output: TRUE


Example 2:

    1                1
   /                  \
  2                    2

Output: FALSE
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We compare both trees node by node.

At every node:
1. If both nodes are NULL → valid
2. If one is NULL → not same
3. If values differ → not same

Then recursively check:
Left subtree and Right subtree
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

Recursive approach:

Step 1:
If both nodes are NULL → return true

Step 2:
If one node is NULL → return false

Step 3:
If values are different → return false

Step 4:
Recursively check:
left subtree AND right subtree

Return result
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: both NULL
        if(!p && !q)
            return true;

        // Case 2: one NULL
        if(p == NULL || q == NULL)
            return false;

        // Case 3: values not equal
        if(p->val != q->val)
            return false;

        // Recursive check
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree 1:       Tree 2:

    1             1
   / \           / \
  2   3         2   3


Call stack:

compare(1,1) → equal

→ compare(2,2) → equal
→ compare(3,3) → equal

Final result: TRUE


Example 2:

compare(2,NULL) → false
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Each node is visited once

Time Complexity: O(n)

Where n = number of nodes
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

1. Always check NULL conditions first

2. Order of checks matters:
   → NULL check
   → value check
   → recursive calls

3. Use AND (&&) for both subtree checks

4. Very common tree recursion problem

5. Base template for:
   → tree comparison problems
*/


/*
============================================================
END OF FILE
============================================================
*/
/*
============================================================
CHECK COMPLETENESS OF A BINARY TREE
============================================================
*/

#include <iostream>
#include <queue>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given the root of a binary tree, check whether it is a
COMPLETE BINARY TREE.

Definition:

A binary tree is complete if:

1) All levels are completely filled except possibly the last
2) All nodes in the last level are as LEFT as possible

Example:

        1
       / \
      2   3
     / \  /
    4  5 6

Output: TRUE

Example (Not Complete):

        1
       / \
      2   3
     / \   \
    4  5    7

Output: FALSE
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We use LEVEL ORDER TRAVERSAL (BFS).

Key idea:

👉 Once we see a NULL node,
   all nodes after it must also be NULL

If we see a NON-NULL node after NULL → NOT complete
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

STEP 1:
If root is NULL → return true

STEP 2:
Use queue for BFS

STEP 3:
Traverse level order

STEP 4:
If node is NULL:
    mark flag (isseen = true)

STEP 5:
If node is NOT NULL:
    if flag already true → return false
    else push left and right

STEP 6:
If traversal completes → return true
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


class Solution {
public:

    bool isCompleteTree(TreeNode* root) {

        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);

        bool isseen = false;

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                isseen = true;
            }
            else
            {
                // If NULL was seen before, invalid
                if (isseen)
                    return false;

                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return true;
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
     / \  /
    4  5 6

Queue traversal:

1 → 2 → 3 → 4 → 5 → 6 → NULL → NULL ...

After first NULL:
all remaining must be NULL

Condition satisfied → TRUE


Example 2:

        1
       / \
      2   3
     / \   \
    4  5    7

Traversal:

1 → 2 → 3 → 4 → 5 → NULL → 7

Here:

NULL appears before 7 → INVALID

Return FALSE
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

O(n)

Queue stores nodes
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1) Use BFS (Level Order)

2) Key condition:
   After NULL → no non-null node allowed

3) Use flag (isseen)

4) Works for all tree shapes

5) Classic tree validation problem

6) Related problems:

   • Count Complete Tree Nodes
   • Maximum Width of Binary Tree

------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/

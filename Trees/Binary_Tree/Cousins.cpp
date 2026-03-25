/*
============================================================
COUSINS IN BINARY TREE
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
------------------------------------------------------------
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


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Two nodes in a binary tree are cousins if:

1. They are at the SAME depth
2. They have DIFFERENT parents

Return true if nodes x and y are cousins.
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

To check if two nodes are cousins:

1. Find depth of both nodes
2. Check if they are siblings

If:
depth(x) == depth(y)
AND
they are NOT siblings

→ they are cousins
*/


/*
------------------------------------------------------------
4. FIND DEPTH FUNCTION
------------------------------------------------------------
*/

int depth(TreeNode* root, int x, int d)
{
    if(!root)
        return -1;

    if(root->val == x)
        return d;

    int left = depth(root->left, x, d + 1);

    if(left != -1)
        return left;

    return depth(root->right, x, d + 1);
}


/*
------------------------------------------------------------
5. CHECK SIBLINGS
------------------------------------------------------------
*/

bool isSibling(TreeNode* root, int x, int y)
{
    if(!root)
        return false;

    if(root->left && root->right)
    {
        if((root->left->val == x && root->right->val == y) ||
           (root->left->val == y && root->right->val == x))
            return true;
    }

    return isSibling(root->left, x, y) ||
           isSibling(root->right, x, y);
}


/*
------------------------------------------------------------
6. MAIN FUNCTION
------------------------------------------------------------
*/

bool isCousins(TreeNode* root, int x, int y)
{
    int d1 = depth(root, x, 0);
    int d2 = depth(root, y, 0);

    if(d1 == d2 && !isSibling(root, x, y))
        return true;

    return false;
}


/*
------------------------------------------------------------
7. CREATE SAMPLE TREE
------------------------------------------------------------

        1
       / \
      2   3
     /     \
    4       5

4 and 5 are cousins
*/

TreeNode* createTree()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    return root;
}


/*
------------------------------------------------------------
8. MAIN DRIVER
------------------------------------------------------------
*/

int main()
{
    TreeNode* root = createTree();

    int x = 4, y = 5;

    if(isCousins(root, x, y))
        cout << "Cousins\n";
    else
        cout << "Not Cousins\n";

    return 0;
}


/*
------------------------------------------------------------
9. DRY RUN
------------------------------------------------------------

depth(4) = 2
depth(5) = 2

Check sibling:
4 and 5 → NOT siblings

Result → Cousins
*/


/*
------------------------------------------------------------
10. TIME COMPLEXITY
------------------------------------------------------------

Depth calculation → O(n)
Sibling check → O(n)

Total: O(n)
*/


/*
------------------------------------------------------------
11. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack

O(h) → worst case O(n)
*/


/*
------------------------------------------------------------
12. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Cousins = same depth + different parent

2. Two checks required:
   depth + sibling

3. Depth function returns -1 if node not found

4. Can also be solved using BFS (level order)

5. BFS solution is more optimal in interviews
*/


/*
============================================================
END OF FILE
============================================================
*/
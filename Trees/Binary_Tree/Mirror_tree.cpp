/*
============================================================
MIRROR BINARY TREE (INVERT BINARY TREE)
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
------------------------------------------------------------
*/

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Convert a binary tree into its mirror.

Mirror means:
Swap left and right child of every node.

Example:

Original:              Mirror:

    1                      1
   / \                    / \
  2   3        →         3   2
 / \                        / \
4   5                      5   4
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

At every node:

1. Swap left and right child
2. Recursively apply same for subtrees

This is a DFS problem.
*/


/*
------------------------------------------------------------
4. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return

Step 2:
Swap left and right child

Step 3:
Recursively call on left subtree

Step 4:
Recursively call on right subtree
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION
------------------------------------------------------------
*/

void mirror(Node* root)
{
    if(root == NULL)
        return;

    // Swap children
    swap(root->left, root->right);

    // Recurse
    mirror(root->left);
    mirror(root->right);
}


/*
------------------------------------------------------------
6. CREATE SAMPLE TREE
------------------------------------------------------------

        1
       / \
      2   3
     / \   \
    4   5   6
*/

Node* createTree()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    return root;
}


/*
------------------------------------------------------------
7. INORDER PRINT (FOR VERIFICATION)
------------------------------------------------------------
*/

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


/*
------------------------------------------------------------
8. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    cout << "Inorder before mirror: ";
    inorder(root);

    mirror(root);

    cout << "\nInorder after mirror: ";
    inorder(root);

    return 0;
}


/*
------------------------------------------------------------
9. DRY RUN
------------------------------------------------------------

Node 1:
swap(2,3)

Node 3:
swap(NULL,6)

Node 2:
swap(4,5)

Final tree becomes mirror.
*/


/*
------------------------------------------------------------
10. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
11. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
12. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Simple DFS recursion

2. Key step:
   swap(root->left, root->right)

3. Order doesn't matter:
   swap before or after recursion both work

4. Very commonly asked problem

5. Also called:
   - Invert Binary Tree (LeetCode 226)
*/


/*
============================================================
END OF FILE
============================================================
*/
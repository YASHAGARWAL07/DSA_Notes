/*
============================================================
BOUNDARY TRAVERSAL OF BINARY TREE
============================================================
*/

#include <iostream>
#include <vector>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
------------------------------------------------------------
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Print the boundary of a binary tree in anti-clockwise order.

Boundary includes:

1. Root
2. Left boundary (excluding leaf nodes)
3. All leaf nodes (left to right)
4. Right boundary (excluding leaf nodes, reversed)


Example:

        1
       / \
      2   3
     / \   \
    4   5   6

Output:
1 2 4 5 6 3
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

Break the problem into 3 parts:

1. Left boundary
2. Leaf nodes
3. Right boundary (reverse order)

Important:
Avoid duplicate nodes (especially leaf nodes).
*/


/*
------------------------------------------------------------
4. LEFT BOUNDARY
------------------------------------------------------------

Exclude leaf nodes
Always prefer left, otherwise go right
*/

void left(Node *root, vector<int>& ans)
{
    if(!root || (!root->left && !root->right))
        return;

    ans.push_back(root->data);

    if(root->left)
        left(root->left, ans);
    else
        left(root->right, ans);
}


/*
------------------------------------------------------------
5. LEAF NODES
------------------------------------------------------------
*/

void leaf(Node *root, vector<int>& ans)
{
    if(!root)
        return;

    if(!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }

    leaf(root->left, ans);
    leaf(root->right, ans);
}


/*
------------------------------------------------------------
6. RIGHT BOUNDARY
------------------------------------------------------------

Add nodes in reverse order
*/

void right(Node *root, vector<int>& ans)
{
    if(!root || (!root->left && !root->right))
        return;

    if(root->right)
        right(root->right, ans);
    else
        right(root->left, ans);

    ans.push_back(root->data);
}


/*
------------------------------------------------------------
7. MAIN FUNCTION
------------------------------------------------------------
*/

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;

    if(!root)
        return ans;

    // Add root
    ans.push_back(root->data);

    // Left boundary
    left(root->left, ans);

    // Leaf nodes
    if(root->left || root->right)
        leaf(root, ans);

    // Right boundary
    right(root->right, ans);

    return ans;
}


/*
------------------------------------------------------------
8. CREATE SAMPLE TREE
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
9. MAIN DRIVER
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}


/*
------------------------------------------------------------
10. DRY RUN
------------------------------------------------------------

Root: 1

Left boundary:
2

Leaf nodes:
4, 5, 6

Right boundary (reverse):
3

Final:
1 2 4 5 6 3
*/


/*
------------------------------------------------------------
11. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
12. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
13. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Divide into 3 parts:
   left + leaf + right

2. Avoid duplicate nodes

3. Right boundary must be reversed

4. Leaf nodes must be printed left to right

5. Very common tree traversal problem
*/


/*
============================================================
END OF FILE
============================================================
*/
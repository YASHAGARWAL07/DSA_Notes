/*
============================================================
COUNT NON-LEAF NODES IN BINARY TREE
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. NODE STRUCTURE
------------------------------------------------------------
*/

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Count the number of NON-LEAF nodes in a binary tree.

Non-leaf node:
A node having at least one child.

Leaf node:
A node with NO children.
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return 0

Step 2:
If node is leaf → return 0

Step 3:
Otherwise:
Count this node + left subtree + right subtree

Return:
1 + left_count + right_count
*/


/*
------------------------------------------------------------
4. IMPLEMENTATION
------------------------------------------------------------
*/

int countNonLeafNodes(Node* root)
{
    if(root == NULL)
        return 0;

    // If leaf node → do not count
    if(root->left == NULL && root->right == NULL)
        return 0;

    return 1
        + countNonLeafNodes(root->left)
        + countNonLeafNodes(root->right);
}


/*
------------------------------------------------------------
5. CREATE SAMPLE TREE
------------------------------------------------------------

        1
       / \
      2   3
     / \   \
    4   5   6

Non-leaf nodes: 1, 2, 3 → count = 3
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
6. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    int result = countNonLeafNodes(root);

    cout << "Number of Non-Leaf Nodes: " << result << endl;

    return 0;
}


/*
------------------------------------------------------------
7. DRY RUN
------------------------------------------------------------

Node 4 → leaf → not counted
Node 5 → leaf → not counted
Node 6 → leaf → not counted

Node 2 → non-leaf → count = 1
Node 3 → non-leaf → count = 2
Node 1 → non-leaf → count = 3

Final Answer: 3
*/


/*
------------------------------------------------------------
8. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
9. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
10. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Leaf condition:
   left == NULL && right == NULL

2. Non-leaf:
   at least one child exists

3. This is DFS traversal

4. Can also solve using BFS

5. Related problems:
   - Count leaf nodes
   - Count total nodes
   - Height of tree
*/


/*
============================================================
END OF FILE
============================================================
*/
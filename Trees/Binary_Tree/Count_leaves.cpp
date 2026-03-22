/*
============================================================
COUNT LEAF NODES IN BINARY TREE
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
2. CORE FUNCTION
------------------------------------------------------------

A leaf node is a node with:
left == NULL AND right == NULL
*/

void tcount(Node* root, int &count)
{
    if(root == NULL)
        return;

    // Check leaf node
    if(root->left == NULL && root->right == NULL)
        count++;

    tcount(root->left, count);
    tcount(root->right, count);
}


/*
------------------------------------------------------------
3. DRIVER FUNCTION
------------------------------------------------------------
*/

int countLeaves(Node* root)
{
    int count = 0;
    tcount(root, count);
    return count;
}


/*
------------------------------------------------------------
4. CREATE SAMPLE TREE
------------------------------------------------------------

        1
       / \
      2   3
     / \   \
    4   5   6

Leaf Nodes: 4, 5, 6 → count = 3
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
5. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    int result = countLeaves(root);

    cout << "Number of Leaf Nodes: " << result << endl;

    return 0;
}


/*
------------------------------------------------------------
6. DRY RUN
------------------------------------------------------------

Node 4 → leaf → count = 1
Node 5 → leaf → count = 2
Node 6 → leaf → count = 3

Final Answer: 3
*/


/*
------------------------------------------------------------
7. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
8. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
9. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Leaf condition:
   left == NULL AND right == NULL

2. Always check NULL first

3. This is DFS traversal

4. Can also be solved:
   → Iteratively using stack
   → Using BFS (queue)

5. Very common basic tree question
*/


/*
============================================================
END OF FILE
============================================================
*/
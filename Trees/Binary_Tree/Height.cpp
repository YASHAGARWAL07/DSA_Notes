/*
============================================================
HEIGHT OF BINARY TREE (GFG STYLE)
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

Find the height of a binary tree.

Height = number of edges in the longest
path from root to any leaf node.

NOTE (IMPORTANT):
GFG defines height as number of edges.

So:
NULL node → height = -1
Leaf node → height = 0
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

At each node:

Height = 1 + max(left height, right height)

We recursively compute height
for left and right subtrees.
*/


/*
------------------------------------------------------------
4. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return -1

Step 2:
Recursively compute:
leftHeight
rightHeight

Step 3:
Return:
max(leftHeight, rightHeight) + 1
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION
------------------------------------------------------------
*/

int height(Node* root)
{
    if(!root)
        return -1;   // GFG definition

    return max(height(root->left),
               height(root->right)) + 1;
}


/*
------------------------------------------------------------
6. CREATE SAMPLE TREE
------------------------------------------------------------

        1
       / \
      2   3
     /
    4

Height = 2 (edges: 1→2→4)
*/

Node* createTree()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    return root;
}


/*
------------------------------------------------------------
7. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    cout << "Height of Tree: " << height(root) << endl;

    return 0;
}


/*
------------------------------------------------------------
8. DRY RUN
------------------------------------------------------------

Node 4 → height = 0

Node 2:
max(0, -1) + 1 = 1

Node 3:
height = 0

Node 1:
max(1, 0) + 1 = 2

Final Answer: 2
*/


/*
------------------------------------------------------------
9. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
10. SPACE COMPLEXITY
------------------------------------------------------------

Recursive stack depth

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
11. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Two definitions of height:

GFG:
NULL → -1
Leaf → 0

LeetCode:
NULL → 0
Leaf → 1

2. Always clarify definition in interview

3. Height is used in:
   - Balanced Tree
   - Diameter of Tree
   - Depth problems

4. Very fundamental tree concept
*/


/*
------------------------------------------------------------
12. GFG vs LEETCODE DIFFERENCE
------------------------------------------------------------

GFG Height:
Edges count

LeetCode Height:
Nodes count

Example:

Single node tree:

GFG → 0
LeetCode → 1
*/


/*
============================================================
END OF FILE
============================================================
*/

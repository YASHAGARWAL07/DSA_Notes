/*
============================================================
TREE DATA STRUCTURE – COMPLETE NOTES
============================================================
*/

#include <iostream>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION TO TREE
------------------------------------------------------------

Tree is a non-linear hierarchical data structure that
represents parent-child relationships between nodes.

Unlike arrays or linked lists (linear structures),
trees store data in hierarchical form.

A Tree consists of:

Nodes  → Data elements
Edges  → Connection between nodes

Example:

            Movie
           /     \
      Bollywood  Hollywood
        /   \       /    \
     Action Romance Action Romance

Trees are widely used in:

1) File systems
2) Databases
3) DOM structure (HTML)
4) AI decision trees
5) Network routing
*/


/*
------------------------------------------------------------
2. BASIC TERMINOLOGY
------------------------------------------------------------

1) Node
Each element in a tree is called a node.

2) Root
Topmost node of the tree.

Example:

        1   ← Root

3) Parent
Node that has children.

4) Child
Node connected below a parent.

5) Leaf Node
Node that has no children.

6) Sibling
Nodes having the same parent.

7) Edge
Connection between two nodes.

8) Level
Distance of node from root.

9) Height
Longest path from root to leaf.

10) Degree
Number of children of a node.
*/


/*
------------------------------------------------------------
3. TREE STRUCTURE EXAMPLE
------------------------------------------------------------

Binary Tree Example:

                1
              /   \
             2     3
           /  \   /  \
          4    5 6    7
         / \  / \
        9 10 11 12

Explanation:

1 → Root

2 and 3 → Children of 1

4 and 5 → Children of 2

6 and 7 → Children of 3

Leaf Nodes:
9 10 11 12 6 7
*/


/*
------------------------------------------------------------
4. TYPES OF TREES
------------------------------------------------------------

1) Binary Tree
Each node has at most 2 children.

2) Binary Search Tree (BST)
Left subtree < root < right subtree

3) Balanced Tree
Height is minimized.

4) Complete Binary Tree
All levels filled except possibly last.

5) Full Binary Tree
Every node has either 0 or 2 children.

6) Perfect Binary Tree
All internal nodes have two children
and all leaves are at same level.
*/


/*
============================================================
5. TREE NODE IMPLEMENTATION
============================================================

Each node contains:

1) Data
2) Pointer to left child
3) Pointer to right child
*/

class Node
{
public:

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
============================================================
6. BUILDING A SIMPLE TREE
============================================================
*/

Node* createTree()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return root;
}


/*
------------------------------------------------------------
7. TREE TRAVERSALS
------------------------------------------------------------

Tree traversal means visiting every node
exactly once.

Types:

1) Inorder
Left → Root → Right

2) Preorder
Root → Left → Right

3) Postorder
Left → Right → Root
*/


/*
------------------------------------------------------------
INORDER TRAVERSAL
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
PREORDER TRAVERSAL
------------------------------------------------------------
*/

void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


/*
------------------------------------------------------------
POSTORDER TRAVERSAL
------------------------------------------------------------
*/

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}



/*
============================================================
8. TIME COMPLEXITY
============================================================

Traversal operations:

Inorder     → O(n)
Preorder    → O(n)
Postorder   → O(n)

n = number of nodes
*/


/*
============================================================
9. SPACE COMPLEXITY
============================================================

Recursive stack depends on tree height.

Worst case (skewed tree)

O(n)

Balanced tree

O(log n)
*/


/*
============================================================
10. IMPORTANT APPLICATIONS
============================================================

1) File system hierarchy

2) Binary Search Trees

3) Expression Trees

4) Decision Trees (Machine Learning)

5) Heaps (Priority Queue)

6) Network routing algorithms
*/


/*
============================================================
11. COMMON INTERVIEW QUESTIONS
============================================================

1) Tree Traversals

2) Height of Binary Tree

3) Diameter of Tree

4) Lowest Common Ancestor

5) Level Order Traversal

6) Balanced Binary Tree

7) Binary Search Tree validation
*/


/*
============================================================
12. MAIN FUNCTION
============================================================
*/

int main()
{
    Node* root = createTree();

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}


/*
============================================================
SUMMARY
============================================================

Tree is a hierarchical non-linear data structure.

Key Components:

Node
Root
Parent
Child
Leaf
Edge
Level
Height

Basic operations include:

Traversal
Insertion
Deletion
Searching

Trees are one of the most important data
structures used in:

Databases
Operating systems
Compilers
Artificial Intelligence

============================================================
END
============================================================
*/

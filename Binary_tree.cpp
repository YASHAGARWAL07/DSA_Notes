/*
============================================================
BINARY TREE – COMPLETE NOTES
============================================================
*/

#include <iostream>
#include <queue>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION TO BINARY TREE
------------------------------------------------------------

Binary Tree is a hierarchical data structure where
each node has at most TWO children.

These children are:

Left Child
Right Child

Example:

            1
          /   \
         2     3
        / \   / \
       4  5  6   7

Properties:

• Root is the topmost node
• Nodes are connected using edges
• Each node has max 2 children

Applications:

1) Binary Search Tree
2) Heap
3) Expression Trees
4) Huffman Coding
5) Decision Trees
*/


/*
------------------------------------------------------------
2. BASIC TERMINOLOGY
------------------------------------------------------------

Node
Each element in the tree.

Root
Topmost node.

Parent
Node having children.

Child
Node connected below parent.

Leaf Node
Node with no children.

Internal Node
Node having at least one child.

Sibling
Nodes having same parent.

Ancestor
Nodes above a given node.

Descendant
Nodes below a given node.

Edge
Connection between nodes.

Degree
Number of children of a node.

Level
Distance from root.

Height
Longest path from root to leaf.
*/


/*
------------------------------------------------------------
3. IMPORTANT BINARY TREE FORMULAS
------------------------------------------------------------

Let:

N = number of nodes
E = number of edges
H = height of tree
L = level number


1) TOTAL EDGES

E = N - 1

Example:
Nodes = 7
Edges = 6


2) MAXIMUM NODES AT LEVEL L

Max Nodes = 2^L

Example:

Level 0 → 1
Level 1 → 2
Level 2 → 4
Level 3 → 8


3) MAXIMUM NODES IN A BINARY TREE

Max Nodes = 2^(H+1) - 1

Example:

Height = 3

Max Nodes = 2^(4) - 1
Max Nodes = 16 - 1 = 15


4) MAXIMUM LEAF NODES

Leaf Nodes = 2^H


5) MINIMUM HEIGHT

H = log2(N)


6) MAXIMUM HEIGHT (SKEWED TREE)

H = N - 1
*/


/*
------------------------------------------------------------
4. TYPES OF BINARY TREES
------------------------------------------------------------

Full Binary Tree
Every node has either 0 or 2 children.

Complete Binary Tree
All levels filled except last.

Perfect Binary Tree
All internal nodes have 2 children
and all leaves at same level.

Balanced Binary Tree
Height difference ≤ 1

Skewed Binary Tree
Nodes arranged like linked list.
*/


/*
============================================================
5. NODE IMPLEMENTATION
============================================================
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
6. METHOD 1 – MANUAL TREE CREATION
============================================================
*/

Node* buildTreeExample()
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
============================================================
7. METHOD 2 – CREATE TREE USING RECURSION
============================================================

Input Format:

Preorder traversal with -1 for NULL

Example Input:

1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

Generated Tree:

            1
          /   \
         2     3
        / \     \
       4   5     6
*/

Node* createBinaryTree()
{
    int x;

    cin >> x;

    if(x == -1)
        return NULL;

    Node* temp = new Node(x);

    temp->left = createBinaryTree();
    temp->right = createBinaryTree();

    return temp;
}


/*
------------------------------------------------------------
8. TREE TRAVERSALS
------------------------------------------------------------

Traversal means visiting all nodes.

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
------------------------------------------------------------
LEVEL ORDER TRAVERSAL (BFS)
------------------------------------------------------------
*/

void levelOrder(Node* root)
{
    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}


/*
============================================================
9. TIME COMPLEXITY
============================================================

Tree Creation → O(n)

Traversals

Inorder → O(n)
Preorder → O(n)
Postorder → O(n)
Level Order → O(n)
*/


/*
============================================================
10. SPACE COMPLEXITY
============================================================

Recursive Stack

Worst Case (Skewed Tree)

O(n)

Balanced Tree

O(log n)
*/


/*
============================================================
11. IMPORTANT APPLICATIONS
============================================================

1) Binary Search Trees
2) Heap / Priority Queue
3) Expression Trees
4) Syntax Trees (Compiler)
5) Huffman Coding
6) Decision Trees
*/


/*
============================================================
12. COMMON INTERVIEW QUESTIONS
============================================================

1) Height of Binary Tree

2) Diameter of Binary Tree

3) Level Order Traversal

4) Lowest Common Ancestor

5) Balanced Binary Tree

6) ZigZag Traversal

7) Maximum Path Sum
*/


/*
============================================================
13. MAIN FUNCTION
============================================================
*/

int main()
{
    cout << "Example Tree Traversals\n";

    Node* root = buildTreeExample();

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);


    cout << "\n\nCreate Binary Tree (-1 for NULL):\n";

    Node* root2 = createBinaryTree();

    cout << "Inorder Traversal: ";
    inorder(root2);

    return 0;
}


/*
============================================================
SUMMARY
============================================================

Binary Tree is a hierarchical data structure.

Each node has at most two children.

Important formulas:

Edges = Nodes - 1
Max Nodes at level L = 2^L
Max Nodes in tree = 2^(H+1) - 1
Max Leaf Nodes = 2^H

Binary Tree creation methods:

1) Manual linking
2) Recursive creation using -1 input

Traversal types:

Inorder
Preorder
Postorder
Level Order

Binary Trees are the base for:

BST
Heap
AVL Tree
Segment Tree
Red Black Tree

============================================================
END
============================================================
*/

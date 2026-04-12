/*
============================================================
AVL TREE INSERTION (DETAILED IMPLEMENTATION)
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
    int height;

    Node(int val) {
        data = val;
        height = 1;
        left = right = NULL;
    }
};


/*
------------------------------------------------------------
2. GET HEIGHT
------------------------------------------------------------
*/

int getHeight(Node* root) {
    if (!root)
        return 0;

    return root->height;
}


/*
------------------------------------------------------------
3. GET BALANCE FACTOR
------------------------------------------------------------
*/

int getBalance(Node* root) {
    if (!root)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}


/*
------------------------------------------------------------
4. RIGHT ROTATION (LL CASE)
------------------------------------------------------------
*/

Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // update height
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}


/*
------------------------------------------------------------
5. LEFT ROTATION (RR CASE)
------------------------------------------------------------
*/

Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // update height
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}


/*
------------------------------------------------------------
6. INSERTION
------------------------------------------------------------
*/

Node* insert(Node* root, int key) {

    // doesn't exist
    if (!root)
        return new Node(key);

    // BST insertion
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // duplicate not allowed


    // update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));


    // get balance factor
    int balance = getBalance(root);


    /*
    --------------------------------------------------------
    ROTATION CASES
    --------------------------------------------------------
    */

    // LL Case
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


/*
------------------------------------------------------------
7. INORDER TRAVERSAL
------------------------------------------------------------
*/

void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


/*
------------------------------------------------------------
8. MAIN
------------------------------------------------------------
*/

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}


/*
------------------------------------------------------------
9. IMPORTANT POINTS
------------------------------------------------------------

1) Always update height after insertion

2) Balance factor decides rotation

3) 4 cases:
   LL → right rotate
   RR → left rotate
   LR → left + right rotate
   RL → right + left rotate

4) AVL ensures O(log n) height

------------------------------------------------------------
END
------------------------------------------------------------
*/
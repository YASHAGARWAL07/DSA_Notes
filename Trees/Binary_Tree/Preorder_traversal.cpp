/*
============================================================
PREORDER TRAVERSAL (RECURSIVE)
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


/*
------------------------------------------------------------
2. PREORDER FUNCTION
------------------------------------------------------------

ROOT → LEFT → RIGHT
*/

void preorder(TreeNode* root, vector<int>& ans)
{
    if(root == NULL)
        return;

    ans.push_back(root->val);

    preorder(root->left, ans);
    preorder(root->right, ans);
}


/*
------------------------------------------------------------
3. DRIVER FUNCTION
------------------------------------------------------------
*/

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}


/*
------------------------------------------------------------
4. PRINT FUNCTION
------------------------------------------------------------
*/

void printVector(vector<int>& v)
{
    for(int x : v)
        cout << x << " ";
    cout << endl;
}


/*
------------------------------------------------------------
5. CREATE SAMPLE TREE
------------------------------------------------------------

        1
       / \
      2   3
     / \
    4   5
*/

TreeNode* createTree()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}


/*
------------------------------------------------------------
6. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    TreeNode* root = createTree();

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal: ";
    printVector(result);

    return 0;
}


/*
============================================================
OUTPUT
============================================================

Preorder Traversal:
1 2 4 5 3

============================================================
END OF FILE
============================================================
*/
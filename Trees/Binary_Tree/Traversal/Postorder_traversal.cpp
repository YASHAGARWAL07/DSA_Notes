/*
============================================================
POSTORDER TRAVERSAL (RECURSIVE)
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
2. POSTORDER FUNCTION
------------------------------------------------------------

LEFT → RIGHT → ROOT
*/

void postorder(TreeNode* root, vector<int>& ans)
{
    if(root == NULL)
        return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}


/*
------------------------------------------------------------
3. DRIVER FUNCTION
------------------------------------------------------------
*/

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> ans;
    postorder(root, ans);
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

    vector<int> result = postorderTraversal(root);

    cout << "Postorder Traversal: ";
    printVector(result);

    return 0;
}


/*
============================================================
OUTPUT
============================================================

Postorder Traversal:
4 5 2 3 1

============================================================
END OF FILE
============================================================
*/
/*
============================================================
DIAGONAL TRAVERSAL OF BINARY TREE
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

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


/*
------------------------------------------------------------
2. PROBLEM STATEMENT
------------------------------------------------------------

Print the diagonal traversal of a binary tree.

Nodes having same diagonal distance
are grouped together.

Rule:

• Moving LEFT → diagonal + 1
• Moving RIGHT → same diagonal


Example:

        1
       / \
      2   3
     / \   \
    4   5   6

Output:
1 3 6 2 5 4
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

We assign a diagonal index:

Root → diagonal 0

Left child → diagonal + 1
Right child → same diagonal

Group nodes based on diagonal index.
*/


/*
------------------------------------------------------------
4. FIND MAX DIAGONAL INDEX
------------------------------------------------------------
*/

void find(Node *root, int pos, int &l)
{
    if(!root)
        return;

    l = max(l, pos);

    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}


/*
------------------------------------------------------------
5. STORE DIAGONAL VALUES
------------------------------------------------------------
*/

void findDia(Node *root, int pos, vector<vector<int>>& ans)
{
    if(!root)
        return;

    ans[pos].push_back(root->data);

    findDia(root->left, pos + 1, ans);
    findDia(root->right, pos, ans);
}


/*
------------------------------------------------------------
6. MAIN FUNCTION
------------------------------------------------------------
*/

vector<int> diagonal(Node *root)
{
    int l = 0;

    // Find number of diagonals
    find(root, 0, l);

    vector<vector<int>> ans(l + 1);

    // Fill diagonals
    findDia(root, 0, ans);

    vector<int> temp;

    // Flatten result
    for(int i = 0; i < ans.size(); i++)
        for(int j = 0; j < ans[i].size(); j++)
            temp.push_back(ans[i][j]);

    return temp;
}


/*
------------------------------------------------------------
7. CREATE SAMPLE TREE
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
8. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    vector<int> result = diagonal(root);

    cout << "Diagonal Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}


/*
------------------------------------------------------------
9. DRY RUN
------------------------------------------------------------

Diagonal 0:
1, 3, 6

Diagonal 1:
2, 5

Diagonal 2:
4

Final:
1 3 6 2 5 4
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

Extra storage for diagonals

Space Complexity: O(n)
*/


/*
------------------------------------------------------------
12. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Key rule:
   left → diagonal + 1
   right → same diagonal

2. Group nodes using diagonal index

3. Alternative approach:
   use queue (more optimal and common)

4. This is variation of vertical traversal

5. Frequently asked in tree problems
*/


/*
============================================================
END OF FILE
============================================================
*/

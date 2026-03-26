/*
============================================================
MORRIS INORDER TRAVERSAL (O(1) SPACE)
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

struct Node {
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

Perform inorder traversal of a binary tree
WITHOUT using recursion or stack.

Inorder:

LEFT → ROOT → RIGHT

Constraint:
Space Complexity must be O(1)
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

Normally we use stack/recursion.

Morris Traversal uses:

→ Temporary threads (links)
→ Modify tree structure during traversal
→ Restore it afterward

Key Idea:
Connect rightmost node of left subtree
to current node (temporary link).
*/


/*
------------------------------------------------------------
4. APPROACH / ALGORITHM
------------------------------------------------------------

While current node exists:

Case 1:
If left is NULL:
    → process node
    → move to right

Case 2:
If left exists:
    → find inorder predecessor (rightmost in left subtree)

    If predecessor->right == NULL:
        → create thread to current node
        → move to left

    Else:
        → remove thread
        → process node
        → move to right
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION (C++ CODE)
------------------------------------------------------------
*/

vector<int> inOrder(Node* root)
{
    vector<int> ans;

    while(root)
    {
        // Case 1: No left child
        if(!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            Node* curr = root->left;

            while(curr->right && curr->right != root)
                curr = curr->right;

            // Create thread
            if(curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                // Remove thread
                curr->right = NULL;

                ans.push_back(root->data);
                root = root->right;
            }
        }
    }

    return ans;
}


/*
------------------------------------------------------------
6. CREATE SAMPLE TREE / INPUT
------------------------------------------------------------

        1
       / \
      2   3
     / \
    4   5
*/

Node* createTree()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    return root;
}


/*
------------------------------------------------------------
7. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = createTree();

    vector<int> result = inOrder(root);

    cout << "Morris Inorder Traversal: ";
    for(int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}


/*
------------------------------------------------------------
8. DRY RUN (STEP-BY-STEP, DETAILED)
------------------------------------------------------------

Tree:

        1
       / \
      2   3
     / \
    4   5


Start:
root = 1


Step 1:
root = 1 (has left)

Find predecessor → rightmost of left subtree = 5

5->right = NULL → create thread
5->right = 1

Move root → 2


Step 2:
root = 2 (has left)

Find predecessor → rightmost of left subtree = 4

4->right = NULL → create thread
4->right = 2

Move root → 4


Step 3:
root = 4 (no left)

Process (print) 4

Move root → 4->right = 2 (thread)


Step 4:
root = 2

Find predecessor → 4

4->right == root → thread exists

Remove thread → 4->right = NULL

Process (print) 2

Move root → 5


Step 5:
root = 5 (no left)

Process (print) 5

Move root → 5->right = 1 (thread)


Step 6:
root = 1

Find predecessor → 5

5->right == root → thread exists

Remove thread → 5->right = NULL

Process (print) 1

Move root → 3


Step 7:
root = 3 (no left)

Process (print) 3

Move root → NULL


Final Output:
4 2 5 1 3
*/


/*
------------------------------------------------------------
9. TIME COMPLEXITY
------------------------------------------------------------

Each edge is visited at most twice

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
10. SPACE COMPLEXITY
------------------------------------------------------------

No recursion, no stack used

Space Complexity: O(1)
*/


/*
------------------------------------------------------------
11. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Eliminates recursion and stack usage

2. Uses temporary threading (modifies tree)

3. Ensures tree is restored after traversal

4. Slightly tricky but very important for interviews

5. Variants:
   → Morris Preorder Traversal
   → Morris Postorder Traversal
*/


/*
------------------------------------------------------------
12. KEY CONCEPT / TRICKS (if applicable)
------------------------------------------------------------

Inorder Predecessor:

→ Rightmost node of left subtree

Used to:
→ Create temporary link (thread)
→ Avoid using stack/recursion
*/


/*
------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
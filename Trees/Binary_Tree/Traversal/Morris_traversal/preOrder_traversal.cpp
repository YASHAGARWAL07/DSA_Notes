/*
============================================================
MORRIS PREORDER TRAVERSAL (O(1) SPACE)
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

Perform preorder traversal of a binary tree
WITHOUT using recursion or stack.

Preorder:

ROOT → LEFT → RIGHT

Constraint:
Space Complexity must be O(1)
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

In preorder, we process ROOT first.

Morris Traversal helps us avoid recursion/stack by:

→ Creating temporary threads
→ Visiting nodes while traversing
→ Restoring the tree afterward

Key Idea:
Print node BEFORE going to left subtree.
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
    → find inorder predecessor (rightmost of left subtree)

    If predecessor->right == NULL:
        → process node (IMPORTANT difference from inorder)
        → create thread to current node
        → move to left

    Else:
        → remove thread
        → move to right
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION (C++ CODE)
------------------------------------------------------------
*/

vector<int> preOrder(Node* root)
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
            // Find predecessor
            Node* curr = root->left;

            while(curr->right && curr->right != root)
                curr = curr->right;

            // Left part not traversed
            if(curr->right == NULL)
            {
                ans.push_back(root->data); // Process BEFORE going left
                curr->right = root;
                root = root->left;
            }
            else
            {
                // Left part already traversed
                curr->right = NULL;
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

    vector<int> result = preOrder(root);

    cout << "Morris Preorder Traversal: ";
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

Find predecessor → 5

5->right = NULL → create thread

Process (print) 1

Move root → 2


Step 2:
root = 2 (has left)

Find predecessor → 4

4->right = NULL → create thread

Process (print) 2

Move root → 4


Step 3:
root = 4 (no left)

Process (print) 4

Move root → 4->right = 2 (thread)


Step 4:
root = 2

Find predecessor → 4

4->right == root → thread exists

Remove thread

Move root → 5


Step 5:
root = 5 (no left)

Process (print) 5

Move root → 5->right = 1 (thread)


Step 6:
root = 1

Find predecessor → 5

5->right == root → thread exists

Remove thread

Move root → 3


Step 7:
root = 3 (no left)

Process (print) 3

Move root → NULL


Final Output:
1 2 4 5 3
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

1. Difference from inorder:
   → Process node BEFORE going left

2. Uses threading to avoid stack

3. Tree structure is restored after traversal

4. Common follow-up:
   → Morris Inorder vs Preorder difference

5. Very important for space-optimized traversal
*/


/*
------------------------------------------------------------
12. KEY CONCEPT / TRICKS (if applicable)
------------------------------------------------------------

Key Trick:

→ Print node when:
   - Left is NULL OR
   - First time visiting node (before creating thread)

This ensures preorder (ROOT → LEFT → RIGHT)
*/


/*
------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/
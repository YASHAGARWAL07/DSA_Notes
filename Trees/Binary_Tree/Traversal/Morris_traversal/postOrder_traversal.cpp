/*
============================================================
MORRIS POSTORDER TRAVERSAL (O(1) SPACE)
============================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

Perform postorder traversal of a binary tree
WITHOUT using recursion or stack.

Postorder:

LEFT → RIGHT → ROOT

Constraint:
Space Complexity must be O(1)
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

Postorder is tricky in Morris traversal.

Idea:

→ Reverse modified preorder traversal
→ Preorder = ROOT → LEFT → RIGHT
→ Reverse Preorder = ROOT → RIGHT → LEFT

If we collect this order and reverse it:
→ LEFT → RIGHT → ROOT (Postorder)

So:
→ Traverse ROOT → RIGHT → LEFT using Morris
→ Reverse result at the end
*/


/*
------------------------------------------------------------
4. APPROACH / ALGORITHM
------------------------------------------------------------

While current node exists:

Case 1:
If right is NULL:
    → process node
    → move to left

Case 2:
If right exists:
    → find predecessor (leftmost in right subtree)

    If predecessor->left == NULL:
        → process node
        → create thread
        → move to right

    Else:
        → remove thread
        → move to left

Finally:
→ reverse the result
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION (C++ CODE)
------------------------------------------------------------
*/

vector<int> postOrder(Node* root)
{
    vector<int> ans;

    while(root)
    {
        // Case 1: No right child
        if(!root->right)
        {
            ans.push_back(root->data);
            root = root->left;
        }
        else
        {
            // Find predecessor (leftmost in right subtree)
            Node* curr = root->right;

            while(curr->left && curr->left != root)
                curr = curr->left;

            // Not traversed
            if(curr->left == NULL)
            {
                ans.push_back(root->data); // process
                curr->left = root;
                root = root->right;
            }
            else
            {
                // Already traversed
                curr->left = NULL;
                root = root->left;
            }
        }
    }

    // Reverse to get postorder
    reverse(ans.begin(), ans.end());

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

    vector<int> result = postOrder(root);

    cout << "Morris Postorder Traversal: ";
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


We follow modified preorder:
ROOT → RIGHT → LEFT

Collected order (before reverse):

Step 1: Visit 1
Step 2: Visit 3
Step 3: Visit 2
Step 4: Visit 5
Step 5: Visit 4

Intermediate result:
1 3 2 5 4

Now reverse:

Final Postorder:
4 5 2 3 1
*/


/*
------------------------------------------------------------
9. TIME COMPLEXITY
------------------------------------------------------------

Each edge visited at most twice

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
10. SPACE COMPLEXITY
------------------------------------------------------------

No recursion, no stack

Space Complexity: O(1)
(Note: output array not counted)
*/


/*
------------------------------------------------------------
11. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Most difficult among Morris traversals

2. Trick:
   → Reverse modified preorder

3. Uses reverse at end

4. Tree structure restored after traversal

5. Alternative method:
   → Using dummy node + reverse edges
*/


/*
------------------------------------------------------------
12. KEY CONCEPT / TRICKS (if applicable)
------------------------------------------------------------

Key Trick:

→ Convert Postorder into reversed preorder

ROOT → RIGHT → LEFT  (collect)
Then reverse → LEFT → RIGHT → ROOT
*/


/*
------------------------------------------------------------
END OF FILE
------------------------------------------------------------
*/

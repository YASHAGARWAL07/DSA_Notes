/*
============================================================
PREORDER TRAVERSAL (ITERATIVE USING STACK)
============================================================
*/

#include <iostream>
#include <vector>
#include <stack>
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

Perform preorder traversal of a binary tree
without using recursion.

Preorder:

ROOT → LEFT → RIGHT
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

Use a stack to simulate recursion.

Key idea:

1. Process current node
2. Push right child
3. Push left child

Why?

Stack is LIFO → left will be processed first
*/


/*
------------------------------------------------------------
4. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return empty

Step 2:
Push root into stack

Step 3:
While stack not empty:

    - Pop node
    - Add its value to answer
    - Push right child (if exists)
    - Push left child (if exists)

Step 4:
Return result
*/


/*
------------------------------------------------------------
5. IMPLEMENTATION
------------------------------------------------------------
*/

vector<int> preOrder(Node* root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;

    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();

        ans.push_back(temp->data);

        if(temp->right)
            st.push(temp->right);

        if(temp->left)
            st.push(temp->left);
    }

    return ans;
}


/*
------------------------------------------------------------
6. CREATE SAMPLE TREE
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
    Node* root = createTree();

    vector<int> result = preOrder(root);

    cout << "Preorder Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}


/*
------------------------------------------------------------
8. DRY RUN
------------------------------------------------------------

Stack: [1]

Pop 1 → print 1
Push 3, Push 2

Stack: [3,2]

Pop 2 → print 2
Push 5, Push 4

Stack: [3,5,4]

Pop 4 → print 4

Pop 5 → print 5

Pop 3 → print 3

Output:
1 2 4 5 3
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

Stack stores nodes

Space Complexity: O(h)

Worst case: O(n)
*/


/*
------------------------------------------------------------
11. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Push RIGHT first, then LEFT

2. Stack simulates recursion

3. Very important iterative traversal

4. Faster than recursion (no function calls)

5. Common mistake:
   pushing left before right (wrong order)
*/


/*
============================================================
END OF FILE
============================================================
*/
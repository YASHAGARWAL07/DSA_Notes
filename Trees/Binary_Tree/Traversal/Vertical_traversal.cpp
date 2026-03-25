/*
============================================================
VERTICAL ORDER TRAVERSAL OF BINARY TREE
============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
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

Print nodes of a binary tree in vertical order.

Vertical order groups nodes based on
horizontal distance (HD) from root.

Rules:

Root → HD = 0  
Left → HD - 1  
Right → HD + 1  


Example:

        1
       / \
      2   3
     / \   \
    4   5   6

Output:
[
 [4],
 [2],
 [1,5],
 [3],
 [6]
]
*/


/*
------------------------------------------------------------
3. INTUITION
------------------------------------------------------------

Assign each node a horizontal distance (pos).

Store nodes according to pos.

Traverse tree using BFS so that
top-to-bottom order is maintained.

Finally, print from leftmost to rightmost.
*/


/*
------------------------------------------------------------
4. FIND RANGE OF POSITIONS
------------------------------------------------------------
*/

void find(Node* root, int pos, int &l, int &r)
{
    if(!root) return;

    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}


/*
------------------------------------------------------------
5. MAIN LOGIC (BFS)
------------------------------------------------------------
*/

vector<vector<int>> verticalOrder(Node *root)
{
    if(!root) return {};

    int l = 0, r = 0;

    // Find min and max horizontal distance
    find(root, 0, l, r);

    vector<vector<int>> negative(abs(l) + 1);
    vector<vector<int>> positive(r + 1);

    queue<Node*> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int pos = index.front();
        index.pop();

        // Store node
        if(pos >= 0)
            positive[pos].push_back(temp->data);
        else
            negative[abs(pos)].push_back(temp->data);

        // Traverse children
        if(temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }

        if(temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    vector<vector<int>> ans;

    // Left side (negative indices)
    for(int i = negative.size() - 1; i >= 1; i--)
    {
        if(!negative[i].empty())
            ans.push_back(negative[i]);
    }

    // Middle (pos = 0)
    if(!positive[0].empty())
        ans.push_back(positive[0]);

    // Right side (positive indices)
    for(int i = 1; i < positive.size(); i++)
    {
        if(!positive[i].empty())
            ans.push_back(positive[i]);
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
7. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    Node* root = createTree();

    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:\n";

    for(auto &col : result)
    {
        for(int x : col)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}


/*
------------------------------------------------------------
8. DRY RUN
------------------------------------------------------------

HD Mapping:

4 → -2  
2 → -1  
1 →  0  
5 →  0  
3 → +1  
6 → +1  

Result:
[4], [2], [1,5], [3], [6]
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

Queue + storage

Space Complexity: O(n)
*/


/*
------------------------------------------------------------
11. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Use BFS for correct ordering

2. Horizontal Distance (HD) concept is key

3. Left → -1, Right → +1

4. Separate negative and positive indices

5. Common variations:
   - Top View
   - Bottom View
   - Vertical Sum
*/


/*
============================================================
END OF FILE
============================================================
*/
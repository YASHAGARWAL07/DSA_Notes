/*
============================================================
LEVEL ORDER TRAVERSAL (BFS - BINARY TREE)
============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given a binary tree, return its level order traversal.

Level order traversal means:
Traverse nodes level by level (top to bottom).

Example:

        1
       / \
      2   3
     / \
    4   5

Output:
[
  [1],
  [2,3],
  [4,5]
]
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

We traverse the tree level by level.

Use a queue (FIFO):

1. Push root
2. Process nodes level by level
3. Push children into queue

Key idea:
At each step, we process ALL nodes
present in the queue (one level).
*/


/*
------------------------------------------------------------
3. APPROACH / ALGORITHM
------------------------------------------------------------

Step 1:
If root is NULL → return empty result

Step 2:
Push root into queue

Step 3:
While queue is not empty:

    size = number of nodes at current level

    Create empty vector "level"

    Loop size times:
        - take front node
        - push its value into level
        - push its children into queue

    Add level to answer

Step 4:
Return answer
*/


/*
------------------------------------------------------------
4. C++ IMPLEMENTATION
------------------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();     // nodes in current level
            vector<int> level;

            for(int i = 0; i < size; i++){

                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};


/*
------------------------------------------------------------
5. DRY RUN
------------------------------------------------------------

Tree:

        1
       / \
      2   3
     / \
    4   5


Queue = [1]

Level 1:
Process 1
Queue = [2,3]
Result = [ [1] ]

Level 2:
Process 2,3
Queue = [4,5]
Result = [ [1], [2,3] ]

Level 3:
Process 4,5
Queue = []
Result = [ [1], [2,3], [4,5] ]
*/


/*
------------------------------------------------------------
6. TIME COMPLEXITY
------------------------------------------------------------

Each node visited once

Time Complexity: O(n)
*/


/*
------------------------------------------------------------
7. SPACE COMPLEXITY
------------------------------------------------------------

Queue stores nodes of one level

Worst case: O(n)

Space Complexity: O(n)
*/


/*
------------------------------------------------------------
8. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. Uses BFS (queue-based traversal)

2. Key trick:
   Use "size = q.size()" to separate levels

3. Very common pattern for:
   - Level order traversal
   - Zigzag traversal
   - Right/Left view
   - Minimum depth (BFS)

4. Always check root == NULL first
*/


/*
------------------------------------------------------------
9. VARIATIONS
------------------------------------------------------------

1. Zigzag Level Order Traversal
2. Right View of Tree
3. Left View of Tree
4. Level Order Bottom-Up
5. Average of Levels
*/


/*
============================================================
END OF FILE
============================================================
*/
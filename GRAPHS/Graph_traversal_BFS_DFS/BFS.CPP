/*
============================================================
BFS TRAVERSAL (GRAPH)
============================================================

- Uses queue
- Level order traversal
- Start from node 0 (given)

============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        queue<int> q;

        q.push(0);

        vector<bool> visited(V, 0);
        visited[0] = 1;

        vector<int> ans;
        int node;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++) {
                if (!visited[adj[node][j]]) {
                    visited[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }

        return ans;
    }
};

/*
------------------------------------------------------------
MAIN
------------------------------------------------------------
*/

int main() {
    Solution obj;

    vector<vector<int>> adj = {
        {2, 3, 1},
        {0},
        {0, 4},
        {0},
        {2}
    };

    vector<int> res = obj.bfs(adj);

    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
------------------------------------------------------------
TIME
------------------------------------------------------------
O(V + E)
*/
/*
============================================================
DFS TRAVERSAL (GRAPH)
============================================================

- recursion use hota hai
- depth wise traversal
- backtracking involved

============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = 1;
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j]])
                DFS(adj[node][j], adj, visited, ans);
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), 0);
        vector<int> ans;
        DFS(0, adj, visited, ans);

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

    vector<int> res = obj.dfs(adj);

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
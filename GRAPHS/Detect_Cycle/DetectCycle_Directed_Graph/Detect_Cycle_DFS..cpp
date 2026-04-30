/*
============================================================
DETECT CYCLE IN DIRECTED GRAPH (DFS)
============================================================

- visited[] → node visited ya nahi
- path[] → current recursion path
- agar path me dobara aaye → cycle

============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool DetectCycle(int node, vector<vector<int>>& adj, vector<bool>& path, vector<bool>& visited) {
        visited[node] = 1;
        path[node] = 1;

        for (int j = 0; j < adj[node].size(); j++) {
            // agar already path me hai → cycle
            if (path[adj[node][j]])
                return true;

            // agar visited nahi hai → DFS
            else {
                if (!visited[adj[node][j]]) {
                    if (DetectCycle(adj[node][j], adj, path, visited))
                        return true;
                }
            }
        }

        path[node] = 0; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // convert edges → adj list
        vector<vector<int>> adj(V);

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, 0);
        vector<bool> path(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DetectCycle(i, adj, path, visited))
                    return true;
            }
        }

        return false;
    }
};

/*
------------------------------------------------------------
MAIN
------------------------------------------------------------
*/

int main() {
    Solution obj;

    int V = 4;
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,0}, {2,3}
    };

    if (obj.isCyclic(V, edges))
        cout << "Cycle Present\n";
    else
        cout << "No Cycle\n";

    return 0;
}

/*
------------------------------------------------------------
TIME
------------------------------------------------------------
O(V + E)
*/
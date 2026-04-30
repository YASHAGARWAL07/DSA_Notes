/*
============================================================
BIPARTITE GRAPH (BFS - 2 COLORING)
============================================================

WHAT IS BIPARTITE GRAPH?
- Graph jise 2 groups me divide kar sake
- No edge between nodes of same group
- Adjacent nodes ka color same nahi hona chahiye

EXAMPLE:
Set A → 0,2
Set B → 1,3

0 --- 1
|     |
2 --- 3

============================================================
CORE IDEA
============================================================

- 2 color assign karte hain (0,1)
- agar kisi edge ke dono ends ka color same ho → NOT bipartite
- BFS ya DFS dono use kar sakte hain

============================================================
PROPERTIES
============================================================

- No odd length cycle → Bipartite
- Odd cycle present → NOT bipartite
- Even cycle → Bipartite

============================================================
REAL LIFE USES
============================================================

- Job assignment (workers ↔ jobs)
- Matching problems
- Graph coloring problems
- Network flow problems
- Social graph partition

============================================================
IMPORTANT QUESTIONS
============================================================

1) Check bipartite graph (BFS/DFS)
2) Possible bipartition (Leetcode)
3) Graph coloring
4) Detect odd cycle
5) Maximum matching (advanced)

============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(int V, vector<vector<int>>& edges) {

        // convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);
        queue<int> q;

        q.push(0);
        color[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {

                // not colored
                if (color[adj[node][j]] == -1) {
                    color[adj[node][j]] = (color[node] + 1) % 2;
                    q.push(adj[node][j]);
                }
                // already colored
                else {
                    if (color[adj[node][j]] == color[node])
                        return false;
                }
            }
        }

        return true;
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
        {0,1}, {1,2}, {2,3}, {3,0}
    };

    if (obj.isBipartite(V, edges))
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}

/*
------------------------------------------------------------
TIME
------------------------------------------------------------
O(V + E)

------------------------------------------------------------
EXTRA POINTS (IMPORTANT)
------------------------------------------------------------

- disconnected graph ho → har node pe BFS lagana
- color array initialize with -1
- BFS = queue, DFS = recursion

------------------------------------------------------------
REVISION
------------------------------------------------------------

- 2 color problem
- same color adjacent → false
- odd cycle → not bipartite
- BFS/DFS dono valid

============================================================
*/
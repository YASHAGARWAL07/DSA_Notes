/*
============================================================
BIPARTITE GRAPH (DFS APPROACH)
============================================================

basic idea:
- graph ko 2 colors me divide karna hai
- adjacent nodes ka color same nahi hona chahiye

example:
0 - 1 - 2
possible:
0 -> color 0
1 -> color 1
2 -> color 0

============================================================
logic (as sir explained)
============================================================

- current node ke saare neighbours dekho
- agar neighbour ka color assign nahi hua:
    -> usse opposite color do
    -> DFS call karo us par

- agar already colored hai:
    -> check karo same color to nahi
    -> agar same → not bipartite

============================================================
important observations
============================================================

- odd cycle → NOT bipartite
- even cycle → bipartite
- tree → always bipartite

============================================================
real life intuition
============================================================

- group division (boys / girls type)
- job assignment
- matching problems

============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool checkBip(int node, vector<vector<int>>& adj, vector<int>& color){

        // look at each neighbour
        for(int j=0;j<adj[node].size();j++){

            // not yet colored
            if(color[adj[node][j]] == -1){
                color[adj[node][j]] = (color[node]+1)%2;

                if(!checkBip(adj[node][j], adj, color))
                    return false;
            }

            // already colored
            else{
                if(color[adj[node][j]] == color[node])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<vector<int>>& edges) {

        // convert to adjacency list
        vector<vector<int>> adj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);

        // handle disconnected graph
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!checkBip(i, adj, color))
                    return false;
            }
        }

        return true;
    }
};

/*
------------------------------------------------------------
MAIN (for VS Code run)
------------------------------------------------------------
*/

int main() {

    Solution obj;

    int V = 4;
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,3}, {3,0}
    };

    if(obj.isBipartite(V, edges))
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}

/*
------------------------------------------------------------
quick revision
------------------------------------------------------------

- 2 color problem
- DFS recursion
- same color adjacent → false
- disconnected → loop lagao

------------------------------------------------------------
interview hint
------------------------------------------------------------

- BFS version bhi poochte hain
- odd cycle detect → direct answer

============================================================
*/
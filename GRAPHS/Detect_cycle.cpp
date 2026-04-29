/*
============================================================
CYCLE DETECTION (UNDIRECTED - DFS)
============================================================

- visited + not parent = cycle
- works for multiple components

============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool cycleDetect(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node] = 1;
        for(int j=0;j<adj[node].size();j++){
            if(parent == adj[node][j])
                continue;
            else if(visited[adj[node][j]]==1)
                return true;
            else
                if(cycleDetect(adj[node][j],node,adj,visited))
                    return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // edge list -> adj list
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V,0);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycleDetect(i,-1,adj,visited))
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
        {0,1}, {0,2}, {1,2}, {2,3}
    };

    if(obj.isCycle(V, edges))
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
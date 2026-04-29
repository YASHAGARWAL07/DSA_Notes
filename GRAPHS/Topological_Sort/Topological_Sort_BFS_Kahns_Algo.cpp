/*
============================================================
TOPOLOGICAL SORT (BFS - KAHN'S ALGORITHM)
============================================================

- Works on DAG
- Uses indegree
- start from nodes with indegree 0

idea:
- remove node with 0 indegree
- reduce indegree of neighbours

============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // Kahn's Algorithm
        vector<int> ans;
        vector<int> inDeg(V,0);

        // calculate indegree
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                inDeg[adj[i][j]]++;
            }
        }

        // push nodes with indegree 0
        queue<int> q;
        for(int i=0;i<inDeg.size();i++){
            if(inDeg[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            // reduce indegree
            for(int j=0;j<adj[node].size();j++){
                inDeg[adj[node][j]]--;

                if(inDeg[adj[node][j]]==0)
                    q.push(adj[node][j]);
            }
        }

        // if cycle exists
        if(ans.size() != V)
            return {};

        return ans;
    }
};

/*
------------------------------------------------------------
MAIN
------------------------------------------------------------
*/

int main(){
    Solution obj;

    int V = 4;
    vector<vector<int>> edges = {
        {3,0}, {1,0}, {2,0}
    };

    vector<int> ans = obj.topoSort(V, edges);

    if(ans.empty()){
        cout << "Cycle present, topo not possible\n";
    } else {
        for(int x : ans)
            cout << x << " ";
    }

    return 0;
}

/*
------------------------------------------------------------
NOTES
------------------------------------------------------------

- indegree = incoming edges
- start from indegree 0
- if ans size < V → cycle

time: O(V + E)

============================================================
*/
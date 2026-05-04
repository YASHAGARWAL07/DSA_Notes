/*
------------------------------------------------------------
find if path exists in graph
------------------------------------------------------------

intuition:

- simple question:

"can we go from source → destination?"

→ matlab: kya path exist karta hai?

------------------------------------------------------------

core idea:

- graph traversal problem
- use DFS

why DFS?

- ek path pakdo aur end tak jao
- agar destination mil gaya → true
- warna backtrack

------------------------------------------------------------

approach:

1. graph ko adjacency list me convert karo
2. visited array rakho
3. DFS call from source
4. agar kabhi destination mil gaya → return true
5. nahi mila → false

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool DFS(int node,vector<vector<int>>&adj,vector<bool>&visited,int   destination)
    {
        if(node == destination)
        return true;
        visited[node] = 1;
        for(int j=0;j<adj[node].size();j++)
        if(!visited[adj[node][j]])
        if(DFS(adj[node][j],adj,visited,destination))
        return true;

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //convert edge matrix into adjacy list
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool>visited(n,0);
        return DFS(source,adj,visited,destination);

    }
};

/*
------------------------------------------------------------
main (for vs code)
------------------------------------------------------------
*/

int main(){

    Solution obj;

    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;

    cout << obj.validPath(n, edges, source, destination);

    return 0;
}

/*
------------------------------------------------------------
important points:

- undirected graph → dono direction me edge add karna
- visited array mandatory (cycle avoid karne ke liye)
- DFS ya BFS dono use kar sakte ho

------------------------------------------------------------
time complexity:

O(V + E)

------------------------------------------------------------
space complexity:

O(V)  (visited + recursion stack)

------------------------------------------------------------
pattern:

- reachability problem
- DFS/BFS traversal

------------------------------------------------------------
similar questions:

- keys and rooms
- number of provinces
- flood fill
- BFS/DFS traversal

------------------------------------------------------------
quick recall:

- build adj list
- DFS from source
- if destination mil gaya → true

------------------------------------------------------------
*/

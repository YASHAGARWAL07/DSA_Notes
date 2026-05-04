/*
------------------------------------------------------------
eventual safe states
------------------------------------------------------------

intuition:

- safe node = jo kabhi cycle me nahi jata
- agar kisi node se cycle reachable hai → unsafe

direct graph me ye check karna hard hota hai

→ trick: graph reverse karo

kyu?

- original me:
  node -> neighbours (outgoing)

- reverse me:
  neighbours -> node

→ ab outdegree becomes indegree

------------------------------------------------------------

core idea:

- terminal nodes (outdegree = 0) → always safe
- unse jo nodes connect hain → wo bhi safe
- BFS se backward propagate karte hain safety

→ use Kahn's Algorithm (topo sort)

cycle wale nodes:
→ kabhi indegree 0 nahi hoga
→ automatically ignore ho jayenge

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse the graph -> it will become topological sort ques - outdegree changes to Indegree
        vector<vector<int>>adj(graph.size());
        vector<int>InDeg(graph.size(),0);
        for(int i=0;i<graph.size();i++)
         for(int j=0;j<graph[i].size();j++){
          adj[graph[i][j]].push_back(i);
          InDeg[i]++;
         }

        //Topological sort - Kahn's Algoorithm
        queue<int>q;
        for(int i=0;i<InDeg.size();i++)
        if(!InDeg[i])
        q.push(i);
        
        vector<int>topo;  //stores topological order

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int j=0;j<adj[node].size();j++){
                InDeg[adj[node][j]]--;
                if(!InDeg[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        sort(topo.begin(),topo.end());  //sort in ascending order
        return topo;
    }
};

/*
------------------------------------------------------------
main (for vs code)
------------------------------------------------------------
*/

int main(){

    Solution obj;

    vector<vector<int>> graph = {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = obj.eventualSafeNodes(graph);

    for(int x : ans) cout << x << " ";

    return 0;
}

/*
------------------------------------------------------------
important points:

- reverse graph = main trick
- indegree = original outdegree
- kahn algo removes acyclic nodes
- cycle nodes remain unprocessed

------------------------------------------------------------
time complexity:

O(V + E)

------------------------------------------------------------
space complexity:

O(V + E)

------------------------------------------------------------
alternative approach:

DFS + cycle detection

- visited[]
- pathVisited[]

------------------------------------------------------------
interview patterns:

- course schedule
- topo sort
- detect cycle (directed)
- safe nodes
- dependency graph problems

------------------------------------------------------------
quick recall:

- reverse
- indegree
- queue
- topo sort
- answer

------------------------------------------------------------
*/

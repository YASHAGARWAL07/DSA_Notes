#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
PRIMS ALGORITHM
====================================================================

USED FOR:
--------------------------------------------------------------------

Finding Minimum Spanning Tree (MST)

====================================================================
INTUITION
====================================================================

Always choose minimum weight edge
which connects a NEW node.

Grow MST gradually.

====================================================================
GREEDY APPROACH
====================================================================

At every step:

Pick minimum weight edge possible.

====================================================================
ALGORITHM
====================================================================

1. Start from any node

2. Put all neighbour edges into Min Heap

3. Pick minimum weight edge

4. If node not already in MST:
   -> include it

5. Push all neighbour edges

6. Repeat until all nodes included

====================================================================
DATA STRUCTURES USED
====================================================================

1. Adjacency List

2. Priority Queue (Min Heap)

3. Visited / IsMST array

4. Parent array

====================================================================
TIME COMPLEXITY
====================================================================

Using Priority Queue:

O(E log V)

====================================================================
SPACE COMPLEXITY
====================================================================

O(V + E)

====================================================================
IMPORTANT POINTS
====================================================================

1. Greedy Algorithm

2. Works on:
   -> Weighted
   -> Undirected
   -> Connected graph

3. Negative weights allowed

4. MST contains V-1 edges

====================================================================
PRIMS vs DIJKSTRA
====================================================================

PRIMS:
---------
Minimum edge weight

DIJKSTRA:
-----------
Minimum distance from source

====================================================================
EDGE CASES
====================================================================

1. Disconnected graph
   -> MST not possible

2. Multiple same weight edges
   -> Multiple MST possible

3. Negative weights
   -> Works correctly

====================================================================
WHEN TO USE PRIMS?
====================================================================

Use when:

1. Need MST

2. Graph is weighted undirected

3. Graph is dense

====================================================================
DRY RUN
====================================================================

GRAPH:

        5
    0 ------- 1
     \       /
    1 \     / 3
       \   /
         2

MST:
0 -> 2 = 1
2 -> 1 = 3

Total Cost = 4

====================================================================
CODE
====================================================================

*/

class Solution {
public:

    int spanningTree(int V, vector<vector<int>>& edges) {

        //convert edge list into adjacency list
        vector<vector<int>> adj[V];

        for(auto it : edges) {

            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        //min heap -> {weight,{node,parent}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        vector<bool> IsMST(V,0);          //stores MST nodes
        vector<int> parent(V,-1);         //stores parent

        int cost = 0;                     //stores MST cost

        pq.push({0,{0,-1}});              //{weight,{node,parent}}

        while(!pq.empty()) {

            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;

            pq.pop();

            //ignore if already included
            if(IsMST[node])
                continue;

            //include in MST
            IsMST[node] = 1;

            cost += wt;

            parent[node] = par;

            //traverse neighbours
            for(int i = 0; i < adj[node].size(); i++) {

                int neigh = adj[node][i][0];
                int weight = adj[node][i][1];

                if(!IsMST[neigh]) {

                    pq.push({weight,{neigh,node}});
                }
            }
        }

        return cost;
    }
};

int main() {

    int V = 3;

    vector<vector<int>> edges = {
        {0,1,5},
        {1,2,3},
        {0,2,1}
    };

    Solution obj;

    cout << "Minimum MST Cost = ";
    cout << obj.spanningTree(V, edges);

    return 0;
}

/*

====================================================================
STEP BY STEP DRY RUN
====================================================================

STEP 1:
--------
Start from node 0

PQ:
{0,{0,-1}}

Cost = 0

====================================================================

STEP 2:
--------
Take node 0

Push:
0 -> 1 = 5
0 -> 2 = 1

PQ:
{1,{2,0}}
{5,{1,0}}

====================================================================

STEP 3:
--------
Take node 2

Cost += 1

Push:
2 -> 1 = 3

PQ:
{3,{1,2}}
{5,{1,0}}

====================================================================

STEP 4:
--------
Take node 1

Cost += 3

All nodes included

Final Cost = 4

====================================================================
FINAL MST
====================================================================

0 -> 2 = 1
2 -> 1 = 3

Total Cost = 4

====================================================================
IMPORTANT INTERVIEW QUESTIONS
====================================================================

Q1. Why use priority queue?

Q2. Why cycle not formed?

Q3. Why IsMST array used?

Q4. Why complexity is O(E log V)?

Q5. Prim's vs Kruskal?

====================================================================
SHORT REVISION
====================================================================

1. Prim's finds MST

2. Greedy Algorithm

3. Uses Min Heap

4. Picks minimum edge

5. Complexity:
   O(E log V)

====================================================================

*/
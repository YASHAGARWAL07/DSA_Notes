#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
KRUSKAL ALGORITHM
====================================================================

USED FOR:
--------------------------------------------------------------------

Finding Minimum Spanning Tree (MST)

====================================================================
MINIMUM SPANNING TREE (MST)
====================================================================

A Minimum Spanning Tree is a tree obtained from a
weighted undirected connected graph such that:

1. All vertices are connected
2. No cycle exists
3. Total edge weight is minimum

====================================================================
PROPERTIES OF MST
====================================================================

1. MST contains exactly:
   V - 1 edges

2. MST contains NO cycle

3. MST connects all vertices

4. Removing any edge disconnects graph

5. Adding one extra edge creates cycle

====================================================================
INTUITION
====================================================================

Always pick minimum weight edge
which DOES NOT form a cycle.

====================================================================
GREEDY APPROACH
====================================================================

At every step:

Pick smallest weight edge possible.

====================================================================
MAIN IDEA
====================================================================

1. Process edges according to weight

2. Pick smallest edge

3. If cycle not formed:
   -> include edge in MST

4. Else:
   -> ignore edge

5. Continue until:
   MST contains V-1 edges

====================================================================
WHY DSU USED?
====================================================================

DSU helps in:

1. Cycle Detection

2. Merging Components

====================================================================
DSU (DISJOINT SET UNION)
====================================================================

Used for:

1. Cycle Detection

2. Merging Components

====================================================================
DSU OPERATIONS
====================================================================

1. findParent(node)
   -> Finds ultimate parent

2. unionByRank(u,v)
   -> Merges two sets

====================================================================
PATH COMPRESSION
====================================================================

Used in findParent()

Purpose:
---------
Reduce height of DSU tree

Makes future operations faster

====================================================================
UNION BY RANK
====================================================================

Smaller rank tree
gets attached to bigger rank tree

Helps reduce tree height

====================================================================
TIME COMPLEXITY
====================================================================

Priority Queue:
----------------
O(E log E)

DSU Operations:
----------------
Nearly O(1)

Overall:
----------
O(E log E)

====================================================================
SPACE COMPLEXITY
====================================================================

Adjacency List -> O(V + E)

Priority Queue -> O(E)

Parent Array -> O(V)

Rank Array -> O(V)

Overall:
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

4. Uses DSU for cycle detection

5. MST contains exactly:
   V-1 edges

====================================================================
KRUSKAL vs PRIMS
====================================================================

KRUSKAL:
----------
1. Edge based
2. Uses DSU
3. Good for sparse graph

PRIMS:
--------
1. Node based
2. Uses Priority Queue
3. Good for dense graph

====================================================================
WHEN TO USE KRUSKAL?
====================================================================

Use when:

1. Graph is sparse

2. Edge list given directly

3. MST required

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
CODE
====================================================================

*/

class Solution {
  public:
  
  //KRUSKAL ALGORITHM
  
    int findParent(int u, vector<int>&parent) {

        //ultimate parent found
        if(u == parent[u])
            return u;
      
        //Path compression
        return parent[u] = findParent(parent[u],parent);
    }

    void unionByRank(int u, int v,
                     vector<int>&parent,
                     vector<int>&Rank) {

        int pu = findParent(u,parent);
        int pv = findParent(v,parent);
      
        //merge according to rank
        if(Rank[pu] > Rank[pv])
            parent[pv] = pu;

        else if(Rank[pu] < Rank[pv])
            parent[pu] = pv;

        else {

            parent[pv] = pu;
            Rank[pu]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {

        //converting edge matrix into adjacency list
        vector<vector<int>>adj[V];

        for(auto it:edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int>parent(V);       //stores ultimate parent
        vector<int>Rank(V,0);       //helps in merging sets

        //initially every node is parent of itself
        for(int i=0;i<V;i++)
            parent[i] = i;
        
        //priority queue
        //{weight,{u,v}}
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        //push all edges into min heap
        for(int i=0;i<V;i++)

            for(int j=0;j<adj[i].size();j++) {

                pq.push({adj[i][j][1],
                        {i,adj[i][j][0]}});
            }

        int cost = 0;
        int edge = 0;
        
        while(!pq.empty()) {

            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;

            pq.pop();
            
            //check if they are in different set
            if(findParent(u,parent)
            !=
            findParent(v,parent)) {

                cost += wt;

                unionByRank(u,v,parent,Rank);

                edge++;
            }
        }

        return cost;
    }
};

int main() {

    int V = 3;

    vector<vector<int>>edges = {

        {0,1,5},
        {1,2,3},
        {0,2,1}
    };

    Solution obj;

    cout << "Minimum MST Cost = ";

    cout << obj.spanningTree(V,edges);

    return 0;
}

/*

====================================================================
STEP BY STEP DRY RUN
====================================================================

GRAPH:
-------

        5
    0 ------- 1
     \       /
    1 \     / 3
       \   /
         2

====================================================================

ALL EDGES:
------------
0-1 = 5
1-2 = 3
0-2 = 1

====================================================================

MIN HEAP ORDER:
----------------
0-2 = 1
1-2 = 3
0-1 = 5

====================================================================

STEP 1:
--------
Take edge:
0-2 = 1

Cycle?
-------
NO

Include edge

Cost = 1

====================================================================

STEP 2:
--------
Take edge:
1-2 = 3

Cycle?
-------
NO

Include edge

Cost = 4

====================================================================

STEP 3:
--------
Take edge:
0-1 = 5

Cycle?
-------
YES

Ignore edge

====================================================================

FINAL MST
====================================================================

0-2 = 1
1-2 = 3

Total Cost = 4

====================================================================
IMPORTANT INTERVIEW QUESTIONS
====================================================================

Q1. Why DSU used?

Q2. Why cycle detection needed?

Q3. Why Path Compression used?

Q4. Why Union by Rank used?

Q5. Kruskal vs Prim's?

====================================================================
VERY IMPORTANT NOTES
====================================================================

1. Kruskal works on:
   -> Weighted
   -> Undirected
   -> Connected graph

2. Negative weights allowed

3. DSU optimizations:
   -> Path Compression
   -> Union by Rank

4. MST contains:
   V-1 edges

====================================================================
SHORT REVISION
====================================================================

1. Pick minimum edge

2. Ignore cycle forming edge

3. Use DSU

4. Greedy Algorithm

5. Complexity:
   O(E log E)

====================================================================

*/
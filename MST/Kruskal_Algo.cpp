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
INTUITION
====================================================================

Always pick the minimum weight edge
which DOES NOT form a cycle.

====================================================================
GREEDY APPROACH
====================================================================

At every step:

Pick smallest weight edge possible.

====================================================================
MAIN IDEA
====================================================================

1. Sort all edges according to weight

2. Pick smallest edge

3. If cycle not formed:
   -> include edge in MST

4. Else:
   -> ignore edge

5. Continue until:
   MST contains V-1 edges

====================================================================
DATA STRUCTURES USED
====================================================================

1. Edge List

2. Sorting

3. DSU / Union Find

====================================================================
WHAT IS DSU?
====================================================================

DSU = Disjoint Set Union

Used to:
---------
1. Detect cycle
2. Merge components efficiently

====================================================================
DSU OPERATIONS
====================================================================

1. findParent(node)
   -> Finds ultimate parent

2. Union(u,v)
   -> Connects two components

====================================================================
TIME COMPLEXITY
====================================================================

Sorting:
----------
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

O(V)

====================================================================
IMPORTANT POINTS
====================================================================

1. Greedy Algorithm

2. Works on:
   -> Weighted
   -> Undirected
   -> Connected graph

3. Negative weights allowed

4. Uses cycle detection

====================================================================
WHEN TO USE KRUSKAL?
====================================================================

Use when:

1. Need MST

2. Graph is sparse

3. Edge list already given

====================================================================
KRUSKAL vs PRIMS
====================================================================

KRUSKAL:
----------
1. Edge based
2. Uses sorting
3. Uses DSU
4. Better for sparse graph

PRIMS:
--------
1. Node based
2. Uses priority queue
3. Better for dense graph

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
WHY DSU REQUIRED?
====================================================================

To check whether adding edge
creates cycle or not.

====================================================================
CYCLE CONDITION
====================================================================

If two nodes already belong
to same component:

-> adding edge forms cycle

====================================================================
EXAMPLE
====================================================================

Edges:
-------
0-1 = 5
1-2 = 3
0-2 = 1

Sorted Edges:
--------------
0-2 = 1
1-2 = 3
0-1 = 5

Pick:
------
0-2 = 1
1-2 = 3

Total MST Cost = 4

====================================================================
CODE
====================================================================

*/

class DSU {

public:

    vector<int> parent;
    vector<int> rank1;

    DSU(int n) {

        parent.resize(n);
        rank1.resize(n,0);

        for(int i=0;i<n;i++) {

            parent[i] = i;
        }
    }

    //find ultimate parent
    int findParent(int node) {

        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    //union by rank
    void Union(int u,int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        //already connected
        if(pu == pv)
            return;

        if(rank1[pu] < rank1[pv]) {

            parent[pu] = pv;
        }

        else if(rank1[pv] < rank1[pu]) {

            parent[pv] = pu;
        }

        else {

            parent[pv] = pu;

            rank1[pu]++;
        }
    }
};

class Solution {
public:

    int spanningTree(int V, vector<vector<int>>& edges) {

        //sort edges according to weight
        sort(edges.begin(),edges.end(),
        [](vector<int>&a,vector<int>&b){

            return a[2] < b[2];
        });

        DSU dsu(V);

        int cost = 0;

        //traverse sorted edges
        for(auto e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            //if cycle not formed
            if(dsu.findParent(u) != dsu.findParent(v)) {

                dsu.Union(u,v);

                cost += wt;
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

STEP 1:
--------
Sort all edges

0-2 = 1
1-2 = 3
0-1 = 5

====================================================================

STEP 2:
--------
Take edge:
0-2 = 1

Cycle?
-------
NO

Include edge

Cost = 1

====================================================================

STEP 3:
--------
Take edge:
1-2 = 3

Cycle?
-------
NO

Include edge

Cost = 4

====================================================================

STEP 4:
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

Q1. Why sorting required?

Q2. Why DSU used?

Q3. How cycle detected?

Q4. Kruskal vs Prim's?

Q5. Why complexity O(E log E)?

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

4. MST contains exactly:
   V-1 edges

====================================================================
SHORT REVISION
====================================================================

1. Sort edges

2. Pick smallest edge

3. Ignore cycle forming edge

4. Use DSU

5. Complexity:
   O(E log E)

====================================================================

*/
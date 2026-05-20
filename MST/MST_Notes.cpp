#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
MINIMUM SPANNING TREE (MST)
====================================================================

DEFINITION:
--------------------------------------------------------------------

A Minimum Spanning Tree is a tree obtained from a
weighted undirected connected graph such that:

1. All vertices are connected
2. No cycle exists
3. Total edge weight is minimum

====================================================================
SPANNING TREE
====================================================================

A spanning tree is a tree that:

1. Connects all vertices
2. Contains V-1 edges
3. Has no cycle

====================================================================
MINIMUM SPANNING TREE
====================================================================

Among all spanning trees,
the one having minimum total edge weight
is called MST.

====================================================================
IMPORTANT CONDITIONS FOR MST
====================================================================

Graph should be:

1. Weighted
2. Undirected
3. Connected

====================================================================
PROPERTIES OF MST
====================================================================

1. MST contains exactly V-1 edges

2. MST contains no cycle

3. MST connects all vertices

4. Removing any edge disconnects graph

5. Adding one extra edge creates cycle

====================================================================
CAN MULTIPLE MST EXIST?
====================================================================

YES

If graph has same edge weights,
multiple MSTs may exist.

====================================================================
WHEN MST DOES NOT EXIST?
====================================================================

1. Disconnected graph

2. Directed graph
   (Generally MST is defined for undirected graph)

====================================================================
IMPORTANT OBSERVATIONS
====================================================================

1. MST minimizes TOTAL graph cost

2. MST does NOT guarantee shortest path
   between every pair of nodes

3. Negative weights are allowed

====================================================================
MST vs SHORTEST PATH
====================================================================

MST:
-----
Minimum total graph cost

Shortest Path:
---------------
Minimum distance from source to destination

====================================================================
MST ALGORITHMS
====================================================================

1. Prim's Algorithm
   -> Node based greedy

2. Kruskal Algorithm
   -> Edge based greedy

====================================================================
PRIMS vs KRUSKAL
====================================================================

PRIMS:
--------
1. Starts from node
2. Uses Priority Queue
3. Better for dense graph

KRUSKAL:
----------
1. Sorts edges
2. Uses DSU
3. Better for sparse graph

====================================================================
TIME COMPLEXITIES
====================================================================

Prim's:
---------
O(E log V)

Kruskal:
-----------
O(E log E)

====================================================================
REAL LIFE APPLICATIONS
====================================================================

1. Road construction
2. Electrical wiring
3. Network cable design
4. Water pipelines
5. Railway networks

====================================================================
IMPORTANT INTERVIEW QUESTIONS
====================================================================

Q1. Why MST contains V-1 edges?

Q2. Why cycle is not allowed?

Q3. Can MST contain negative weights?
-> YES

Q4. Can multiple MSTs exist?
-> YES

Q5. Difference between shortest path and MST?

====================================================================
VERY IMPORTANT POINT
====================================================================

MST works ONLY on:

-> Weighted
-> Undirected
-> Connected graph

====================================================================

*/
/*
============================================================
GRAPH NOTES (COMPLETE) - BASICS + TYPES + REAL WORLD
============================================================

------------------------------------------------------------
1) WHAT IS A GRAPH?
------------------------------------------------------------
- A graph is a NON-LINEAR data structure
- Consists of:
    • Vertices (Nodes)
    • Edges (Connections)

Example:
A ----- B
|       |
C ----- D

============================================================

2) TYPES OF GRAPHS
------------------------------------------------------------

1) Undirected Graph
   - Edges have no direction
   - A -- B (both ways)

2) Directed Graph (DiGraph)
   - Edges have direction
   - A → B

3) Weighted Graph
   - Edges have weights (cost/distance)

4) Unweighted Graph
   - All edges equal

5) Cyclic Graph
   - Contains cycle

6) Acyclic Graph
   - No cycle

7) Connected Graph
   - Every node reachable

8) Disconnected Graph
   - Some nodes not connected

============================================================

3) GRAPH REPRESENTATION
------------------------------------------------------------

1) Adjacency Matrix
   - 2D array (n x n)
   - Space: O(n^2)

2) Adjacency List (MOST USED)
   - Vector of lists
   - Space: O(V + E)

============================================================

4) BASIC TERMINOLOGY
------------------------------------------------------------

- Degree → Number of edges connected
- Indegree → Incoming edges
- Outdegree → Outgoing edges
- Path → Sequence of nodes
- Cycle → Path that starts & ends same node

============================================================

5) GRAPH TRAVERSAL
------------------------------------------------------------

1) BFS (Breadth First Search)
   - Uses Queue
   - Level-wise traversal
   - Shortest path (unweighted)

2) DFS (Depth First Search)
   - Uses Stack / Recursion
   - Goes deep first

============================================================

6) REAL WORLD APPLICATIONS
============================================================

------------------------------------------------------------
A) GOOGLE MAPS (SHORTEST PATH)
------------------------------------------------------------
- Nodes → Cities
- Edges → Roads
- Weight → Distance/Time

Algorithms:
- Dijkstra
- BFS (unweighted)

Example:
Delhi ---- Jaipur ---- Udaipur
   \                      /
    -------- Ajmer ------

============================================================

------------------------------------------------------------
B) FACEBOOK / INSTAGRAM (MUTUAL FRIENDS)
------------------------------------------------------------
- Nodes → Users
- Edges → Friendships

Use:
- Friend Suggestions

Example:
A → B, C
B → A, D
C → A, D

Suggestion → D (common connection)

============================================================

------------------------------------------------------------
C) NETWORK ROUTING (INTERNET)
------------------------------------------------------------
- Nodes → Routers
- Edges → Network links

Goal:
- Fastest data transfer

============================================================

------------------------------------------------------------
D) RECOMMENDATION SYSTEMS
------------------------------------------------------------
- Nodes → Users + Products
- Edges → Interactions

Use:
- Netflix, Amazon recommendations

============================================================

------------------------------------------------------------
E) DEPENDENCY GRAPH (PROJECTS)
------------------------------------------------------------
- Nodes → Tasks
- Edges → Dependencies

Used in:
- Topological Sort

Example:
A → B → C

============================================================

------------------------------------------------------------
F) WEB SEARCH (GOOGLE)
------------------------------------------------------------
- Nodes → Web pages
- Edges → Links

Used in:
- PageRank

============================================================

------------------------------------------------------------
G) FLIGHT SYSTEM
------------------------------------------------------------
- Nodes → Airports
- Edges → Flights

Use:
- Cheapest / shortest route

============================================================

7) COMMON GRAPH ALGORITHMS
------------------------------------------------------------

- BFS → Shortest path (unweighted)
- DFS → Traversal
- Dijkstra → Shortest path (weighted)
- Bellman-Ford → Negative weights
- Floyd-Warshall → All pairs shortest path
- Topological Sort → DAG
- Union-Find → Cycle detection

============================================================

8) TIME COMPLEXITY
------------------------------------------------------------

Adj List:
- BFS/DFS → O(V + E)

Adj Matrix:
- BFS/DFS → O(V^2)

============================================================

9) QUICK REVISION
------------------------------------------------------------

- Graph = Nodes + Edges
- BFS → Queue → Level order
- DFS → Stack → Deep traversal
- Directed vs Undirected
- Weighted vs Unweighted

REAL WORLD:
- Maps → Shortest Path
- Social Media → Suggestions
- Internet → Routing
- Amazon/Netflix → Recommendation
- Projects → Dependency Graph

============================================================
*/
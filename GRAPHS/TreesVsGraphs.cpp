/*
============================================================
TREES vs GRAPHS
============================================================

->Every Tree is a Graph but Every Graph is not a tree
------------------------------------------------------------
1) DEFINITIONS
------------------------------------------------------------

TREE:
- Special type of graph
- Hierarchical structure
- No cycles
- Connected

GRAPH:
- General data structure
- May or may not be connected
- May contain cycles

============================================================

2) STRUCTURE
------------------------------------------------------------

TREE:
- Root node present
- Parent → Child relation
- Exactly one path between any two nodes

GRAPH:
- No fixed root
- Arbitrary connections
- Multiple paths possible

============================================================

3) NUMBER OF EDGES
------------------------------------------------------------

TREE:
- If n nodes:
  edges = n - 1

GRAPH:
- No fixed formula
- Can have multiple edges

============================================================

4) CYCLES
------------------------------------------------------------

TREE:
- No cycles allowed

GRAPH:
- Cycles may exist

============================================================

5) CONNECTIVITY
------------------------------------------------------------

TREE:
- Always connected

GRAPH:
- May be disconnected

============================================================

6) DIRECTION
------------------------------------------------------------

TREE:
- Mostly directed (parent → child)
- Sometimes considered undirected

GRAPH:
- Can be directed or undirected

============================================================

7) ROOT NODE
------------------------------------------------------------

TREE:
- One root node

GRAPH:
- No root concept

============================================================

8) PATH
------------------------------------------------------------

TREE:
- Only one unique path between nodes

GRAPH:
- Multiple paths possible

============================================================

9) HIERARCHY
------------------------------------------------------------

TREE:
- Strict hierarchical structure

GRAPH:
- No hierarchy

============================================================

10) TRAVERSAL
------------------------------------------------------------

TREE:
- Inorder
- Preorder
- Postorder
- Level Order

GRAPH:
- BFS
- DFS

============================================================

11) APPLICATIONS
------------------------------------------------------------

TREE:
- File systems
- BST
- Heaps
- Expression trees

GRAPH:
- Google Maps (shortest path)
- Social networks (friends)
- Routing networks
- Recommendation systems

============================================================

12) EXAMPLE
------------------------------------------------------------

TREE:

        1
       / \
      2   3
     /
    4

GRAPH:

    1 ---- 2
    |    / |
    4 ---- 3

============================================================

13) SUMMARY
------------------------------------------------------------

TREE:
- No cycles
- Connected
- n nodes → n-1 edges
- One path between nodes

GRAPH:
- General structure
- May have cycles
- Multiple paths
- May be disconnected

============================================================
END OF FILE
============================================================
*/
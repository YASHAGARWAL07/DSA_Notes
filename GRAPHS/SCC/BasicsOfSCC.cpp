/*
====================================================================
STRONGLY CONNECTED COMPONENT (SCC)
====================================================================

DEFINITION
====================================================================

A Strongly Connected Component (SCC) is a maximal group of vertices
in a Directed Graph such that every vertex is reachable from every
other vertex in that group.

In simple words,

For every pair of vertices (u, v),

u can reach v

AND

v can also reach u.

If this condition is satisfied, they belong to the same SCC.

====================================================================
WHY "STRONGLY" CONNECTED?
====================================================================

In an Undirected Graph,

Connected means every node can reach every other node.

In a Directed Graph,

Directions matter.

Even if u can reach v,

v may not be able to reach u.

Therefore we introduce the term

Strongly Connected.

====================================================================
EXAMPLE 1
====================================================================

        0 → 1
        ↑   ↓
        3 ← 2

Here,

0 can reach 1,2,3

1 can reach 0,2,3

2 can reach 0,1,3

3 can reach 0,1,2

Every node can reach every other node.

Therefore,

SCC = {0,1,2,3}

Number of SCC = 1

====================================================================
EXAMPLE 2
====================================================================

0 → 1 → 2

0 cannot be reached from 2.

1 cannot be reached from 2.

Hence,

SCCs are

{0}

{1}

{2}

Total SCC = 3

====================================================================
EXAMPLE 3
====================================================================

      0 ↔ 1

      2 ↔ 3

      1 → 2

SCCs are

{0,1}

{2,3}

There are two SCCs.

Although there is an edge from
SCC1 to SCC2,

there is no path back.

Hence they remain separate SCCs.

====================================================================
PROPERTIES OF SCC
====================================================================

1.

Every Directed Graph has at least one SCC.

------------------------------------------------------------

2.

A single isolated vertex is also an SCC.

------------------------------------------------------------

3.

Every vertex belongs to exactly one SCC.

------------------------------------------------------------

4.

Different SCCs never overlap.

------------------------------------------------------------

5.

If the entire graph is mutually reachable,

the whole graph becomes one SCC.

------------------------------------------------------------

6.

After compressing every SCC into one node,

the resulting graph is always a DAG
(Directed Acyclic Graph).

====================================================================
WHEN DO WE NEED SCC?
====================================================================

Whenever the graph is Directed
and we need to find groups of nodes
that are mutually reachable.

====================================================================
APPLICATIONS
====================================================================

• Social Networks

• Compiler Optimization

• Deadlock Detection

• Package Dependency Graphs

• Web Crawlers

• Circuit Analysis

• Network Routing

• Graph Compression

====================================================================
ALGORITHMS TO FIND SCC
====================================================================

1.

Kosaraju Algorithm

Time Complexity

O(V + E)

Uses

• 2 DFS
• Graph Transpose
• Stack

------------------------------------------------------------

2.

Tarjan Algorithm

Time Complexity

O(V + E)

Uses

• 1 DFS
• Discovery Time
• Low Link Value
• Stack

No graph reversal required.

====================================================================
CONNECTED COMPONENT vs STRONGLY CONNECTED COMPONENT
====================================================================

Connected Component

↓

Undirected Graph

Uses

DFS / BFS

------------------------------------------------------------

Strongly Connected Component

↓

Directed Graph

Uses

Kosaraju

or

Tarjan Algorithm

====================================================================
INTERVIEW TIP
====================================================================

Whenever the interviewer says

"Directed Graph"

and asks

• Count SCCs

• Print SCCs

• Compress Graph

Immediately think

Kosaraju Algorithm

or

Tarjan Algorithm.

====================================================================
QUICK REVISION
====================================================================

Graph Type

↓

Directed Graph

------------------------------------------------------------

Condition

↓

Every node should be reachable
from every other node.

------------------------------------------------------------

Algorithms

↓

Kosaraju

Tarjan

------------------------------------------------------------

Time Complexity

↓

O(V + E)

------------------------------------------------------------

Applications

↓

Dependency Analysis

Deadlock Detection

Compiler Design

Network Analysis

Social Networks

====================================================================
*/
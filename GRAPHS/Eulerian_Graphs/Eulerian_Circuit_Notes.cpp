#include <iostream>
#include <vector>
using namespace std;

/*

==============================================================
EULERIAN CIRCUIT IN GRAPH
==============================================================

DEFINITION:
--------------------------------------------------------------
Euler Circuit is a circuit in graph which visits every edge
EXACTLY ONCE and returns back to starting node.

Start node == End node

==============================================================
EXAMPLE
==============================================================

0 ----- 1
|       |
|       |
3 ----- 2

Euler Circuit:
0 -> 1 -> 2 -> 3 -> 0

Every edge visited exactly once
and starts/ends at same node.

==============================================================
CONDITIONS FOR EULER CIRCUIT
==============================================================

For UNDIRECTED GRAPH:

1. Graph should be connected
   (All non-zero degree nodes connected)

2. ALL nodes should have EVEN degree

==============================================================
WHY EVEN DEGREE?
==============================================================

Whenever we enter a node,
we must leave that node too.

So edges always form pairs.

Hence degree must be EVEN.

==============================================================
HOW TO CHECK EULER CIRCUIT
==============================================================

STEP 1:
Find degree of every node

STEP 2:
Check all degrees are even

STEP 3:
Check connectivity
(ignore isolated nodes)

STEP 4:
If both true
=> Euler Circuit exists

==============================================================
WHEN EULER CIRCUIT NOT POSSIBLE?
==============================================================

1. Graph disconnected

2. Any node has odd degree

==============================================================
IMPORTANT NOTE
==============================================================

If Euler Circuit exists,
then Euler Path also exists.

But reverse is NOT always true.

==============================================================
TIME COMPLEXITY
==============================================================

Finding degree      -> O(E)
DFS/BFS             -> O(V + E)

Overall:
O(V + E)

==============================================================
SPACE COMPLEXITY
==============================================================

Adjacency List -> O(V + E)
Visited Array  -> O(V)

Overall:
O(V + E)

==============================================================
IMPORTANT EDGE CASES
==============================================================

1. Single node graph
   -> Euler Circuit possible

2. Empty graph
   -> Euler Circuit possible

3. Isolated nodes
   -> Ignore during connectivity check

4. One odd degree node
   -> Not possible

5. Two odd degree nodes
   -> Euler PATH possible
   -> Euler CIRCUIT NOT possible

==============================================================
DIRECTED GRAPH CONDITIONS
==============================================================

Euler Circuit in Directed Graph:

1. indegree == outdegree for every node

2. Graph strongly connected
   (or weakly connected ignoring zero degree nodes)

==============================================================
EULER PATH vs EULER CIRCUIT
==============================================================

Euler Path:
-------------
Start != End possible
0 or 2 odd degree nodes

Euler Circuit:
----------------
Start == End
All degrees even

==============================================================
INTERVIEW QUESTIONS
==============================================================

Q1. Can Euler Circuit exist with odd degree node?
-> NO

Q2. If Euler Circuit exists,
does Euler Path exist?
-> YES

Q3. Why even degree required?

Q4. Difference between connected and strongly connected?

Q5. Why isolated nodes ignored?

==============================================================
IMPORTANT FORMULA
==============================================================

Undirected Graph:

Euler Circuit Exists IF:
1. Graph connected
2. All degrees even

==============================================================
REAL LIFE APPLICATIONS
==============================================================

1. Drawing figures without lifting pen
2. Network routing
3. Street sweeping
4. Delivery optimization
5. PCB design

==============================================================
VERY IMPORTANT CONCEPT
==============================================================

Euler:
------
EDGE based traversal

Hamiltonian:
------------
NODE based traversal

==============================================================
SHORT REVISION
==============================================================

Euler Circuit:
---------------
1. Visit every edge exactly once
2. Start node == End node
3. Graph connected
4. All degrees even

==============================================================

*/

int main() {

    cout << "Euler Circuit Notes" << endl;

    return 0;
}
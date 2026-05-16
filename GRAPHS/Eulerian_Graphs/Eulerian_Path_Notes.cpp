#include <iostream>
#include <vector>
using namespace std;

/*

==============================================================
EULERIAN PATH IN GRAPH
==============================================================

DEFINITION:
--------------------------------------------------------------
Euler Path is a path in graph which visits every edge
EXACTLY ONCE.

Start node and end node can be DIFFERENT.

--------------------------------------------------------------
EXAMPLE:
--------------------------------------------------------------

0 ----- 1
|       |
|       |
2 ----- 3

Possible Euler Path:
0 -> 1 -> 3 -> 2 -> 0

Every edge visited exactly once.

==============================================================
CONDITIONS FOR EULER PATH
==============================================================

For UNDIRECTED GRAPH:

1. Graph should be connected
   (All non-zero degree nodes should be connected)

2. Number of odd degree nodes should be:
   -> Either 0
   -> OR 2

--------------------------------------------------------------
CASE 1:
--------------------------------------------------------------

0 odd degree nodes
=> Euler Circuit exists
=> Euler Path also exists

--------------------------------------------------------------
CASE 2:
--------------------------------------------------------------

2 odd degree nodes
=> Euler Path exists
=> Euler Circuit DOES NOT exist

Path starts from one odd node
and ends at another odd node.

--------------------------------------------------------------
CASE 3:
--------------------------------------------------------------

More than 2 odd degree nodes
=> Euler Path NOT possible

==============================================================
IMPORTANT POINT
==============================================================

Every graph cannot have Euler Path.

--------------------------------------------------------------
Example:
--------------------------------------------------------------

Degree:
0 -> 3
1 -> 3
2 -> 2
3 -> 2

Odd degree nodes = 2
=> Euler Path exists

==============================================================
HOW TO CHECK EULER PATH
==============================================================

STEP 1:
Find degree of every node

STEP 2:
Count odd degree nodes

STEP 3:
Check connectivity
(ignore zero degree nodes)

STEP 4:
Apply conditions

==============================================================
TIME COMPLEXITY
==============================================================

Finding degrees      -> O(E)
DFS/BFS connectivity -> O(V + E)

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

1. Empty graph
   -> Euler Path possible

2. Single node graph
   -> Euler Path possible

3. Disconnected graph
   -> Euler Path NOT possible

4. Graph with isolated nodes
   -> Ignore isolated nodes while checking connectivity

5. More than 2 odd nodes
   -> Not possible

==============================================================
EULER PATH vs HAMILTONIAN PATH
==============================================================

Euler Path:
-------------
Visits every EDGE exactly once

Hamiltonian Path:
-----------------
Visits every NODE exactly once

==============================================================
INTERVIEW QUESTIONS
==============================================================

Q1. Difference between Euler Path and Euler Circuit?

Q2. Why can only 0 or 2 odd degree nodes exist?

Q3. Why isolated nodes are ignored?

Q4. Why connected component is important?

Q5. Can disconnected graph have Euler Path?
-> NO

==============================================================
IMPORTANT FORMULA
==============================================================

Undirected Graph:

Euler Path Exists IF:
odd degree nodes == 0 OR 2

==============================================================
DIRECTED GRAPH CONDITIONS
==============================================================

Euler Path in Directed Graph:

1. At most one node:
   outdegree = indegree + 1

2. At most one node:
   indegree = outdegree + 1

3. All remaining nodes:
   indegree == outdegree

4. Graph connected

==============================================================
REAL LIFE APPLICATIONS
==============================================================

1. Route planning
2. Garbage collection path
3. Postal delivery
4. Network traversal
5. DNA sequencing

==============================================================
SHORT REVISION
==============================================================

Euler Path:
-----------
1. Visit every edge exactly once
2. Start and end may be different
3. Graph connected
4. Odd degree nodes:
   -> 0 or 2

==============================================================

*/

int main() {

    cout << "Euler Path Notes" << endl;

    return 0;
}
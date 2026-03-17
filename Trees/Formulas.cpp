/*
------------------------------------------------------------
3. IMPORTANT TREE PROPERTIES & FORMULAS
------------------------------------------------------------

Let:

N = Total number of nodes
E = Total number of edges
H = Height of tree
L = Number of leaf nodes
I = Number of internal nodes


------------------------------------------------------------
1) TOTAL NUMBER OF EDGES
------------------------------------------------------------

Formula:

E = N - 1

Explanation:

Every node except the root has exactly one incoming edge.

Example:

Nodes = 7

Edges = 7 - 1
Edges = 6


------------------------------------------------------------
2) MAXIMUM NODES AT LEVEL L
------------------------------------------------------------

Formula:

Maximum nodes = 2^L

Where:

L = level number
(Level starts from 0)

Example:

Level 0 → 2^0 = 1
Level 1 → 2^1 = 2
Level 2 → 2^2 = 4
Level 3 → 2^3 = 8


------------------------------------------------------------
3) MAXIMUM NODES IN A BINARY TREE
------------------------------------------------------------

Formula:

Max Nodes = 2^(H+1) - 1

Where:

H = height of tree

Example:

Height = 3

Max Nodes = 2^(3+1) - 1
Max Nodes = 16 - 1
Max Nodes = 15


------------------------------------------------------------
4) MAXIMUM LEAF NODES
------------------------------------------------------------

Formula:

Max Leaf Nodes = 2^H

Example:

Height = 3

Leaf Nodes = 2^3 = 8


------------------------------------------------------------
5) RELATION BETWEEN LEAF & INTERNAL NODES
(FULL BINARY TREE)
------------------------------------------------------------

Formula:

L = I + 1

Where:

L = number of leaf nodes
I = number of internal nodes


------------------------------------------------------------
6) MINIMUM HEIGHT OF BINARY TREE
------------------------------------------------------------

Formula:

H = log2(N)

Example:

Nodes = 15

Height = log2(15) ≈ 3


------------------------------------------------------------
7) MAXIMUM HEIGHT OF BINARY TREE
------------------------------------------------------------

Worst Case (Skewed Tree)

Formula:

H = N - 1

Example:

Nodes = 5

Height = 4
*/


/*
------------------------------------------------------------
TREE EXAMPLE FOR FORMULA UNDERSTANDING
------------------------------------------------------------

                1
              /   \
             2     3
           /  \   /  \
          4    5 6    7

Nodes = 7

Edges = 6

Height = 2

Leaf Nodes = 4
*/

/*
====================================================================================================
                                   M-COLORING PROBLEM (BACKTRACKING)
====================================================================================================

PROBLEM:
GeeksforGeeks - M Coloring Problem

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given an undirected graph with V vertices and E edges along with an integer M,
determine whether it is possible to color all vertices using at most M colors
such that no two adjacent vertices have the same color.

Return true if possible, otherwise return false.

====================================================================================================
PREREQUISITES
====================================================================================================

• Graph Representation
• DFS
• Recursion
• Backtracking

====================================================================================================
INTUITION
====================================================================================================

Each node can be painted using one of the M available colors.

For every node,

Try Color 1

↓

If valid,

Move to next node.

↓

If later no color works,

Undo the current assignment

and try another color.

This process continues until

either

every node gets a valid color

or

all possibilities are exhausted.

This "Try → Explore → Undo"

is Backtracking.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Convert edge list into adjacency list.

↓

Step 2

Maintain a color array.

Initially every node has color 0.

↓

Step 3

Start coloring from node 0.

↓

Step 4

Try every color

1 to M.

↓

Step 5

Check whether any adjacent node already has
the same color.

↓

If safe,

Assign the color.

↓

Recursively color next node.

↓

If recursion succeeds,

Return true.

↓

Else

Remove the color

(Backtrack)

↓

Try next color.

====================================================================================================
ALGORITHM
====================================================================================================

Color(Node)

↓

Node == V ?

Return true

↓

Try Color 1

↓

Safe ?

↓

YES

↓

Assign Color

↓

Color(Node+1)

↓

Success ?

↓

YES

Return true

↓

NO

Undo Assignment

↓

Try Next Color

↓

No Color Works

↓

Return false

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Functions Used

1.

find()

Recursive Backtracking function.

Attempts to color one node at a time.

-----------------------------------------

2.

graphColoring()

Creates adjacency list.

Initializes color array.

Starts recursion.

====================================================================================================
HOW YOUR SAFE CHECK WORKS
====================================================================================================

For every color i,

your code checks every adjacent vertex.

for(auto j : graph[node])

↓

If

color[j] == i

↓

Current color cannot be used.

Otherwise,

assign the color.

This avoids writing a separate isSafe() function.

The safety checking is performed directly inside find().

====================================================================================================
BACKTRACKING STEP
====================================================================================================

Assign Color

↓

Recursive Call

↓

Fails ?

↓

color[node] = 0;

↓

Try another color.

====================================================================================================
BASE CASE
====================================================================================================

If

node == n

All vertices have been colored successfully.

Return true.

====================================================================================================
DRY RUN
====================================================================================================

Example

0 ---- 1
|      |
|      |
2 ---- 3

M = 3

Start

Node 0

Try Color 1

Success

↓

Node 1

Color 1 not possible

Use Color 2

↓

Node 2

Color 2 not possible

Use Color 3

↓

Node 3

Color 1 possible

↓

All nodes colored

Return true.

====================================================================================================
WHY BACKTRACKING WORKS
====================================================================================================

Whenever a wrong color is assigned,

future nodes may become impossible to color.

Instead of stopping,

we simply remove the previous color

and explore another possibility.

Eventually,

either

a valid coloring is found

or

every possible coloring has been explored.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Worst Case

O(M^V)

where

M = Number of Colors

V = Number of Vertices

Every vertex may try every color.

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

Adjacency List

O(V + E)

Color Array

O(V)

Recursive Stack

O(V)

Overall

O(V + E)

====================================================================================================
EDGE CASES
====================================================================================================

✓ Single Vertex

✓ Empty Graph

✓ Complete Graph

✓ Bipartite Graph

✓ M = 1

✓ M greater than number of vertices

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why Backtracking?

Because one wrong color choice may prevent
future nodes from being colored.

------------------------------------------------

Q2.

Can Greedy always solve this?

No.

Greedy may fail even when a valid coloring exists.

------------------------------------------------

Q3.

Can this be optimized?

Yes.

Using

• Vertex Ordering

• Degree Heuristic

• Bitmasking

• Constraint Propagation

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Backtracking Problem

✓ Graph Coloring

✓ DFS + Recursion

✓ Try every color

✓ Undo on failure

✓ Explore all possibilities

====================================================================================================
APPLICATIONS
====================================================================================================

• Register Allocation

• Exam Timetabling

• Frequency Assignment

• Map Coloring

• Scheduling Problems

• Resource Allocation

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Sudoku Solver

• N Queens

• Rat in a Maze

• Hamiltonian Path

• Word Search

• Crossword Puzzle

• Combination Sum

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Graph Coloring is an NP-Complete problem.

✓ Backtracking guarantees finding a solution if one exists.

✓ Try → Check → Recurse → Undo.

✓ Adjacency list makes neighbor checking efficient.

✓ Your implementation performs safety checking directly inside recursion.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool find(int node, vector<vector<int>> &graph, int n, int m, vector<int> &color)
    {
        // Base condition
        if(node == n)
            return true;

        // Color the node with m colors
        for(int i = 1; i <= m; i++)
        {
            // Check whether adjacent nodes have same color
            bool IsPossible = true;

            for(auto j : graph[node])
            {
                if(color[j] == i)
                {
                    IsPossible = false;
                    break;
                }
            }

            // Assign color
            if(IsPossible)
            {
                color[node] = i;

                if(find(node + 1, graph, n, m, color))
                    return true;

                // Backtrack
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        // Create graph from edges
        vector<vector<int>> graph(v);

        for(auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> color(v, 0);

        return find(0, graph, v, m, color);
    }
};

int main()
{
    Solution obj;

    int V = 4;
    int M = 3;

    vector<vector<int>> edges = {
        {0,1},
        {1,3},
        {2,3},
        {3,0},
        {0,2}
    };

    if(obj.graphColoring(V, edges, M))
        cout << "Graph can be colored using " << M << " colors." << endl;
    else
        cout << "Graph cannot be colored using " << M << " colors." << endl;

    return 0;
}
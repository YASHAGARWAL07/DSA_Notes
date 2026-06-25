#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
                    HAMILTONIAN PATH
====================================================================

There is NO fixed algorithm like

• BFS
• DFS
• Dijkstra
• Bellman Ford
• Floyd Warshall
• Prim's
• Kruskal

to solve Hamiltonian Path for a general graph.

Hamiltonian Path is an NP-Complete Problem.

Hence,

Backtracking is the standard approach.

For smaller constraints,

Dynamic Programming + Bitmask can also be used.

====================================================================
WHAT IS HAMILTONIAN PATH?
====================================================================

A Hamiltonian Path is a path that visits

EVERY VERTEX

exactly ONCE.

Vertices should not repeat.

Edges may or may not repeat,
but since every vertex is visited exactly once,
repeating an edge is generally impossible.

Example

1 ----- 2
|       |
|       |
4 ----- 3

Hamiltonian Path

1 → 2 → 3 → 4

Every vertex visited exactly once.

====================================================================
WHAT IS HAMILTONIAN CYCLE?
====================================================================

A Hamiltonian Cycle is a Hamiltonian Path
that returns to the starting vertex.

Example

1 → 2 → 3 → 4 → 1

Start = End

Every vertex visited exactly once.

====================================================================
HAMILTONIAN PATH vs HAMILTONIAN CYCLE
====================================================================

Hamiltonian Path

• Visits every vertex once.

• Start and End may be different.

------------------------------------------

Hamiltonian Cycle

• Visits every vertex once.

• Start and End must be same.

====================================================================
WHY BACKTRACKING?
====================================================================

Unlike Euler Path,

there is NO mathematical property

like

Odd Degree

Even Degree

or

Discovery Time

which directly tells whether
Hamiltonian Path exists.

We must

TRY

every possible path.

If one path visits all vertices,

answer is TRUE.

Otherwise,

FALSE.

Hence,

Backtracking.

====================================================================
INTUITION
====================================================================

Start from every vertex.

↓

Mark current node visited.

↓

Visit every unvisited neighbour.

↓

Repeat.

↓

If all vertices become visited,

Hamiltonian Path exists.

↓

Otherwise,

Backtrack.

↓

Unvisit current node.

↓

Try another neighbour.

====================================================================
APPROACH
====================================================================

1.

Create adjacency list.

2.

Create visited[] array.

3.

Start DFS from every vertex.

4.

Mark current node visited.

5.

Increase visited count.

6.

If count == n

return true.

7.

Visit every unvisited neighbour.

8.

If neighbour gives answer,

return true.

9.

Otherwise,

Backtrack.

10.

Unvisit current node.

11.

Decrease count.

12.

Return false.

====================================================================
WHY START DFS FROM EVERY NODE?
====================================================================

Hamiltonian Path

can start from ANY vertex.

Example

1 ---- 2 ---- 3

Starting from

2

fails.

Starting from

1

works.

Hence

Run DFS from every node.

====================================================================
CODE
====================================================================

class Solution {
public:

    bool DFS(int node,
             vector<vector<int>>&adj,
             vector<bool>&visited,
             int &count,
             int n){

        visited[node]=1;                 //mark visited

        count++;                         //visited one more node

        //All vertices visited
        if(count==n)
            return true;

        //Visit neighbours
        for(int j=0;j<adj[node].size();j++){

            int neigh=adj[node][j];

            if(!visited[neigh] &&
               DFS(neigh,adj,visited,count,n))

                return true;
        }

        //Backtracking

        visited[node]=0;

        count--;

        return false;
    }

    bool check(int n,int m,
               vector<vector<int>> edges){

        //Create adjacency list

        vector<vector<int>>adj(n);

        for(int i=0;i<m;i++){

            int u=edges[i][0]-1;

            int v=edges[i][1]-1;

            adj[u].push_back(v);

            adj[v].push_back(u);

        }

        vector<bool>visited(n,0);

        int count=0;

        //Try every starting node

        for(int i=0;i<n;i++){

            if(DFS(i,adj,visited,count,n))

                return true;

        }

        return false;
    }

};

====================================================================
VS CODE RUNNABLE CODE
====================================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool DFS(int node,vector<vector<int>>&adj,
             vector<bool>&visited,int &count,int n){

        visited[node]=1;                 //mark current node visited

        count++;                         //visited one more node

        if(count==n)                     //all vertices visited

            return true;

        for(int j=0;j<adj[node].size();j++){

            int neigh=adj[node][j];

            if(!visited[neigh] &&
               DFS(neigh,adj,visited,count,n))

                return true;
        }

        //Backtracking

        visited[node]=0;

        count--;

        return false;
    }

    bool check(int n,int m,vector<vector<int>> edges){

        vector<vector<int>>adj(n);

        for(int i=0;i<m;i++){

            int u=edges[i][0]-1;

            int v=edges[i][1]-1;

            adj[u].push_back(v);

            adj[v].push_back(u);

        }

        vector<bool>visited(n,0);

        int count=0;

        for(int i=0;i<n;i++){

            if(DFS(i,adj,visited,count,n))

                return true;

        }

        return false;
    }
};

int main(){

    int n=4;
    int m=4;

    vector<vector<int>>edges={
        {1,2},
        {2,3},
        {3,4},
        {2,4}
    };

    Solution obj;

    if(obj.check(n,m,edges))

        cout<<"Hamiltonian Path Exists";

    else

        cout<<"Hamiltonian Path Does Not Exist";

    return 0;
}

====================================================================
DRY RUN
====================================================================

Example

n = 4

1 ----- 2
|       |
|       |
4 ----- 3

Edges

1-2
2-3
3-4
4-1

------------------------------------------

Start DFS from 1

visited = {1}

count = 1

↓

Go to 2

visited = {1,2}

count = 2

↓

Go to 3

visited = {1,2,3}

count = 3

↓

Go to 4

visited = {1,2,3,4}

count = 4

Since count == n

Return TRUE

Hamiltonian Path exists.

====================================================================
BACKTRACKING VISUALIZATION
====================================================================

Suppose

1

/ \

2  3

 \
  4

Start

1

↓

Choose

2

↓

Choose

4

↓

Dead End

↓

Backtrack

Remove 4

↓

Remove 2

↓

Choose

3

↓

Continue exploring

This is exactly why it is called

BACKTRACKING

====================================================================
TIME COMPLEXITY
====================================================================

Worst Case

O(N!)

Reason

Every vertex can be visited
in every possible order.

Example

1

Can go to

2

or

3

or

4

Then again

remaining vertices

Hence

N!

====================================================================
SPACE COMPLEXITY
====================================================================

Visited Array

O(N)

Recursion Stack

O(N)

Adjacency List

O(V+E)

Overall

O(V+E)

====================================================================
WHY IS HAMILTONIAN PATH HARD?
====================================================================

There is NO greedy choice.

There is NO shortest path property.

There is NO degree property.

There is NO mathematical shortcut.

We must explore different possibilities.

Hence,

Hamiltonian Path is

NP Complete.

====================================================================
WHEN TO USE BACKTRACKING?
====================================================================

Whenever

• Need every possible arrangement

• Need every possible path

• Decision tree exploration

Examples

N Queens

Sudoku

Rat in Maze

Hamiltonian Path

Permutation Generation

Subset Generation

====================================================================
HAMILTONIAN vs EULER
====================================================================

Hamiltonian Path

Visits

VERTICES

exactly once.

------------------------------------------

Euler Path

Visits

EDGES

exactly once.

------------------------------------------

Hamiltonian Cycle

Start = End

Every vertex exactly once.

------------------------------------------

Euler Circuit

Start = End

Every edge exactly once.

====================================================================
IMPORTANT DIFFERENCE
====================================================================

Euler

↓

Concerned with

EDGES

Degree matters.

Odd / Even degree matters.

Can be solved mathematically.

------------------------------------------

Hamiltonian

↓

Concerned with

VERTICES

Degree does NOT directly determine answer.

Usually solved using

Backtracking.

====================================================================
WHEN TO USE HAMILTONIAN PATH?
====================================================================

Whenever

Every city

Every computer

Every location

Every task

must be visited

ONLY ONCE.

====================================================================
REAL WORLD APPLICATIONS
====================================================================

1.

Route Planning

Visit every city exactly once.

------------------------------------------

2.

Delivery Optimization

Parcel delivery.

------------------------------------------

3.

Robot Navigation

Visit every checkpoint once.

------------------------------------------

4.

PCB Manufacturing

Tool path optimization.

------------------------------------------

5.

Genome Sequencing

DNA reconstruction.

------------------------------------------

6.

Network Testing

Visit every server once.

------------------------------------------

7.

Scheduling Problems

Complete every task exactly once.

====================================================================
EDGE CASES
====================================================================

1.

Single Vertex

Answer = TRUE

------------------------------------------

2.

Disconnected Graph

FALSE

------------------------------------------

3.

Graph with isolated node

FALSE

------------------------------------------

4.

Tree

May or may not contain Hamiltonian Path.

------------------------------------------

5.

Complete Graph

Always has Hamiltonian Path.

====================================================================
COMMON MISTAKES
====================================================================

1.

Forget Backtracking

visited[node]=0

count--

------------------------------------------

2.

Start DFS from only one node

Wrong.

Hamiltonian Path can start anywhere.

------------------------------------------

3.

Forget to mark visited.

------------------------------------------

4.

Forget to decrease count while backtracking.

------------------------------------------

5.

Wrong indexing

GFG uses

1-based edges

Need

-1

conversion.

====================================================================
INTERVIEW QUESTIONS
====================================================================

Q1.

Difference between Hamiltonian and Euler?

------------------------------------------

Q2.

Why Backtracking?

------------------------------------------

Q3.

Can BFS solve Hamiltonian Path?

No.

------------------------------------------

Q4.

Can DFS alone solve Hamiltonian Path?

Only with Backtracking.

------------------------------------------

Q5.

Time Complexity?

O(N!)

------------------------------------------

Q6.

Why NP Complete?

No polynomial time algorithm
is known for the general graph.

====================================================================
QUICK REVISION
====================================================================

Hamiltonian Path

↓

Visit every vertex exactly once.

------------------------------------------

Hamiltonian Cycle

↓

Visit every vertex exactly once.

Start = End.

------------------------------------------

Algorithm

↓

Backtracking

------------------------------------------

Technique

↓

DFS + Backtracking

------------------------------------------

Time

↓

O(N!)

------------------------------------------

Space

↓

O(V+E)

------------------------------------------

Remember

Hamiltonian

→ Vertices

Euler

→ Edges

====================================================================
INTERVIEW TIP
====================================================================

Whenever the question says

"Visit every vertex exactly once"

Immediately think

Hamiltonian Path

↓

Backtracking

NOT

DFS

NOT

BFS

NOT

Dijkstra

NOT

MST

because there is no fixed polynomial-time algorithm for the general Hamiltonian Path problem.

====================================================================

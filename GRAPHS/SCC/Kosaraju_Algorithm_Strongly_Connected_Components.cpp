#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
KOSARAJU ALGORITHM (STRONGLY CONNECTED COMPONENTS)
====================================================================

PROBLEM

Given a Directed Graph,

Find the number of
Strongly Connected Components (SCCs).

====================================================================
WHAT IS A STRONGLY CONNECTED COMPONENT (SCC)?
====================================================================

A Strongly Connected Component is a group of vertices
such that every vertex is reachable from every other
vertex in that group.

Suppose

0 → 1
↑   ↓
3 ← 2

Every node can reach every other node.

Hence,

{0,1,2,3}

is one SCC.

---------------------------------------------------------

Another Example

0 → 1 → 2

No way to come back.

SCCs

{0}
{1}
{2}

Total = 3

====================================================================
WHY ONLY DIRECTED GRAPH?
====================================================================

Kosaraju Algorithm works ONLY for Directed Graphs.

Reason

Reachability changes when directions change.

In Undirected Graph

Connected Components

can be found simply using

DFS / BFS.

No need of Kosaraju.

====================================================================
INTUITION
====================================================================

Suppose

A -----> B

where

A and B are SCCs.

Graph

A ---> B

Once we enter B,

we cannot come back to A.

So while doing DFS,

A finishes AFTER B.

Therefore,

A should appear ABOVE B
inside the stack.

That is exactly what
Topological Finish Order stores.

====================================================================
WHY DO WE REVERSE THE GRAPH?
====================================================================

Original

A -----> B

Reverse

A <----- B

Now,

starting from A (top of stack),

we cannot go into another SCC.

DFS remains inside one SCC.

Hence,

one DFS
=
one SCC.

This is the whole idea of
Kosaraju Algorithm.

====================================================================
ALGORITHM
====================================================================

STEP 1

Create adjacency list.

↓

STEP 2

Perform DFS.

Store vertices in stack
according to finishing time.

↓

STEP 3

Reverse every edge.

(Create Transpose Graph)

↓

STEP 4

Pop one vertex at a time.

↓

STEP 5

If vertex not visited

Run DFS on transpose graph.

Entire DFS gives one SCC.

Increase answer.

Repeat until stack becomes empty.

====================================================================
WHY TOPOLOGICAL ORDER?
====================================================================

Actually,

this is NOT real Topological Sort.

Graph may even contain cycles.

We are simply storing vertices
according to

FINISHING TIME.

The node finishing last
comes on top of stack.

====================================================================
CODE
====================================================================

class Solution {
public:

    //Store nodes according to finishing time
    void Topological(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st){

        visited[node] = 1;

        //look at its neighbours
        for(int j=0;j<adj[node].size();j++)
            if(!visited[adj[node][j]])
                Topological(adj[node][j],adj,visited,st);

        st.push(node);
    }

    //Normal DFS on transpose graph
    void DFS(int node,vector<vector<int>>&adj2,vector<bool>&visited){

        visited[node] = 1;

        for(int j=0;j<adj2[node].size();j++)
            if(!visited[adj2[node][j]])
                DFS(adj2[node][j],adj2,visited);
    }

    int kosaraju(int V, vector<vector<int>>& edges) {

        //Create adjacency list
        vector<vector<int>>adj(V);

        for(auto e:edges){

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
        }

        //Store finishing order
        vector<bool>visited(V,0);
        stack<int>st;

        for(int i=0;i<V;i++)
            if(!visited[i])
                Topological(i,adj,visited,st);

        //Create transpose graph
        vector<vector<int>>adj2(V);

        for(auto e:edges){

            int u = e[0];
            int v = e[1];

            adj2[v].push_back(u);
        }

        //Reset visited array
        for(int i=0;i<V;i++)
            visited[i]=0;

        int SCC = 0;

        //Process vertices in reverse finishing order
        while(!st.empty()){

            int node = st.top();
            st.pop();

            if(!visited[node]){

                SCC++;

                DFS(node,adj2,visited);
            }
        }

        return SCC;
    }
};

====================================================================
DRY RUN
====================================================================

Example

0 → 2

↓   ↓

3   1

↑

|

0

3 → 4

SCCs

{0,1,2}

{3}

{4}

--------------------------------------------

STEP 1

Perform DFS.

Finish order becomes

4

3

1

2

0

Stack

Top

0

2

1

3

4

Bottom

--------------------------------------------

STEP 2

Reverse every edge.

Original

0 → 2

becomes

2 → 0

Similarly reverse
all edges.

--------------------------------------------

STEP 3

Reset visited array.

visited = 0

--------------------------------------------

STEP 4

Pop

0

Run DFS.

Reach

0

1

2

One SCC found.

SCC = 1

--------------------------------------------

Next Pop

3

DFS

Only 3

SCC = 2

--------------------------------------------

Next Pop

4

DFS

Only 4

SCC = 3

Final Answer

3

====================================================================
WHY DOES IT WORK?
====================================================================

Original Graph

SCC A -----> SCC B

Finish order

B finishes first.

A finishes last.

Hence

A stays above B
inside stack.

After reversing graph

A <----- B

Starting DFS from A

cannot enter B.

Therefore,

entire DFS remains
inside only one SCC.

This is the key idea behind
Kosaraju Algorithm.

====================================================================

====================================================================
TIME COMPLEXITY
====================================================================

Building Adjacency List

O(E)

------------------------------------------------------------

First DFS

O(V + E)

------------------------------------------------------------

Transpose Graph

O(E)

------------------------------------------------------------

Second DFS

O(V + E)

------------------------------------------------------------

Overall

O(V + E)

Kosaraju performs two DFS traversals,
therefore the complexity still remains linear.

====================================================================
SPACE COMPLEXITY
====================================================================

Adjacency List

O(V + E)

------------------------------------------------------------

Transpose Graph

O(V + E)

------------------------------------------------------------

Visited Array

O(V)

------------------------------------------------------------

Stack

O(V)

------------------------------------------------------------

Recursion Stack

O(V)

------------------------------------------------------------

Overall

O(V + E)

====================================================================
WHEN TO USE KOSARAJU?
====================================================================

Use Kosaraju when

• Need to count SCCs.

• Need to print SCCs.

• Need to compress graph into SCC DAG.

• Working with Directed Graphs.

====================================================================
APPLICATIONS
====================================================================

1.

Finding Strongly Connected Components.

------------------------------------------------------------

2.

Deadlock Detection

Processes waiting for each other.

------------------------------------------------------------

3.

Compiler Optimization

Dependency Analysis.

------------------------------------------------------------

4.

Social Networks

Finding strongly connected communities.

------------------------------------------------------------

5.

Web Crawlers

Finding mutually reachable webpages.

------------------------------------------------------------

6.

Package Dependency Resolution.

------------------------------------------------------------

7.

Circuit Analysis.

------------------------------------------------------------

8.

Transportation Networks.

------------------------------------------------------------

9.

Network Routing.

------------------------------------------------------------

10.

Graph Compression.

Collapse each SCC into one node.

====================================================================
EDGE CASES
====================================================================

Case 1

Single Vertex

0

Answer = 1 SCC

------------------------------------------------------------

Case 2

Disconnected Graph

0      1

Answer = 2 SCC

------------------------------------------------------------

Case 3

One Big Cycle

0 → 1 → 2 → 0

Answer = 1 SCC

------------------------------------------------------------

Case 4

Directed Chain

0 → 1 → 2 → 3

Answer = 4 SCC

------------------------------------------------------------

Case 5

Completely Disconnected

0

1

2

3

Answer = 4 SCC

------------------------------------------------------------

Case 6

Self Loop

0 ↺

Still

Answer = 1 SCC

------------------------------------------------------------

Case 7

Multiple SCCs

0 ↔ 1

↓

2 ↔ 3

↓

4

Answer

3 SCCs

====================================================================
WHY TRANSPOSE GRAPH?
====================================================================

Original

A -----> B

Suppose

A and B are SCCs.

If DFS starts from A,

it can reach B.

We don't want DFS to merge
multiple SCCs.

After reversing

A <----- B

Now

DFS starting from A

cannot reach B.

Hence,

one DFS remains inside
one SCC.

====================================================================
WHY STACK?
====================================================================

Stack stores

Reverse Finishing Order.

Node finishing LAST

comes on TOP.

This guarantees

we always start DFS
from the correct SCC.

Without stack,

algorithm fails.

====================================================================
COMMON MISTAKES
====================================================================

1.

Forget to reverse graph.

Wrong Answer.

------------------------------------------------------------

2.

Forget to reset visited array.

Second DFS never runs.

------------------------------------------------------------

3.

Push node before DFS.

Wrong.

Push AFTER visiting children.

------------------------------------------------------------

4.

Run second DFS
on original graph.

Wrong.

Always use

Transpose Graph.

------------------------------------------------------------

5.

Use BFS instead of DFS.

Kosaraju is based on DFS finishing time.

====================================================================
INTERVIEW QUESTIONS
====================================================================

Q1.

What is SCC?

Every node can reach every other node.

------------------------------------------------------------

Q2.

Why transpose graph?

To isolate one SCC during DFS.

------------------------------------------------------------

Q3.

Why stack?

Stores reverse finishing order.

------------------------------------------------------------

Q4.

Can Kosaraju work on Undirected Graph?

No.

Undirected graph has Connected Components,
not Strongly Connected Components.

------------------------------------------------------------

Q5.

Time Complexity?

O(V + E)

------------------------------------------------------------

Q6.

Space Complexity?

O(V + E)

------------------------------------------------------------

Q7.

Can graph have one SCC?

Yes.

If every node reaches every other node.

------------------------------------------------------------

Q8.

Can disconnected graph have SCCs?

Yes.

Each connected part
can contain multiple SCCs.

====================================================================
KOSARAJU vs TARJAN
====================================================================

Kosaraju

----------

DFS Required

2

Graph Reverse

YES

Stack Needed

YES

Low Array

NO

Discovery Time

NO

Time

O(V+E)

Implementation

Easy

------------------------------------------------------------

Tarjan

----------

DFS Required

1

Graph Reverse

NO

Stack Needed

YES

Low Array

YES

Discovery Time

YES

Time

O(V+E)

Implementation

Hard

====================================================================
KOSARAJU vs CONNECTED COMPONENTS
====================================================================

Connected Components

↓

Undirected Graph

Simple DFS/BFS

------------------------------------------------------------

Strongly Connected Components

↓

Directed Graph

Kosaraju / Tarjan

====================================================================
QUICK REVISION
====================================================================

Graph Type

↓

Directed

------------------------------------------------------------

Goal

↓

Count SCCs

------------------------------------------------------------

Algorithm

↓

Kosaraju

------------------------------------------------------------

Steps

↓

1.

DFS

↓

Store Finish Order

↓

2.

Transpose Graph

↓

3.

Reset Visited

↓

4.

Pop Stack

↓

DFS on Transpose

↓

5.

Count SCC

------------------------------------------------------------

Time

↓

O(V + E)

------------------------------------------------------------

Space

↓

O(V + E)

====================================================================
IMPORTANT POINTS
====================================================================

1.

Works only for Directed Graphs.

------------------------------------------------------------

2.

Requires two DFS traversals.

------------------------------------------------------------

3.

Requires Graph Transpose.

------------------------------------------------------------

4.

Uses finishing order.

------------------------------------------------------------

5.

One DFS in transpose graph
gives exactly one SCC.

------------------------------------------------------------

6.

Every graph has at least one SCC.

------------------------------------------------------------

7.

A single isolated vertex
is also an SCC.

------------------------------------------------------------

8.

If the whole graph is mutually reachable,

Number of SCCs = 1.

====================================================================
REMEMBER
====================================================================

Connected Components

↓

Undirected

DFS / BFS

------------------------------------------------------------

Strongly Connected Components

↓

Directed

Kosaraju

Tarjan

====================================================================
INTERVIEW TIP
====================================================================

Whenever the interviewer says

"Directed Graph"

and asks

• Count SCC

• Print SCC

• Compress SCCs

Immediately think

Kosaraju Algorithm

or

Tarjan Algorithm.

Kosaraju is easier to understand and implement.

Tarjan is more optimized because it finds SCCs
in a single DFS traversal without creating the transpose graph.

====================================================================


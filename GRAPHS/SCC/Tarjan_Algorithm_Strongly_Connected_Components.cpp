#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
TARJAN'S ALGORITHM (STRONGLY CONNECTED COMPONENTS)
====================================================================

PROBLEM

Given a Directed Graph,

Find all the
Strongly Connected Components (SCCs).

Unlike Kosaraju,

Tarjan finds every SCC
using only ONE DFS.

====================================================================
WHAT IS A STRONGLY CONNECTED COMPONENT?
====================================================================

A Strongly Connected Component (SCC)
is a maximal group of vertices
such that every vertex can reach
every other vertex.

Example

0 → 1
↑   ↓
3 ← 2

All vertices can reach one another.

Hence,

{0,1,2,3}

is one SCC.

------------------------------------------------------------

Example

0 → 1 → 2

There is no way to return.

SCCs are

{0}

{1}

{2}

====================================================================
WHY TARJAN ALGORITHM?
====================================================================

Kosaraju Algorithm

↓

Needs

2 DFS

+

Transpose Graph

+

Extra Stack

------------------------------------------------------------

Tarjan Algorithm

↓

Only

1 DFS

No transpose graph.

Finds SCCs during DFS itself.

Hence,

Tarjan is considered
more elegant and optimized.

====================================================================
WHEN TO USE TARJAN?
====================================================================

Use Tarjan when

• Need all SCCs

• Need better implementation

• Don't want transpose graph

• Need SCCs during DFS

====================================================================
MAIN IDEA
====================================================================

Every node stores

1.

Discovery Time

disc[]

2.

Lowest Reachable Discovery Time

low[]

3.

Whether present in stack

InStack[]

If

disc[node] == low[node]

↓

Node becomes the HEAD
of one SCC.

====================================================================
WHAT IS DISCOVERY TIME?
====================================================================

Discovery Time

=

Time when node is visited
for the first time.

Example

DFS

0

↓

1

↓

2

↓

3

disc[]

0 = 0

1 = 1

2 = 2

3 = 3

====================================================================
WHAT IS LOW VALUE?
====================================================================

Low Value

=

Minimum discovery time
reachable from current node.

Initially

low[node] = disc[node]

Later

it becomes smaller
if a back edge exists.

====================================================================
WHY LOW VALUE?
====================================================================

Suppose

0 → 1 → 2

↑       |

|_______|

There exists

2 → 0

Back Edge

disc

0 = 0

1 = 1

2 = 2

Initially

low

0 = 0

1 = 1

2 = 2

After seeing

2 → 0

low[2] = 0

Then

low[1] = 0

Then

low[0] = 0

Hence

All belong to same SCC.

====================================================================
DATA STRUCTURES USED
====================================================================

1.

disc[]

Discovery time.

------------------------------------------------------------

2.

low[]

Lowest reachable discovery time.

------------------------------------------------------------

3.

visited[]

Marks visited node.

------------------------------------------------------------

4.

stack<int>

Stores current DFS path.

------------------------------------------------------------

5.

InStack[]

Tells whether node
is present inside stack.

====================================================================
WHY STACK?
====================================================================

Stack stores only

CURRENT ACTIVE DFS PATH.

Whenever an SCC finishes,

all its vertices are removed
from the stack together.

Hence,

Every SCC appears
as one continuous block.

====================================================================
TREE EDGE
====================================================================

Suppose

0

↓

1

↓

2

When

DFS visits an unvisited node,

it is called

Tree Edge.

Example

0 → 1

1 → 2

====================================================================
BACK EDGE
====================================================================

Suppose

0

↓

1

↓

2

↑

|

Back Edge

2 → 0

This edge creates
a cycle.

Therefore,

update

low[node].

====================================================================
IMPORTANT OBSERVATION
====================================================================

Only Back Edge

changes

low[]

Tree Edge

only propagates
child's low value.

====================================================================
WHEN IS SCC FOUND?
====================================================================

Suppose

disc[node]

=

low[node]

This means

No ancestor can be reached.

Therefore,

Current node is the ROOT
of one SCC.

Now,

Pop nodes from stack
until current node appears.

Those popped nodes
form one SCC.

====================================================================
ALGORITHM
====================================================================

Step 1

Run DFS.

↓

Step 2

Assign

disc

and

low.

↓

Step 3

Push node into stack.

↓

Step 4

Traverse neighbours.

↓

Case 1

Neighbour not visited

↓

DFS(neighbour)

↓

Update

low[node]

=

min(low[node],low[child])

------------------------------------------------------------

Case 2

Neighbour already
inside stack

↓

Back Edge

↓

Update

low[node]

=

min(low[node],disc[neighbour])

------------------------------------------------------------

Case 3

Neighbour visited
but not in stack

Ignore.

It belongs to another SCC.

====================================================================
CODE
====================================================================

class Solution {
public:

    void DFS(int node,
             vector<vector<int>>&adj,
             vector<bool>&visited,
             vector<int>&disc,
             vector<int>&low,
             stack<int>&s,
             vector<bool>&InStack,
             vector<vector<int>>&ans,
             int &timer){

        visited[node] = true;

        disc[node] = low[node] = timer;

        timer++;

        s.push(node);

        InStack[node] = true;

        for(int j=0;j<adj[node].size();j++){

            int neigh = adj[node][j];

            //Tree Edge
            if(!visited[neigh]){

                DFS(neigh,adj,visited,disc,low,s,InStack,ans,timer);

                low[node] = min(low[node],low[neigh]);
            }

            //Back Edge
            else if(InStack[neigh]){

                low[node] = min(low[node],disc[neigh]);
            }
        }

        //Head of SCC
        if(disc[node]==low[node]){

            vector<int>temp;

            while(!s.empty() && s.top()!=node){

                temp.push_back(s.top());

                InStack[s.top()] = false;

                s.pop();
            }

            temp.push_back(node);

            InStack[node]=false;

            s.pop();

            sort(temp.begin(),temp.end());

            ans.push_back(temp);
        }
    }

    vector<vector<int>> tarjans(int V,
                                vector<vector<int>>&adj){

        vector<vector<int>>ans;

        vector<int>disc(V);

        vector<int>low(V);

        vector<bool>visited(V,false);

        stack<int>s;

        vector<bool>InStack(V,false);

        int timer=0;

        for(int i=0;i<V;i++){

            if(!visited[i]){

                DFS(i,adj,visited,disc,low,s,
                    InStack,ans,timer);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};

====================================================================
DRY RUN
====================================================================

Example

0 → 1

↑   ↓

2 ←

3 → 4

SCCs

{0,1,2}

{3}

{4}

------------------------------------------------------------

Start DFS

timer = 0

Visit

0

disc[0]=0

low[0]=0

Push 0

Stack

0

------------------------------------------------------------

Visit

1

disc[1]=1

low[1]=1

Push

Stack

1

0

------------------------------------------------------------

Visit

2

disc[2]=2

low[2]=2

Push

Stack

2

1

0

------------------------------------------------------------

Back Edge

2 → 0

Update

low[2]=0

------------------------------------------------------------

Return to 1

low[1]

=

min(1,0)

=

0

------------------------------------------------------------

Return to 0

low[0]

=

min(0,0)

=

0

------------------------------------------------------------

Now

disc[0]

=

0

low[0]

=

0

Hence

0 becomes

HEAD OF SCC.

Pop

2

1

0

One SCC found

{0,1,2}

====================================================================

====================================================================
DRY RUN (CONTINUED)
====================================================================

Current Stack

Top

2

1

0

Bottom

------------------------------------------------------------

All three nodes

2

1

0

are popped together.

Reason

They belong to the same SCC.

Current Answer

{0,1,2}

------------------------------------------------------------

Continue DFS

Visit

3

disc[3]=3

low[3]=3

Push 3

Stack

3

------------------------------------------------------------

Visit

4

disc[4]=4

low[4]=4

Push

Stack

4

3

------------------------------------------------------------

Node 4

No outgoing edges.

disc[4]=low[4]

Hence

4 itself becomes
head of SCC.

Pop

4

Current SCC

{4}

------------------------------------------------------------

Return to 3

low[3]=3

disc[3]=3

Again

disc==low

Pop

3

Current SCC

{3}

------------------------------------------------------------

Final Answer

{0,1,2}

{3}

{4}

====================================================================
WHY DOES TARJAN WORK?
====================================================================

During DFS,

every node stores

disc[]

↓

Time when node
was first visited.

------------------------------------------------------------

low[]

↓

Earliest discovery time
reachable from current node.

------------------------------------------------------------

Whenever

low[node]

=

disc[node]

No ancestor can be reached.

Hence,

Current node is the ROOT
of one SCC.

====================================================================
TIME COMPLEXITY
====================================================================

DFS Traversal

O(V + E)

------------------------------------------------------------

Every Vertex

Visited once.

------------------------------------------------------------

Every Edge

Processed once.

------------------------------------------------------------

Overall

O(V + E)

====================================================================
SPACE COMPLEXITY
====================================================================

Adjacency List

O(V + E)

------------------------------------------------------------

disc[]

O(V)

------------------------------------------------------------

low[]

O(V)

------------------------------------------------------------

visited[]

O(V)

------------------------------------------------------------

InStack[]

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
APPLICATIONS
====================================================================

1.

Finding Strongly Connected Components.

------------------------------------------------------------

2.

Compiler Optimization.

------------------------------------------------------------

3.

Package Dependency Analysis.

------------------------------------------------------------

4.

Deadlock Detection.

------------------------------------------------------------

5.

Social Network Community Detection.

------------------------------------------------------------

6.

Web Crawlers.

------------------------------------------------------------

7.

Circuit Analysis.

------------------------------------------------------------

8.

Graph Compression.

Compress every SCC into
a single node.

------------------------------------------------------------

9.

Network Routing.

------------------------------------------------------------

10.

Dependency Graph Analysis.

====================================================================
EDGE CASES
====================================================================

Case 1

Single Vertex

0

Answer

1 SCC

------------------------------------------------------------

Case 2

Directed Chain

0 → 1 → 2 → 3

Answer

4 SCC

------------------------------------------------------------

Case 3

Single Cycle

0 → 1 → 2 → 0

Answer

1 SCC

------------------------------------------------------------

Case 4

Disconnected Graph

0

1

2

Answer

3 SCC

------------------------------------------------------------

Case 5

Self Loop

0 ↺

Answer

1 SCC

------------------------------------------------------------

Case 6

Multiple Cycles

Each cycle becomes
one SCC.

====================================================================
COMMON MISTAKES
====================================================================

1.

Updating

low[node]

with

low[neigh]

for Back Edge.

Wrong.

Correct

low[node]

=

min(low[node],disc[neigh])

------------------------------------------------------------

2.

Ignoring

InStack[].

Wrong.

Visited node does NOT
always mean Back Edge.

Only update low[]

if neighbour is
currently inside stack.

------------------------------------------------------------

3.

Forgetting to pop
entire SCC.

------------------------------------------------------------

4.

Not marking

InStack[node]=false

after popping.

------------------------------------------------------------

5.

Using transpose graph.

Tarjan never needs
graph reversal.

====================================================================
TARJAN vs KOSARAJU
====================================================================

Tarjan

------------

DFS

1

------------------------------------------------

Transpose Graph

NO

------------------------------------------------

Extra Stack

YES

------------------------------------------------

disc[]

YES

------------------------------------------------

low[]

YES

------------------------------------------------

InStack[]

YES

------------------------------------------------

Implementation

Hard

------------------------------------------------

Time

O(V+E)

================================================

Kosaraju

------------

DFS

2

------------------------------------------------

Transpose Graph

YES

------------------------------------------------

Extra Stack

YES

------------------------------------------------

disc[]

NO

------------------------------------------------

low[]

NO

------------------------------------------------

InStack[]

NO

------------------------------------------------

Implementation

Easy

------------------------------------------------

Time

O(V+E)

====================================================================
WHEN TO USE TARJAN?
====================================================================

Choose Tarjan when

• Need SCCs using one DFS.

• Need optimized implementation.

• Want to avoid transpose graph.

• Working on large directed graphs.

====================================================================
WHEN TO USE KOSARAJU?
====================================================================

Choose Kosaraju when

• Simplicity is preferred.

• Easy implementation is needed.

• Interview begins with SCC concept.

====================================================================
INTERVIEW QUESTIONS
====================================================================

Q1.

What is SCC?

Every node can reach
every other node.

------------------------------------------------------------

Q2.

Why use low[]?

To know the earliest
reachable ancestor.

------------------------------------------------------------

Q3.

Why InStack[]?

To identify Back Edges
inside current SCC.

------------------------------------------------------------

Q4.

When is SCC formed?

Whenever

disc[node]

=

low[node]

------------------------------------------------------------

Q5.

Does Tarjan require
transpose graph?

No.

------------------------------------------------------------

Q6.

Time Complexity?

O(V+E)

------------------------------------------------------------

Q7.

Space Complexity?

O(V+E)

------------------------------------------------------------

Q8.

Can Tarjan work
on Undirected Graph?

Not for SCC.

Undirected graphs have
Connected Components.

====================================================================
IMPORTANT OBSERVATIONS
====================================================================

1.

Every SCC has exactly
one HEAD node.

------------------------------------------------------------

2.

Head node satisfies

disc==low

------------------------------------------------------------

3.

Every node is pushed
exactly once.

------------------------------------------------------------

4.

Every node is popped
exactly once.

------------------------------------------------------------

5.

Each SCC appears
as one continuous block
inside stack.

------------------------------------------------------------

6.

Back Edge updates

low[]

------------------------------------------------------------

7.

Tree Edge propagates

child's low[]

====================================================================
QUICK REVISION
====================================================================

Graph Type

↓

Directed

------------------------------------------------------------

Goal

↓

Find SCC

------------------------------------------------------------

Algorithm

↓

Tarjan

------------------------------------------------------------

Technique

↓

DFS

------------------------------------------------------------

Arrays Used

↓

disc[]

low[]

visited[]

InStack[]

------------------------------------------------------------

Extra Data Structure

↓

Stack

------------------------------------------------------------

Condition for SCC

↓

disc[node]

==

low[node]

------------------------------------------------------------

Time

↓

O(V+E)

------------------------------------------------------------

Space

↓

O(V+E)

====================================================================
REMEMBER
====================================================================

Connected Components

↓

Undirected Graph

↓

DFS / BFS

------------------------------------------------------------

Strongly Connected Components

↓

Directed Graph

↓

Kosaraju

or

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

Kosaraju

or

Tarjan.

If they ask for

"One DFS solution"

or

"Without reversing the graph"

The expected answer is

Tarjan's Algorithm.

====================================================================
SUMMARY
====================================================================

Tarjan Algorithm

↓

Uses only ONE DFS.

------------------------------------------------------------

No Transpose Graph.

------------------------------------------------------------

Uses

disc[]

low[]

Stack

InStack[]

------------------------------------------------------------

Whenever

disc[node]

==

low[node]

↓

Current node is the
HEAD of one SCC.

------------------------------------------------------------

Pop nodes until
that node appears.

Those popped vertices
form one Strongly Connected Component.

------------------------------------------------------------

Time Complexity

O(V + E)

------------------------------------------------------------

Space Complexity

O(V + E)

====================================================================
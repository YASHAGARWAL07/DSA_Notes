#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
                    TARJAN'S ARTICULATION POINT
====================================================================

Also Known As

• Cut Vertex
• Cut Node

====================================================================
PROBLEM
====================================================================

Given an Undirected Graph,

Find all vertices whose removal disconnects the graph.

These vertices are called Articulation Points.

====================================================================
WHAT IS AN ARTICULATION POINT?
====================================================================

An Articulation Point is a vertex whose removal increases
the number of connected components of the graph.

OR

Removing that vertex disconnects the graph.

Example

        0
       / \
      1---2
      |
      3

Articulation Point

1

Removing node 1 disconnects node 3.

====================================================================
INTUITION
====================================================================

While performing DFS,

Every node stores

1. Discovery Time (Disc[])
2. Lowest Reachable Discovery Time (low[])

Using these two arrays,

we determine whether a child subtree has another path
to reach an ancestor.

If not,

current node becomes an Articulation Point.

====================================================================
DISCOVERY TIME
====================================================================

Discovery Time means

"When was this node first visited?"

Suppose DFS

0 → 1 → 2 → 3

Then

Disc[0] = 0

Disc[1] = 1

Disc[2] = 2

Disc[3] = 3

Each newly visited node gets the next timer value.

====================================================================
LOW TIME
====================================================================

low[node]

=

Smallest Discovery Time reachable from that node

using

• Tree Edges
• Back Edge

Initially

low[node] = Disc[node]

Later it may decrease because of back edges.

====================================================================
WHY DO WE NEED LOW[] ?
====================================================================

Suppose

0
|
1
|
2

If node 2 has another edge

2 ---- 0

Then

Node 2 can still reach node 0

even if node 1 is removed.

This information is stored in low[].

====================================================================
DFS HAS 3 CASES
====================================================================

------------------------------------------------------------
CASE 1
------------------------------------------------------------

Neighbour is Parent

Ignore it.

Code

if(neigh==parent)
continue;

------------------------------------------------------------
CASE 2
------------------------------------------------------------

Neighbour already visited

Means

Back Edge

Update

low[node]=min(low[node],Disc[neigh]);

Notice

We use Disc[]

NOT low[]

because

Back edge directly reaches an ancestor.

------------------------------------------------------------
CASE 3
------------------------------------------------------------

Neighbour not visited

Perform DFS.

DFS(neigh)

After returning,

Update

low[node]=min(low[node],low[neigh]);

Now check whether current node
becomes an Articulation Point.

====================================================================
ROOT NODE CONDITION
====================================================================

Root is special.

Root has no parent.

Root becomes Articulation Point only if

Child Count > 1

Example

        0
       / \
      1   2

Removing 0

disconnects graph.

Therefore

0 is Articulation Point.

But

        0
        |
        1
        |
        2

Root has only one child.

Removing root

does NOT disconnect DFS tree.

Hence

Not an Articulation Point.

Condition

child > 1

====================================================================
NON-ROOT CONDITION
====================================================================

For every child

if

low[child] >= Disc[node]

Then

Current node

is Articulation Point.

Code

if(parent!=-1 && low[child]>=Disc[node])

artPoint[node]=1;

====================================================================
WHY >= ?
====================================================================

Suppose

0
|
1
|
2

No back edge.

Disc

0 1 2

Low

0 1 2

For node 1

low[2]=2

Disc[1]=1

2 >= 1

True

Removing node 1 disconnects node 2.

Hence

Articulation Point.

Now suppose

0
|
1
|\
| \
2--3

Node 2 has back edge to 1

low[2]=1

Disc[1]=1

Still

1>=1

True

Removing node 1 still disconnects subtree.

Hence

>=

NOT >

====================================================================
WHY BRIDGES USE >
BUT ARTICULATION USE >= ?
====================================================================

Bridge

low[child] > Disc[parent]

Edge gets disconnected.

--------------------------------

Articulation Point

low[child] >= Disc[parent]

Vertex gets disconnected.

Equal case is also valid.

That is the major difference.

====================================================================
ALGORITHM
====================================================================

1.

Create

Disc[]

low[]

visited[]

artPoint[]

2.

Start DFS

3.

Ignore Parent Edge

4.

Update low[] using Back Edge

5.

DFS on unvisited neighbour

6.

Update low[]

7.

Check

Root Condition

or

Non-root Condition

8.

Return all Articulation Points.

====================================================================
CODE
====================================================================

class Solution {
public:

    void DFS(int node,int parent,
             vector<int> adj[],
             vector<bool>&artPoint,
             vector<int>&Disc,
             vector<int>&low,
             vector<bool>&visited,
             int &timer){

        visited[node]=1;                     //mark visited

        Disc[node]=low[node]=timer;          //initialize discovery & low time

        int child=0;                         //stores DFS children

        for(int j=0;j<adj[node].size();j++){

            int neigh=adj[node][j];

            //Case 1 : Parent Edge
            if(neigh==parent)
                continue;

            //Case 2 : Back Edge
            else if(visited[neigh]){

                low[node]=min(low[node],Disc[neigh]);

            }

            //Case 3 : Tree Edge
            else{

                timer++;
                child++;

                DFS(neigh,node,adj,artPoint,Disc,low,visited,timer);

                //Non-root Condition
                if(parent!=-1 && low[neigh]>=Disc[node])

                    artPoint[node]=1;

                //Update low
                low[node]=min(low[node],low[neigh]);
            }

        }

        //Root Condition
        if(parent==-1 && child>1)

            artPoint[node]=1;

    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {

        vector<bool>artPoint(V,0);

        vector<int>Disc(V);

        vector<int>low(V);

        vector<bool>visited(V,0);

        int timer=0;

        for(int i=0;i<V;i++){

            if(!visited[i])

                DFS(i,-1,adj,artPoint,Disc,low,visited,timer);

        }

        vector<int>ans;

        for(int i=0;i<V;i++){

            if(artPoint[i])

                ans.push_back(i);

        }

        if(ans.size()==0)

            return {-1};

        return ans;

    }

};

/*

====================================================================
DRY RUN
====================================================================

Graph

            0
          /   \
         1-----2
         |
         3
        / \
       4   5

DFS Order

0 → 1 → 2 → 3 → 4 → 5

------------------------------------------------------------

Discovery Time

Node      Disc

0          0
1          1
2          2
3          3
4          4
5          5

------------------------------------------------------------

Initially

Disc

0 1 2 3 4 5

Low

0 1 2 3 4 5

------------------------------------------------------------

DFS at node 2

Back Edge

2 → 0

Update

low[2]=min(2,0)

low[2]=0

------------------------------------------------------------

Return to node 1

low[1]=min(1,0)

low[1]=0

------------------------------------------------------------

Visit node 3

Disc[3]=3

Low[3]=3

------------------------------------------------------------

Visit node 4

Disc[4]=4

Low[4]=4

Return

low[3]=min(3,4)

low[3]=3

Check

low[4]>=Disc[3]

4>=3

YES

3 becomes Articulation Point.

------------------------------------------------------------

Visit node 5

Disc[5]=5

Low[5]=5

Return

low[3]=min(3,5)

3

Check

5>=3

YES

3 is already Articulation Point.

------------------------------------------------------------

Return to node 1

low[1]=min(0,3)

0

Check

low[3]>=Disc[1]

3>=1

YES

1 becomes Articulation Point.

------------------------------------------------------------

Return to node 0

Root Child Count

Only one DFS child

Hence

0 is NOT Articulation Point.

====================================================================
FINAL ANSWER
====================================================================

Articulation Points

1

3

====================================================================
TIME COMPLEXITY
====================================================================

DFS Traversal

O(V)

Traversing Edges

O(E)

Overall

O(V + E)

====================================================================
SPACE COMPLEXITY
====================================================================

Adjacency List

O(V + E)

visited[]

O(V)

Disc[]

O(V)

low[]

O(V)

artPoint[]

O(V)

Recursion Stack

O(V)

Overall

O(V + E)

====================================================================
EDGE CASES
====================================================================

1.

Single Node

No Articulation Point.

----------------------------------------

2.

Graph with No Edge

No Articulation Point.

----------------------------------------

3.

Disconnected Graph

Run DFS for every unvisited node.

for(int i=0;i<V;i++)

    if(!visited[i])

        DFS(...);

----------------------------------------

4.

Complete Graph

No Articulation Point.

Every node has multiple alternate paths.

----------------------------------------

5.

Tree

Every non-leaf node

is an Articulation Point.

----------------------------------------

6.

Cycle

No Articulation Point.

Every node has alternate path.

----------------------------------------

7.

Root with One Child

NOT Articulation Point.

----------------------------------------

8.

Root with Two or More DFS Children

Articulation Point.

====================================================================
COMMON MISTAKES
====================================================================

1.

Using

>

instead of

>=

Wrong

Correct

low[child]>=Disc[node]

------------------------------------------------------------

2.

Forgetting Root Condition.

------------------------------------------------------------

3.

Updating

low[node]

using

low[visitedNode]

Wrong

Correct

low[node]=min(low[node],Disc[visitedNode]);

------------------------------------------------------------

4.

Not ignoring Parent Edge.

------------------------------------------------------------

5.

Running DFS only from node 0.

Fails for disconnected graph.

====================================================================
IMPORTANT INTERVIEW QUESTIONS
====================================================================

Q1.

What is an Articulation Point?

------------------------------------------------------------

Q2.

Difference between Bridge and Articulation Point?

------------------------------------------------------------

Q3.

Why Root has separate condition?

------------------------------------------------------------

Q4.

Why use

>=

instead of

> ?

------------------------------------------------------------

Q5.

Why use Disc[] instead of Low[]

for Back Edge?

------------------------------------------------------------

Q6.

Can Tarjan's Algorithm work for Directed Graph?

No.

This implementation is for
Undirected Graph only.

------------------------------------------------------------

Q7.

Can there be multiple Articulation Points?

YES

------------------------------------------------------------

Q8.

Can a Tree have Articulation Points?

YES

Every non-leaf node.

====================================================================
BRIDGE vs ARTICULATION POINT
====================================================================

Bridge
--------

Remove Edge

↓

Graph Disconnects

Condition

low[child] > Disc[parent]

Returns

Edge

------------------------------------------------------------

Articulation Point

Remove Vertex

↓

Graph Disconnects

Condition

low[child] >= Disc[parent]

Returns

Vertex

------------------------------------------------------------

Root Condition

Bridge

No

Articulation

YES

child > 1

====================================================================
REAL WORLD APPLICATIONS
====================================================================

1.

Computer Networks

Finding critical routers.

------------------------------------------------------------

2.

Road Networks

Finding important intersections.

------------------------------------------------------------

3.

Electric Power Grid

Critical substations.

------------------------------------------------------------

4.

Internet Backbone

Important communication nodes.

------------------------------------------------------------

5.

Social Network Analysis

Finding influential users.

------------------------------------------------------------

6.

Transportation Systems

Critical railway junctions.

------------------------------------------------------------

7.

Network Reliability

Finding single points of failure.

====================================================================
IMPORTANT OBSERVATIONS
====================================================================

1.

Works only for

Undirected Graph.

------------------------------------------------------------

2.

Uses

DFS

------------------------------------------------------------

3.

Uses

Discovery Time

and

Low Time.

------------------------------------------------------------

4.

One DFS finds all Articulation Points.

------------------------------------------------------------

5.

Tarjan's Algorithm

Time Complexity

O(V+E)

====================================================================
QUICK REVISION
====================================================================

Articulation Point

↓

Remove Vertex

↓

Graph Disconnects

------------------------------------

Disc[]

↓

Discovery Time

------------------------------------

low[]

↓

Lowest Reachable Discovery Time

------------------------------------

Root Condition

↓

child > 1

------------------------------------

Non-root Condition

↓

low[child] >= Disc[node]

------------------------------------

Back Edge

↓

low[node]=min(low[node],Disc[neigh])

------------------------------------

Tree Edge

↓

low[node]=min(low[node],low[child])

------------------------------------

Time

↓

O(V+E)

------------------------------------

Space

↓

O(V+E)

------------------------------------

Graph

↓

Undirected

------------------------------------

Algorithm

↓

Tarjan's DFS

------------------------------------

Output

↓

Cut Vertices / Articulation Points

====================================================================

*/
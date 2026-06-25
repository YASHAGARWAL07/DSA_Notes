#include <bits/stdc++.h>
using namespace std;

/*

====================================================================
                TARJAN'S ALGORITHM (BRIDGES)
====================================================================

Also Known As:
---------------
Critical Connections in a Network

====================================================================
PROBLEM
====================================================================

Given an undirected graph,

Find all edges whose removal increases the number of connected
components.

Such edges are called BRIDGES.

Example

0 ----- 1
|      / |
|     /  |
2     3

Bridge = (1,3)

Removing (1,3) disconnects node 3.

====================================================================
WHAT IS A BRIDGE?
====================================================================

A Bridge is an edge whose removal disconnects the graph.

OR

Removing that edge increases the number of connected components.

Bridge = Critical Connection

====================================================================
INTUITION
====================================================================

During DFS every node gets

1. Discovery Time (disc[])
2. Lowest Reachable Time (low[])

disc[node]
-------------
Time when node is first visited.

low[node]
-------------
Lowest discovery time reachable from that node.

including

• Tree Edge
• Back Edge

using at most ONE back edge.

====================================================================
DISCOVERY TIME
====================================================================

Suppose DFS order

0 → 1 → 2 → 3

disc[]

0 = 0
1 = 1
2 = 2
3 = 3

Simply increasing timer.

====================================================================
LOW TIME
====================================================================

Low time tells

"How far upward can I reach?"

Initially

low[node] = disc[node]

Later it may decrease because of back edges.

====================================================================
3 DFS CASES
====================================================================

For every neighbour

------------------------------------------------
CASE 1
------------------------------------------------

Neighbour is Parent

Ignore it.

if(neigh == parent)
continue;

------------------------------------------------
CASE 2
------------------------------------------------

Neighbour already visited

Means Back Edge

Update

low[node] = min(low[node],disc[neigh]);

------------------------------------------------
CASE 3
------------------------------------------------

Neighbour not visited

DFS(neigh)

After returning

low[node] = min(low[node],low[neigh]);

Now check

if(low[neigh] > disc[node])

Bridge Found.

====================================================================
WHY?

low[child] > disc[parent]
====================================================================

Suppose

0 ----- 1 ----- 2

No back edge.

disc

0 1 2

low

0 1 2

For edge

1 → 2

low[2] = 2

disc[1] = 1

Since

2 > 1

Node 2 cannot reach
1 or any ancestor.

Removing edge (1,2)

disconnects graph.

Hence

Bridge.

====================================================================
WHEN IS EDGE NOT A BRIDGE?
====================================================================

0
|\
| \
1--2

There exists another path.

low[2] becomes 0.

Now

low[2] <= disc[1]

Hence

NOT Bridge.

====================================================================
ALGORITHM
====================================================================

1. Create adjacency list.

2. Maintain

disc[]
low[]
visited[]

3. Start DFS.

4. Ignore Parent Edge.

5. Update Low values.

6. Check

low[child] > disc[parent]

7. Store bridge.

====================================================================
YOUR CODE
====================================================================

*/

class Solution {
public:

    void DFS(int node,int parent,vector<vector<int>>&adj,
             vector<int>&disc,vector<int>&low,
             vector<bool>&visited,
             vector<vector<int>>&Bridges,
             int &count){

        disc[node] = low[node] = count;      //store discovery & low time
        visited[node] = 1;                   //mark visited

        for(int j=0;j<adj[node].size();j++){

            int neigh = adj[node][j];

            //Case 1 : Parent edge
            if(neigh == parent)
                continue;

            //Case 2 : Back edge
            else if(visited[neigh]){
                low[node] = min(low[node],disc[neigh]);
            }

            //Case 3 : DFS edge
            else{

                count++;

                DFS(neigh,node,adj,disc,low,visited,Bridges,count);

                //Bridge may exist
                low[node] = min(low[node],low[neigh]);

                //Bridge Found
                if(low[neigh] > disc[node]){
                    Bridges.push_back({node,neigh});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                    vector<vector<int>>&connections){

        vector<vector<int>>adj(n);

        for(auto x:connections){

            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>Bridges;

        vector<int>disc(n);          //discovery time
        vector<int>low(n);           //lowest reachable time
        vector<bool>visited(n,0);    //visited array

        int count = 0;

        DFS(0,-1,adj,disc,low,visited,Bridges,count);

        return Bridges;
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

DFS

0

disc=0
low=0

↓

1

disc=1
low=1

↓

2

disc=2
low=2

Back Edge

2 → 0

low[2]=0

Return

low[1]=0

↓

3

disc=3
low=3

Check

low[3] > disc[1]

3 > 1

YES

Bridge

(1,3)

====================================================================
TIME COMPLEXITY
====================================================================

DFS             O(V)

Traverse Edges  O(E)

Total

O(V + E)

====================================================================
SPACE COMPLEXITY
====================================================================

Adjacency List

O(V + E)

Visited

O(V)

disc

O(V)

low

O(V)

Recursion Stack

O(V)

Overall

O(V + E)

====================================================================
IMPORTANT INTERVIEW POINTS
====================================================================

1.

Works ONLY on

Undirected Graph.

2.

Bridge

=

Critical Connection

3.

Uses

Discovery Time

and

Low Time.

4.

Condition

low[child] > disc[parent]

5.

Time Complexity

O(V+E)

6.

Can find all bridges in one DFS.

====================================================================
EDGE CASES
====================================================================

1.

Disconnected Graph

Run DFS for every unvisited node.

for(int i=0;i<n;i++)
    if(!visited[i])
        DFS(...);

2.

Single Node

No bridge.

3.

No Edge

No bridge.

4.

Complete Graph

No bridge.

5.

Tree

Every edge is a bridge.

====================================================================
BRIDGE vs ARTICULATION POINT
====================================================================

Bridge
--------

Remove Edge

↓

Graph disconnects

Condition

low[child] > disc[parent]

--------------------------------------------

Articulation Point

Remove Vertex

↓

Graph disconnects

Condition

low[child] >= disc[parent]

Root Case

Root should have

2 or more DFS children.

====================================================================
REAL WORLD APPLICATIONS
====================================================================

• Network reliability

• Computer networks

• Road connectivity

• Electrical grids

• Communication links

• Social network analysis

• Infrastructure planning

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

low[node] = min(low[node],disc[neigh]);

2.

Not ignoring Parent Edge.

3.

Using

>=

instead of

>

for Bridges.

4.

Running DFS from only one node
for disconnected graph.

====================================================================
REVISION
====================================================================

Remember

disc[]

↓

Discovery Time

--------------------------

low[]

↓

Lowest Discovery Time Reachable

--------------------------

Bridge Condition

↓

low[child] > disc[parent]

--------------------------

Time

↓

O(V+E)

--------------------------

Graph

↓

Undirected Only

====================================================================

*/
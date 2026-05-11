#include <bits/stdc++.h>
using namespace std;

/*
============================================================
BELLMAN FORD ALGORITHM
============================================================

USED FOR:

1. Shortest Path in Directed Weighted Graph

2. Works for:
   Positive Weights
   Negative Weights

3. Can Detect:
   Negative Weight Cycle

============================================================
WHEN TO USE WHICH ALGORITHM?
============================================================

------------------------------------------------------------
1. BFS
------------------------------------------------------------

USE WHEN:

→ Graph is UNWEIGHTED
OR
→ All edge weights are SAME

Example:
weight = 1 for every edge

TIME:
O(V + E)

------------------------------------------------------------
2. DIJKSTRA ALGORITHM
------------------------------------------------------------

USE WHEN:

→ Graph has POSITIVE weights only

Works for:
✔ Directed Graph
✔ Undirected Graph

DO NOT USE WHEN:
✘ Negative edge exists

WHY?

Because Dijkstra is GREEDY.

Once node is finalized,
it assumes:
"this is minimum distance"

But negative edge can later
give smaller distance.

So Dijkstra fails.

TIME:
Using Priority Queue:
O(E logV)

------------------------------------------------------------
3. BELLMAN FORD ALGORITHM
------------------------------------------------------------

USE WHEN:

→ Negative edge exists

Works for:
✔ Directed Graph
✔ Positive weights
✔ Negative weights

ALSO:
✔ Detects Negative Cycle

TIME:
O(V * E)

------------------------------------------------------------
4. FLOYD WARSHALL
------------------------------------------------------------

USE WHEN:

→ All Pair Shortest Path needed

Find shortest distance between:
every pair of vertices

Works with:
✔ Negative edges

Fails for:
✘ Negative cycle

TIME:
O(V³)

============================================================
VERY IMPORTANT INTERVIEW POINT
============================================================

UNDIRECTED GRAPH + NEGATIVE EDGE
============================================================

If graph is UNDIRECTED and contains
even ONE negative edge:

u ----(-5)---- v

Then:

u -> v -> u

cycle weight = -10

Negative cycle ban jayega

So:
Shortest Path cannot be defined

------------------------------------------------------------

THEREFORE:

1. Undirected + Negative Weight
   → No valid shortest path

2. Undirected + Positive Weight
   → Use Dijkstra

3. Directed + Negative Weight
   → Use Bellman Ford

============================================================
INTUITION
============================================================

Dijkstra greedy approach use karta hai.

Negative edge aane par:
future me better path mil sakta hai.

So Dijkstra fail ho jata hai.

------------------------------------------------------------

Bellman Ford:

Har edge ko baar baar relax karta hai.

Agar:
V vertices hain

Toh:
maximum shortest path me
V-1 edges ho sakti hain

Isliye:
all edges ko V-1 times relax karte hain

============================================================
WHAT IS RELAXATION?
============================================================

Agar:

dist[u] + wt < dist[v]

Then:
better path mil gaya

So update:

dist[v] = dist[u] + wt

============================================================
APPROACH
============================================================

1. dist array initialize karo

2. source distance = 0

3. All edges ko:
   V-1 times relax karo

4. Ek extra iteration karo:
   agar ab bhi relaxation hota hai

   → negative cycle exists

============================================================
*/

class Solution {
public:

    vector<int> bellmanFord(int V,
                            vector<vector<int>>& edges,
                            int src) {

        vector<int>dist(V,1e8);     //stores shortest distance

        dist[src] = 0;

        int e = edges.size();

        //relax all edges V-1 times
        for(int i=0;i<V-1;i++){

            int flag = 0;           //checks relaxation happened or not

            for(int j=0;j<e;j++){

                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                //source unreachable
                if(dist[u] == 1e8)
                continue;

                //relax edge
                if(dist[u] + wt < dist[v]){

                    flag = 1;

                    dist[v] = dist[u] + wt;
                }
            }

            //no relaxation happened
            if(!flag)
            break;
        }

        //check negative cycle
        for(int j=0;j<e;j++){

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] == 1e8)
            continue;

            //still relaxation possible
            if(dist[u] + wt < dist[v]){

                return {-1};
            }
        }

        return dist;
    }
};

int main(){

    int V = 5;

    vector<vector<int>>edges = {
        {0,1,5},
        {1,2,1},
        {2,4,1},
        {4,3,-1},
        {1,3,2}
    };

    int src = 0;

    Solution obj;

    vector<int>ans = obj.bellmanFord(V,edges,src);

    if(ans.size()==1 && ans[0]==-1){

        cout<<"Negative Weight Cycle Exists\n";
        return 0;
    }

    cout<<"Shortest Distances From Source "<<src<<" :\n";

    for(int i=0;i<ans.size();i++)
        cout<<"Node "<<i<<" -> "<<ans[i]<<"\n";

    return 0;
}

/*
============================================================
DRY RUN
============================================================

EDGES:

0 -> 1 (5)
1 -> 2 (1)
2 -> 4 (1)
4 -> 3 (-1)
1 -> 3 (2)

SOURCE = 0

------------------------------------------------------------

INITIAL:

dist = [0,INF,INF,INF,INF]

------------------------------------------------------------

1st RELAXATION:

0->1

dist[1] = 5

1->2

dist[2] = 6

2->4

dist[4] = 7

4->3

dist[3] = 6

------------------------------------------------------------

FINAL:

dist = [0,5,6,6,7]

============================================================
TIME COMPLEXITY
============================================================

O(V * E)

============================================================
SPACE COMPLEXITY
============================================================

O(V)

============================================================
DIJKSTRA VS BELLMAN FORD
============================================================

DIJKSTRA:

✔ Faster
✔ Greedy
✔ Positive weights only

✘ Cannot detect negative cycle
✘ Fails for negative edge

TIME:
O(E logV)

------------------------------------------------------------

BELLMAN FORD:

✔ Handles negative weights
✔ Detects negative cycle

✘ Slower

TIME:
O(V * E)

============================================================
IMPORTANT INTERVIEW QUESTIONS
============================================================

Q1. Why V-1 relaxations?

→ shortest path can contain
at most V-1 edges

------------------------------------------------------------

Q2. Why extra iteration?

→ to detect negative cycle

------------------------------------------------------------

Q3. Why Dijkstra fails for negative edge?

→ greedy choice becomes invalid

------------------------------------------------------------

Q4. Can Bellman Ford work on undirected
graph with negative edge?

→ No

Because immediate negative cycle forms

------------------------------------------------------------

Q5. Which is faster:
Dijkstra or Bellman Ford?

→ Dijkstra

------------------------------------------------------------

Q6. Which algorithm detects
negative cycle?

→ Bellman Ford

============================================================
QUICK RECALL
============================================================

UNWEIGHTED GRAPH
→ BFS

------------------------------------------------------------

POSITIVE WEIGHTS
→ Dijkstra

------------------------------------------------------------

NEGATIVE WEIGHTS
→ Bellman Ford

------------------------------------------------------------

NEGATIVE CYCLE DETECTION
→ Bellman Ford

------------------------------------------------------------

ALL PAIR SHORTEST PATH
→ Floyd Warshall

============================================================
*/
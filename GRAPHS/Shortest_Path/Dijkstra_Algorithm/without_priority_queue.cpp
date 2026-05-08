#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
============================================================
DIJKSTRA ALGORITHM (NORMAL VERSION)
============================================================

INTUITION:

- shortest distance from source node to all nodes
- graph weighted hai
- har step par minimum distance node choose karte hain

------------------------------------------------------------

NORMAL DIJKSTRA:

- priority queue use nahi hoti
- manually minimum distance node find karte hain

------------------------------------------------------------

RELAXATION:

if(dist[node] + weight < dist[neigh])

→ better path mil gaya
→ distance update karo

============================================================
APPROACH
============================================================

1. edge list ko adjacency list me convert karo

2. dist[] array banao
   - initially sab INT_MAX
   - source = 0

3. har iteration me:
   - minimum distance unexplored node find karo

4. neighbours relax karo

5. repeat until all nodes processed

============================================================
*/

class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for(auto e : edges){

            int u = e[0];
            int v = e[1];
            int weight = e[2];

            adj[u].push_back(make_pair(v,weight)); //u -> v
            adj[v].push_back(make_pair(u,weight)); //v -> u
        }

        vector<bool> explored(V,0);                //visited nodes
        vector<int> dist(V,INT_MAX);               //shortest distances

        dist[src] = 0;                             //source distance = 0

        // Dijkstra Algorithm
        for(int count = 0; count<V; count++){

            int node = -1;

            // find minimum distance node
            for(int i=0;i<V;i++){

                if(!explored[i]
                &&
                (node == -1 || dist[i] < dist[node])){

                    node = i;
                }
            }

            explored[node] = true;                 //mark visited

            // traverse neighbours
            for(int j=0;j<adj[node].size();j++){

                int neigh = adj[node][j].first;    //neighbour node
                int weight = adj[node][j].second;  //edge weight

                // relaxation
                if(!explored[neigh]
                &&
                dist[node] + weight < dist[neigh]
                &&
                dist[node] != INT_MAX){

                    dist[neigh] = dist[node] + weight; //update shortest distance
                }
            }
        }

        return dist;
    }
};

/*
============================================================
MAIN FUNCTION
============================================================
*/

int main(){

    Solution obj;

    int V = 3;

    vector<vector<int>> edges = {
        {0,1,1},
        {1,2,3},
        {0,2,6}
    };

    int src = 2;

    vector<int> ans = obj.dijkstra(V,edges,src);

    cout<<"Shortest Distances:\n";

    for(int x : ans)
        cout<<x<<" ";

    return 0;
}

/*
============================================================
DRY RUN
============================================================

GRAPH:

0 --1-- 1
 \      |
  6     3
   \    |
      2

source = 2

------------------------------------------------------------

INITIAL:

dist = [INF, INF, 0]

------------------------------------------------------------

PROCESS NODE 2

2 -> 1 (3)
2 -> 0 (6)

dist = [6,3,0]

------------------------------------------------------------

PROCESS NODE 1

1 -> 0 (1)

3 + 1 < 6

update:

dist[0] = 4

------------------------------------------------------------

FINAL ANSWER

[4,3,0]

============================================================
TIME COMPLEXITY
============================================================

O(V²)

============================================================
SPACE COMPLEXITY
============================================================

O(V + E)

============================================================
IMPORTANT POINTS
============================================================

1. Works only for NON-NEGATIVE weights

2. Greedy Algorithm

3. Slower than Priority Queue version

4. Minimum node manually search karte hain

5. Good for learning Dijkstra basics

============================================================
APPLICATIONS
============================================================

- Google Maps
- GPS Navigation
- Network Routing
- Flight Routes
- Shortest Path Problems

============================================================
INTERVIEW QUESTIONS
============================================================

Q1. Why slower than Priority Queue version?

→ minimum node manually search karna padta hai

------------------------------------------------------------

Q2. Time complexity difference?

Normal:
O(V²)

Priority Queue:
O((V+E)logV)

------------------------------------------------------------

Q3. Why Dijkstra fails for negative weights?

→ greedy choice wrong ho sakti hai

============================================================
QUICK RECALL
============================================================

weighted graph
+ shortest path
+ no negative weight

→ Dijkstra Algorithm

============================================================
*/

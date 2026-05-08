#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
============================================================
DIJKSTRA ALGORITHM (PRIORITY QUEUE)
============================================================

INTUITION:

- shortest distance from source node to all nodes
- graph weighted hai
- always minimum distance node process karte hain

------------------------------------------------------------

WHY PRIORITY QUEUE?

- minimum distance node quickly milta hai
- normal Dijkstra se faster

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

3. min heap (priority queue) use karo
   - stores {distance,node}

4. minimum distance node nikalo

5. neighbours relax karo

6. agar better path mile:
   - distance update
   - priority queue me push

7. repeat until queue empty

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

        // min heap -> {distance,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;                             //source distance = 0

        pq.push(make_pair(0,src));                 //push source node

        while(!pq.empty()){

            int node = pq.top().second;            //minimum distance node
            pq.pop();

            if(explored[node])
            continue;                              //already processed

            explored[node] = true;

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

                    pq.push({dist[neigh],neigh});      //push updated node
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

push:
(0,2)

------------------------------------------------------------

PROCESS NODE 2

2 -> 1 (3)
2 -> 0 (6)

dist = [6,3,0]

push:
(3,1)
(6,0)

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

O((V + E) logV)

============================================================
SPACE COMPLEXITY
============================================================

O(V + E)

============================================================
IMPORTANT POINTS
============================================================

1. Works only for NON-NEGATIVE weights

2. Greedy Algorithm

3. Priority Queue gives fastest implementation

4. BFS cannot be used because graph weighted hai

5. Priority Queue stores:
   {distance,node}

6. explored[] prevents multiple processing

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

Q1. Why Dijkstra fails for negative edge?

→ greedy decision wrong ho sakta hai

------------------------------------------------------------

Q2. Difference between BFS and Dijkstra?

BFS:
- unweighted graph
- queue

Dijkstra:
- weighted graph
- priority queue

------------------------------------------------------------

Q3. Which algorithm for negative weights?

→ Bellman Ford

------------------------------------------------------------

Q4. Why Priority Queue?

→ minimum distance node efficiently milta hai

============================================================
QUICK RECALL
============================================================

weighted graph
+ shortest path
+ no negative weight

→ Dijkstra Algorithm

============================================================
*/
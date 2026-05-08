#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
============================================================
NETWORK DELAY TIME
============================================================

INTUITION:

- signal source node se start hota hai
- minimum time me har node tak signal pahuchana hai
- weighted directed graph
- shortest path problem

------------------------------------------------------------

MAIN IDEA:

- source node se shortest distance find karo
- last node tak pahuchne ka minimum time answer hoga
- agar koi node unreachable hai -> return -1

------------------------------------------------------------

WHY DIJKSTRA?

- graph weighted hai
- shortest path chahiye
- all weights positive hain

============================================================
APPROACH
============================================================

1. adjacency list banao

2. dist[] array banao
   - initially INT_MAX
   - source = 0

3. priority queue use karo
   - stores {distance,node}

4. minimum distance node process karo

5. neighbours relax karo

6. finally:
   - maximum shortest distance return karo
   - agar koi node unreachable hai -> return -1

============================================================
*/

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        // create adjacency list
        for(auto e:times){

            int u = e[0];
            int v = e[1];
            int weight = e[2];

            adj[u].push_back(make_pair(v,weight)); //u -> v
        }

        vector<bool> explored(n+1,0);              //fully explored nodes

        vector<int> dist(n+1,INT_MAX);             //minimum distances

        // min heap -> {distance,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k] = 0;                               //source distance

        pq.push(make_pair(0,k));                   //push source node

        while(!pq.empty()){

            int node = pq.top().second;            //minimum distance node

            pq.pop();

            if(explored[node])
            continue;                              //already processed

            explored[node] = true;                 //mark explored

            // relax neighbours
            for(int j=0;j<adj[node].size();j++){

                int neigh = adj[node][j].first;    //neighbour node

                int weight = adj[node][j].second;  //edge weight

                // relaxation
                if(!explored[neigh]
                &&
                dist[node] + weight < dist[neigh]){

                    dist[neigh] = dist[node] + weight; //update distance

                    pq.push({dist[neigh],neigh});      //push updated node
                }
            }
        }

        // find maximum shortest distance
        int ans = 0;

        for(int i=1;i<dist.size();i++){

            if(dist[i] == INT_MAX)
            return -1;                             //unreachable node

            ans = max(ans,dist[i]);
        }

        return ans;
    }
};

/*
============================================================
MAIN FUNCTION
============================================================
*/

int main(){

    Solution obj;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;
    int k = 2;

    cout<<obj.networkDelayTime(times,n,k);

    return 0;
}

/*
============================================================
DRY RUN
============================================================

INPUT:

times = [[2,1,1],[2,3,1],[3,4,1]]

source = 2

------------------------------------------------------------

GRAPH:

2 -> 1 (1)
2 -> 3 (1)
3 -> 4 (1)

------------------------------------------------------------

INITIAL:

dist = [INF,INF,0,INF,INF]

------------------------------------------------------------

PROCESS NODE 2

update:

dist[1] = 1
dist[3] = 1

------------------------------------------------------------

PROCESS NODE 3

update:

dist[4] = 2

------------------------------------------------------------

FINAL DISTANCES:

1 -> 1
2 -> 0
3 -> 1
4 -> 2

maximum shortest distance = 2

ANSWER = 2

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

1. Directed Weighted Graph

2. Dijkstra Algorithm used

3. Answer = maximum shortest distance

4. If any node unreachable:
   return -1

5. Priority Queue stores:
   {distance,node}

============================================================
INTERVIEW QUESTIONS
============================================================

Q1. Why maximum distance return kar rahe hain?

→ signal ko sab nodes tak pahuchne ka total time chahiye

------------------------------------------------------------

Q2. Why Dijkstra used?

→ weighted graph + shortest path

------------------------------------------------------------

Q3. Why BFS not used?

→ graph weighted hai

============================================================
QUICK RECALL
============================================================

weighted graph
+ shortest path
+ source to all nodes

→ Dijkstra Algorithm

============================================================
*/
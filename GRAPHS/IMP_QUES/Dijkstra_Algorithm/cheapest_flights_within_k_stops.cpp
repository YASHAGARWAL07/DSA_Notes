#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
============================================================
CHEAPEST FLIGHTS WITHIN K STOPS
============================================================

INTUITION:

- source se destination tak minimum cost me jana hai
- but maximum k stops allowed hain

Normal Dijkstra sirf minimum distance dekhta hai.

Yaha:
- cheaper path invalid ho sakta hai
- because stops zyada ho sakte hain

Isliye:
cost + stops
dono track karne padenge

============================================================
MAIN IDEA
============================================================

Priority Queue stores:

{cost,node,stops}

Har baar:
- minimum cost state process karenge
- stops limit maintain karenge

============================================================
APPROACH
============================================================

1. adjacency list banao

2. min heap use karo:
   {cost,node,stops}

3. source node push karo

4. neighbours explore karo

5. agar stops > k
   ignore

6. destination milte hi return cost

============================================================
*/

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        //create adjacency list
        vector<vector<pair<int,int>>>adj(n);

        for(auto e : flights){
            int u = e[0];
            int v = e[1];
            int price = e[2];

            adj[u].push_back(make_pair(v,price));
        }

        //{cost,node,stops}
        priority_queue<vector<int>,
        vector<vector<int>>,
        greater<vector<int>>>pq;

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        pq.push({0,src,0});

        //stores minimum stops to reach node
        vector<int>minStops(n,INT_MAX);

        while(!pq.empty()){

            int cost = pq.top()[0];
            int node = pq.top()[1];
            int stops = pq.top()[2];

            pq.pop();

            //destination reached
            if(node == dst)
            return cost;

            //invalid case
            if(stops > k || stops >= minStops[node])
            continue;

            minStops[node] = stops;

            //explore neighbours
            for(int j=0;j<adj[node].size();j++){

                int neigh = adj[node][j].first;
                int price = adj[node][j].second;

                pq.push({cost+price,neigh,stops+1});
            }
        }

        return -1;
    }
};

/*
============================================================
DRY RUN
============================================================

INPUT:

n = 4

0 -> 1 (100)
1 -> 2 (100)
1 -> 3 (600)
2 -> 3 (200)

src = 0
dst = 3
k = 1

------------------------------------------------------------

START:

pq = {0,0,0}

------------------------------------------------------------

POP:

cost = 0
node = 0
stops = 0

push:
{100,1,1}

------------------------------------------------------------

POP:

cost = 100
node = 1
stops = 1

push:
{200,2,2}
{700,3,2}

------------------------------------------------------------

POP:

cost = 200
node = 2
stops = 2

invalid
because stops > k

------------------------------------------------------------

POP:

cost = 700
node = 3

destination reached

ANSWER = 700

============================================================
TIME COMPLEXITY
============================================================

O(E logE)

============================================================
SPACE COMPLEXITY
============================================================

O(V + E)

============================================================
IMPORTANT POINTS
============================================================

1. Normal Dijkstra se different problem hai

2. Cost + Stops dono maintain karne padte hain

3. Cheapest path always valid nahi hota

4. Priority Queue stores:
   {cost,node,stops}

5. minStops array optimization ke liye use hota hai

============================================================
WHY minStops ARRAY?
============================================================

Agar kisi node tak:
- kam stops me already pahuch gaye

toh zyada stops wala path useless hoga

============================================================
INTERVIEW QUESTIONS
============================================================

Q1. Why not normal Dijkstra?

→ because stops constraint bhi hai

------------------------------------------------------------

Q2. Why priority queue?

→ minimum cost state pehle process karne ke liye

------------------------------------------------------------

Q3. Why minStops array?

→ unnecessary states avoid karne ke liye

------------------------------------------------------------

Q4. Can BFS solve this?

→ weighted graph hai
so normal BFS nahi chalega

============================================================
QUICK RECALL
============================================================

weighted graph
+ minimum cost
+ stop constraint

→ Modified Dijkstra

============================================================
*/
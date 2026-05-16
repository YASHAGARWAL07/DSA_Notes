#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void DFS(int node, vector<int> adj[], vector<bool>& visited) {

        visited[node] = 1;                    //mark node visited

        for(int j = 0; j < adj[node].size(); j++) {

            int neigh = adj[node][j];

            if(!visited[neigh])               //visit unvisited neighbour
                DFS(neigh, adj, visited);
        }
    }

    int isEulerCircuit(int V, vector<int> adj[]) {

        /*
        RETURN VALUES:
        ----------------
        0 -> Not Euler Graph
        1 -> Euler Path Exists
        2 -> Euler Circuit Exists
        */

        /*
        EULER CIRCUIT CONDITIONS:
        --------------------------
        1. All non-zero degree nodes connected
        2. All degrees even

        EULER PATH CONDITIONS:
        -----------------------
        1. All non-zero degree nodes connected
        2. Either 0 or 2 odd degree nodes
        */

        vector<bool> visited(V, 0);
        vector<int> Deg(V, 0);

        int odd_Deg = 0;                      //count odd degree nodes

        //calculate degree of each node
        for(int i = 0; i < V; i++) {

            Deg[i] = adj[i].size();

            if(Deg[i] % 2)                    //if degree odd
                odd_Deg++;
        }

        //if odd degree nodes are neither 0 nor 2
        if(odd_Deg != 0 && odd_Deg != 2)
            return 0;

        //find first non-zero degree node and start DFS
        for(int i = 0; i < V; i++) {

            if(Deg[i]) {

                DFS(i, adj, visited);
                break;
            }
        }

        //check all non-zero degree nodes are connected
        for(int i = 0; i < V; i++) {

            if(Deg[i] && !visited[i])
                return 0;
        }

        //all degrees even -> Euler Circuit
        if(odd_Deg == 0)
            return 2;

        //2 odd degree nodes -> Euler Path
        return 1;
    }
};

int main() {

    int V = 5;

    vector<int> adj[V];

    //Undirected Graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    adj[0].push_back(2);
    adj[2].push_back(0);

    Solution obj;

    int ans = obj.isEulerCircuit(V, adj);

    if(ans == 0)
        cout << "Not Euler Graph" << endl;

    else if(ans == 1)
        cout << "Euler Path Exists" << endl;

    else
        cout << "Euler Circuit Exists" << endl;

    return 0;
}

/*

===========================================================
INTUITION
===========================================================

Euler Path:
------------
Visit every edge exactly once.

Euler Circuit:
---------------
Visit every edge exactly once
and return back to starting node.

===========================================================
IMPORTANT CONDITIONS
===========================================================

Euler Path:
-------------
1. Connected graph
2. 0 or 2 odd degree nodes

Euler Circuit:
----------------
1. Connected graph
2. All degree even

===========================================================
WHY ODD DEGREE = 2 ?
===========================================================

One odd node becomes START
Another odd node becomes END

All remaining nodes must have even degree.

===========================================================
TIME COMPLEXITY
===========================================================

Degree Calculation -> O(V)

DFS Traversal -> O(V + E)

Overall:
O(V + E)

===========================================================
SPACE COMPLEXITY
===========================================================

Visited Array -> O(V)

DFS Stack -> O(V)

Overall:
O(V)

===========================================================
IMPORTANT EDGE CASES
===========================================================

1. Disconnected graph
   -> No Euler Path/Circuit

2. All even degree
   -> Euler Circuit exists

3. Exactly 2 odd degree nodes
   -> Euler Path exists

4. More than 2 odd degree nodes
   -> Not possible

5. Isolated nodes
   -> Ignore while checking connectivity

===========================================================
INTERVIEW QUESTIONS
===========================================================

Q1. Difference between Euler Path and Euler Circuit?

Q2. Why only 0 or 2 odd degree nodes?

Q3. Why connectivity important?

Q4. Difference between Euler and Hamiltonian?

Euler:
------
Visit EDGES exactly once

Hamiltonian:
-------------
Visit NODES exactly once

===========================================================

*/
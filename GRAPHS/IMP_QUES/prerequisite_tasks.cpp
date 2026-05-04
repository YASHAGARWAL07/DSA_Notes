/*
------------------------------------------------------------
prerequisite tasks
------------------------------------------------------------

intuition:

- har task ke kuch prerequisites ho sakte hain

example:
task u karne ke liye v pehle complete hona chahiye

→ dependency graph

------------------------------------------------------------

core idea:

- problem = detect cycle in directed graph

kyun?

- agar cycle hai → tasks circular dependency me hain → possible nahi
- agar cycle nahi hai → possible

------------------------------------------------------------

approach (kahn's algorithm - BFS):

1. graph banao (adj list)
2. indegree calculate karo
3. jinka indegree 0 hai → queue me daalo
4. BFS chalao:
   - node nikalo
   - neighbours ka indegree reduce karo
   - agar indegree 0 ho jaye → queue me daalo
5. count karo kitne nodes process hue

→ agar count == N → possible
→ warna → cycle hai → not possible

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        //create adjacency list
        vector<int>InDeg(N,0);
        vector<vector<int>>adj(N);
        for(auto e:prerequisites){
            int u = e.first;
            int v = e.second;
            adj[v].push_back(u);
            InDeg[u]++;
        }

        //Kahn's Algorithm - Topological sort
        queue<int>q;
        for(int i=0;i<N;i++)
        if(InDeg[i]==0)
        q.push(i);

        int count = 0;  //store size of topological sort

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            //look at the neighbours
            for(int j=0;j<adj[node].size();j++){
                InDeg[adj[node][j]]--;
                if(InDeg[adj[node][j]]==0)
                q.push(adj[node][j]);
            }
        }

        return(count==N);
    }
};

/*
------------------------------------------------------------
main (for vs code)
------------------------------------------------------------
*/

int main(){

    Solution obj;

    int N = 4;
    int P = 3;

    vector<pair<int,int>> prerequisites = {
        {1,0},
        {2,1},
        {3,2}
    };

    cout << obj.isPossible(N,P,prerequisites);

    return 0;
}

/*
------------------------------------------------------------
important points:

- directed graph hai
- dependency = edge
- indegree concept important

------------------------------------------------------------
time complexity:

O(V + E)

------------------------------------------------------------
space complexity:

O(V + E)

------------------------------------------------------------
pattern:

- topological sort
- cycle detection (indirectly)

------------------------------------------------------------
similar questions:

- course schedule
- find eventual safe states
- alien dictionary
- topo sort

------------------------------------------------------------
quick recall:

- indegree 0 → start
- BFS
- count nodes
- count != N → cycle

------------------------------------------------------------
*/
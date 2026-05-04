/*
------------------------------------------------------------
keys and rooms
------------------------------------------------------------

intuition:

- har room me kuch keys milti hain
- key = dusre room ka access

→ problem becomes:

"can we visit all nodes starting from node 0?"

→ graph traversal problem

------------------------------------------------------------

core idea:

- treat rooms as graph
- room = node
- keys = edges

→ BFS use karo (queue)

step:

1. start from room 0
2. jo keys milti hain → un rooms me jao
3. visited mark karo
4. end me check → sab visited hue ya nahi

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>visited(rooms.size(),0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(auto key : rooms[room])
             if(!visited[key]){
              visited[key] = true;
              q.push(key);
             }
        }
        for(int i=0;i<visited.size();i++)
        if(!visited[i])
        return false;

        return true;
    }
};

/*
------------------------------------------------------------
main (for vs code)
------------------------------------------------------------
*/

int main(){

    Solution obj;

    vector<vector<int>> rooms = {
        {1},
        {2},
        {3},
        {}
    };

    cout << obj.canVisitAllRooms(rooms);

    return 0;
}

/*
------------------------------------------------------------
important points:

- BFS / DFS dono chalega
- starting node always 0
- simple graph traversal

------------------------------------------------------------
time complexity:

O(V + E)

------------------------------------------------------------
space complexity:

O(V)

------------------------------------------------------------
pattern:

- reachability problem
- traversal (BFS / DFS)
- graph connectivity

------------------------------------------------------------
similar questions:

- number of provinces
- flood fill
- number of islands
- DFS/BFS traversal

------------------------------------------------------------
quick recall:

- start from 0
- queue
- visit neighbours
- check all visited

------------------------------------------------------------
*/

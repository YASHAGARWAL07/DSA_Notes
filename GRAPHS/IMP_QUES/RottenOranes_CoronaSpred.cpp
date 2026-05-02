/*
============================================================
ROTTEN ORANGES / HOSPITAL INFECTION (BFS)
============================================================

given:
0 -> empty
1 -> healthy
2 -> infected

goal:
minimum time to infect all

============================================================
idea:
============================================================

- multiple sources (all 2's)
- BFS level by level (time = levels)

each level = 1 minute

============================================================
logic:
============================================================

1. sab infected cells queue me daal do
2. BFS chalao
3. har level pe:
    -> neighbours infect karo
    -> agar kuch infect hua → timer++

4. end me check:
    -> koi 1 bacha hai → return -1
    -> else return timer

============================================================
important:
============================================================

- multi-source BFS
- grid traversal
- direction array use

============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
  
    int r;
    int c;
    
    bool valid(int i, int j){
         if(i>=0 && i<r && j>=0 && j<c)
           return true;
      
         return false;
    }
    
    int helpaterp(vector<vector<int>> hospital) {
        
        r = hospital.size();
        c = hospital[0].size();
        
        queue<pair<int,int>> q;
        
        // push all infected cells
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(hospital[i][j]==2)
            q.push({i,j});
        
        int timer = 0;
        
        while(!q.empty()){
            
            bool spread = false;
            
            int curr_patient = q.size();
            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};
            
            while(curr_patient--){
                
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++)
                if(valid(i+row[k],j+col[k]) && hospital[i+row[k]][j+col[k]]==1){
                    
                    hospital[i+row[k]][j+col[k]] = 2;
                    q.push({i+row[k],j+col[k]});
                    spread = true;
                }
            }
            
            if(spread)
                timer++;
        }
        
        // check if any healthy left
        for(int i=0;i<r;i++)
         for(int j=0;j<c;j++)
           if(hospital[i][j]==1)
              return -1;
           
        return timer;
    }
};

/*
------------------------------------------------------------
MAIN (for VS Code)
------------------------------------------------------------
*/

int main() {

    Solution obj;

    vector<vector<int>> hospital = {
        {2,1,0},
        {1,1,0},
        {0,1,1}
    };

    int ans = obj.helpaterp(hospital);

    cout << ans << endl;

    return 0;
}

/*
------------------------------------------------------------
quick revision:
------------------------------------------------------------

- queue me sab 2 daalo
- level wise BFS
- spread hua → timer++
- last me check 1 bacha ya nahi

------------------------------------------------------------
similar problems:
------------------------------------------------------------

- Rotten Oranges (Leetcode)
- Fire Spread
- Zombie Infection

============================================================
*/
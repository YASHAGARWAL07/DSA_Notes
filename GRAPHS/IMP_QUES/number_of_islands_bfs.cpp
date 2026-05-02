/*
------------------------------------------------------------
number of islands (bfs - 8 directions)
------------------------------------------------------------

'L' -> land
'W' -> water

goal:
count connected components (islands)

------------------------------------------------------------
idea:

- jab bhi 'L' mile → new island
- BFS chala ke pura island mark karo (W bana do)
- count++

------------------------------------------------------------
important:

- 8 directions (including diagonal)
- visited ke liye grid modify kar diya (space save)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
  
  int r;
  int c;
  
  int row[8] = {-1,-1,-1,0,0,1,1,1};
  int col[8] = {-1,0,1,-1,1,-1,0,1};
  
  bool valid(int i,int j){
      return (i>=0 && i<r && j>=0 && j<c);
  }
  
    int countIslands(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        int count = 0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<r;i++)
         for(int j=0;j<c;j++)
             if(grid[i][j]=='L'){
                 
                 count++;
                 q.push({i,j});
                 grid[i][j] = 'W';
                 
                 while(!q.empty()){
                     int new_i = q.front().first;
                     int new_j = q.front().second;
                     q.pop();
                     
                     for(int k=0;k<8;k++)
                         if(valid(new_i+row[k],new_j+col[k]) && 
                            grid[new_i+row[k]][new_j+col[k]]=='L'){
                            
                            q.push({new_i+row[k],new_j+col[k]});
                            grid[new_i+row[k]][new_j+col[k]] = 'W';
                         }
                 }
         }
         return count;
    }
};

/*
------------------------------------------------------------
main (vs code)
------------------------------------------------------------
*/

int main(){

    Solution obj;

    vector<vector<char>> grid = {
        {'L','L','W','W','W'},
        {'W','L','W','W','L'},
        {'L','W','W','L','L'},
        {'W','W','W','W','W'},
        {'L','W','L','L','W'}
    };

    cout << obj.countIslands(grid);

    return 0;
}

/*
------------------------------------------------------------
quick recall:

- for every 'L' → BFS
- mark visited as 'W'
- 8 directions check

------------------------------------------------------------
variations:

- 4 direction version (common in leetcode)
- DFS version
- number of provinces (graph version)

------------------------------------------------------------
*/

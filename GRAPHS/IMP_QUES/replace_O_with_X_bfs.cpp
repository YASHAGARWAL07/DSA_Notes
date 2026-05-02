/*
------------------------------------------------------------
replace O with X (boundary bfs)
------------------------------------------------------------

rule:
'O' ko 'X' banana hai agar wo completely surrounded hai

------------------------------------------------------------
idea:

- boundary wale 'O' safe hote hain (unko change nahi karna)
- unko mark karo ('Y')
- baaki jo 'O' bach gaye → wo surrounded hain → 'X'

------------------------------------------------------------
steps:

1. boundary ke sab 'O' → BFS → mark as 'Y'
2. jo 'O' bach gaye → 'X'
3. 'Y' ko wapas 'O'

------------------------------------------------------------
important:

- 4 direction only
- boundary traversal is key

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
  int row[4] = {-1,1,0,0};
  int col[4] = {0,0,-1,1};
  
  bool valid(int i,int j){
      return (i>=0 && i<r && j>=0 && j<c);
  }
  
    void fill(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        queue<pair<int,int>>q;
        
        // first row
        for(int j=0;j<c;j++)
            if(grid[0][j] == 'O'){
                q.push({0,j});
                grid[0][j] = 'Y';
            }

        // first column
        for(int i=0;i<r;i++)
            if(grid[i][0] == 'O'){
                q.push({i,0});
                grid[i][0] = 'Y';
            }

        // last row
        for(int j=0;j<c;j++)
            if(grid[r-1][j] == 'O'){
                q.push({r-1,j});
                grid[r-1][j] = 'Y';
            }

        // last column
        for(int i=0;i<r;i++)
            if(grid[i][c-1] == 'O'){
                q.push({i,c-1});
                grid[i][c-1] = 'Y';
            }
        
        // bfs
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
                if(valid(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]] == 'O'){
                    q.push({i+row[k],j+col[k]});
                    grid[i+row[k]][j+col[k]] = 'Y';
                }
        }

        // final conversion
        for(int i=0;i<r;i++)
         for(int j=0;j<c;j++){
             if(grid[i][j] == 'O')
                 grid[i][j] = 'X';
             else if(grid[i][j] == 'Y')
                 grid[i][j] = 'O';
         }
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
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    obj.fill(grid);

    for(auto &row : grid){
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*
------------------------------------------------------------
quick recall:

- boundary 'O' safe
- BFS from boundary
- mark 'Y'
- convert rest

------------------------------------------------------------
similar questions:

- surrounded regions (leetcode)
- flood fill
- number of islands

------------------------------------------------------------
*/
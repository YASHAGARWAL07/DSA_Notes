#include<iostream>
#include<vector>
using namespace std;

/*
  ============ MAKE A SQUARE WITH THE SAME COLOR ============
  (LeetCode 3127 – Make a Square with the Same Color)

  Problem:
  - Given a 3 x 3 grid
  - Each cell is either:
      'B' → Black
      'W' → White
  - You are allowed to change AT MOST ONE cell
  - Check if it is possible to form a 2 x 2 square
    where all 4 cells have the SAME color

  -----------------------------------------------------------
  KEY OBSERVATION (VERY IMPORTANT):

  - In a 2x2 square:
      If at least 3 cells are same color,
      then by changing at most 1 cell,
      all 4 can be made same.

  So condition:
  - Count 'B' and 'W' in every 2x2 subgrid
  - If (black >= 3) OR (white >= 3) → return true
*/

/*
  Possible 2x2 squares in a 3x3 grid:
  ----------------------------------
  (0,0) (0,1)   (0,1) (0,2)
  (1,0) (1,1)   (1,1) (1,2)

  (1,0) (1,1)   (1,1) (1,2)
  (2,0) (2,1)   (2,1) (2,2)
*/

bool canMakeSquare(vector<vector<char>>& grid)
{
    // Only 4 possible 2x2 squares in a 3x3 grid
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int black = 0, white = 0;

            // Count colors in current 2x2 square
            if(grid[i][j] == 'B') black++; else white++;
            if(grid[i+1][j] == 'B') black++; else white++;
            if(grid[i][j+1] == 'B') black++; else white++;
            if(grid[i+1][j+1] == 'B') black++; else white++;

            // If at least 3 cells are same color
            if(black >= 3 || white >= 3)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> grid = {
        {'B','W','B'},
        {'B','W','W'},
        {'B','W','B'}
    };

    cout << (canMakeSquare(grid) ? "true" : "false") << endl;

    /*
      ===================== IMPORTANT NOTES =====================

      1) Only check 2x2 squares (not whole grid)

      2) Why ">= 3" works?
         - Because we can change at most ONE cell

      3) Total checks:
         - Fixed: only 4 sub-grids

      4) Time Complexity:
         O(1)

      5) Space Complexity:
         O(1)

      6) Very common for:
         - LeetCode Easy
         - Pattern observation
         - Interview logic questions
    */

    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== SHIFT 2D GRID =====================
  (LeetCode 1260 – Shift 2D Grid)

  Problem:
  - Given a 2D grid of size m x n
  - Given an integer k
  - Shift the grid k times

  One shift operation:
  --------------------
  1) grid[i][j] → grid[i][j+1]
  2) grid[i][n-1] → grid[i+1][0]
  3) grid[m-1][n-1] → grid[0][0]

  ---------------------------------------------------------
  KEY IDEA (IMPORTANT):
  - Treat 2D grid as a 1D array
  - Perform rotation on 1D array
  - Convert back to 2D
*/

/*
  Example:
  --------
  Input:
  1 2 3
  4 5 6
  7 8 9
  k = 1

  Output:
  9 1 2
  3 4 5
  6 7 8
*/

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
    int m = grid.size();        // rows
    int n = grid[0].size();     // cols
    int total = m * n;

    // Optimize k (important for large k)
    k = k % total;

    // ---------- STEP 1: FLATTEN 2D → 1D ----------
    vector<int> temp;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            temp.push_back(grid[i][j]);
    }

    // ---------- STEP 2: SHIFT IN 1D ----------
    vector<int> shifted(total);
    for(int i = 0; i < total; i++)
    {
        shifted[(i + k) % total] = temp[i];
    }

    // ---------- STEP 3: PUT BACK INTO 2D ----------
    int idx = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            grid[i][j] = shifted[idx];
            idx++;
        }
    }

    return grid;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 1;

    vector<vector<int>> ans = shiftGrid(grid, k);

    // Print shifted grid
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    /*
      ===================== IMPORTANT NOTES =====================

      1) Always reduce k:
         k = k % (m*n)

      2) Linear indexing:
         index = i*n + j

      3) Reverse mapping:
         i = index / n
         j = index % n

      4) Time Complexity:
         O(m * n)

      5) Space Complexity:
         O(m * n)

      6) Very common problem for:
         - LeetCode Easy
         - Matrix + Array mapping
         - Interview basics

      7) In-place solution is NOT required here
    */

    return 0;
}

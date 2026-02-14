#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== DIAGONAL TRAVERSE =====================
  (LeetCode 498 – Diagonal Traverse)

  Problem:
  - Given an m x n matrix
  - Return all elements in DIAGONAL ORDER (zig-zag)

  Traversal Pattern:
  ------------------
  ↗ Up-right direction
  ↙ Down-left direction
  (Direction changes when boundary is hit)
*/

/*
  Example:
  --------
  Input:
  1 2 3
  4 5 6
  7 8 9

  Output:
  1 2 4 7 5 3 6 8 9
*/

vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();

    vector<int> ans;
    int r = 0, c = 0;
    bool up = true;   // direction flag

    for(int k = 0; k < m * n; k++)
    {
        ans.push_back(mat[r][c]);

        if(up)
        {
            // ---------- MOVING UP-RIGHT ----------
            if(c == n - 1)       // hit right boundary
            {
                r++;
                up = false;
            }
            else if(r == 0)      // hit top boundary
            {
                c++;
                up = false;
            }
            else
            {
                r--;
                c++;
            }
        }
        else
        {
            // ---------- MOVING DOWN-LEFT ----------
            if(r == m - 1)       // hit bottom boundary
            {
                c++;
                up = true;
            }
            else if(c == 0)      // hit left boundary
            {
                r++;
                up = true;
            }
            else
            {
                r++;
                c--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans = findDiagonalOrder(mat);

    // Print diagonal traversal
    for(int x : ans)
        cout << x << " ";

    /*
      ===================== IMPORTANT NOTES =====================

      1) Two directions:
         - up-right (↗)
         - down-left (↙)

      2) Direction changes ONLY when boundary is hit

      3) Boundaries:
         - Top row    → r == 0
         - Bottom row → r == m-1
         - Left col   → c == 0
         - Right col  → c == n-1

      4) Time Complexity:
         O(m * n)

      5) Space Complexity:
         O(m * n) for answer

      6) Very IMPORTANT for:
         - LeetCode Medium
         - Matrix traversal logic
         - Interview zig-zag patterns
    */

    return 0;
}

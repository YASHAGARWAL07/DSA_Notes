#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== SUM OF DIAGONAL ELEMENTS =====================

  Problem:
  - Given a square matrix (n x n)
  - Find the sum of:
      1) Primary Diagonal
      2) Secondary Diagonal
  - If matrix size is ODD, the middle element
    (common to both diagonals) should be counted ONLY ONCE

  --------------------------------------------------
  Diagonal Indices:
  - Primary Diagonal    → matrix[i][i]
  - Secondary Diagonal  → matrix[i][n - i - 1]
*/

/*
  Example:
  --------
  Input:
  1  2  3
  4  5  6
  7  8  9

  Primary diagonal   = 1 + 5 + 9 = 15
  Secondary diagonal = 3 + 5 + 7 = 15

  Middle element (5) counted twice → subtract once

  Final Answer = 15 + 15 - 5 = 25
*/

int diagonalSum(vector<vector<int>>& mat)
{
    int n = mat.size();
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        // Primary diagonal
        sum += mat[i][i];

        // Secondary diagonal
        sum += mat[i][n - i - 1];
    }

    // If n is odd, subtract middle element once
    if(n % 2 == 1)
        sum -= mat[n / 2][n / 2];

    return sum;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << diagonalSum(mat) << endl;

    /*
      ===================== IMPORTANT NOTES =====================

      1) Works ONLY for square matrix (n x n)

      2) Middle element overlap occurs ONLY when n is odd

      3) Time Complexity:
         O(n)

      4) Space Complexity:
         O(1)

      5) Very common problem:
         - LeetCode
         - Matrix basics
         - Interview warm-up

      6) Alternate name:
         - Diagonal Sum
         - Matrix Diagonal Traversal (basic)
    */

    return 0;
}

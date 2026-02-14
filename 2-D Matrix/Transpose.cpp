#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== TRANSPOSE OF MATRIX =====================
  (LeetCode 867 – Transpose Matrix)

  Definition:
  - Transpose of a matrix means:
    Row becomes Column
    Column becomes Row

  If original matrix is:
    matrix[i][j]

  Then transpose matrix is:
    transpose[j][i]

  --------------------------------------------------------------
  Original Size : n x m
  Transpose Size: m x n
*/

/*
  Example:
  --------
  Input:
  1 2 3
  4 5 6

  Output (Transpose):
  1 4
  2 5
  3 6
*/

vector<vector<int>> transpose(vector<vector<int>>& matrix)
{
    int n = matrix.size();        // number of rows
    int m = matrix[0].size();     // number of columns

    // Create transpose matrix of size m x n
    vector<vector<int>> tmat(m, vector<int>(n, 0));

    // Swap indices
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tmat[j][i] = matrix[i][j];
        }
    }

    return tmat;
}

int main()
{
    /*
      Example Input:
      matrix =
      {
        {1, 2, 3},
        {4, 5, 6}
      }
    */

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> ans = transpose(matrix);

    // Print transpose matrix
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    /*
      ===================== IMPORTANT NOTES =====================

      1) Transpose means:
         matrix[i][j] → matrix[j][i]

      2) Size changes:
         n x m → m x n

      3) Always create NEW matrix for transpose
         (unless square matrix + in-place allowed)

      4) Time Complexity:
         O(n * m)

      5) Space Complexity:
         O(n * m)

      6) Very common in:
         - LeetCode
         - GATE
         - Interviews

      7) In-place transpose is possible ONLY for square matrices
    */

    return 0;
}

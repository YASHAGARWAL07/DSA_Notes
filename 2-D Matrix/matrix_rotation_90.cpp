#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== ROTATE IMAGE (90° CLOCKWISE) =====================
  (LeetCode 48 – Rotate Image)

  Problem:
  - Given an n x n matrix
  - Rotate the matrix by 90 degrees CLOCKWISE
  - Rotation must be done IN-PLACE
  - Do NOT use extra 2D matrix

  ----------------------------------------------------
  KEY OBSERVATION (VERY IMPORTANT):

  90° Clockwise Rotation can be done in 2 STEPS:
  1) Transpose the matrix
  2) Reverse each row
*/

/*
  STEP 1: TRANSPOSE
  -----------------
  matrix[i][j] ↔ matrix[j][i]

  NOTE:
  - Transpose only upper triangle (j = i+1)
  - Avoid double swapping
*/

/*
  STEP 2: REVERSE EACH ROW
  -----------------------
  Reverse elements of every row
*/

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // ---------- STEP 1: TRANSPOSE ----------
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // ---------- STEP 2: REVERSE EACH ROW ----------
    for(int i = 0; i < n; i++)
    {
        int start = 0;
        int end = n - 1;

        while(start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

int main()
{
    /*
      Example:
      Input:
      1 2 3
      4 5 6
      7 8 9

      Output (90° Clockwise):
      7 4 1
      8 5 2
      9 6 3
    */

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(matrix);

    // Print rotated matrix
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix.size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    /*
      ===================== IMPORTANT NOTES =====================

      1) Works ONLY for square matrix (n x n)

      2) In-place rotation:
         - No extra 2D array used

      3) Time Complexity:
         O(n^2)

      4) Space Complexity:
         O(1)  (in-place)

      5) Order matters:
         ✔ Transpose first
         ✔ Then reverse rows

      6) For 90° Anti-clockwise:
         - Transpose
         - Reverse each COLUMN (not row)

      7) VERY IMPORTANT for:
         - LeetCode
         - Interviews
         - GATE
    */

    return 0;
}

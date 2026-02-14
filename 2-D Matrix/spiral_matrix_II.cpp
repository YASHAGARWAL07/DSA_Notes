#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== SPIRAL MATRIX II =====================
  (LeetCode 59)

  Problem:
  - Given an integer n
  - Generate an n x n matrix filled with numbers from 1 to n^2
  - Fill the matrix in SPIRAL ORDER

  Spiral Direction Order:
  → Right
  ↓ Down
  ← Left
  ↑ Up
*/

/*
  Boundary Variables:
  ------------------
  top    : starting row
  bottom : ending row
  left   : starting column
  right  : ending column

  num:
  ----
  - Current number to be inserted (starts from 1)
*/

vector<vector<int>> generateMatrix(int n)
{
    // Create n x n matrix filled with 0
    vector<vector<int>> mat(n, vector<int>(n, 0));

    int top = 0, left = 0;
    int bottom = n - 1, right = n - 1;
    int num = 1;

    // Loop until boundaries cross
    while(top <= bottom && left <= right)
    {
        // ---------- LEFT → RIGHT (top row) ----------
        for(int j = left; j <= right; j++)
            mat[top][j] = num++;
        top++;

        // ---------- TOP → BOTTOM (right column) ----------
        for(int i = top; i <= bottom; i++)
            mat[i][right] = num++;
        right--;

        // ---------- RIGHT → LEFT (bottom row) ----------
        if(top <= bottom)
        {
            for(int j = right; j >= left; j--)
                mat[bottom][j] = num++;
            bottom--;
        }

        // ---------- BOTTOM → TOP (left column) ----------
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                mat[i][left] = num++;
            left++;
        }
    }

    return mat;
}

int main()
{
    /*
      Example:
      Input : n = 3

      Output:
      1  2  3
      8  9  4
      7  6  5
    */

    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    /*
      ===================== IMPORTANT NOTES =====================

      1) This is opposite of Spiral Matrix I:
         - Here we FILL the matrix
         - There we READ the matrix

      2) Boundary checks (VERY IMPORTANT):
         - Always check:
           top <= bottom
           left <= right

      3) Time Complexity:
         O(n^2)  → each cell filled once

      4) Space Complexity:
         O(n^2)  → matrix storage

      5) Common Mistakes:
         ❌ Forgetting boundary checks
         ❌ Wrong update of top/bottom/left/right
         ❌ Incrementing num incorrectly

      6) Asked frequently in:
         - LeetCode
         - Interviews
         - GATE (logic based)
    */

    return 0;
}

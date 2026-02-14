#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== 2-D MATRIX : SPIRAL ORDER =====================
  (LeetCode 54 – Spiral Matrix)

  Problem:
  - Given an m x n matrix
  - Return all elements in spiral order

  Spiral Order Direction:
  → Right
  ↓ Down
  ← Left
  ↑ Up

  We keep shrinking the boundary after every traversal
*/

/*
  Boundary Variables:
  -------------------
  top    : starting row
  bottom : ending row
  left   : starting column
  right  : ending column
*/

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;

    // Edge case: empty matrix
    if(matrix.size() == 0)
        return ans;

    int top = 0;
    int left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;

    // Continue while boundaries are valid
    while(top <= bottom && left <= right)
    {
        // ---------- LEFT → RIGHT (top row) ----------
        for(int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        // ---------- TOP → BOTTOM (right column) ----------
        for(int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // ---------- RIGHT → LEFT (bottom row) ----------
        if(top <= bottom)
        {
            for(int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        // ---------- BOTTOM → TOP (left column) ----------
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

int main()
{
    /*
      Example:
      matrix =
      {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
      }

      Output:
      1 2 3 6 9 8 7 4 5
    */

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);

    for(int x : result)
        cout << x << " ";

    cout << endl;

    /*
      ===================== IMPORTANT NOTES =====================

      1) Always check:
         - top <= bottom
         - left <= right
         before traversing

      2) Order of traversal is FIXED:
         top row →
         right column ↓
         bottom row ←
         left column ↑

      3) Time Complexity:
         O(m * n)  (each element visited once)

      4) Space Complexity:
         O(m * n) for output vector
         O(1) extra space (excluding output)

      5) Very common in:
         - LeetCode
         - GATE
         - Interviews
    */

    return 0;
}

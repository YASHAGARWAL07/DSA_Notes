#include<iostream>
#include<vector>
using namespace std;

/*
  ================= ROTATE MATRIX BY 180° (COUNTER-CLOCKWISE) =================
  (Same as 180° CLOCKWISE – direction does NOT matter for 180°)

  Problem:
  - Given an n x n matrix
  - Rotate it by 180 degrees
  - Must be done IN-PLACE (no extra matrix)

  ------------------------------------------------------------------
  KEY OBSERVATION:

  180° rotation = reverse order of rows + reverse elements in each row

  OR (another view):
  - Reverse each row
  - Then reverse the order of rows

  Both give same result.
*/

/*
  Example:
  --------
  Input:
  1 2 3
  4 5 6
  7 8 9

  Output (180° rotated):
  9 8 7
  6 5 4
  3 2 1
*/

void rotateMatrix(vector<vector<int>>& mat)
{
    int n = mat.size();

    // ---------- STEP 1: REVERSE EACH ROW ----------
    for(int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while(start < end)
        {
            swap(mat[i][start], mat[i][end]);
            start++;
            end--;
        }
    }

    // ---------- STEP 2: REVERSE THE ORDER OF ROWS ----------
    int top = 0, bottom = n - 1;
    while(top < bottom)
    {
        swap(mat[top], mat[bottom]);
        top++;
        bottom--;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(mat);

    // Print result
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    /*
      ===================== IMPORTANT NOTES =====================

      1) Works only for SQUARE matrix (n x n)

      2) No transpose required for 180° rotation

      3) Time Complexity:
         O(n^2)

      4) Space Complexity:
         O(1)  (in-place)

      5) 180° Clockwise == 180° Counter-Clockwise

      6) Common Interview / GFG / LeetCode pattern
    */

    return 0;
}

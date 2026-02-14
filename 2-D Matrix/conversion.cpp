#include<iostream>
#include<vector>
using namespace std;

/*
  ================= CONVERT 1D ARRAY INTO 2D ARRAY =================
  (LeetCode 2022 – Convert 1D Array Into 2D Array)

  Problem:
  - Given a 1D array "original"
  - Given integers m (rows) and n (columns)
  - Convert original into a 2D array of size m x n
  - Fill row-wise using elements from original

  CONDITION:
  - If (m * n) != original.size()
    → Conversion NOT possible
    → Return empty 2D array

  -------------------------------------------------------
  Mapping Logic:
  original[0 ... n-1]     → row 0
  original[n ... 2n-1]    → row 1
  original[2n ... 3n-1]   → row 2
  and so on...
*/

/*
  Example:
  --------
  original = [1, 2, 3, 4]
  m = 2, n = 2

  Result:
  1 2
  3 4
*/

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
{
    // ---------- CHECK POSSIBILITY ----------
    if(m * n != original.size())
        return {};   // empty matrix

    // ---------- CREATE 2D MATRIX ----------
    vector<vector<int>> mat(m, vector<int>(n));

    int idx = 0;  // pointer for 1D array

    // ---------- FILL MATRIX ROW-WISE ----------
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = original[idx];
            idx++;
        }
    }

    return mat;
}

int main()
{
    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;

    vector<vector<int>> ans = construct2DArray(original, m, n);

    // Print matrix
    if(ans.empty())
    {
        cout << "Conversion not possible" << endl;
        return 0;
    }

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    /*
      ===================== IMPORTANT NOTES =====================

      1) 반드시 check:
         m * n == original.size()

      2) Filling order:
         - Row-wise (left → right, top → bottom)

      3) Time Complexity:
         O(m * n)

      4) Space Complexity:
         O(m * n)

      5) Very common:
         - LeetCode Easy
         - Matrix basics
         - Interview warm-up

      6) Index mapping:
         mat[i][j] = original[i*n + j]
         (Alternate direct formula)
    */

    return 0;
}

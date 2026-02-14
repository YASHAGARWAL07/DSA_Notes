#include<iostream>
#include<vector>
using namespace std;

/*
  ================= RICHEST CUSTOMER WEALTH =================
  (LeetCode 1672 – Richest Customer Wealth)

  Problem:
  - Given a 2D matrix "accounts"
  - accounts[i][j] = money of ith customer in jth bank
  - Wealth of a customer = SUM of all elements in that row
  - Find the MAXIMUM wealth among all customers

  -----------------------------------------------------------
  Simple Logic:
  - Traverse each row
  - Calculate row sum
  - Track maximum row sum
*/

/*
  Example:
  --------
  accounts =
  [
    [1, 2, 3],
    [3, 2, 1]
  ]

  Customer 0 wealth = 1+2+3 = 6
  Customer 1 wealth = 3+2+1 = 6

  Answer = 6
*/

int maximumWealth(vector<vector<int>>& accounts)
{
    int m = accounts.size();        // number of customers (rows)
    int n = accounts[0].size();     // number of banks (columns)

    int maxi = 0;

    // ---------- ROW-WISE SUM ----------
    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += accounts[i][j];
        }
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main()
{
    vector<vector<int>> accounts = {
        {1, 5},
        {7, 3},
        {3, 5}
    };

    cout << maximumWealth(accounts) << endl;

    /*
      ===================== IMPORTANT NOTES =====================

      1) Wealth = row sum

      2) Traverse matrix row-wise

      3) Time Complexity:
         O(m * n)

      4) Space Complexity:
         O(1)

      5) Very EASY but IMPORTANT:
         - LeetCode Easy
         - Matrix basics
         - Interview warm-up

      6) Can also be solved using:
         - STL accumulate()
    */

    return 0;
}

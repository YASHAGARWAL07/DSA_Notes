#include<iostream>
#include<vector>
using namespace std;

/*
  ===================== PRIME IN DIAGONAL =====================
  (LeetCode 2614 – Prime In Diagonal)

  Problem:
  - Given an n x n matrix nums
  - Check both diagonals:
      1) Primary diagonal    → nums[i][i]
      2) Secondary diagonal  → nums[i][n-i-1]
  - Find the LARGEST PRIME number present on ANY diagonal
  - If no prime exists → return 0
*/

/*
  PRIME NUMBER RULES:
  -------------------
  - Prime > 1
  - Divisible only by 1 and itself
*/

/*
  Optimized Prime Check:
  ----------------------
  - Handle small cases separately
  - Skip even numbers
  - Check till sqrt(n)
*/

bool isPrime(int x)
{
    if(x <= 1) return false;
    if(x <= 3) return true;

    if(x % 2 == 0 || x % 3 == 0)
        return false;

    for(int i = 5; i * i <= x; i += 6)
    {
        if(x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int diagonalPrime(vector<vector<int>>& nums)
{
    int n = nums.size();
    int prime = 0;

    // ---------- PRIMARY DIAGONAL ----------
    for(int i = 0; i < n; i++)
    {
        if(isPrime(nums[i][i]))
            prime = max(prime, nums[i][i]);
    }

    // ---------- SECONDARY DIAGONAL ----------
    for(int i = 0; i < n; i++)
    {
        if(isPrime(nums[i][n - i - 1]))
            prime = max(prime, nums[i][n - i - 1]);
    }

    return prime;
}

int main()
{
    vector<vector<int>> nums = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11}
    };

    cout << diagonalPrime(nums) << endl;

    /*
      ===================== IMPORTANT NOTES =====================

      1) Diagonals indices:
         - Primary:   nums[i][i]
         - Secondary: nums[i][n-i-1]

      2) Always take MAX prime from both diagonals

      3) If no prime found → answer remains 0

      4) Time Complexity:
         - Diagonal traversal: O(n)
         - Prime check: O(sqrt(x))
         - Overall: O(n * sqrt(maxElement))

      5) Space Complexity:
         O(1)

      6) Very common for:
         - LeetCode Easy
         - Matrix + Math
         - Interview questions
    */

    return 0;
}

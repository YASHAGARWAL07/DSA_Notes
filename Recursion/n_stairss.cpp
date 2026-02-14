#include<iostream>
using namespace std;

/*
  ===================== CLIMB STAIRS PROBLEM =====================
  (LeetCode 70)

  Problem:
  - You can climb 1 or 2 steps at a time
  - Find number of distinct ways to reach the top (n steps)

  Observation:
  - Ways(n) = Ways(n-1) + Ways(n-2)
  - This is exactly the Fibonacci pattern

  ===============================================================
  APPROACH 1: RECURSION (GIVES TLE)
  ===============================================================
*/

class SolutionRecursion {
public:
    int climbStairs(int n) {

        // Base case
        // If 0 or 1 step → only 1 way
        if(n <= 1)
            return 1;

        // Recursive relation (Fibonacci)
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

/*
  Why TLE?
  - Same subproblems are solved again and again
  - Exponential time complexity

  Time Complexity: O(2^n)
  Space Complexity: O(n) (recursion stack)

  NOTE:
  - Recursion is correct logically
  - But inefficient without DP (memoization)
*/

/*
  ===============================================================
  APPROACH 2: ITERATIVE (FOR LOOP / DP OPTIMIZED)
  ===============================================================
*/

class Solution {
public:
    int climbStairs(int n) {

        // Base cases
        if(n <= 2)
            return n;

        // prev1 = ways to reach (i-2)
        // prev2 = ways to reach (i-1)
        int prev1 = 1;
        int prev2 = 2;

        // Build answer from 3 to n
        for(int i = 3; i <= n; i++)
        {
            int curr = prev1 + prev2;  // Fibonacci step
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

/*
  ===================== FINAL NOTES =====================

  - Climb Stairs = Fibonacci problem
  - Recursion without DP → TLE
  - Iterative DP avoids recomputation

  Comparison:
  -------------------------------------------------------
  Method        | Time      | Space
  -------------------------------------------------------
  Recursion     | O(2^n)    | O(n)
  Iterative DP  | O(n)      | O(1)
  -------------------------------------------------------

  Formula:
  ways(n) = ways(n-1) + ways(n-2)

  Base cases:
  n = 1 → 1
  n = 2 → 2
*/

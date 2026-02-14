#include<iostream>
using namespace std;

/*
  ===================== FIBONACCI NUMBER (RECURSION + ITERATIVE) =====================

  This file is RUNNABLE in VS Code.

  Problem:
  - Find nth Fibonacci number

  Fibonacci definition:
    fib(0) = 0
    fib(1) = 1
    fib(n) = fib(n-1) + fib(n-2)

  --------------------------------------------------
  NOTE:
  - Recursive solution is shown for understanding
  - Iterative solution is used for actual execution
*/

/* ===================== RECURSIVE SOLUTION (TLE) ===================== */
class SolutionRecursion {
public:
    int fib(int n) {
        // Base case
        if(n <= 1)
            return n;

        // Recursive relation
        return fib(n-1) + fib(n-2);
    }
};

/*
  Issues with recursion:
  - Recomputes same values again and again
  - Time Complexity: O(2^n)
  - Causes TLE for large n
*/

/* ===================== ITERATIVE SOLUTION (OPTIMIZED) ===================== */
class Solution {
public:
    int fib(int n) {

        // Base case
        if(n <= 1)
            return n;

        int prev1 = 0;   // fib(0)
        int prev2 = 1;   // fib(1)

        // Loop to compute fib(n)
        for(int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Using optimized solution
    Solution obj;
    cout << "Fibonacci(" << n << ") = " << obj.fib(n) << endl;

    /*
      Example:
      Input:  n = 7
      Output: Fibonacci(7) = 13
    */

    return 0;
}

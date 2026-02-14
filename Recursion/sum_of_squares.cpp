#include<iostream>
using namespace std;

/*
  ===================== SUM OF SQUARES USING RECURSION =====================

  Problem:
  - Find sum of squares of first n natural numbers
  - i.e. 1^2 + 2^2 + 3^2 + ... + n^2

  Mathematical Formula:
  sumSq(n) = 1^2 + 2^2 + ... + n^2

  Recursive Relation:
  sumSq(n) = n*n + sumSq(n-1)

  Recursion Requirements:
  1) Base Case      -> stops recursion
  2) Recursive Call -> reduces n
*/

int sumSq(int n)
{
    // ---------- Base Case ----------
    // Sum of squares of first 1 number = 1^2
    if(n == 1)
        return 1;

    // ---------- Recursive Case ----------
    // Add square of n and solve smaller problem
    return n*n + sumSq(n - 1);
}

int main()
{
    /*
      Task:
      - Print sum of squares of first n natural numbers
      - Example: n = 5
    */

    int n = 5;

    cout << sumSq(n) << endl;   // Output: 55

    /*
      Working (for n = 5):
      sumSq(5) = 5^2 + sumSq(4)
      sumSq(4) = 4^2 + sumSq(3)
      sumSq(3) = 3^2 + sumSq(2)
      sumSq(2) = 2^2 + sumSq(1)
      sumSq(1) = 1   (base case)

      Final Answer = 55
    */

    /*
      Notes:
      - Time Complexity: O(n)
      - Space Complexity: O(n) (recursive stack)
      - Missing base case → infinite recursion
      - n must decrease to reach base case
    */

    return 0;
}

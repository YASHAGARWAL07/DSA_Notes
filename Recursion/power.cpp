#include<iostream>
using namespace std;

/*
  ===================== POWER OF A NUMBER USING RECURSION =====================

  Problem:
  - Find power of a number using recursion
  - Compute n^p (n raised to power p)

  Mathematical Definition:
  n^p = n * n * n * ... (p times)

  Recursive Relation:
  power(n, p) = n * power(n, p-1)

  Recursion Requirements:
  1) Base Case      -> stops recursion
  2) Recursive Call -> reduces power
*/

int power(int n, int p)
{
    // ---------- Base Case ----------
    // Any number raised to power 0 is 1
    if(p == 0)
        return 1;

    // ---------- Recursive Case ----------
    // Multiply n with result of smaller power
    return n * power(n, p - 1);
}

int main()
{
    /*
      Task:
      - Find n raised to power p using recursion
      - Example: n = 2, p = 5
    */

    int n = 2;
    int p = 5;

    cout << power(n, p) << endl;   // Output: 32

    /*
      Working (for n = 2, p = 5):
      power(2,5) = 2 * power(2,4)
      power(2,4) = 2 * power(2,3)
      power(2,3) = 2 * power(2,2)
      power(2,2) = 2 * power(2,1)
      power(2,1) = 2 * power(2,0)
      power(2,0) = 1   (base case)

      Final Answer = 32
    */

    /*
      Notes:
      - Time Complexity: O(p)
      - Space Complexity: O(p) (recursive stack)
      - Base case is mandatory
      - p must decrease to reach base case
    */

    return 0;
}

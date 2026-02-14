#include<iostream>
using namespace std;

/*
  ===================== FACTORIAL USING RECURSION =====================

  Factorial:
  n! = n * (n-1) * (n-2) * ... * 1

  Recursion requirements:
  1) Base Case      -> stops recursion
  2) Recursive Call -> reduces problem size

  Formula used:
  fact(n) = n * fact(n-1)
*/

int fact(int n)
{
    // ---------- Base Case ----------
    // Factorial of 1 is 1
    if(n == 1)
        return 1;

    // ---------- Recursive Case ----------
    // Multiply current n with factorial of (n-1)
    return n * fact(n - 1);
}

int main()
{
    /*
      Task:
      - Find factorial of a number using recursion
      - Example: n = 10
    */

    int n = 5;
    if(n<0) {
    cout<< "Enter positive values only!";
    return 0;
    }
    cout << fact(n);

    /*
      Working (for n = 5):
      fact(5) = 5 * fact(4)
      fact(4) = 4 * fact(3)
      fact(3) = 3 * fact(2)
      fact(2) = 2 * fact(1)
      fact(1) = 1  (base case)

      Final result = 120
    */

    /*
      Notes:
      - Each recursive call uses stack memory
      - Missing base case → infinite recursion
      - Time Complexity: O(n)
      - Space Complexity: O(n) (recursive stack)
    */

    return 0;
}

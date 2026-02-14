#include<iostream>
using namespace std;

/*
  ===================== SUM OF FIRST N NATURAL NUMBERS =====================
  Topic: Recursion

  Problem:
  - Find sum of first n natural numbers using recursion

  Mathematical Formula:
  sum(n) = n + (n-1) + (n-2) + ... + 1

  Recursive Relation:
  sum(n) = n + sum(n-1)

  Requirements of Recursion:
  1) Base Case      -> stops recursion
  2) Recursive Call -> reduces problem size
*/

int sum(int n)
{
    // ---------- Base Case ----------
    // Sum of first 1 natural number is 1
    if(n == 1)
        return 1;

    // ---------- Recursive Case ----------
    // Add current n and solve smaller problem
    return n + sum(n - 1);
}

int main()
{
    /*
      Task:
      - Print sum of first n natural numbers
      - Example: n = 6
    */

    int n = 6;

    cout << sum(n) << endl;   // Output: 21

    /*
      Working (for n = 6):
      sum(6) = 6 + sum(5)
      sum(5) = 5 + sum(4)
      sum(4) = 4 + sum(3)
      sum(3) = 3 + sum(2)
      sum(2) = 2 + sum(1)
      sum(1) = 1   (base case)

      Final Answer = 21
    */

    /*
      Notes:
      - Each recursive call uses stack memory
      - Time Complexity: O(n)
      - Space Complexity: O(n) (recursion stack)
      - Missing base case → infinite recursion
    */

    return 0;
}

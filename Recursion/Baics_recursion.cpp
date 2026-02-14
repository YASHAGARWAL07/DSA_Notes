#include<iostream>
using namespace std;

/*
  ===================== RECURSION NOTES =====================

  Topic: Printing even numbers from n to 2 using recursion

  Key concepts:
  - Recursion = function calling itself
  - Two mandatory parts:
      1) Base Case      -> stops recursion
      2) Recursive Call -> reduces problem size
  - Each call uses stack memory
  - Order of work decides output order
*/

void print(int n)
{
    // ---------- Base Case ----------
    // When n becomes 2, stop recursion
    if(n == 2)
    {
        cout << 2 << endl;
        return;
    }

    // ---------- Work ----------
    // Print current even number
    cout << n << endl;

    // ---------- Recursive Call ----------
    // Move towards base case
    print(n - 2);
}

int main()
{
    /*
      Task:
      - Print even numbers from n to 2
      - Example: n = 10
        Output: 10 8 6 4 2
    */

    int n = 10;

    print(n);

    /*
      Notes:
      - Base case prevents infinite recursion
      - n-2 ensures progress toward base case
      - Printing before recursive call → descending order
      - If print was after call → ascending order
    */

    return 0;
}

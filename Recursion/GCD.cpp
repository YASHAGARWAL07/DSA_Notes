#include<iostream>
using namespace std;

/*
  ===================== GCD USING RECURSION (EUCLIDEAN ALGORITHM) =====================

  Problem:
  - Find GCD (Greatest Common Divisor) of two numbers a and b

  Given Recursive Relation:
  gcd(a, b) = gcd(b, a % b)

  ---------------------------------------------------------------
  IMPORTANT NOTE ABOUT BASE CASE
  ---------------------------------------------------------------
  Your base case:
      if(a % b == 0) return b;

  This works ONLY when:
  - b != 0
  - a % b eventually becomes 0

  BUT the SAFEST and STANDARD base case is:
      if(b == 0) return a;

  Because:
  - Division/modulo by 0 is invalid
  - Euclidean algorithm guarantees b will become 0
*/

/* ===================== CORRECT & SAFE IMPLEMENTATION ===================== */
class Solution {
public:
    int gcd(int a, int b) {

        // ---------- Base Case ----------
        // When b becomes 0, a is the GCD
        if(b == 0)
            return a;

        // ---------- Recursive Call ----------
        return gcd(b, a % b);
    }
};

int main()
{
    int a, b;
    cin >> a >> b;

    Solution obj;
    cout << obj.gcd(a, b) << endl;

    /*
      Example:
      Input : 48 18
      Output: 6
    */

    /*
      Trace:
      gcd(48,18)
      → gcd(18,12)
      → gcd(12,6)
      → gcd(6,0)
      → return 6
    */

    /*
      KEY NOTES (EXAM / VIVA):

      - a % b is always smaller than b
      - b keeps decreasing in each call
      - Eventually b becomes 0
      - Recursion always terminates

      Time Complexity : O(log(min(a,b)))
      Space Complexity: O(log(min(a,b)))  // recursion stack
    */

    return 0;
}

/*
  WHY NOT USE ONLY:
      if(a % b == 0) return b;

  Problems:
  - Unsafe if b == 0
  - Less general
  - Not standard in textbooks / GATE

  ALWAYS prefer:
      if(b == 0) return a;
*/

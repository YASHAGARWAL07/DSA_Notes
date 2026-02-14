#include<iostream>
using namespace std;

int main(){

    int n = 10;

    // Single pointer: stores address of n
    int *p = &n;

    // Double pointer: stores address of pointer p
    int **p2 = &p;

    // Triple pointer: stores address of pointer p2
    int ***p3 = &p2;

    // ---------------- Printing addresses ----------------
    cout << p << endl;     // address of n
    cout << &p << endl;    // address of pointer p

    cout << p2 << endl;    // address of p
    cout << &p2 << endl;   // address of pointer p2

    cout << p3 << endl;    // address of p2

    // ---------------- Dereferencing ----------------
    cout << *p << endl;      // value of n
    cout << **p2 << endl;    // value of n
    cout << ***p3 << endl;   // value of n

    // ---------------- Modify value ----------------
    *p = *p + 5;   // modify n using single pointer
    cout << n << endl;   // n becomes 15

    /*
      Summary:
      n    -> actual value
      p    -> &n
      p2   -> &p
      p3   -> &p2

      *p        = n
      *p2       = p
      **p2      = n
      *p3       = p2
      **p3      = p
      ***p3     = n
    */

    return 0;
}

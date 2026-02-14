#include<iostream>
using namespace std;

int main(){

    int x = 10;

    // Single pointer: stores address of x
    int *p = &x;

    // Double pointer: stores address of pointer p
    int **pp = &p;

    // x -> value
    cout << x << endl;

    // p -> address of x
    cout << p << endl;

    // *p -> value of x
    cout << *p << endl;

    // pp -> address of pointer p
    cout << pp << endl;

    // *pp -> value stored in p (address of x)
    cout << *pp << endl;

    // **pp -> value of x
    cout << **pp << endl;

    /*
      Memory relation:
      x   -> value
      p   -> &x
      pp  -> &p

      *p   = x
      *pp  = p
      **pp = x
    */

    // Changing value using double pointer
    **pp = 50;
    cout << x << endl;   // x becomes 50

    /*
      Important points:
      int *p   -> pointer
      int **pp -> pointer to pointer

      &p  gives address of p
      *pp gives value of p
      **pp gives value of variable pointed by p

      Used in:
      - Dynamic memory
      - Functions (pass pointer by reference)
      - 2D arrays
    */

    return 0;
}

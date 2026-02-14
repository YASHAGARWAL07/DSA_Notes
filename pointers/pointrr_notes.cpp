#include<iostream>
using namespace std;

/*
  ===================== POINTER NOTES (ALL-IN-ONE) =====================

  Covers:
  - int pointer
  - double & triple pointer
  - pointer in functions
  - char array & char pointer
  - reference vs pointer
  - GATE / output-based logic

  Design minimal, notes focused.
*/

void second(int *p1, int *p2)
{
    // Pointer reassignment is local
    p1 = p2;
    *p1 = 2;   // modifies value pointed by p2
}

int four(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1;   // modifies original variable
    z = **ppz;
    *py += 2;     // modifies original variable
    y = *py;
    x += 3;       // local change
    return x + y + z;
}

void five(char *str1, char *str2)
{
    // Compare characters
    while(*str1 == *str2)
    {
        str1++;
        str2++;
    }
}

int main(){

    // ===================== BASIC POINTER =====================
    int x = 0;
    int *ptr = &x;
    int y = *ptr;
    *ptr = 1;
    cout << x << " " << y << endl;   // 1 0

    // ===================== DOUBLE POINTER =====================
    int n = 10;
    int *p = &n;
    int **q = &p;
    cout << *p << " " << **q << endl; // 10 10

    // ===================== TRIPLE POINTER =====================
    int ***r = &q;
    ***r = 20;
    cout << n << endl;   // 20

    // ===================== POINTER IN FUNCTION =====================
    int i = 0, j = 1;
    second(&i, &j);
    cout << i << " " << j << endl;   // 0 2

    // ===================== REFERENCE vs POINTER =====================
    int a = 5, b = 10;
    int &name = a;
    int *pt = &a;
    (*pt)++;        // a = 6
    pt = &b;
    *pt += 5;       // b = 15
    name += 5;      // a = 11
    cout << a << " " << b << endl;   // 11 15

    // ===================== CHAR ARRAY & POINTER =====================
    char c[] = "GATE2024";
    char *cp = c;
    cout << cp + cp[3] - cp[1] << endl; // 2024

    // ===================== CHAR POINTER COMPARISON =====================
    char first[] = "Mohit";
    char secondStr[] = "Rohan";
    five(first, secondStr);
    cout << first << endl;   // Mohit

    // ===================== DOUBLE POINTER FUNCTION =====================
    int cval = 4;
    int *bptr = &cval;
    int **aptr = &bptr;
    cout << four(cval, bptr, aptr) << endl;  // 19

    /*
      ===================== QUICK REVISION =====================

      p        -> address
      *p       -> value
      **pp     -> original data
      arr[i]   == *(arr+i)
      char*    prints string till '\0'
      ptr++    allowed, arr++ not allowed
      pointer reassignment inside function is local
      reference is alias (fixed)
    */

    return 0;
}

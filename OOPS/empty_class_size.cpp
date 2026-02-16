/************************************************************
        WHY EMPTY CLASS SIZE IS 1 BYTE (C++)
************************************************************/

/*
============================================================
1. QUESTION
------------------------------------------------------------
Why does an empty class have size 1 byte in C++?
============================================================
*/

/*
============================================================
2. KEY RULE
------------------------------------------------------------
- Every object must have a unique memory address.
- Size of an object can never be 0.
============================================================
*/

/*
============================================================
3. EXPLANATION
------------------------------------------------------------
If an empty class had size = 0:

class A {};
A a1, a2;

Both objects would point to the same memory location.

This would break:
- Object identity
- this pointer behavior
- Address-based operations

To prevent this, the compiler assigns
minimum possible size = 1 byte.

This 1 byte is not for data,
it is for object identity.
============================================================
*/

/*
============================================================
4. IMPORTANT POINTS
------------------------------------------------------------
1) Empty class has no data members.
2) Size is for maintaining unique identity.
3) 1 byte is the smallest allocatable memory unit.
4) Ensures different objects have different addresses.
============================================================
*/

/*
============================================================
5. EXAMPLE
============================================================
*/

#include <iostream>
using namespace std;

class Empty {};

int main() {

    Empty e1, e2;

    cout << sizeof(Empty) << endl;   // Output: 1
    cout << &e1 << endl;            // Different address
    cout << &e2 << endl;            // Different address

    return 0;
}

/*
============================================================
6. EMPTY STRUCT
------------------------------------------------------------
struct A {};
sizeof(A) = 1 byte

Same rule applies to struct.
============================================================
*/

/*
============================================================
7. EMPTY BASE CLASS OPTIMIZATION (EBO)
------------------------------------------------------------

class A {};        // size = 1

class B : public A {
    int x;
};

Normally:
Size = 1 + sizeof(int)

But compiler applies optimization.

Result:
sizeof(B) = sizeof(int)

Empty base class does not increase size.

This is called:
Empty Base Class Optimization (EBO)
============================================================
*/

/*
============================================================
8. INTERVIEW ONE-LINER
------------------------------------------------------------
"An empty class has size 1 byte to ensure every object
has a unique memory address."
============================================================
*/

/*
============================================================
9. EXAM REMEMBER
------------------------------------------------------------
- Empty class size = 1 byte
- Objects must have unique addresses
- Zero-size objects are not allowed in C++
============================================================
*/

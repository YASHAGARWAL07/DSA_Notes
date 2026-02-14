/*========================================================
        WHY EMPTY CLASS SIZE IS 1 BYTE (C++)
==========================================================

Q) Why does an empty class have size 1 byte in C++?

----------------------------------------------------------
KEY RULE:
----------------------------------------------------------
→ In C++, every object MUST have a unique memory address.
→ Size of an object can NEVER be 0.

----------------------------------------------------------
EXPLANATION:
----------------------------------------------------------
If an empty class had size = 0 bytes:

    class A {};
    A a1, a2;

Both objects would point to the SAME memory address,
which breaks:
• Object identity
• this pointer
• Address-based operations

So compiler assigns the MINIMUM POSSIBLE SIZE = 1 BYTE.

----------------------------------------------------------
IMPORTANT POINTS:
----------------------------------------------------------
1) Empty class has NO data members
2) Size is NOT for data, it is for IDENTITY
3) 1 byte is the minimum allocatable memory
4) Ensures different objects have different addresses

----------------------------------------------------------
EXAMPLE:
----------------------------------------------------------
#include <iostream>
using namespace std;

class Empty {};

int main() {
    Empty e1, e2;
    cout << sizeof(Empty) << endl; // Output: 1
}

----------------------------------------------------------
OUTPUT:
----------------------------------------------------------
1

----------------------------------------------------------
EMPTY STRUCT:
----------------------------------------------------------
struct A {};
sizeof(A) → 1 byte (same rule applies)

----------------------------------------------------------
EMPTY BASE CLASS OPTIMIZATION (EBO):
----------------------------------------------------------
class A {};        // size = 1
class B : A {      // A takes NO extra space
    int x;
};

sizeof(B) → size of int (not 1 + int)

→ Compiler optimizes empty base classes.

----------------------------------------------------------
INTERVIEW ONE-LINER:
----------------------------------------------------------
"An empty class has size 1 byte to ensure every object
has a unique memory address."

----------------------------------------------------------
EXAM REMEMBER:
----------------------------------------------------------
• Empty class  → 1 byte
• Empty object → unique address
• Zero size objects are NOT allowed

==========================================================
*/ 

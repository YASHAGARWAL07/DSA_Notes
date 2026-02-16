/************************************************************
        FUNCTION OVERLOADING (Compile-Time Polymorphism)
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. FUNCTION OVERLOADING
------------------------------------------------------------
Definition:
Function overloading means having multiple functions
with the same name but different parameter lists
in the same class.

Key Points:
- Same function name
- Different number or type of parameters
- Resolved at compile time
- Example of Compile-Time Polymorphism
============================================================
*/

class Calculator {

public:

    // Function with 2 parameters
    int add(int a, int b) {
        return a + b;
    }

    // Function with 3 parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

/*
============================================================
2. MAIN FUNCTION
============================================================
*/

int main() {

    Calculator c;

    cout << c.add(2, 3) << endl;     // Calls first function
    cout << c.add(2, 3, 4) << endl;  // Calls second function

    return 0;
}

/*
============================================================
3. OUTPUT
------------------------------------------------------------
5
9
============================================================
*/

/*
============================================================
4. IMPORTANT RULES
------------------------------------------------------------
- Function signature must be different.
- Return type alone cannot differentiate functions.
- Overloading is resolved at compile time.
============================================================
*/

/*
============================================================
5. VIVA QUESTIONS
------------------------------------------------------------
Q1: What is function overloading?
Ans: Same function name with different parameters.

Q2: Is this runtime polymorphism?
Ans: No, it is compile-time polymorphism.

Q3: Can we overload only by changing return type?
Ans: No.
============================================================
*/

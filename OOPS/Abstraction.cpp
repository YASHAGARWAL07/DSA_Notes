/************************************************************
        ABSTRACTION IN C++ (OOPS)
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. INTRODUCTION TO ABSTRACTION
------------------------------------------------------------
Abstraction means hiding implementation details
and showing only essential features.

In simple words:
User knows WHAT the system does,
but does not know HOW it works internally.

Example:
ATM Machine
- Insert card
- Enter PIN
- Withdraw money

Internal processes like:
- Database queries
- Encryption
- Server logic
are hidden.
============================================================
*/

/*
============================================================
2. WHY ABSTRACTION IS REQUIRED
------------------------------------------------------------
- Reduces code complexity
- Improves security
- Makes code clean and modular
- Focuses on essential behavior
- Prevents misuse of internal logic
============================================================
*/

/*
============================================================
3. HOW TO ACHIEVE ABSTRACTION IN C++
------------------------------------------------------------
In C++, abstraction is achieved using:

1) Abstract Class
2) Pure Virtual Function
3) Interface concept (via abstract class)
============================================================
*/

/*
============================================================
4. PURE VIRTUAL FUNCTION
------------------------------------------------------------
Syntax:
virtual return_type function_name() = 0;

If a class contains at least one pure virtual function,
it becomes an ABSTRACT CLASS.

Properties of Abstract Class:
- Cannot create object
- Used as blueprint for derived classes
- Must be inherited
============================================================
*/

class Shape {

public:
    virtual void draw() = 0;   // Pure virtual function
};

/*
============================================================
5. DERIVED CLASS IMPLEMENTATION
------------------------------------------------------------
Derived class must override pure virtual function.
============================================================
*/

class Circle : public Shape {

public:
    void draw() {
        cout << "Drawing Circle..." << endl;
    }
};

class Rectangle : public Shape {

public:
    void draw() {
        cout << "Drawing Rectangle..." << endl;
    }
};

/*
============================================================
6. MAIN FUNCTION – USING ABSTRACTION
============================================================
*/

int main() {

    // Shape s;  // Error: Cannot create object of abstract class

    Shape* s1;
    Circle c1;
    Rectangle r1;

    s1 = &c1;
    s1->draw();

    s1 = &r1;
    s1->draw();

    return 0;
}

/*
============================================================
7. IMPORTANT RULES
------------------------------------------------------------
- A class with at least one pure virtual function
  becomes abstract.
- Abstract class cannot have objects.
- Derived class must override pure virtual function.
- Abstract class defines interface.
- Abstraction hides implementation details.
============================================================
*/

/*
============================================================
8. DIFFERENCE: ABSTRACTION VS ENCAPSULATION
------------------------------------------------------------

Encapsulation:
    - Hides data
    - Achieved using private members
    - Focus on data protection

Abstraction:
    - Hides implementation details
    - Achieved using abstract class
    - Focus on behavior
============================================================
*/

/*
============================================================
9. COMMON INTERVIEW QUESTIONS
------------------------------------------------------------
Q1. Can abstract class have constructor?
Answer: Yes.

Q2. Can abstract class have normal functions?
Answer: Yes.

Q3. Can we create pointer of abstract class?
Answer: Yes.

Q4. Why abstraction is important?
Answer: To reduce complexity and improve security.
============================================================
*/

/*
============================================================
10. REAL-LIFE EXAMPLE
------------------------------------------------------------
Car:
User uses:
- Start
- Accelerate
- Brake

Internal engine mechanism remains hidden.

That hiding of internal working is abstraction.
============================================================
*/

/************************************************************
 *              ABSTRACTION IN C++ (OOPS)
 *
 *  Abstraction is one of the 4 pillars of OOPS:
 *  1. Encapsulation
 *  2. Abstraction
 *  3. Inheritance
 *  4. Polymorphism
 *
 *  This file contains:
 *  ✔ Concept
 *  ✔ Real-life examples
 *  ✔ Abstract class
 *  ✔ Pure virtual function
 *  ✔ Interface concept
 *  ✔ Interview points
 ************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1️⃣ WHAT IS ABSTRACTION?
============================================================

Abstraction means:
➡ Hiding implementation details
➡ Showing only essential features

In simple words:
User ko sirf "WHAT" pata hota hai,
lekin "HOW" internally kaam karta hai, woh hidden rehta hai.

Example:
ATM Machine
We know:
✔ Insert card
✔ Enter PIN
✔ Withdraw money

But we DON'T know:
- Database queries
- Encryption
- Bank server logic

That hidden internal working = Abstraction
*/

/*
============================================================
2️⃣ WHY DO WE NEED ABSTRACTION?
============================================================

✔ Reduces code complexity
✔ Improves security
✔ Makes code clean
✔ Focus on important features
✔ Prevents misuse of internal logic
*/

/*
============================================================
3️⃣ HOW TO ACHIEVE ABSTRACTION IN C++?
============================================================

In C++, abstraction is achieved using:

1. Abstract Class
2. Pure Virtual Function
3. Interfaces (using abstract class)
*/

/*
============================================================
4️⃣ PURE VIRTUAL FUNCTION
============================================================

Syntax:
virtual return_type function_name() = 0;

If a class has at least one pure virtual function,
it becomes an ABSTRACT CLASS.

Abstract class:
- Cannot create object
- Used as blueprint for derived classes
*/

class Shape {

public:
    // Pure Virtual Function
    virtual void draw() = 0;

    /*
    This makes Shape an ABSTRACT CLASS
    Now we cannot create object of Shape
    */
};

/*
============================================================
5️⃣ DERIVED CLASS IMPLEMENTATION
============================================================

Derived class MUST override pure virtual function
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
6️⃣ MAIN FUNCTION – USING ABSTRACTION
============================================================
*/

int main() {

    // Shape s; ❌ ERROR (Cannot create object of abstract class)

    Shape *s1;
    Circle c1;
    Rectangle r1;

    s1 = &c1;
    s1->draw();   // Calls Circle draw()

    s1 = &r1;
    s1->draw();   // Calls Rectangle draw()

    return 0;
}

/*
============================================================
7️⃣ IMPORTANT RULES (EXAM / VIVA)
============================================================

✔ If class has at least one pure virtual function,
  it becomes ABSTRACT CLASS.

✔ Abstract class cannot have object.

✔ Derived class must override pure virtual function.

✔ Used to define interface.

✔ Abstraction hides internal implementation.

============================================================
8️⃣ DIFFERENCE BETWEEN ABSTRACTION & ENCAPSULATION
============================================================

Encapsulation:
    - Hides data
    - Uses private members

Abstraction:
    - Hides implementation details
    - Uses abstract class / pure virtual functions

============================================================
9️⃣ INTERVIEW QUESTIONS
============================================================

Q1. Can abstract class have constructor?
→ YES

Q2. Can abstract class have normal functions?
→ YES

Q3. Can we create pointer of abstract class?
→ YES

Q4. Why abstraction is important?
→ To reduce complexity & improve security

============================================================
🔟 REAL-LIFE EXAMPLE (SHORT)
============================================================

Car:
You use:
✔ Start
✔ Accelerate
✔ Brake

But internal engine mechanism is hidden.

That hiding = Abstraction

============================================================
END OF NOTES ✔
============================================================
*/

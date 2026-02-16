/************************************************************
                POLYMORPHISM IN C++
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. INTRODUCTION TO POLYMORPHISM
------------------------------------------------------------
Poly  = Many
Morph = Forms

Definition:
Polymorphism means one function or name behaving
in multiple forms.

Types:
1) Compile-Time Polymorphism (Static Binding)
2) Run-Time Polymorphism (Dynamic Binding)
============================================================
*/

/*
============================================================
2. COMPILE-TIME POLYMORPHISM
------------------------------------------------------------
Definition:
Function call is resolved at compile time.

Achieved using:
- Function Overloading
- Operator Overloading
============================================================
*/

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

/*
Key Points:
- Same function name
- Different parameters
- Decided at compile time
*/

/*
============================================================
3. RUN-TIME POLYMORPHISM
------------------------------------------------------------
Definition:
Function call is resolved at runtime.

Achieved using:
- Function Overriding
- Virtual Functions

Requirements:
- Inheritance
- Base class pointer or reference
============================================================
*/

/*
============================================================
4. VIRTUAL FUNCTION
------------------------------------------------------------
Definition:
A function declared with the keyword 'virtual'
in the base class to enable runtime polymorphism.

Syntax:
virtual return_type functionName();

Purpose:
Without virtual -> Base class function is called.
With virtual    -> Derived class function is called.
============================================================
*/

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Bark" << endl;
    }
};

/*
Example:

Animal* ptr;
Dog d;
ptr = &d;
ptr->speak();

Output:
Bark

Reason:
Dynamic binding through virtual function.
*/

/*
============================================================
5. PURE VIRTUAL FUNCTION
------------------------------------------------------------
Definition:
A virtual function with no implementation in
the base class.

Declared using:
virtual return_type functionName() = 0;

If a class contains at least one pure virtual
function, it becomes an ABSTRACT CLASS.

Abstract Class:
- Cannot create objects
- Must be inherited
- Derived class must override pure virtual function
============================================================
*/

class Shape {
public:
    virtual void area() = 0;
};

class Circle : public Shape {
public:
    void area() {
        cout << "Area of Circle" << endl;
    }
};

/*
============================================================
6. DIFFERENCE: VIRTUAL vs PURE VIRTUAL
------------------------------------------------------------

Virtual Function:
- Has implementation in base class
- Object creation allowed
- Overriding optional

Pure Virtual Function:
- No implementation in base class
- Class becomes abstract
- Overriding mandatory
============================================================
*/

/*
============================================================
7. IMPORTANT CONCEPTS
------------------------------------------------------------
- Base class pointer required for runtime polymorphism.
- Function must be virtual in base class.
- override keyword recommended in derived class.
- Virtual functions use dynamic binding.
- Internally implemented using VTABLE.
============================================================
*/

/*
============================================================
8. BINDING
------------------------------------------------------------
Binding = Linking function call with function body.

Static Binding  -> Compile time
Dynamic Binding -> Runtime (using virtual)
============================================================
*/

/*
============================================================
9. COMMON VIVA QUESTIONS
------------------------------------------------------------
Q1: What is polymorphism?
Ans: Ability of a function to behave in multiple forms.

Q2: Types of polymorphism?
Ans: Compile-time and Run-time.

Q3: What is virtual function?
Ans: Function declared with 'virtual' in base class
to enable runtime polymorphism.

Q4: What is pure virtual function?
Ans: Virtual function declared with = 0.

Q5: What is abstract class?
Ans: Class containing at least one pure virtual function.
============================================================
*/

/*
============================================================
10. MAIN FUNCTION DEMO
============================================================
*/

int main() {

    Animal* ptr;
    Dog d;

    ptr = &d;
    ptr->speak();

    Circle c;
    Shape* s = &c;
    s->area();

    return 0;
}

/************************************************************
                    END OF NOTES
************************************************************/

/************************************************************
                POLYMORPHISM IN C++
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. POLYMORPHISM
============================================================

Poly  = Many
Morph = Forms

Definition:
Polymorphism means one function or name behaving in
multiple forms.

Types:
1) Compile-Time Polymorphism (Static Binding)
2) Run-Time Polymorphism (Dynamic Binding)

============================================================
2. COMPILE-TIME POLYMORPHISM
============================================================

Definition:
Function call is resolved at compile time.

Achieved by:
- Function Overloading
- Operator Overloading

------------------------------------------------------------
Example: Function Overloading
------------------------------------------------------------
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
============================================================

Definition:
Function call is resolved at runtime.

Achieved by:
- Function Overriding
- Virtual Functions

Important:
Requires inheritance + base class pointer/reference.

============================================================
4. VIRTUAL FUNCTION
============================================================

Definition:
A function declared using 'virtual' keyword in base class
to enable runtime polymorphism.

Syntax:
virtual return_type functionName();

Why Needed?
Without virtual -> base class version is called.
With virtual    -> derived class version is called.

------------------------------------------------------------
Example: Virtual Function
------------------------------------------------------------
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
If we write:

Animal* ptr;
Dog d;
ptr = &d;
ptr->speak();

Output:
Bark

Reason:
Dynamic binding using virtual function.
*/


/*
============================================================
5. PURE VIRTUAL FUNCTION
============================================================

Definition:
A virtual function with no body in base class.
Declared using = 0.

Syntax:
virtual void functionName() = 0;

If a class contains at least one pure virtual function,
it becomes an ABSTRACT CLASS.

Abstract Class:
- Cannot create objects
- Must be inherited
- Derived class must override pure virtual function

------------------------------------------------------------
Example: Pure Virtual Function
------------------------------------------------------------
*/

class Shape {
public:
    virtual void area() = 0;   // Pure virtual function
};

class Circle : public Shape {
public:
    void area() {
        cout << "Area of Circle" << endl;
    }
};


/*
============================================================
6. VIRTUAL vs PURE VIRTUAL
============================================================

Virtual Function:
- Has body in base class
- Object can be created
- Optional to override

Pure Virtual Function:
- No body in base class
- Class becomes abstract
- Must override in derived class

============================================================
7. IMPORTANT CONCEPTS
============================================================

1) Base class pointer is required for runtime polymorphism.
2) Function must be virtual in base class.
3) override keyword is recommended in derived class.
4) Virtual functions use dynamic binding.
5) Internally uses VTABLE (Virtual Table).

============================================================
8. DYNAMIC BINDING
============================================================

Binding means linking function call with function body.

Static Binding  -> Compile time
Dynamic Binding -> Runtime (using virtual)

============================================================
9. COMMON VIVA QUESTIONS
============================================================

Q1: What is polymorphism?
Ans: Ability of a function to behave in multiple forms.

Q2: Types of polymorphism?
Ans: Compile-time and Run-time.

Q3: What is virtual function?
Ans: Function declared with 'virtual' in base class to
enable runtime polymorphism.

Q4: What is pure virtual function?
Ans: Virtual function with = 0 and no body.

Q5: What is abstract class?
Ans: Class containing at least one pure virtual function.

============================================================
10. MAIN FUNCTION DEMO
============================================================
*/

int main() {

    Animal* ptr;
    Dog d;

    ptr = &d;
    ptr->speak();   // Runtime polymorphism

    Circle c;
    Shape* s = &c;
    s->area();      // Pure virtual example

    return 0;
}

/************************************************************
                    END OF NOTES
************************************************************/

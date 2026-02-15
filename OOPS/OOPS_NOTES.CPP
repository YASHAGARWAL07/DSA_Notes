/**************************************************************
        OBJECT ORIENTED PROGRAMMING (OOPS) - C++
        MASTER COMPLETE NOTES (Written in My Own Style)

        ✔ Based on Class Notes
        ✔ College Exam Ready
        ✔ Interview Ready
        ✔ Concept Building
**************************************************************/

#include <iostream>
using namespace std;

/*
==============================================================
1️⃣ PROGRAMMING PARADIGM
==============================================================

Programming Paradigm = Style / approach of programming

Main Types:
1) Procedural Programming
2) Object Oriented Programming (OOP)

--------------------------------------------------------------
PROCEDURAL PROGRAMMING
--------------------------------------------------------------
• Focus on functions
• Top-down approach
• Data shared among functions
• No data hiding
• Less secure
• Difficult to manage large programs

Example: C

--------------------------------------------------------------
OBJECT ORIENTED PROGRAMMING (OOP)
--------------------------------------------------------------
• Focus on objects
• Bottom-up approach
• Data + Functions wrapped together
• Supports data hiding
• High security
• Easy maintenance
• Real world modelling

Examples: C++, Java, Python, C#
*/

/*
==============================================================
2️⃣ ADVANTAGES OF OOPS
==============================================================

✔ Code Reusability
✔ Data Security
✔ Easy Debugging
✔ Better Maintainability
✔ Real World Representation
✔ Scalable for Large Projects

--------------------------------------------------------------
DISADVANTAGES
--------------------------------------------------------------
✘ Complex for beginners
✘ Higher memory usage
✘ Slightly slower sometimes
*/

/*
==============================================================
3️⃣ HISTORY (SHORT)
==============================================================

1960s → Simula (First OOP concept)
1980s → C++ (Bjarne Stroustrup)
1990s → Java
2000s → C#
*/

/*
==============================================================
4️⃣ CLASS
==============================================================

Class = Blueprint / Template

• User-defined data type
• No memory allocated until object is created

Contains:
1) Data Members
2) Member Functions
*/

class Student {
public:
    int roll;
    string name;

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
    }
};

/*
==============================================================
5️⃣ OBJECT
==============================================================

Object = Instance of a class

• Memory allocated when object is created
• Object has:
    1) Identity
    2) State
    3) Behavior
*/

/*
==============================================================
6️⃣ ACCESS SPECIFIERS
==============================================================

public:
    Accessible everywhere

private:
    Accessible only inside class
    Default access specifier

protected:
    Accessible inside class + derived class
*/

/*
==============================================================
7️⃣ FOUR PILLARS OF OOPS
==============================================================

1) Encapsulation
2) Abstraction
3) Inheritance
4) Polymorphism
*/

/*
--------------------------------------------------------------
1️⃣ ENCAPSULATION
--------------------------------------------------------------

Wrapping data + functions into a single unit (class)

Achieved by:
• Private data members
• Public getter/setter

Ensures:
✔ Data security
✔ Controlled access
*/

class BankAccount {
private:
    int balance;

public:
    void setBalance(int amt) {
        balance = amt;
    }

    int getBalance() {
        return balance;
    }
};

/*
--------------------------------------------------------------
2️⃣ ABSTRACTION
--------------------------------------------------------------

Hiding implementation details
Showing only essential features

Example:
ATM → You know withdraw(), not internal logic

Achieved using:
• Abstract class
• Pure virtual function
*/

class Shape {
public:
    virtual void draw() = 0;   // Pure Virtual Function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

/*
--------------------------------------------------------------
3️⃣ INHERITANCE
--------------------------------------------------------------

One class acquires properties of another class

Syntax:
class Child : accessSpecifier Parent
*/

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

/*
Types of Inheritance:
1) Single
2) Multiple
3) Multilevel
4) Hierarchical
5) Hybrid
*/

/*
--------------------------------------------------------------
4️⃣ POLYMORPHISM
--------------------------------------------------------------

One name → Multiple forms

Types:
1) Compile-time (Overloading)
2) Run-time (Overriding)
*/

/* Function Overloading */
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

/* Runtime Polymorphism */
class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show()" << endl;
    }
};

/*
==============================================================
8️⃣ CONSTRUCTOR
==============================================================

• Special member function
• Same name as class
• No return type
• Automatically called

Types:
1) Default
2) Parameterized
3) Copy
*/

class Demo {
public:
    Demo() {
        cout << "Constructor Called" << endl;
    }
};

/*
==============================================================
9️⃣ DESTRUCTOR
==============================================================

• Called automatically when object destroyed
• Used to free resources
• Name starts with ~
• No return type
*/

class Sample {
public:
    ~Sample() {
        cout << "Destructor Called" << endl;
    }
};

/*
==============================================================
🔟 THIS POINTER
==============================================================

• Holds address of current object
• Used to resolve name conflict
*/

class Box {
    int length;
public:
    void setLength(int length) {
        this->length = length;
    }
};

/*
==============================================================
1️⃣1️⃣ STATIC DATA MEMBER
==============================================================

• Belongs to class
• Shared among all objects
• Single copy exists
• Must be defined outside class
*/

class Counter {
public:
    static int count;
};

int Counter::count = 0;

/*
==============================================================
1️⃣2️⃣ VIRTUAL FUNCTION
==============================================================

• Enables runtime polymorphism
• Function call resolved at runtime
*/

/*
==============================================================
1️⃣3️⃣ DIAMOND PROBLEM
==============================================================

Occurs in multiple inheritance

Solution:
Use virtual inheritance
*/

/*
==============================================================
1️⃣4️⃣ SCOPE RESOLUTION OPERATOR (::)
==============================================================

Used to define function outside class
Used to access static members

Example:
ClassName::variable
*/

/*
==============================================================
1️⃣5️⃣ GLOBAL vs LOCAL CLASS
==============================================================

Global Class:
    Defined outside all functions

Local Class:
    Defined inside a function
*/

/*
==============================================================
1️⃣6️⃣ MAIN FUNCTION DEMO
==============================================================
*/

int main() {

    // Object Creation
    Student s;
    s.roll = 1;
    s.name = "Yash";
    s.display();

    // Encapsulation
    BankAccount acc;
    acc.setBalance(10000);
    cout << "Balance: " << acc.getBalance() << endl;

    // Abstraction
    Shape* sp = new Circle();
    sp->draw();

    // Inheritance
    Dog d;
    d.eat();
    d.bark();

    // Compile-time Polymorphism
    Calculator calc;
    cout << calc.add(2, 3) << endl;
    cout << calc.add(2, 3, 4) << endl;

    // Runtime Polymorphism
    Base* obj = new Derived();
    obj->show();

    // Constructor & Destructor
    Demo d1;
    Sample s1;

    return 0;
}

/**************************************************************
                    END OF MASTER OOPS NOTES
**************************************************************/

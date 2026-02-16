/************************************************************
        OBJECT ORIENTED PROGRAMMING (OOPS) - C++
        MASTER NOTES
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. PROGRAMMING PARADIGM
------------------------------------------------------------
Programming Paradigm = Style / approach of programming.

Main Types:
1) Procedural Programming
2) Object Oriented Programming
============================================================
*/

/*
------------------------------------------------------------
PROCEDURAL PROGRAMMING
------------------------------------------------------------
- Focus on functions
- Top-down approach
- Data shared among functions
- No data hiding
- Less secure
- Difficult for large programs

Example: C
*/

/*
------------------------------------------------------------
OBJECT ORIENTED PROGRAMMING
------------------------------------------------------------
- Focus on objects
- Bottom-up approach
- Data + functions wrapped together
- Supports data hiding
- High security
- Easy maintenance
- Real world modelling

Examples: C++, Java, Python, C#
============================================================
*/

/*
============================================================
2. ADVANTAGES AND DISADVANTAGES
------------------------------------------------------------

Advantages:
- Code reusability
- Data security
- Easy debugging
- Better maintainability
- Real world modelling
- Scalable systems

Disadvantages:
- Complex for beginners
- Higher memory usage
- Slightly slower in some cases
============================================================
*/

/*
============================================================
3. CLASS
------------------------------------------------------------
Class is a blueprint or template.

- User-defined data type
- No memory allocated until object is created
- Contains data members and member functions
============================================================
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
============================================================
4. OBJECT
------------------------------------------------------------
Object is an instance of a class.

Memory is allocated when object is created.

Object has:
- Identity
- State
- Behavior
============================================================
*/

/*
============================================================
5. ACCESS SPECIFIERS
------------------------------------------------------------
public:
    Accessible everywhere

private:
    Accessible only inside class
    Default access in class

protected:
    Accessible inside class and derived class
============================================================
*/

/*
============================================================
6. FOUR PILLARS OF OOPS
------------------------------------------------------------
1) Encapsulation
2) Abstraction
3) Inheritance
4) Polymorphism
============================================================
*/

/*
------------------------------------------------------------
ENCAPSULATION
------------------------------------------------------------
Wrapping data and functions into a class.

Achieved using:
- Private data members
- Public getter and setter functions
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
------------------------------------------------------------
ABSTRACTION
------------------------------------------------------------
Hiding implementation details and exposing only
essential features.

Achieved using:
- Abstract class
- Pure virtual function
*/

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

/*
------------------------------------------------------------
INHERITANCE
------------------------------------------------------------
One class acquires properties of another.

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
Types:
- Single
- Multiple
- Multilevel
- Hierarchical
- Hybrid
*/

/*
------------------------------------------------------------
POLYMORPHISM
------------------------------------------------------------
One name, multiple forms.

Types:
1) Compile-time
2) Run-time
*/

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

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
============================================================
7. CONSTRUCTOR
------------------------------------------------------------
- Special member function
- Same name as class
- No return type
- Automatically called
============================================================
*/

class Demo {
public:
    Demo() {
        cout << "Constructor Called" << endl;
    }
};

/*
============================================================
8. DESTRUCTOR
------------------------------------------------------------
- Called automatically when object is destroyed
- Used to release resources
- Name starts with '~'
============================================================
*/

class Sample {
public:
    ~Sample() {
        cout << "Destructor Called" << endl;
    }
};

/*
============================================================
9. THIS POINTER
------------------------------------------------------------
- Refers to current object
- Used to resolve name conflict
============================================================
*/

class Box {
    int length;
public:
    void setLength(int length) {
        this->length = length;
    }
};

/*
============================================================
10. STATIC DATA MEMBER
------------------------------------------------------------
- Belongs to class
- Shared among all objects
- Only one copy exists
- Must be defined outside class
============================================================
*/

class Counter {
public:
    static int count;
};

int Counter::count = 0;

/*
============================================================
11. VIRTUAL FUNCTION
------------------------------------------------------------
- Enables runtime polymorphism
- Function call resolved at runtime
============================================================
*/

/*
============================================================
12. DIAMOND PROBLEM
------------------------------------------------------------
Occurs in multiple inheritance.

Solution:
Use virtual inheritance.
============================================================
*/

/*
============================================================
13. SCOPE RESOLUTION OPERATOR (::)
------------------------------------------------------------
Used to:
- Define functions outside class
- Access static members

Example:
ClassName::variable
============================================================
*/

/*
============================================================
14. GLOBAL VS LOCAL CLASS
------------------------------------------------------------
Global Class:
    Defined outside all functions

Local Class:
    Defined inside a function
============================================================
*/

/*
============================================================
MAIN FUNCTION DEMO
============================================================
*/

int main() {

    Student s;
    s.roll = 1;
    s.name = "Yash";
    s.display();

    BankAccount acc;
    acc.setBalance(10000);
    cout << "Balance: " << acc.getBalance() << endl;

    Shape* sp = new Circle();
    sp->draw();

    Dog d;
    d.eat();
    d.bark();

    Calculator calc;
    cout << calc.add(2, 3) << endl;
    cout << calc.add(2, 3, 4) << endl;

    Base* obj = new Derived();
    obj->show();

    Demo d1;
    Sample s1;

    return 0;
}

/************************************************************
                    END OF MASTER NOTES
************************************************************/

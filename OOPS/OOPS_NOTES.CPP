/************************************************************
        OBJECT ORIENTED PROGRAMMING (OOPS) - C++
        COMPLETE & DETAILED NOTES (WITH CODE)
        Suitable for:
        ✔ College Exams
        ✔ Interviews
        ✔ Concept Building
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. PROGRAMMING PARADIGM
------------------------------------------------------------
Paradigm = Style / approach of programming

Main Paradigms:
1) Procedural Programming
2) Object Oriented Programming (OOP)
============================================================
*/

/*
============================================================
2. PROCEDURAL PROGRAMMING
------------------------------------------------------------
- Focuses on functions
- Data is shared among functions
- Top-down approach
- Low security
- Difficult to maintain large programs

Example Language: C
============================================================
*/

/*
============================================================
3. OBJECT ORIENTED PROGRAMMING (OOP)
------------------------------------------------------------
- Focuses on objects
- Objects contain data + functions
- Bottom-up approach
- High data security
- Better maintainability

Languages:
C++, Java, Python, C#
============================================================
*/

/*
============================================================
4. CLASS
------------------------------------------------------------
- Blueprint / template
- User-defined data type
- No memory allocation

Contains:
1) Data Members (variables)
2) Member Functions (methods)
============================================================
*/

class Student {
public:
    int roll;        // data member
    string name;     // data member

    void display() { // member function
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
    }
};

/*
============================================================
5. OBJECT
------------------------------------------------------------
- Instance of a class
- Memory allocated when object is created

Syntax:
ClassName objectName;
============================================================
*/

/*
============================================================
6. ACCESS SPECIFIERS
------------------------------------------------------------
public:
- Accessible everywhere

private:
- Accessible only inside class
- Default access specifier

protected:
- Accessible in class & derived class
============================================================
*/

/*
============================================================
7. ENCAPSULATION
------------------------------------------------------------
Definition:
Wrapping data and methods into a single unit (class)

Why?
- Data security
- Controlled access

Achieved by:
- Making data members private
- Using getter & setter
============================================================
*/

class BankAccount {
private:
    int balance;  // hidden data

public:
    void setBalance(int amt) {
        balance = amt;
    }

    int getBalance() {
        return balance;
    }
};

/*
============================================================
8. ABSTRACTION
------------------------------------------------------------
Definition:
Hiding implementation details and showing only essential features

Example:
- ATM (you know withdraw, not internal logic)

Achieved by:
1) Abstract class
2) Pure virtual function
============================================================
*/

class Shape {
public:
    virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

/*
============================================================
9. INHERITANCE
------------------------------------------------------------
Definition:
One class acquires properties of another class

Why?
- Code reusability
- Reduces redundancy

Syntax:
class Child : accessSpecifier Parent
============================================================
*/

// Base class
class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

/*
============================================================
10. TYPES OF INHERITANCE
------------------------------------------------------------
1) Single
2) Multiple
3) Multilevel
4) Hierarchical
5) Hybrid
============================================================
*/

/*
============================================================
11. POLYMORPHISM
------------------------------------------------------------
Meaning:
One name, many forms

Types:
1) Compile-time Polymorphism
   - Function Overloading
   - Operator Overloading

2) Runtime Polymorphism
   - Function Overriding
   - Virtual Function
============================================================
*/

// Function Overloading
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

/*
============================================================
12. FUNCTION OVERRIDING
------------------------------------------------------------
- Same function name
- Same parameters
- Different classes
- Requires inheritance
============================================================
*/

class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show()" << endl;
    }
};

/*
============================================================
13. CONSTRUCTOR
------------------------------------------------------------
- Special member function
- Same name as class
- No return type
- Automatically called

Types:
1) Default
2) Parameterized
3) Copy
============================================================
*/

class Demo {
public:
    Demo() {
        cout << "Default Constructor Called" << endl;
    }
};

/*
============================================================
14. DESTRUCTOR
------------------------------------------------------------
- Called automatically
- Frees memory/resources
- Name starts with ~
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
15. THIS POINTER
------------------------------------------------------------
- Holds address of current object
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
16. STATIC DATA MEMBER
------------------------------------------------------------
- Shared among all objects
- Single copy
============================================================
*/

class Counter {
public:
    static int count;
};
int Counter::count = 0;

/*
============================================================
17. VIRTUAL FUNCTION
------------------------------------------------------------
- Function call resolved at runtime
- Achieves runtime polymorphism
============================================================
*/

/*
============================================================
18. DIAMOND PROBLEM
------------------------------------------------------------
Occurs in multiple inheritance

Solved using:
- virtual inheritance
============================================================
*/

/*
============================================================
19. ADVANTAGES OF OOPS
------------------------------------------------------------
✔ Code reusability
✔ Data security
✔ Easy debugging
✔ Real-world modeling
✔ Scalability
============================================================
*/

/*
============================================================
20. DISADVANTAGES OF OOPS
------------------------------------------------------------
✘ Complex syntax
✘ Higher memory usage
✘ Slower execution sometimes
============================================================
*/

/*
============================================================
21. MAIN FUNCTION (DEMO)
============================================================
*/

int main() {

    // Object creation
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

    // Polymorphism
    Calculator c;
    cout << c.add(2, 3) << endl;
    cout << c.add(2, 3, 4) << endl;

    Base* obj = new Derived();
    obj->show();

    // Constructor & Destructor
    Demo d1;
    Sample s1;

    return 0;
}

/************************************************************
                    END OF OOPS NOTES
************************************************************/

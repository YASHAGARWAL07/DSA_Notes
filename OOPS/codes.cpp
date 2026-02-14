/****************************************************
 OOPS NOTES IN C++ (DETAILED & RUNNABLE)
 Author : Yash
 Purpose: Complete OOP revision with examples
****************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
====================================================
1. CLASS & OBJECT
- Class : Blueprint / user-defined data type
- Object: Instance of class
====================================================
*/

class Student {
private:
    // Data Members (Encapsulation)
    string name;
    int age;
    int roll;
    string grade;

public:
    /*
    ====================================================
    2. SETTER FUNCTIONS (Controlled access)
    ====================================================
    */

    void setName(string n) {
        if (n.size() == 0) {
            cout << "Invalid name!" << endl;
            return;
        }
        name = n;
    }

    void setAge(int a) {
        if (a <= 0 || a > 100) {
            cout << "Invalid age!" << endl;
            return;
        }
        age = a;
    }

    void setRoll(int r) {
        roll = r;
    }

    void setGrade(string g) {
        grade = g;
    }

    /*
    ====================================================
    3. GETTER FUNCTIONS (Read-only access)
    ====================================================
    */

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    int getRoll() {
        return roll;
    }

    // Security using PIN
    string getGrade(int pin) {
        if (pin == 123)
            return grade;
        return "Access Denied";
    }
};

/*
====================================================
4. CONSTRUCTOR
- Special function
- Same name as class
- Automatically called when object is created
====================================================
*/

class Employee {
private:
    int id;
    string dept;

public:
    // Default Constructor
    Employee() {
        id = 0;
        dept = "NA";
    }

    // Parameterized Constructor
    Employee(int i, string d) {
        id = i;
        dept = d;
    }

    void display() {
        cout << "ID: " << id << ", Dept: " << dept << endl;
    }
};

/*
====================================================
5. DESTRUCTOR
- Called automatically when object is destroyed
- Used to free resources
====================================================
*/

class Test {
public:
    Test() {
        cout << "Constructor Called" << endl;
    }

    ~Test() {
        cout << "Destructor Called" << endl;
    }
};

/*
====================================================
6. INHERITANCE
- Reusability
- Types: Single, Multilevel, Multiple, Hybrid
====================================================
*/

// Base Class
class Animal {
public:
    void eat() {
        cout << "Animal eats" << endl;
    }
};

// Derived Class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

/*
====================================================
7. POLYMORPHISM
7.1 Compile-time (Function Overloading)
====================================================
*/

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

/*
====================================================
7.2 Runtime Polymorphism (Virtual Function)
====================================================
*/

class Base {
public:
    virtual void show() {
        cout << "Base class show" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show" << endl;
    }
};

/*
====================================================
8. ABSTRACTION
- Hiding implementation details
- Using virtual functions
====================================================
*/

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

/*
====================================================
9. STATIC DATA MEMBER
- Shared among all objects
====================================================
*/

class Counter {
public:
    static int count;

    Counter() {
        count++;
    }
};

int Counter::count = 0;

/*
====================================================
10. THIS POINTER
- Points to current object
====================================================
*/

class Box {
private:
    int length;

public:
    void set(int length) {
        this->length = length;
    }

    int get() {
        return length;
    }
};

/*
====================================================
MAIN FUNCTION
====================================================
*/

int main() {

    cout << "---- Student Class ----" << endl;
    Student s1;
    s1.setName("Yash");
    s1.setAge(21);
    s1.setRoll(7);
    s1.setGrade("A+");

    cout << s1.getName() << endl;
    cout << s1.getAge() << endl;
    cout << s1.getRoll() << endl;
    cout << s1.getGrade(123) << endl;

    cout << "\n---- Constructor ----" << endl;
    Employee e1;
    Employee e2(101, "CSE");
    e1.display();
    e2.display();

    cout << "\n---- Destructor ----" << endl;
    Test t;

    cout << "\n---- Inheritance ----" << endl;
    Dog d;
    d.eat();
    d.bark();

    cout << "\n---- Polymorphism ----" << endl;
    Math m;
    cout << m.add(2, 3) << endl;
    cout << m.add(1, 2, 3) << endl;

    Base* b;
    Derived obj;
    b = &obj;
    b->show();

    cout << "\n---- Abstraction ----" << endl;
    Shape* sh = new Circle();
    sh->draw();

    cout << "\n---- Static Member ----" << endl;
    Counter c1, c2, c3;
    cout << Counter::count << endl;

    cout << "\n---- This Pointer ----" << endl;
    Box box;
    box.set(50);
    cout << box.get() << endl;

    return 0;
}

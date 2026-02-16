/************************************************************
        COMPLETE OOPS CONCEPT SUMMARY (C++)
************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
============================================================
1. CLASS AND OBJECT
------------------------------------------------------------
Class:
    - Blueprint or user-defined data type.
    - Defines properties and behavior.

Object:
    - Instance of a class.
    - Memory is allocated when object is created.
============================================================
*/

class Student {

private:
    string name;
    int age;
    int roll;
    string grade;

public:

/*
============================================================
2. ENCAPSULATION
------------------------------------------------------------
- Data members are private.
- Access controlled using public setter and getter functions.
============================================================
*/

    void setName(string n) {
        if (n.size() == 0) {
            cout << "Invalid name" << endl;
            return;
        }
        name = n;
    }

    void setAge(int a) {
        if (a <= 0 || a > 100) {
            cout << "Invalid age" << endl;
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
============================================================
3. GETTER FUNCTIONS
------------------------------------------------------------
Provide controlled read access.
============================================================
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

    string getGrade(int pin) {
        if (pin == 123)
            return grade;
        return "Access Denied";
    }
};

/*
============================================================
4. CONSTRUCTOR
------------------------------------------------------------
- Special member function.
- Same name as class.
- Automatically called when object is created.
============================================================
*/

class Employee {

private:
    int id;
    string dept;

public:

    Employee() {
        id = 0;
        dept = "NA";
    }

    Employee(int i, string d) {
        id = i;
        dept = d;
    }

    void display() {
        cout << "ID: " << id
             << ", Dept: " << dept << endl;
    }
};

/*
============================================================
5. DESTRUCTOR
------------------------------------------------------------
- Automatically called when object is destroyed.
- Used to release resources.
============================================================
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
============================================================
6. INHERITANCE
------------------------------------------------------------
- Allows one class to acquire properties of another.
- Promotes code reusability.
============================================================
*/

class Animal {
public:
    void eat() {
        cout << "Animal eats" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

/*
============================================================
7. POLYMORPHISM
============================================================
*/

/*
7.1 Compile-Time Polymorphism (Function Overloading)
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
7.2 Runtime Polymorphism (Virtual Function)
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
============================================================
8. ABSTRACTION
------------------------------------------------------------
- Hides implementation details.
- Achieved using pure virtual functions.
============================================================
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
============================================================
9. STATIC DATA MEMBER
------------------------------------------------------------
- Shared among all objects.
- Only one copy exists.
============================================================
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
============================================================
10. THIS POINTER
------------------------------------------------------------
- Refers to current object.
- Used to resolve name conflict.
============================================================
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
============================================================
MAIN FUNCTION
============================================================
*/

int main() {

    Student s1;
    s1.setName("Yash");
    s1.setAge(21);
    s1.setRoll(7);
    s1.setGrade("A+");

    cout << s1.getName() << endl;
    cout << s1.getAge() << endl;
    cout << s1.getRoll() << endl;
    cout << s1.getGrade(123) << endl;

    Employee e1;
    Employee e2(101, "CSE");
    e1.display();
    e2.display();

    Test t;

    Dog d;
    d.eat();
    d.bark();

    Math m;
    cout << m.add(2, 3) << endl;
    cout << m.add(1, 2, 3) << endl;

    Base* b;
    Derived obj;
    b = &obj;
    b->show();

    Shape* sh = new Circle();
    sh->draw();

    Counter c1, c2, c3;
    cout << Counter::count << endl;

    Box box;
    box.set(50);
    cout << box.get() << endl;

    return 0;
}

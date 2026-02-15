/***************************************************************
 *                  INHERITANCE IN C++
 *          Detailed Notes with Examples (My Class Notes)
 *
 *  ✔ Concept Clarity
 *  ✔ Access Modifier Explanation
 *  ✔ Types of Inheritance
 *  ✔ Constructor Call Order
 *  ✔ Diamond Problem
 ***************************************************************/

#include <iostream>
using namespace std;

/*
=================================================================
1️⃣ WHAT IS INHERITANCE?
=================================================================

Inheritance is the capability of one class to acquire
properties (data members) and behaviors (functions)
of another class.

It promotes:
✔ Code Reusability
✔ Logical Structure
✔ Real-world modeling
✔ Reduces redundancy

-----------------------------------------------------------------
SYNTAX:

class Child : accessSpecifier Parent
{
    // body
};

Example:
class Dog : public Animal
*/




/*
=================================================================
2️⃣ WHY DO WE NEED INHERITANCE?
=================================================================

Without inheritance:
→ We would rewrite same code again and again.

With inheritance:
→ We reuse base class code.

Real-life Example:
Human → Student → Engineer
Vehicle → Car → ElectricCar
*/




/*
=================================================================
3️⃣ BASE CLASS & DERIVED CLASS
=================================================================

Base Class:
→ The class whose properties are inherited.

Derived Class:
→ The class that inherits properties.
*/

class Human {
protected:
    string name;
    int age;

public:
    void setHuman(string n, int a) {
        name = n;
        age = a;
    }

    void showHuman() {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }
};


/*
=================================================================
4️⃣ TYPES OF INHERITANCE
=================================================================

1) Single Inheritance
2) Multiple Inheritance
3) Multilevel Inheritance
4) Hierarchical Inheritance
5) Hybrid Inheritance
*/




/*
===============================================================
4.1️⃣ SINGLE INHERITANCE
===============================================================

One base → One derived
*/

class Student : public Human {
private:
    int roll_number;

public:
    void setStudent(string n, int a, int r) {
        setHuman(n, a);
        roll_number = r;
    }

    void displayStudent() {
        showHuman();
        cout << "Roll Number: " << roll_number << endl;
    }
};




/*
===============================================================
4.2️⃣ MULTILEVEL INHERITANCE
===============================================================

Grandparent → Parent → Child
*/

class CollegeStudent : public Student {
private:
    string branch;

public:
    void setCollege(string n, int a, int r, string b) {
        setStudent(n, a, r);
        branch = b;
    }

    void displayCollege() {
        displayStudent();
        cout << "Branch: " << branch << endl;
    }
};




/*
===============================================================
4.3️⃣ MULTIPLE INHERITANCE
===============================================================

One class inherits from multiple classes.
*/

class Sports {
public:
    void play() {
        cout << "Playing sports..." << endl;
    }
};

class Academic {
public:
    void study() {
        cout << "Studying..." << endl;
    }
};

class AllRounder : public Sports, public Academic {
public:
    void perform() {
        cout << "Excellent in both academics & sports" << endl;
    }
};




/*
===============================================================
4.4️⃣ HIERARCHICAL INHERITANCE
===============================================================

One base → Multiple derived classes
*/

class Teacher : public Human {
public:
    void teach() {
        cout << "Teaching..." << endl;
    }
};

class Doctor : public Human {
public:
    void treat() {
        cout << "Treating patients..." << endl;
    }
};




/*
===============================================================
5️⃣ ACCESS SPECIFIER IN INHERITANCE
===============================================================

Base Member → public inheritance → private inheritance

Base Class Access     |  Public Derive | Private Derive
--------------------------------------------------------
public                |  public        | private
protected             |  protected     | private
private               |  NOT accessible in derived

IMPORTANT:
Private members are never directly inherited.
*/




/*
===============================================================
6️⃣ CONSTRUCTOR CALL ORDER IN INHERITANCE
===============================================================

Rule:
1) Base class constructor executes first
2) Then derived class constructor

Destruction:
1) Derived destructor executes first
2) Then base destructor
*/

class BaseDemo {
public:
    BaseDemo() {
        cout << "Base Constructor Called" << endl;
    }

    ~BaseDemo() {
        cout << "Base Destructor Called" << endl;
    }
};

class DerivedDemo : public BaseDemo {
public:
    DerivedDemo() {
        cout << "Derived Constructor Called" << endl;
    }

    ~DerivedDemo() {
        cout << "Derived Destructor Called" << endl;
    }
};




/*
===============================================================
7️⃣ DIAMOND PROBLEM
===============================================================

Occurs in multiple inheritance when:

        A
       / \
      B   C
       \ /
        D

Class D gets two copies of A.

Solution:
Use virtual inheritance.
*/

class A {
public:
    int x;
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};




/*
===============================================================
8️⃣ KEY INTERVIEW POINTS
===============================================================

✔ Inheritance promotes code reuse.
✔ Constructors execute top-down.
✔ Destructors execute bottom-up.
✔ Private members not accessible in derived.
✔ Use virtual inheritance to avoid diamond problem.
✔ "protected" is mostly used for inheritance.
*/




/*
===============================================================
9️⃣ MAIN FUNCTION (DEMO EXECUTION)
===============================================================
*/

int main() {

    cout << "----- Single Inheritance -----" << endl;
    Student s;
    s.setStudent("Yash", 19, 101);
    s.displayStudent();

    cout << "\n----- Multilevel Inheritance -----" << endl;
    CollegeStudent cs;
    cs.setCollege("Yash", 19, 101, "CSE");
    cs.displayCollege();

    cout << "\n----- Multiple Inheritance -----" << endl;
    AllRounder ar;
    ar.play();
    ar.study();
    ar.perform();

    cout << "\n----- Constructor Order -----" << endl;
    DerivedDemo obj;

    cout << "\n----- Hierarchical Inheritance -----" << endl;
    Teacher t;
    t.setHuman("Sir", 40);
    t.teach();

    Doctor d;
    d.setHuman("Dr. Rao", 45);
    d.treat();

    return 0;
}

/***************************************************************
                    END OF INHERITANCE NOTES
***************************************************************/

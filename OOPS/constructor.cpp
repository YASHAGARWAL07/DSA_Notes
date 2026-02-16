/************************************************************
        CONSTRUCTORS IN C++ (Lecture 71)
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. INTRODUCTION TO CONSTRUCTOR
------------------------------------------------------------
Constructor is a special member function of a class.

Characteristics:
- Same name as class
- No return type (not even void)
- Automatically called when object is created
- Used to initialize data members
============================================================
*/

/*
============================================================
2. DEFAULT CONSTRUCTOR
------------------------------------------------------------
- Takes no arguments
- Called when object is created without parameters
- If no constructor is written, compiler creates a
  default constructor automatically
============================================================
*/

class Customer {

    string name;
    int account_number;
    int balance;

public:

    Customer() {
        name = "Rohit";
        account_number = 5;
        balance = 100;
    }

/*
============================================================
3. PARAMETERIZED CONSTRUCTOR
------------------------------------------------------------
- Takes parameters
- Used to initialize object with custom values
============================================================
*/

    Customer(string a, int b, int c) {
        name = a;
        account_number = b;
        balance = c;
    }

/*
============================================================
4. CONSTRUCTOR USING this POINTER
------------------------------------------------------------
- Used when parameter names and data members are same
- this pointer refers to current object
============================================================
*/

    Customer(string name, int account_number) {
        this->name = name;
        this->account_number = account_number;
        this->balance = 50;
    }

/*
============================================================
5. CONSTRUCTOR OVERLOADING
------------------------------------------------------------
- Multiple constructors in same class
- Different parameter lists
- Resolved at compile time
============================================================
*/

    inline Customer(string a, int b, int c, bool flag)
        : name(a), account_number(b), balance(c) {
        // Initializer list (faster than assignment)
    }

/*
============================================================
6. MEMBER FUNCTION
============================================================
*/

    void display() {
        cout << name << " "
             << account_number << " "
             << balance << endl;
    }

/*
============================================================
7. COPY CONSTRUCTOR
------------------------------------------------------------
- Used to copy one object into another
- Called when:
    1) Object is initialized using another object
    2) Object is passed by value
    3) Object is returned by value

Default copy constructor performs SHALLOW COPY.
============================================================
*/

    Customer(Customer &B) {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }
};

/*
============================================================
8. MAIN FUNCTION
============================================================
*/

int main() {

    Customer A1;                          // Default constructor
    Customer A2("Rohit", 23, 1000);       // Parameterized
    Customer A3("Mohit", 25);             // Overloaded
    Customer A4(A3);                      // Copy constructor

    A1.display();
    A2.display();
    A3.display();
    A4.display();

    return 0;
}

/*
============================================================
9. IMPORTANT POINTS
------------------------------------------------------------
- Constructor name must match class name
- Constructor has no return type
- Constructor can be overloaded
- Constructor can be inline
- Copy constructor must take argument by reference
- If not written, compiler creates default copy constructor
- Shallow copy occurs with pointers
- Deep copy required for dynamic memory
============================================================
*/

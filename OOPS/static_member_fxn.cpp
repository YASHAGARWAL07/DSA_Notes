/************************************************************
    STATIC DATA MEMBERS & STATIC MEMBER FUNCTIONS (C++)
    + CONST KEYWORD
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. STATIC DATA MEMBER
------------------------------------------------------------
- Belongs to the class, not individual objects.
- Only one copy exists for entire program.
- Shared among all objects.
- Memory allocated only once.
- Used to store common information.

Syntax (inside class):
    static data_type variable_name;

Important:
Static data member must be defined outside the class.
============================================================
*/

class Customer {

private:
    string name;
    int account_number;
    int balance;

    static int total_customer;
    static int total_balance;

public:

/*
============================================================
2. PARAMETERIZED CONSTRUCTOR
------------------------------------------------------------
- Automatically called when object is created.
- Updates static members.
============================================================
*/

    Customer(string name, int acc, int bal) {
        this->name = name;
        this->account_number = acc;
        this->balance = bal;

        total_customer++;
        total_balance += bal;
    }

/*
============================================================
3. NON-STATIC MEMBER FUNCTION
------------------------------------------------------------
- Requires object to call.
- Can access both static and non-static members.
============================================================
*/

    void display() const {
        cout << name << " "
             << account_number << " "
             << balance << endl;
    }

/*
============================================================
4. STATIC MEMBER FUNCTION
------------------------------------------------------------
- Belongs to class, not object.
- Can access only static members.
- No 'this' pointer available.
- Cannot access non-static members.

Calling:
    ClassName::function();
============================================================
*/

    static void showStats() {
        cout << "Total Customers : "
             << total_customer << endl;

        cout << "Total Balance   : "
             << total_balance << endl;
    }

/*
============================================================
5. NON-STATIC FUNCTION USING STATIC DATA
============================================================
*/

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            total_balance += amount;
        }
    }
};

/*
============================================================
6. STATIC DATA MEMBER DEFINITION
------------------------------------------------------------
Mandatory.
Must be defined outside class.
============================================================
*/

int Customer::total_customer = 0;
int Customer::total_balance  = 0;

/*
============================================================
7. CONST KEYWORD
============================================================

const means value cannot be modified.
*/

/*
------------------------------------------------------------
7.1 CONST MEMBER FUNCTION
------------------------------------------------------------
- Guarantees function will not modify object data.
- Can be called using const objects.
============================================================
*/

class Demo {

    int x;

public:
    Demo(int x) {
        this->x = x;
    }

    int getX() const {
        return x;
    }

    // void setX(int v) const { }  // Invalid
};

/*
------------------------------------------------------------
7.2 CONST OBJECT
------------------------------------------------------------
- Can call only const member functions.
============================================================
*/

void constObjectExample() {

    const Demo d(10);
    cout << d.getX() << endl;
}

/*
------------------------------------------------------------
7.3 CONST WITH STATIC MEMBERS
------------------------------------------------------------
- Static functions cannot be const.
- const applies to object-level functions only.

Invalid:
    static void show() const;
============================================================
*/

/*
============================================================
8. COMMON ERRORS
============================================================

Error:
Call to non-static member function without object.

Wrong:
    Customer::display();
    Customer::deposit(100);

Correct:
    Customer obj("A",1,100);
    obj.display();

Static function:
    Customer::showStats();
============================================================
*/

/*
============================================================
9. MAIN FUNCTION
============================================================
*/

int main() {

    Customer A1("Rohit", 1, 1000);
    Customer A2("Mohit", 2, 1800);
    Customer A3("Mohan", 3, 2000);

    A1.display();
    A2.display();
    A3.display();

    A1.deposit(800);

    Customer::showStats();

    constObjectExample();

    return 0;
}

/*
============================================================
10. QUICK REVISION
------------------------------------------------------------
Static Data Member:
- One copy for class.
- Defined outside class.
- Shared by all objects.

Static Member Function:
- Access only static members.
- No this pointer.
- Called using ClassName::.

const Keyword:
- Prevents modification.
- Const object calls only const functions.
- Static function cannot be const.
============================================================
*/

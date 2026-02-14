/************************************************************
 *  STATIC DATA MEMBERS & STATIC MEMBER FUNCTIONS (C++)
 *  + CONST KEYWORD
 *
 *  Lecture 72 – Coder Army (Rohit Negi Sir)
 *
 *  Useful for:
 *  ✔ College Exams
 *  ✔ Interviews
 *  ✔ Concept Clarity
 ************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1️⃣ STATIC DATA MEMBER
============================================================

• Belongs to the CLASS, not to individual objects
• Only ONE copy exists for the entire program
• Shared among all objects of the class
• Memory allocated only once
• Used to store common information

SYNTAX (inside class):
    static data_type variable_name;

IMPORTANT:
• Static data member MUST be defined outside the class
• Otherwise linker error will occur
*/

class Customer {
private:
    string name;
    int account_number;
    int balance;

    // Static Data Members (class-level data)
    static int total_customer;
    static int total_balance;

public:
    /*
    --------------------------------------------------------
    2️⃣ PARAMETERIZED CONSTRUCTOR
    --------------------------------------------------------
    • Called automatically when object is created
    • Updates static members
    */
    Customer(string name, int acc, int bal) {
        this->name = name;
        this->account_number = acc;
        this->balance = bal;

        total_customer++;
        total_balance += bal;
    }

    /*
    --------------------------------------------------------
    3️⃣ NON-STATIC MEMBER FUNCTION
    --------------------------------------------------------
    • Requires object to call
    • Can access BOTH static & non-static members
    */
    void display() const {
        cout << name << " "
             << account_number << " "
             << balance << endl;
    }

    /*
    --------------------------------------------------------
    4️⃣ STATIC MEMBER FUNCTION
    --------------------------------------------------------
    • Belongs to CLASS, not object
    • Can access ONLY static members
    • No 'this' pointer available
    • Cannot access non-static members

    CALLING:
        ClassName::function();
    */
    static void showStats() {
        cout << "Total Customers : " << total_customer << endl;
        cout << "Total Balance   : " << total_balance << endl;
    }

    /*
    --------------------------------------------------------
    5️⃣ NON-STATIC FUNCTION USING STATIC DATA
    --------------------------------------------------------
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
6️⃣ STATIC DATA MEMBER DEFINITION
============================================================
• Mandatory
• Done outside the class
*/

int Customer::total_customer = 0;
int Customer::total_balance  = 0;

/*
============================================================
7️⃣ CONST KEYWORD (IMPORTANT WITH STATIC CONTEXT)
============================================================

const means:
➡ Value or data cannot be modified
*/

/*
------------------------------------------------------------
7.1 CONST MEMBER FUNCTION
------------------------------------------------------------

• Guarantees function will NOT modify object data
• Can be called using const objects
*/

class Demo {
    int x;
public:
    Demo(int x) {
        this->x = x;
    }

    int getX() const {   // const function
        return x;
    }

    // void setX(int v) const { ❌ ERROR
    //     x = v;
    // }
};

/*
------------------------------------------------------------
7.2 CONST OBJECT
------------------------------------------------------------

• Can call ONLY const member functions
*/

void constObjectExample() {
    const Demo d(10);
    cout << d.getX() << endl;   // ✔ Allowed
}

/*
------------------------------------------------------------
7.3 CONST WITH STATIC MEMBERS
------------------------------------------------------------

• Static functions CANNOT be const
• const keyword applies to OBJECT functions only

❌ static void show() const;   // INVALID
*/

/*
============================================================
8️⃣ COMMON ERRORS (FROM YOUR SCREENSHOTS)
============================================================

ERROR:
call to non-static member function without an object argument

WRONG:
    Customer::display();      ❌
    Customer::deposit(100);  ❌

CORRECT:
    Customer obj("A",1,100);
    obj.display();            ✔

STATIC FUNCTION CALL:
    Customer::showStats();    ✔
*/

/*
============================================================
9️⃣ MAIN FUNCTION – EXECUTION FLOW
============================================================
*/

int main() {

    Customer A1("Rohit", 1, 1000);
    Customer A2("Mohit", 2, 1800);
    Customer A3("Mohan", 3, 2000);

    A1.display();
    A2.display();
    A3.display();

    // Updates object + static balance
    A1.deposit(800);

    // Static function call (correct way)
    Customer::showStats();

    constObjectExample();

    return 0;
}

/*
============================================================
10️⃣ QUICK REVISION (EXAM READY)
============================================================

✔ Static Data Member:
    - One copy for entire class
    - Defined outside class
    - Shared among all objects

✔ Static Member Function:
    - Access only static members
    - No this pointer
    - Called using ClassName::

✔ const keyword:
    - Prevents modification
    - const object → calls only const functions
    - static function CANNOT be const

============================================================
END OF NOTES ✔
============================================================
*/

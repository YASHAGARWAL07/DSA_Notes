/************************************************************
        ENCAPSULATION IN C++
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. DEFINITION OF ENCAPSULATION
------------------------------------------------------------
Encapsulation means wrapping data (variables) and 
functions (methods) into a single unit called a CLASS.

In simple words:
    Data + Functions = One Capsule (Class)

It is one of the four pillars of OOPS:
1) Encapsulation
2) Abstraction
3) Inheritance
4) Polymorphism
============================================================
*/

/*
============================================================
2. WHY ENCAPSULATION IS REQUIRED
------------------------------------------------------------
Encapsulation provides:

- Data Hiding
- Security
- Controlled access
- Protection from accidental modification
- Better code organization

Real-Life Example:
ATM Machine
You cannot directly access bank database.
You interact through buttons (interface).
============================================================
*/

/*
============================================================
3. ACCESS SPECIFIERS
------------------------------------------------------------

private:
    - Accessible only inside the class
    - Used for data hiding
    - Default access in class

public:
    - Accessible everywhere
    - Used for member functions

protected:
    - Accessible in class and derived class
    - Used in inheritance
============================================================
*/

class BankAccount {

private:
    string name;
    int account_number;
    double balance;

public:

    BankAccount(string name, int acc, double bal) {
        this->name = name;
        this->account_number = acc;
        this->balance = bal;
    }

    string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Account No: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

/*
============================================================
4. MAIN FUNCTION – IMPLEMENTATION
============================================================
*/

int main() {

    BankAccount user1("Rohit", 101, 5000);

    user1.display();

    // user1.balance = 100000;  // ERROR (private)

    user1.deposit(2000);
    user1.withdraw(1500);

    cout << "Updated Balance: "
         << user1.getBalance() << endl;

    return 0;
}

/*
============================================================
5. HOW ENCAPSULATION PROVIDES SECURITY
============================================================

Without Encapsulation:

class Bad {
public:
    int balance;
};

Anyone can modify balance directly.

With Encapsulation:

class Good {
private:
    int balance;
public:
    void deposit(int amount);
};

Now modification is controlled.
============================================================
*/

/*
============================================================
6. DIFFERENCE: ENCAPSULATION VS ABSTRACTION
============================================================

Encapsulation:
    - Hides data
    - Protects internal state
    - Achieved using private data members

Abstraction:
    - Hides implementation details
    - Shows only essential functionality
    - Achieved using abstract classes
============================================================
*/

/*
============================================================
7. IMPORTANT POINTS
============================================================

- Encapsulation = Data Hiding
- Achieved using private data members
- Access through public functions
- Improves maintainability
- Improves security
- Default access in class is private
============================================================
*/

/*
============================================================
8. COMMON MISTAKES
============================================================

- Making all members public
- Not validating input in setters
- Forgetting const in getter functions
- Returning private data incorrectly
============================================================
*/

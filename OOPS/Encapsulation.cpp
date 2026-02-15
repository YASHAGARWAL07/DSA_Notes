/************************************************************
 *  ENCAPSULATION IN C++
 *  Lecture Notes – OOPS Concept
 *  Useful for: Exams | Viva | Interviews
 ************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1️⃣ WHAT IS ENCAPSULATION?
============================================================

Encapsulation means:
➡ Wrapping Data (variables) and Methods (functions)
   into a single unit (Class).

In simple words:
Data + Functions = One Capsule (Class)

It is one of the 4 pillars of OOPS:
✔ Encapsulation
✔ Abstraction
✔ Inheritance
✔ Polymorphism
*/

/*
============================================================
2️⃣ WHY DO WE NEED ENCAPSULATION?
============================================================

✔ Data Hiding
✔ Security
✔ Control over data modification
✔ Better code structure
✔ Prevents accidental changes

Real-life Example:
ATM machine
You cannot directly access bank database.
You use buttons (interface).
*/

/*
============================================================
3️⃣ ACCESS SPECIFIERS (IMPORTANT)
============================================================

private   → Accessible only inside class
public    → Accessible everywhere
protected → Used in inheritance

Default access in class = private
*/

class BankAccount {
private:
    // 🔒 Data Hidden (Encapsulation)
    string name;
    int account_number;
    double balance;

public:
    /*
    --------------------------------------------------------
    4️⃣ CONSTRUCTOR
    --------------------------------------------------------
    */
    BankAccount(string name, int acc, double bal) {
        this->name = name;
        this->account_number = acc;
        this->balance = bal;
    }

    /*
    --------------------------------------------------------
    5️⃣ GETTER FUNCTIONS
    --------------------------------------------------------
    Used to READ private data
    */
    string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    /*
    --------------------------------------------------------
    6️⃣ SETTER FUNCTIONS
    --------------------------------------------------------
    Used to MODIFY private data safely
    */
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

    /*
    --------------------------------------------------------
    7️⃣ DISPLAY FUNCTION
    --------------------------------------------------------
    */
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Account No: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

/*
============================================================
8️⃣ MAIN FUNCTION – USAGE
============================================================
*/

int main() {

    BankAccount user1("Rohit", 101, 5000);

    user1.display();

    // Direct access NOT allowed
    // user1.balance = 100000; ❌ ERROR (private)

    user1.deposit(2000);
    user1.withdraw(1500);

    cout << "\nUpdated Balance: "
         << user1.getBalance() << endl;

    return 0;
}

/*
============================================================
9️⃣ HOW ENCAPSULATION PROVIDES SECURITY
============================================================

Without Encapsulation:

class Bad {
public:
    int balance;
};

Anyone can change balance directly ❌

With Encapsulation:

class Good {
private:
    int balance;
public:
    void deposit(int amount);
};

Now data is controlled ✔
*/

/*
============================================================
🔟 INTERVIEW IMPORTANT POINTS
============================================================

✔ Encapsulation = Data Hiding
✔ Achieved using private data members
✔ Access provided through public functions
✔ Improves maintainability
✔ Improves security

Difference Between Abstraction & Encapsulation:

Encapsulation:
    - Hides data
    - Implementation control

Abstraction:
    - Hides internal working
    - Shows only essential features
*/

/*
============================================================
COMMON MISTAKES
============================================================

❌ Making everything public
❌ Not validating input in setters
❌ Returning reference to private variable incorrectly
❌ Forgetting const in getter functions

============================================================
END OF NOTES ✔
============================================================
*/

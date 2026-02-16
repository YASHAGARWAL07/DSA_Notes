/**************************************************************
            EXCEPTION HANDLING IN C++
**************************************************************/

#include <iostream>
#include <stdexcept>   // For standard exceptions
using namespace std;

/*
============================================================
1. WHAT IS AN EXCEPTION ?
============================================================

An exception is an unexpected problem that occurs
during the execution of a program.

It interrupts the normal flow of the program.

Examples:
- Dividing by zero
- Invalid input
- Accessing invalid memory
- Withdrawing more money than balance

If not handled, program terminates abnormally.
*/

/*
============================================================
2. KEYWORDS USED IN EXCEPTION HANDLING
============================================================

1) try
2) throw
3) catch

------------------------------------------------------------
try:
    Block of code that may generate exception.

throw:
    Used to throw an exception.

catch:
    Used to handle the exception.
*/

/*
============================================================
3. BASIC SYNTAX
============================================================

try {
    // code that may throw exception
}
catch(type variable) {
    // code to handle exception
}
*/

/*
============================================================
4. SIMPLE EXAMPLE
============================================================
*/

void divide(int a, int b)
{
    if (b == 0)
        throw "Division by zero not allowed";

    cout << "Result = " << a / b << endl;
}

/*
============================================================
5. MULTIPLE CATCH BLOCKS
============================================================
*/

void checkNumber(int n)
{
    if (n < 0)
        throw -1;            // integer exception
    else if (n == 0)
        throw 0.0;           // double exception
    else
        cout << "Valid number\n";
}

/*
============================================================
6. STANDARD EXCEPTION CLASSES
============================================================

C++ provides built-in exception classes under:

    std::exception

Some common ones:

- std::runtime_error
- std::logic_error
- std::invalid_argument
- std::out_of_range
- std::overflow_error
- std::underflow_error
- std::bad_alloc
*/

/*
============================================================
7. USER-DEFINED EXCEPTION (IMPORTANT FOR LAB)
============================================================
*/

class InsufficientBalance : public runtime_error
{
public:
    InsufficientBalance(const string &msg)
        : runtime_error(msg) {}
};

class InvalidAmount : public runtime_error
{
public:
    InvalidAmount(const string &msg)
        : runtime_error(msg) {}
};

/*
============================================================
8. PRACTICAL EXAMPLE (BANK SYSTEM)
============================================================
*/

class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmount("Deposit amount must be positive");

        balance += amount;
        cout << "Deposit successful. Balance = " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmount("Withdrawal amount must be positive");

        if (amount > balance)
            throw InsufficientBalance("Insufficient balance");

        balance -= amount;
        cout << "Withdrawal successful. Balance = " << balance << endl;
    }
};

/*
============================================================
9. HOW EXCEPTION WORKS INTERNALLY
============================================================

Step 1: Code inside try block executes
Step 2: If error occurs → throw executes
Step 3: Program immediately stops current function
Step 4: Matching catch block is searched
Step 5: Catch block handles the error
Step 6: Program continues after catch block
*/

/*
============================================================
10. CATCH ALL HANDLER
============================================================

catch(...)
{
    // Handles any type of exception
}
*/

/*
============================================================
11. IMPORTANT RULES FOR EXAM
============================================================

✔ Code that may cause error must be inside try
✔ Catch block must match thrown type
✔ Multiple catch blocks allowed
✔ More specific catch must come first
✔ Use const reference in catch for efficiency:

   catch(const runtime_error &e)

✔ e.what() gives error message
*/

/*
============================================================
12. ADVANTAGES OF EXCEPTION HANDLING
============================================================

- Separates error handling from main logic
- Improves program reliability
- Prevents abrupt termination
- Makes debugging easier
*/

/*
============================================================
13. COMPLETE MAIN FUNCTION DEMO
============================================================
*/

int main()
{
    cout << "---- Basic Example ----\n";
    try {
        divide(10, 0);
    }
    catch (const char *msg) {
        cout << "Exception: " << msg << endl;
    }

    cout << "\n---- Multiple Catch Example ----\n";
    try {
        checkNumber(0);
    }
    catch (int) {
        cout << "Negative number exception\n";
    }
    catch (double) {
        cout << "Zero not allowed\n";
    }

    cout << "\n---- Bank Account Example ----\n";
    BankAccount acc("Yash", 5000);

    try {
        acc.deposit(1000);
        acc.withdraw(7000);
    }
    catch (const InvalidAmount &e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const InsufficientBalance &e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown exception occurred\n";
    }

    cout << "\nProgram continues normally.\n";

    return 0;
}

/**************************************************************
                    END OF NOTES
**************************************************************/

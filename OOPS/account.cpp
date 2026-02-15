#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    static const double minimumBalance;   // Minimum balance required

public:

    // Constructor
    BankAccount(int accNo, double initialBalance) {
        accountNumber = accNo;

        if (initialBalance >= minimumBalance) {
            balance = initialBalance;
        } else {
            cout << "Initial balance too low! "
                 << "Setting balance to minimum ₹"
                 << minimumBalance << endl;
            balance = minimumBalance;
        }
    }

    // Deposit Function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw Function
    void withdraw(double amount) {

        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return;
        }

        if (balance - amount < minimumBalance) {
            cout << "Withdrawal denied! "
                 << "Minimum balance ₹" << minimumBalance
                 << " must be maintained.\n";
        }
        else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
    }

    // Display Account Details
    void display() const {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

// Define static member outside class
const double BankAccount::minimumBalance = 1000.0;

int main() {

    BankAccount acc1(101, 5000);

    acc1.display();

    acc1.deposit(2000);
    acc1.withdraw(5500);  // Should fail
    acc1.withdraw(3000);  // Should succeed

    acc1.display();

    return 0;
}


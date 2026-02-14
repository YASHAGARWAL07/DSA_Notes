/*
===========================================================
        CONSTRUCTORS IN C++  (Lecture 71 Notes)
===========================================================

👉 Constructor:
- A special member function of a class
- Same name as class
- No return type (not even void)
- Automatically called when object is created
- Used to initialize data members

-----------------------------------------------------------
1️⃣ DEFAULT CONSTRUCTOR
-----------------------------------------------------------
- Takes no arguments
- Called when object is created without parameters
- If we do not create any constructor, compiler creates
  a default constructor automatically
*/

#include <iostream>
using namespace std;

class Customer {
    string name;
    int account_number;
    int balance;

public:

    // ✅ Default Constructor
    Customer() {
        name = "Rohit";
        account_number = 5;
        balance = 100;
    }

/*
-----------------------------------------------------------
2️⃣ PARAMETERIZED CONSTRUCTOR
-----------------------------------------------------------
- Takes parameters
- Used to initialize object with custom values
*/

    Customer(string a, int b, int c) {
        name = a;
        account_number = b;
        balance = c;
    }

/*
-----------------------------------------------------------
3️⃣ CONSTRUCTOR USING this POINTER
-----------------------------------------------------------
- Used when parameter names and data members are same
- this → points to current object
*/

    Customer(string name, int account_number) {
        this->name = name;
        this->account_number = account_number;
        this->balance = 50;   // default balance
    }

/*
-----------------------------------------------------------
4️⃣ CONSTRUCTOR OVERLOADING
-----------------------------------------------------------
- Multiple constructors with different parameter lists
- Decided at compile time
*/

    // Overloaded constructor already shown above

/*
-----------------------------------------------------------
5️⃣ INLINE CONSTRUCTOR
-----------------------------------------------------------
- Defined inside class
- Usually short and simple
*/

    inline Customer(string a, int b, int c, bool flag)
        : name(a), account_number(b), balance(c) {
        // initializer list is faster than assignment
    }

/*
-----------------------------------------------------------
6️⃣ DISPLAY FUNCTION
-----------------------------------------------------------
*/

    void display() {
        cout << name << " "
             << account_number << " "
             << balance << endl;
    }

/*
-----------------------------------------------------------
7️⃣ COPY CONSTRUCTOR
-----------------------------------------------------------
- Used to copy data from one object to another
- Called when:
  ✔ Object is passed by value
  ✔ Object is returned by value
  ✔ Object is initialized using another object

⚠ Default copy constructor does SHALLOW COPY
*/

    // ✅ User-defined Copy Constructor
    Customer(Customer &B) {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }
};

/*
-----------------------------------------------------------
8️⃣ MAIN FUNCTION
-----------------------------------------------------------
*/

int main() {

    // Default constructor
    Customer A1;

    // Parameterized constructor
    Customer A2("Rohit", 23, 1000);

    // Constructor overloading
    Customer A3("Mohit", 25);

    // Copy constructor
    Customer A4(A3);

    A1.display();
    A2.display();
    A3.display();
    A4.display();

    return 0;
}

/*
===========================================================
IMPORTANT INTERVIEW POINTS
===========================================================

✔ Constructor name = class name
✔ Constructor has no return type
✔ Constructor can be overloaded
✔ Constructor can be inline
✔ Copy constructor argument must be passed by reference
✔ If copy constructor is not written, compiler creates one
✔ Shallow copy problem occurs with pointers
✔ Deep copy required when dynamic memory is used

===========================================================
*/

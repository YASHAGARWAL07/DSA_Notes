/*
===========================================================
   DESTRUCTOR + CALL ORDER OF CONSTRUCTOR & DESTRUCTOR
                    (C++ OOPS NOTES)
===========================================================

-----------------------------------------------------------
1️⃣ DESTRUCTOR
-----------------------------------------------------------

Destructor:
- Special member function of a class
- Name is same as class name, prefixed with '~'
- Has NO return type
- Takes NO arguments
- Automatically called when object is destroyed
- Used to free resources (memory, file, DB connection, etc.)

Syntax:
~ClassName() {
    // cleanup code
}

-----------------------------------------------------------
2️⃣ WHY DESTRUCTOR IS REQUIRED?
-----------------------------------------------------------

- To avoid MEMORY LEAK
- To release dynamically allocated memory
- To perform final cleanup before object destruction
- Constructor allocates → Destructor deallocates

-----------------------------------------------------------
3️⃣ WHEN IS DESTRUCTOR CALLED?
-----------------------------------------------------------

1) Stack object → automatically when scope ends
2) Heap object  → only when delete is used
3) Program end → for static / global objects

-----------------------------------------------------------
4️⃣ STACK vs HEAP OBJECTS
-----------------------------------------------------------

Stack Object:
- Created normally
- Destructor called automatically
- No memory leak

Heap Object:
- Created using new
- Destructor NOT called automatically
- Must use delete
- Risk of memory leak

-----------------------------------------------------------
5️⃣ EXAMPLE: DESTRUCTOR WITH DYNAMIC MEMORY
-----------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Customer {
    string name;
    int *data;   // dynamic memory

public:
    // Constructor
    Customer(string name) {
        this->name = name;
        data = new int;     // memory allocation
        *data = 10;
        cout << "Constructor is called for " << name << endl;
    }

    // Destructor
    ~Customer() {
        delete data;        // memory deallocation
        cout << "Destructor is called for " << name << endl;
    }
};

int main() {

    cout << "----- STACK OBJECTS -----" << endl;

    Customer A1("1");
    Customer A2("2");
    Customer A3("3");

    cout << "----- HEAP OBJECT -----" << endl;

    Customer *A4 = new Customer("4");
    delete A4;   // Destructor called manually

    return 0;
}

/*
-----------------------------------------------------------
6️⃣ CALL ORDER OF CONSTRUCTOR
-----------------------------------------------------------

Code:
Customer A1("1"), A2("2"), A3("3");

Output:
Constructor is called for 1
Constructor is called for 2
Constructor is called for 3

➡ Constructor is called in SAME ORDER as object creation

-----------------------------------------------------------
7️⃣ CALL ORDER OF DESTRUCTOR (STACK OBJECTS)
-----------------------------------------------------------

Output:
Destructor is called for 3
Destructor is called for 2
Destructor is called for 1

➡ Destructor follows LIFO (Last In First Out)
➡ Reverse order of constructor calls

-----------------------------------------------------------
8️⃣ CALL ORDER OF DESTRUCTOR (HEAP OBJECT)
-----------------------------------------------------------

Customer *A4 = new Customer("4");

❌ Destructor NOT called automatically

delete A4;
✔ Destructor is called here

-----------------------------------------------------------
9️⃣ IMPORTANT RULES (EXAM / VIVA)
-----------------------------------------------------------

✔ Destructor name = ~ClassName
✔ No return type, no parameters
✔ One class → only one destructor
✔ Destructor is called automatically for stack objects
✔ Destructor must be called manually for heap objects
✔ delete → calls destructor
✔ new → calls constructor

-----------------------------------------------------------
🔟 COMMON MISTAKES
-----------------------------------------------------------

❌ Forgetting delete for heap objects
❌ Memory leak due to missing destructor
❌ Using delete instead of delete[] for arrays
❌ Assuming destructor runs automatically for heap memory

-----------------------------------------------------------
⭐ ONE-LINE SUMMARY
-----------------------------------------------------------

Constructor allocates resources.
Destructor releases resources.
Stack → automatic cleanup.
Heap → manual cleanup using delete.
===========================================================
*/

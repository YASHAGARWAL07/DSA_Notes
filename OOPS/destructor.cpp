/************************************************************
        DESTRUCTOR + CALL ORDER (C++ OOPS)
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. DESTRUCTOR
------------------------------------------------------------
Destructor is a special member function of a class.

Characteristics:
- Same name as class
- Prefixed with '~'
- No return type
- No parameters
- Automatically called when object is destroyed
- Used for cleanup of resources

Syntax:
~ClassName() {
    // cleanup code
}
============================================================
*/

/*
============================================================
2. WHY DESTRUCTOR IS REQUIRED
------------------------------------------------------------
- To prevent memory leak
- To release dynamically allocated memory
- To close files / database connections
- To free system resources

Constructor allocates resources.
Destructor releases resources.
============================================================
*/

/*
============================================================
3. WHEN IS DESTRUCTOR CALLED
------------------------------------------------------------
1) Stack object  -> Automatically when scope ends
2) Heap object   -> Only when delete is used
3) Global/static -> When program ends
============================================================
*/

/*
============================================================
4. STACK VS HEAP OBJECTS
------------------------------------------------------------

Stack Object:
- Created normally
- Destructor called automatically
- Safe, no manual cleanup required

Heap Object:
- Created using new
- Destructor NOT called automatically
- Must use delete
- Risk of memory leak if delete is forgotten
============================================================
*/

/*
============================================================
5. EXAMPLE: DESTRUCTOR WITH DYNAMIC MEMORY
============================================================
*/

class Customer {
    string name;
    int *data;

public:
    Customer(string name) {
        this->name = name;
        data = new int;
        *data = 10;
        cout << "Constructor called for " << name << endl;
    }

    ~Customer() {
        delete data;
        cout << "Destructor called for " << name << endl;
    }
};

int main() {

    cout << "---- STACK OBJECTS ----" << endl;

    Customer A1("1");
    Customer A2("2");
    Customer A3("3");

    cout << "---- HEAP OBJECT ----" << endl;

    Customer *A4 = new Customer("4");
    delete A4;   // Destructor called here

    return 0;
}

/*
============================================================
6. CALL ORDER OF CONSTRUCTOR
------------------------------------------------------------

Customer A1("1"), A2("2"), A3("3");

Output:
Constructor called for 1
Constructor called for 2
Constructor called for 3

Rule:
Constructors are called in the SAME ORDER
as object creation.
============================================================
*/

/*
============================================================
7. CALL ORDER OF DESTRUCTOR (STACK OBJECTS)
------------------------------------------------------------

Output:
Destructor called for 3
Destructor called for 2
Destructor called for 1

Rule:
Destructors follow LIFO (Last In First Out)
Reverse order of constructor calls.
============================================================
*/

/*
============================================================
8. CALL ORDER OF DESTRUCTOR (HEAP OBJECT)
------------------------------------------------------------

Customer *A4 = new Customer("4");

Destructor will NOT run automatically.

delete A4;

Now destructor is called.

Important:
new    -> calls constructor
delete -> calls destructor
============================================================
*/

/*
============================================================
9. IMPORTANT RULES
------------------------------------------------------------
- Destructor name = ~ClassName
- No return type
- No parameters
- One class has only one destructor
- Called automatically for stack objects
- Must use delete for heap objects
- delete[] required for dynamic arrays
============================================================
*/

/*
============================================================
10. COMMON MISTAKES
------------------------------------------------------------
- Forgetting delete for heap memory
- Causing memory leak
- Using delete instead of delete[] for arrays
- Assuming destructor runs for heap automatically
============================================================
*/

/*
============================================================
FINAL SUMMARY
------------------------------------------------------------
Constructor allocates resources.
Destructor releases resources.

Stack -> Automatic cleanup.
Heap  -> Manual cleanup using delete.
============================================================
*/

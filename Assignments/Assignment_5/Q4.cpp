#include<iostream>

using namespace std;

// A structure to represent a complex number
struct Complex
{
    double real;
    double imag;
};

// A helper function to print a complex number nicely
void printComplex(Complex c)
{
    cout << c.real;
    if (c.imag >= 0) {
        cout << " + " << c.imag << "i";
    } else {
        cout << " - " << -c.imag << "i";
    }
}

struct Stack
{
private:
    Complex *arr; // The array will store Complex objects
    int top;
    int size;

public:
    // Constructor to create the stack with a user-defined size
    Stack(int s)
    {
        size = s;
        arr = new Complex[size]; // Dynamically allocate an array of Complex objects
        top = -1;
        cout << "Stack for Complex numbers created with size: " << size << endl;
    }

    // Destructor to free the allocated memory
    ~Stack()
    {
        delete[] arr;
        cout << "\nStack destroyed and memory freed." << endl;
    }

    // Function to check if the stack is empty
    bool IsEmpty()
    {
        return top == -1;
    }

    // Function to check if the stack is full
    bool IsFull()
    {
        return top == size - 1;
    }

    // Function to add a Complex number to the stack
    void push(Complex c)
    {
        if (IsFull())
        {
            cout << "Stack Overflow! Cannot push ";
            printComplex(c);
            cout << "." << endl;
            return;
        }
        top++;
        arr[top] = c;
        cout << "Data (";
        printComplex(c);
        cout << ") added to stack." << endl;
    }

    // Function to remove a Complex number from the stack
    Complex pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return {0, 0}; // Return a default Complex number on error
        }
        Complex c = arr[top];
        top--;
        cout << "Data (";
        printComplex(c);
        cout << ") removed from stack." << endl;
        return c;
    }

    // Function to return the top Complex number
    Complex TOP()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty." << endl;
            return {0, 0}; // Return a default Complex number on error
        }
        cout << "Top element is: ";
        printComplex(arr[top]);
        cout << endl;
        return arr[top];
    }
};

int main()
{
    Stack s1(3);

    // Create some complex numbers
    Complex c1 = {5.0, 3.2};
    Complex c2 = {-2.0, 1.5};
    Complex c3 = {4.0, -2.0};

    s1.push(c1);
    s1.push(c2);
    s1.push(c3);

    s1.TOP();
    s1.pop();
    s1.TOP();
    s1.pop();
    s1.pop();
    s1.pop(); // This will show underflow

    return 0;
}

#include<iostream>

using namespace std;

struct Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    // Constructor to create the stack with a user-defined size
    Stack(int s)
    {
        size = s;
        arr = new int[size]; // Dynamically allocate array
        top = -1;
        cout << "Stack created with dynamic size: " << size << endl;
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

    // Function to add an element to the stack
    void push(int d)
    {
        if (IsFull())
        {
            cout << "Stack Overflow! Cannot push " << d << "." << endl;
            return;
        }
        top++;
        arr[top] = d;
        cout << "Data " << d << " added to stack." << endl;
    }

    // Function to remove an element from the stack
    int pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return -999; // Error value
        }
        int d = arr[top];
        top--;
        cout << "Data " << d << " removed from stack." << endl;
        return d;
    }

    // Function to return the top element
    int TOP()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty." << endl;
            return -999; // Error value
        }
        cout << "Top element is: " << arr[top] << endl;
        return arr[top];
    }
};

int main()
{
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    Stack s1(stackSize);
    s1.push(100);
    s1.push(200);
    s1.TOP();
    s1.pop();
    s1.pop();
    s1.pop(); // Shows underflow

    return 0;
}
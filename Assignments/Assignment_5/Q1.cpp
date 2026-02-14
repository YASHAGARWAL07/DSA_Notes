#include<iostream>
#define MAX_SIZE 10 // Defines the maximum size of the stack

using namespace std;

struct Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor to create the stack
    Stack()
    {
        top = -1; // Initialize top to -1 to indicate an empty stack
        cout << "Stack created using an array." << endl;
    }

    // Function to check if the stack is empty
    bool IsEmpty()
    {
        return top == -1;
    }

    // Function to check if the stack is full
    bool IsFull()
    {
        return top == MAX_SIZE - 1;
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

    // Function to return the top element without removing it
    int peak()
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
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.peak();
    s1.pop();
    s1.peak();
    s1.pop();
    s1.pop();
    s1.pop(); // This will show underflow

    return 0;
}

#include<iostream>

using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

struct Stack
{
private:
    Node *top;

public:
    // Constructor to create the stack
    Stack()
    {
        top = NULL;
        cout << "Stack created using a linked list." << endl;
    }

    // Function to check if the stack is empty
    bool IsEmpty()
    {
        return top == NULL;
    }

    // Function to check if the stack is full
    // A linked list stack is full only when heap memory is exhausted.
    // So, we can assume it's never full for practical purposes.
    bool IsFull()
    {
        return false;
    }


    // Function to add an element to the stack [cite: 20]
    void push(int d)
    {
        Node *temp = new Node;
        // Check for heap overflow
        if (!temp) {
            cout << "Heap Overflow! Cannot create new node." << endl;
            return;
        }
        temp->data = d;
        temp->next = top;
        top = temp;
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
        int d = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
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
        cout << "Top element is: " << top->data << endl;
        return top->data;
    }
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.TOP();
    s1.pop();
    s1.TOP();
    s1.pop();
    s1.pop();
    s1.pop(); // This will show underflow

    return 0;
}
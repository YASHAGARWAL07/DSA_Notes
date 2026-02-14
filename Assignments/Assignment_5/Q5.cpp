#include<iostream>
#include<string>
#define MAX_SIZE 100

using namespace std;

// Using the array-based stack from Question 1
struct Stack
{
private:
    char arr[MAX_SIZE]; // Stack of characters
    int top;

public:
    Stack() { top = -1; }
    bool IsEmpty() { return top == -1; }
    bool IsFull() { return top == MAX_SIZE - 1; }
    void push(char c)
    {
        if (IsFull()) return;
        arr[++top] = c;
    }
    char pop()
    {
        if (IsEmpty()) return '\0'; // Return null char on underflow
        return arr[top--];
    }
};

bool areParenthesesBalanced(string expr)
{
    Stack s;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(')
        {
            s.push(expr[i]);
        }
        else if (expr[i] == ')')
        {
            if (s.IsEmpty())
            {
                // Found a closing bracket with no matching opening one
                return false;
            }
            s.pop();
        }
    }
    // If stack is empty, all brackets were matched
    return s.IsEmpty();
}

int main()
{
    string expression1 = "((a+b)*(c-d))";
    if (areParenthesesBalanced(expression1))
        cout << "Expression '" << expression1 << "' is balanced." << endl;
    else
        cout << "Expression '" << expression1 << "' is not balanced." << endl;

    string expression2 = "(a+b)*(c-d)))";
     if (areParenthesesBalanced(expression2))
        cout << "Expression '" << expression2 << "' is balanced." << endl;
    else
        cout << "Expression '" << expression2 << "' is not balanced." << endl;

    return 0;
}
#include<iostream>
#include<string>
#define MAX_SIZE 100

using namespace std;

// The Stack struct remains exactly the same as before
struct Stack
{
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }
    bool IsEmpty() { return top == -1; }
    bool IsFull() { return top == MAX_SIZE - 1; }
    void push(char c) { if (!IsFull()) arr[++top] = c; }
    char pop() { return IsEmpty() ? '\0' : arr[top--]; }
    char peak() { return IsEmpty() ? '\0' : arr[top]; }
};

// Function to check if parentheses are balanced using if-else if
bool areParenthesesBalanced(string expr)
{
    Stack s;

    for (int i = 0; i < expr.length(); i++)
    {
        char currentChar = expr[i];

        // If it's an opening bracket, push it
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            s.push(currentChar);
        }
        // If it's a closing bracket, check for a match
        else if (currentChar == ')') {
            if (s.IsEmpty() || s.pop() != '(') return false;
        }
        else if (currentChar == '}') {
            if (s.IsEmpty() || s.pop() != '{') return false;
        }
        else if (currentChar == ']') {
            if (s.IsEmpty() || s.pop() != '[') return false;
        }
    }

    // If the stack is empty at the end, it's balanced
    return s.IsEmpty();
}

int main()
{
    string expression = "{a+[b*(c-d)]}";
    if (areParenthesesBalanced(expression))
        cout << "Expression '" << expression << "' is balanced." << endl;
    else
        cout << "Expression '" << expression << "' is not balanced." << endl;

    string expression2 = "[(])";
     if (areParenthesesBalanced(expression2))
        cout << "Expression '" << expression2 << "' is balanced." << endl;
    else
        cout << "Expression '" << expression2 << "' is not balanced." << endl;

    return 0;
}

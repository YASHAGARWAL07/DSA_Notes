/*
============================================================
STACK DATA STRUCTURE – COMPLETE NOTES
============================================================
*/

#include <iostream>
#include <stack>
using namespace std;


/*
------------------------------------------------------------
1. INTRODUCTION TO STACK
------------------------------------------------------------

A Stack is a linear data structure that follows:

LIFO Principle
(LAST IN FIRST OUT)

Meaning:
The element inserted last will be removed first.

Example:

Push operations:
1 -> 2 -> 3 -> 4

Stack (top at right):

1 2 3 4
      ↑
     top

Pop operation removes:

4 -> 3 -> 2 -> 1


Real Life Examples:

1) Stack of plates
2) Undo/Redo operations
3) Browser back/forward
4) Function call stack
*/


/*
------------------------------------------------------------
2. BASIC OPERATIONS
------------------------------------------------------------

push(x)
Insert element at top

pop()
Remove top element

top()
Return top element

empty()
Check if stack is empty

size()
Return number of elements
*/


/*
============================================================
3. IMPLEMENTATION USING ARRAY
============================================================

Idea:

Maintain:
top pointer

top = -1 initially

Push:
increment top
insert element

Pop:
return element
decrement top
*/


class StackArray
{
    int arr[100];
    int top;

public:

    StackArray()
    {
        top = -1;
    }

    void push(int x)
    {
        if(top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        top--;
    }

    int Top()
    {
        if(top == -1)
            return -1;

        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }
};


/*
============================================================
4. IMPLEMENTATION USING LINKED LIST
============================================================

Push → Insert at head

Pop → Delete head

Top → head->data

Time Complexity:
Push → O(1)
Pop → O(1)
*/


class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class StackLL
{
    Node* head;

public:

    StackLL()
    {
        head = NULL;
    }

    void push(int x)
    {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void pop()
    {
        if(head == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top()
    {
        if(head == NULL)
            return -1;

        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};


/*
============================================================
5. IMPLEMENTATION USING STL STACK
============================================================

C++ provides built-in stack library.

Header:

#include <stack>
*/


void STLStackDemo()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    if(st.empty())
        cout << "Stack Empty\n";
    else
        cout << "Stack Not Empty\n";
}


/*
============================================================
6. TIME COMPLEXITY ANALYSIS
============================================================

Operation      Time Complexity

Push           O(1)
Pop            O(1)
Top            O(1)
Empty          O(1)
Size           O(1)

Stack is extremely efficient
because operations happen only at top.
*/


/*
============================================================
7. IMPORTANT APPLICATIONS OF STACK
============================================================

1) Balanced Parentheses

Example:
{[()]}

2) Expression Conversion

Infix → Postfix
Infix → Prefix

3) Expression Evaluation

Postfix evaluation

4) Function Calls (Recursion)

Call stack stores:

local variables
return addresses

5) Undo / Redo operations

6) Backtracking algorithms
*/


/*
============================================================
8. COMMON INTERVIEW QUESTIONS
============================================================

1) Implement stack using queue

2) Implement queue using stack

3) Next Greater Element

4) Largest Rectangle in Histogram

5) Valid Parentheses

6) Min Stack

7) Reverse a stack

8) Sort a stack using recursion
*/


/*
============================================================
9. MAIN FUNCTION (DEMO)
============================================================
*/

int main()
{
    cout << "Stack using Array\n";

    StackArray s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.Top() << endl;

    s.pop();

    cout << "Top after pop: " << s.Top() << endl;

    cout << "\nStack using Linked List\n";

    StackLL s2;

    s2.push(5);
    s2.push(15);
    s2.push(25);

    cout << "Top: " << s2.top() << endl;

    s2.pop();

    cout << "Top after pop: " << s2.top() << endl;

    cout << "\nStack using STL\n";

    STLStackDemo();

    return 0;
}


/*
============================================================
SUMMARY
============================================================

Stack follows LIFO principle.

Three main implementations:

1) Array
2) Linked List
3) STL stack

Most interview problems use stack
for solving monotonic or recursive problems.

============================================================
END
============================================================
*/

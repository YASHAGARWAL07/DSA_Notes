/*
    Time and Space Complexity
    Complete Detailed Notes (Basics + Recursion Analysis)
*/

#include <iostream>
using namespace std;


/*
---------------------------------------------------------
Time Complexity
---------------------------------------------------------

Time complexity measures how running time increases
as input size (n) increases.

We do NOT measure seconds.
We measure number of operations relative to n.

Focus is on growth rate.
*/


/*
---------------------------------------------------------
Big-O Notation
---------------------------------------------------------

Big-O represents worst case complexity.

Common orders:

O(1)        constant
O(log n)    logarithmic
O(n)        linear
O(n log n)  linearithmic
O(n^2)      quadratic
O(2^n)      exponential
O(n!)       factorial

As n becomes large:

O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n)
*/


/*
---------------------------------------------------------
Example 1: Constant Time
---------------------------------------------------------
*/

int getFirst(int arr[])
{
    return arr[0];
}

/*
Only one operation.
Time = O(1)
*/


/*
---------------------------------------------------------
Example 2: Linear Time
---------------------------------------------------------
*/

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

/*
Loop runs n times.
Time = O(n)
*/


/*
---------------------------------------------------------
Example 3: Quadratic Time
---------------------------------------------------------
*/

void printPairs(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << arr[i] << "," << arr[j] << endl;
}

/*
Total operations = n * n
Time = O(n^2)
*/


/*
---------------------------------------------------------
Binary Search (Iterative)
---------------------------------------------------------
*/

int binarySearchIterative(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

/*
Each iteration halves the search space.

n → n/2 → n/4 → n/8 ...

Total steps = log n

Time = O(log n)
Space = O(1)
*/


/*
---------------------------------------------------------
Binary Search (Recursive)
---------------------------------------------------------
*/

int binarySearchRecursive(int arr[], int start, int end, int key)
{
    if(start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if(arr[mid] == key)
        return mid;
    else if(key > arr[mid])
        return binarySearchRecursive(arr, mid + 1, end, key);
    else
        return binarySearchRecursive(arr, start, mid - 1, key);
}

/*
Recurrence:

T(n) = T(n/2) + 1

Height of recursion tree = log n

Time = O(log n)

Space = O(log n)
Because recursion stack depth ≈ log n
*/


/*
---------------------------------------------------------
Space Complexity
---------------------------------------------------------

Space complexity measures extra memory used.

Two types:
1) Input space
2) Auxiliary space

We usually calculate auxiliary space.
*/


/*
---------------------------------------------------------
Recursion Stack Concept
---------------------------------------------------------

In recursion, each function call is stored in call stack.

Example:

factorial(5)
factorial(4)
factorial(3)
factorial(2)
factorial(1)

Total depth = 5

Space = O(n)
*/


int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}


/*
---------------------------------------------------------
Fibonacci Recursion (Important)
---------------------------------------------------------
*/

int fib(int n)
{
    if(n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}

/*
Recurrence:

T(n) = T(n-1) + T(n-2) + 1

If we draw recursion tree:

Level 0 → 1 node
Level 1 → 2 nodes
Level 2 → 4 nodes
Level 3 → 8 nodes
...

It approximately doubles.

Total nodes ≈

1 + 2 + 4 + 8 + ... + 2^(n-1)

This is geometric series.

Sum = 2^n - 1

Time Complexity = O(2^n)

Space Complexity = O(n)
(Maximum depth of stack = n)
*/


/*
---------------------------------------------------------
Sum of Array using Recursion
---------------------------------------------------------
*/

int sumArray(int arr[], int index, int n)
{
    if(index == n)
        return 0;

    return arr[index] + sumArray(arr, index+1, n);
}

/*
Recurrence:

T(n) = T(n-1) + 1

Total calls = n

Time = O(n)
Space = O(n)
*/


/*
---------------------------------------------------------
When Recursion Becomes O(n^2)
---------------------------------------------------------

If:

T(n) = T(n-1) + n

Then total work:

n + (n-1) + (n-2) + ... + 1

= n(n+1)/2

= O(n^2)
*/


/*
---------------------------------------------------------
General Recursion Patterns
---------------------------------------------------------

1) T(n) = T(n-1) + c
   → O(n)

2) T(n) = T(n/2) + c
   → O(log n)

3) T(n) = 2T(n/2) + n
   → O(n log n)

4) T(n) = 2T(n-1)
   → O(2^n)
*/


/*
---------------------------------------------------------
Master Theorem (Basic Idea)
---------------------------------------------------------

If:

T(n) = aT(n/b) + f(n)

Compare:

n^(log_b a)  and  f(n)

Used in:
Merge Sort
Quick Sort
Divide & Conquer algorithms
*/


/*
Merge Sort:

T(n) = 2T(n/2) + n

Levels = log n
Work per level = n

Total = n log n

Time = O(n log n)
Space = O(n)
*/


/*
---------------------------------------------------------
Amortized Complexity
---------------------------------------------------------

Example:
vector push_back()

Sometimes resizing costs O(n),
but average cost per operation = O(1)

This is amortized O(1)
*/


/*
---------------------------------------------------------
Time vs Space Tradeoff
---------------------------------------------------------

Using extra space can reduce time.

Example:
Brute force two sum → O(n^2)
Using hashmap → O(n)
But space increases to O(n)
*/


/*
---------------------------------------------------------
Best, Average, Worst Case
---------------------------------------------------------

Best case → minimum operations
Worst case → maximum operations
Average case → expected operations

Big-O usually represents worst case.
*/


/*
---------------------------------------------------------
Important Comparisons
---------------------------------------------------------

Linear Search
Time = O(n)
Space = O(1)

Binary Search
Time = O(log n)
Space = O(1) iterative
Space = O(log n) recursive

Fibonacci (naive recursion)
Time = O(2^n)
Space = O(n)

Merge Sort
Time = O(n log n)
Space = O(n)

Bubble Sort
Time = O(n^2)
Space = O(1)
*/


int main()
{
    cout << "Time and Space Complexity Complete Notes Loaded" << endl;
    return 0;
}

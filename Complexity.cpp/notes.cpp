/*
Time and Space Complexity
*/

#include <iostream>
#include <vector>
using namespace std;


/*
Time Complexity

Measures how running time grows with input size n.
We count operations relative to n (not seconds).
Focus is on growth rate.
*/


/*
Big-O Notation (Worst Case)

O(1)        constant
O(log n)    logarithmic
O(n)        linear
O(n log n)  linearithmic
O(n^2)      quadratic
O(2^n)      exponential
O(n!)       factorial
*/


/*
Best, Average, Worst Case

Best Case    → Minimum operations
Worst Case   → Maximum operations
Average Case → Expected operations

Big-O usually represents worst case.
*/


/*
Growth Order

O(1) < O(log n) < O(n) < O(n log n)
< O(n^2) < O(2^n) < O(n!)
*/


/*
Example 1: Constant Time
*/

int getFirst(int arr[])
{
    return arr[0];
}

/*
Time = O(1)
Space = O(1)
*/


/*
Example 2: Linear Time
*/

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

/*
Loop runs n times
Time = O(n)
Space = O(1)
*/


/*
Example 3: Quadratic Time
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
Space = O(1)
*/


/*
Logarithmic Time Example
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
Each step halves the search space.

Time = O(log n)
Space = O(1)
*/


/*
Recursive Binary Search
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

Height = log n

Time = O(log n)
Space = O(log n)   // recursion stack
*/


/*
Space Complexity

Measures extra memory used by algorithm.

Two types:
1) Input Space
2) Auxiliary Space (extra memory used)

We usually calculate auxiliary space.
*/


/*
Recursion Stack Example
*/

int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}

/*
Recurrence:
T(n) = T(n-1) + 1

Total calls = n

Time = O(n)
Space = O(n)   // recursion depth
*/


/*
Fibonacci (Naive Recursion)
*/

int fib(int n)
{
    if(n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}

/*
Recurrence:
T(n) = T(n-1) + T(n-2)

Tree expands exponentially.

Time = O(2^n)
Space = O(n)
*/


/*
Sum of Array using Recursion
*/

int sumArray(int arr[], int index, int n)
{
    if(index == n)
        return 0;

    return arr[index] + sumArray(arr, index+1, n);
}

/*
T(n) = T(n-1) + 1

Time = O(n)
Space = O(n)
*/


/*
When Recursion Becomes O(n^2)

If:
T(n) = T(n-1) + n

Total work:
n + (n-1) + ... + 1
= n(n+1)/2
= O(n^2)
*/


/*
Divide and Conquer Pattern

Example: Merge Sort

T(n) = 2T(n/2) + n

Height = log n
Work per level = n

Time = O(n log n)
Space = O(n)
*/


/*
General Recursion Patterns

T(n) = T(n-1) + c        → O(n)
T(n) = T(n/2) + c        → O(log n)
T(n) = 2T(n/2) + n       → O(n log n)
T(n) = 2T(n-1)           → O(2^n)
*/


/*
Master Theorem (Basic Idea)

If:
T(n) = aT(n/b) + f(n)

Compare:
n^(log_b a)  and  f(n)

Used in:
Merge Sort
Quick Sort
Divide & Conquer
*/


/*
Amortized Complexity

Example: vector push_back()

Occasionally resizing costs O(n),
but average cost per operation = O(1)

This is amortized O(1).
*/


/*
Time vs Space Tradeoff

Brute Force Two Sum → O(n^2)
Using Hashmap       → O(n)

Time improves,
Space increases to O(n)
*/


/*
Important Comparisons

Linear Search
Time = O(n)
Space = O(1)

Binary Search
Time = O(log n)
Space = O(1) iterative
Space = O(log n) recursive

Fibonacci (naive)
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
    cout << "Time and Space Complexity Notes Loaded" << endl;
    return 0;
}
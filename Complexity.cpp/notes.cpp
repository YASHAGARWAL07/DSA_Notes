/*
    Time and Space Complexity
*/

#include <iostream>
using namespace std;


/*
Time Complexity

Time complexity measures how the running time of an algorithm
grows as input size (n) increases.

We do NOT measure actual time in seconds.
We measure number of operations relative to n.

Focus is on growth rate.
*/


/*
Big-O Notation

Big-O represents worst case complexity.

Common complexities:

O(1)        constant
O(log n)    logarithmic
O(n)        linear
O(n log n)  linearithmic
O(n^2)      quadratic
O(2^n)      exponential
O(n!)       factorial

As n becomes very large:

O(1) < O(log n) < O(n) < O(n log n) < O(n^2)
*/


/*
Example 1: Constant Time
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
Example 2: Linear Time
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
Example 3: Quadratic Time
*/

void printPairs(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << arr[i] << "," << arr[j] << endl;
}

/*
Outer loop runs n times.
Inner loop runs n times.
Total operations = n * n.
Time = O(n^2)
*/


/*
Binary Search (Iterative)
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
Time = O(log n)

Space = O(1)
Only few variables used.
*/


/*
Binary Search (Recursive)
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
Time = O(log n)

Space = O(log n)

Reason:
Recursion stack depth ≈ log n
Each recursive call is stored in stack memory.
*/


/*
Space Complexity

Space complexity measures extra memory used.

Two types:
1. Input space
2. Auxiliary space

We usually calculate auxiliary space.
*/


/*
Recursion Stack Concept

In recursion, every function call is stored in call stack.

Example:
factorial(5)
factorial(4)
factorial(3)
factorial(2)
factorial(1)

Total calls = 5

Space = O(n)
*/


int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}


/*
Tail Recursion

If recursive call is the last statement,
it is called tail recursion.

Example:
*/

int factorialTail(int n, int result)
{
    if(n == 0)
        return result;

    return factorialTail(n - 1, n * result);
}

/*
Tail recursion can be optimized by compiler.
May reduce stack usage in some languages.
*/


/*
How to Calculate Recursion Time Complexity

Example 1:
T(n) = T(n-1) + 1
Time = O(n)

Example 2:
T(n) = 2T(n/2) + n
This is divide and conquer.
Time = O(n log n)
*/


/*
Master Theorem (Basic Idea)

If recurrence is:

T(n) = aT(n/b) + f(n)

Then compare:
n^(log_b a) and f(n)

Used in:
Merge Sort
Quick Sort
Binary Search Tree
*/


/*
Merge Sort Example

T(n) = 2T(n/2) + n

Time = O(n log n)
Space = O(n)
*/


/*
Amortized Complexity

Sometimes worst case seems large,
but average per operation is small.

Example:
Dynamic array push_back.

Occasionally resizing takes O(n),
but average push is O(1).

This is amortized O(1).
*/


/*
Time vs Space Tradeoff

Sometimes we use extra space to reduce time.

Example:
Using hashmap.
Brute force → O(n^2)
Using map → O(n)

Time decreases but space increases.
*/


/*
Best, Average, Worst Case

Best case → minimum operations
Worst case → maximum operations
Average case → expected operations

Big-O represents worst case.
*/


/*
Common Interview Comparisons

Linear Search
Time = O(n)
Space = O(1)

Binary Search
Time = O(log n)
Space = O(1) iterative
Space = O(log n) recursive

Bubble Sort
Time = O(n^2)
Space = O(1)

Merge Sort
Time = O(n log n)
Space = O(n)
*/


int main()
{
    cout << "Final Time and Space Complexity Notes Loaded" << endl;
    return 0;
}

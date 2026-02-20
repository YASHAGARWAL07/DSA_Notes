/*
    Time and Space Complexity
*/

#include <iostream>
using namespace std;


/*
Time Complexity

Time complexity tells us how the running time of an algorithm
increases as the size of input (n) increases.

Important:
We do NOT calculate actual time in seconds.
We calculate how the number of operations grows with n.

Example:
If n = 10  → maybe 10 operations
If n = 100 → maybe 100 operations
Growth matters, not exact count.
*/


/*
Why Big-O?

Big-O notation is used to represent the worst case time complexity.
It gives an upper bound on the running time.

We focus on worst case because:
- It guarantees performance.
- It is easier to analyse.
*/


/*
Common Time Complexities (in increasing order)

O(1)        constant
O(log n)    logarithmic
O(n)        linear
O(n log n)  linearithmic
O(n^2)      quadratic
O(2^n)      exponential
O(n!)       factorial

As n becomes very large:

O(1) is best
O(n!) is worst
*/


/*
Example 1: Constant Time  O(1)
*/

int getFirstElement(int arr[])
{
    return arr[0];
}

/*
No matter how large array is,
only one operation happens.
So time complexity = O(1)
*/


/*
Example 2: Linear Time  O(n)
*/

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*
If n = 5 → loop runs 5 times
If n = 100 → loop runs 100 times

So time complexity = O(n)
*/


/*
Example 3: Quadratic Time  O(n^2)
*/

void printPairs(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i] << "," << arr[j] << endl;
        }
    }
}

/*
Outer loop runs n times.
Inner loop runs n times for each outer iteration.

Total operations = n * n = n^2
So complexity = O(n^2)
*/


/*
Example 4: Logarithmic Time  O(log n)

Binary Search reduces search space by half every time.
*/

int binarySearch(int arr[], int start, int end, int key)
{
    if(start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if(arr[mid] == key)
        return mid;

    else if(key > arr[mid])
        return binarySearch(arr, mid + 1, end, key);

    else
        return binarySearch(arr, start, mid - 1, key);
}

/*
Each recursive call reduces array size to half.

n → n/2 → n/4 → n/8 → ...

So number of calls ≈ log n
Time complexity = O(log n)
*/


/*
Rules to calculate time complexity

1. Ignore constants
   O(2n) becomes O(n)

2. Ignore lower order terms
   O(n^2 + n) becomes O(n^2)

3. Nested loops → multiply
   for i
       for j
   → O(n^2)

4. Separate loops → add
   for i (n)
   for j (n)
   → O(n + n) = O(n)

5. Recursion:
   Count how many recursive calls are made
   and how much work is done in each call.
*/


/*
Space Complexity

Space complexity tells how much extra memory
an algorithm uses.

There are two types:

1. Input space
   Memory required to store input.

2. Auxiliary space
   Extra memory used by algorithm.

Usually we calculate auxiliary space.
*/


/*
Example 1: Constant Space  O(1)
*/

void example1()
{
    int a = 10;
    int b = 20;
}

/*
Only two variables.
No matter input size.
So space = O(1)
*/


/*
Example 2: Linear Space  O(n)
*/

void example2(int n)
{
    int arr[n];
}

/*
If n increases, memory increases.
So space = O(n)
*/


/*
Recursive Space

In recursion, each function call uses stack memory.
*/

int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}

/*
If n = 5,
Stack calls:
factorial(5)
factorial(4)
factorial(3)
factorial(2)
factorial(1)
factorial(0)

Total stack depth = 6

So space complexity = O(n)
*/


/*
Time vs Space Tradeoff

Sometimes we use extra space to reduce time.

Example:
Using hashing.

Brute force → O(n^2)
Using hash map → O(n)

Time decreases but space increases.
*/


/*
Best Case, Average Case, Worst Case

Best case:
Minimum operations.

Worst case:
Maximum operations.
(Big-O usually represents worst case)

Average case:
Expected operations.
*/


/*
Quick Comparison

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
    cout << "Time and Space Complexity Notes Loaded" << endl;
    return 0;
}

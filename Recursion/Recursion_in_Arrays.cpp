/************************************************************
        RECURSION IN ARRAYS – COMPLETE NOTES
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. WHAT IS RECURSION?
============================================================

Recursion is a technique in which a function calls itself
to solve a smaller part of the problem.

Every recursive function must have:

1) Base Case      → Condition to stop recursion
2) Recursive Case → Function calling itself

Without base case, recursion becomes infinite.
*/


/*
============================================================
2. WHY USE RECURSION IN ARRAYS?
============================================================

Instead of using loops, we solve array problems
by reducing the size of array step by step.

We usually reduce:
- Index (increase or decrease)
- Size (n-1)

Recursive Thinking:
"First solve smaller problem, then combine result."
*/


/*
============================================================
3. PRINT ARRAY USING RECURSION (LEFT TO RIGHT)
============================================================
*/

void printForward(int arr[], int index, int n)
{
    // Base Case
    if(index == n)
        return;

    cout << arr[index] << " ";

    // Recursive Call
    printForward(arr, index + 1, n);
}


/*
============================================================
4. PRINT ARRAY USING RECURSION (RIGHT TO LEFT)
============================================================
*/

void printReverse(int arr[], int index)
{
    if(index < 0)
        return;

    cout << arr[index] << " ";

    printReverse(arr, index - 1);
}


/*
============================================================
5. SUM OF ARRAY USING RECURSION
============================================================
*/

int sumArray(int arr[], int n)
{
    // Base Case
    if(n == 0)
        return 0;

    // Recursive Case
    return arr[n - 1] + sumArray(arr, n - 1);
}


/*
============================================================
6. FIND MAX ELEMENT IN ARRAY USING RECURSION
============================================================
*/

int findMax(int arr[], int n)
{
    if(n == 1)
        return arr[0];

    int smallMax = findMax(arr, n - 1);

    if(arr[n - 1] > smallMax)
        return arr[n - 1];
    else
        return smallMax;
}


/*
============================================================
7. FIND MIN ELEMENT IN ARRAY USING RECURSION
============================================================
*/

int findMin(int arr[], int n)
{
    if(n == 1)
        return arr[0];

    int smallMin = findMin(arr, n - 1);

    if(arr[n - 1] < smallMin)
        return arr[n - 1];
    else
        return smallMin;
}


/*
============================================================
8. SEARCH ELEMENT IN ARRAY USING RECURSION
============================================================
*/

bool searchElement(int arr[], int n, int key)
{
    if(n == 0)
        return false;

    if(arr[n - 1] == key)
        return true;

    return searchElement(arr, n - 1, key);
}


/*
============================================================
9. CHECK IF ARRAY IS SORTED (ASCENDING)
============================================================
*/

bool isSorted(int arr[], int n)
{
    if(n == 1)
        return true;

    if(arr[n - 1] < arr[n - 2])
        return false;

    return isSorted(arr, n - 1);
}


/*
============================================================
10. IMPORTANT OBSERVATIONS
============================================================

1) Always define base case clearly.
2) Reduce problem size in every recursive call.
3) Avoid unnecessary recursive calls.
4) Recursion uses stack memory.
5) Too deep recursion can cause stack overflow.
*/


/*
============================================================
MAIN FUNCTION (Testing All Functions)
============================================================
*/

int main()
{
    int arr[] = {3, 4, 1, 2, 8};
    int n = 5;

    cout << "Array Forward: ";
    printForward(arr, 0, n);

    cout << "\nArray Reverse: ";
    printReverse(arr, n - 1);

    cout << "\nSum: " << sumArray(arr, n);

    cout << "\nMaximum: " << findMax(arr, n);

    cout << "\nMinimum: " << findMin(arr, n);

    cout << "\nSearch 4: ";
    if(searchElement(arr, n, 4))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\nIs Sorted: ";
    if(isSorted(arr, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

/************************************************************
                    END OF NOTES
************************************************************/

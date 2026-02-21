/*
====================================================
QUICK SORT
====================================================
*/

#include <iostream>
using namespace std;


/*
----------------------------------------------------
1. INTRODUCTION
----------------------------------------------------

Quick Sort is a Divide and Conquer algorithm.

Steps:
1) Choose a pivot element
2) Partition array around pivot
3) Recursively sort left and right parts

In-place sorting algorithm.
Not stable.
*/


/*
----------------------------------------------------
2. PARTITION FUNCTION
----------------------------------------------------

Pivot chosen as last element.

All elements <= pivot move to left.
All elements > pivot move to right.

Returns final pivot index.
*/

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];   // last element as pivot
    int pos = start;

    for(int i = start; i <= end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }

    return pos - 1;  // final pivot position
}



/*
----------------------------------------------------
3. QUICK SORT FUNCTION
----------------------------------------------------
*/

void quickSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int pivotIndex = partition(arr, start, end);

    // Left side
    quickSort(arr, start, pivotIndex - 1);

    // Right side
    quickSort(arr, pivotIndex + 1, end);
}



/*
----------------------------------------------------
4. TIME COMPLEXITY
----------------------------------------------------

Best Case:
Balanced partition
T(n) = 2T(n/2) + n
Time = O(n log n)

Average Case:
O(n log n)

Worst Case:
Unbalanced (already sorted array)
T(n) = T(n-1) + n
Time = O(n^2)
*/


/*
----------------------------------------------------
5. SPACE COMPLEXITY
----------------------------------------------------

Recursive stack space:

Best/Average: O(log n)
Worst: O(n)

No extra array used.
In-place sorting.
*/


/*
----------------------------------------------------
6. IMPORTANT PROPERTIES
----------------------------------------------------

✔ In-place
✔ Faster in practice than Merge Sort
✔ Cache friendly
✘ Not stable
✘ Worst case O(n^2)
*/


/*
----------------------------------------------------
7. MAIN FUNCTION (TEST)
----------------------------------------------------
*/

int main()
{
    int arr[] = {8, 3, 6, 2, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
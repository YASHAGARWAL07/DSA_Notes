/*
====================================================
MERGE SORT
====================================================
*/

#include <iostream>
#include <vector>
using namespace std;


/*
----------------------------------------------------
1. INTRODUCTION
----------------------------------------------------

Merge Sort is a Divide and Conquer algorithm.

Steps:
1) Divide array into two halves
2) Recursively sort both halves
3) Merge the sorted halves

Stable sorting algorithm.
*/


/*
----------------------------------------------------
2. DIVIDE AND CONQUER IDEA
----------------------------------------------------

Divide → Recursively break array
Conquer → Solve smaller arrays
Combine → Merge sorted halves

Recurrence:
T(n) = 2T(n/2) + n
*/




/*
----------------------------------------------------
3. MERGE FUNCTION
----------------------------------------------------

Merges two sorted halves:
Left  → start to mid
Right → mid+1 to end
*/

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);

    int left = start;
    int right = mid + 1;
    int index = 0;

    // Compare both halves
    while(left <= mid && right <= end)
    {
        if(arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++;
        }
        else
        {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    // Remaining left elements
    while(left <= mid)
    {
        temp[index++] = arr[left++];
    }

    // Remaining right elements
    while(right <= end)
    {
        temp[index++] = arr[right++];
    }

    // Copy back to original array
    index = 0;
    while(start <= end)
    {
        arr[start++] = temp[index++];
    }
}



/*
----------------------------------------------------
4. MERGE SORT FUNCTION
----------------------------------------------------
*/

void mergeSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int mid = start + (end - start) / 2;

    // Left half
    mergeSort(arr, start, mid);

    // Right half
    mergeSort(arr, mid + 1, end);

    // Merge both halves
    merge(arr, start, mid, end);
}



/*
----------------------------------------------------
5. TIME & SPACE COMPLEXITY
----------------------------------------------------

Recurrence:
T(n) = 2T(n/2) + n

Height of recursion tree = log n
Work at each level = n

Time Complexity = O(n log n)

Space Complexity:
Extra temp array = O(n)
Recursion stack = O(log n)

Total Space = O(n)
*/


/*
----------------------------------------------------
6. PROPERTIES
----------------------------------------------------

✔ Stable
✔ Not in-place (uses extra memory)
✔ Good for linked lists
✔ Predictable O(n log n) in all cases
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

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
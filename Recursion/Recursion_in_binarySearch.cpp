/***************************************************************
            (Recursion in Binary Search)
***************************************************************/

#include <iostream>
using namespace std;

/*
===============================================================
1. WHAT IS BINARY SEARCH?
===============================================================

Binary Search is used to search an element in a 
SORTED array.

Condition:
Array must be sorted (ascending or descending).

Idea:
- Divide the array into two halves.
- Compare middle element with target.
- If equal → found.
- If target is greater → search right half.
- If target is smaller → search left half.

Time Complexity:
O(log n)

Space Complexity (recursion stack):
O(log n)
*/


/*
===============================================================
2. RECURSIVE LOGIC
===============================================================

Function Parameters:
- arr[]  → array
- start  → starting index
- end    → ending index
- key    → element to search

Base Condition:
If start > end → element not found

Recursive Case:
mid = start + (end - start) / 2

if arr[mid] == key → return index
if key > arr[mid] → search right half
if key < arr[mid] → search left half
*/


/*
===============================================================
3. RECURSIVE BINARY SEARCH FUNCTION
===============================================================
*/

int binarySearch(int arr[], int start, int end, int key)
{
    // base condition
    if(start > end)
        return -1;

    int mid = start + (end - start) / 2;

    // element found
    if(arr[mid] == key)
        return mid;

    // search in right half
    else if(key > arr[mid])
        return binarySearch(arr, mid + 1, end, key);

    // search in left half
    else
        return binarySearch(arr, start, mid - 1, key);
}


/*
===============================================================
4. MAIN FUNCTION
===============================================================
*/

int main()
{
    int arr[] = {3, 8, 11, 15, 20, 22};
    int n = 6;

    int key = 15;

    int result = binarySearch(arr, 0, n-1, key);

    if(result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}


/*
===============================================================
5. IMPORTANT INTERVIEW / VIVA POINTS
===============================================================

1) Why use mid = start + (end - start) / 2 ?
   To prevent integer overflow.

2) Binary search works only on sorted arrays.

3) Iterative vs Recursive:
   - Iterative uses loop
   - Recursive uses function calls

4) Worst Case Time Complexity:
   O(log n)

5) If duplicates exist:
   This code returns any one occurrence.
*/


/*
===============================================================
6. DRY RUN EXAMPLE
===============================================================

Array: {3, 8, 11, 15, 20, 22}
Key = 15

start = 0
end = 5

mid = 2 → arr[2] = 11
15 > 11 → search right half

start = 3
end = 5

mid = 4 → arr[4] = 20
15 < 20 → search left half

start = 3
end = 3

mid = 3 → arr[3] = 15
Found at index 3

*/

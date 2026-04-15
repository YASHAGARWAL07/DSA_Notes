/*
============================================================
HEAP (MAX HEAP)
============================================================

1) HEAP BASICS
--------------
- Complete Binary Tree (CBT)
- Stored using array
- For Max Heap:
    Parent >= Children

Indexing:
    Parent = (i-1)/2
    Left   = 2*i + 1
    Right  = 2*i + 2

------------------------------------------------------------

2) BUILD HEAP
-------------
- Convert array → Max Heap
- Start from last non-leaf node

Last non-leaf:
    i = n/2 - 1

Why bottom-up?
- Leaves already valid
- Fix subtrees efficiently

Time Complexity: O(n)

------------------------------------------------------------

3) STEP UP (Insertion)
----------------------
- Insert at last index
- Move upward

Steps:
1) Insert at end
2) Compare with parent
3) Swap if greater
4) Repeat

Time: O(log n)

------------------------------------------------------------

4) STEP DOWN (Heapify / Deletion / Build)
-----------------------------------------
- Move downward

Steps:
1) Compare with children
2) Swap with largest child
3) Repeat

Time: O(log n)

------------------------------------------------------------

5) DELETE ROOT
--------------
Steps:
1) Replace root with last element
2) Reduce size
3) Heapify from root

------------------------------------------------------------

6) HEAPIFY FUNCTION
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void Heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != index)
    {
        swap(arr[index], arr[largest]);
        Heapify(arr, largest, n);
    }
}

/*
------------------------------------------------------------
BUILD MAX HEAP
------------------------------------------------------------
*/

void BuildMaxHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

/*
------------------------------------------------------------
MAX HEAP CLASS (STEP UP + STEP DOWN)
------------------------------------------------------------
*/

class MaxHeap {
public:
    int arr[100];
    int size;

    MaxHeap() {
        size = 0;
    }

    // STEP UP (Insertion)
    void insert(int value)
    {
        arr[size] = value;
        int index = size;
        size++;

        while(index > 0 && arr[(index-1)/2] < arr[index])
        {
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    // STEP DOWN (Heapify)
    void heapify(int index)
    {
        int largest = index;

        while(true)
        {
            int left = 2*index + 1;
            int right = 2*index + 2;

            if(left < size && arr[left] > arr[largest])
                largest = left;

            if(right < size && arr[right] > arr[largest])
                largest = right;

            if(largest == index)
                break;

            swap(arr[index], arr[largest]);
            index = largest;
        }
    }

    // DELETE ROOT
    void deleteRoot()
    {
        if(size == 0) return;

        arr[0] = arr[size-1];
        size--;

        heapify(0);
    }

    void print()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

/*
------------------------------------------------------------
PRINT ARRAY HEAP
------------------------------------------------------------
*/

void printHeap(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
------------------------------------------------------------
MAIN
------------------------------------------------------------
*/

int main()
{
    // BUILD HEAP
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    int n = 10;

    BuildMaxHeap(arr, n);
    printHeap(arr, n);

    // CLASS BASED OPERATIONS
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);

    h.print();

    h.deleteRoot();
    h.print();

    return 0;
}

/*
============================================================
REVISION POINTS

- Heap = CBT + Order property
- Build Heap = O(n)
- Insert = Step Up = O(log n)
- Delete = Step Down = O(log n)
- Parent = (i-1)/2
- Left = 2*i+1
- Right = 2*i+2

============================================================
*/
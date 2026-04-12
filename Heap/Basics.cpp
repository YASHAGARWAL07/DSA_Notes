/*
============================================================
HEAP (MAX HEAP) - IMPLEMENTATION
============================================================

1) HEAP DEFINITION
   - Heap is a Complete Binary Tree (CBT)
   - Stored using array representation

2) TYPES OF HEAP
   - Max Heap → Parent >= Children
   - Min Heap → Parent <= Children

3) COMPLETE BINARY TREE (CBT)
   - All levels filled except possibly last
   - Last level filled from left to right

4) ARRAY INDEXING
   - For index i:
        left child  = 2*i + 1
        right child = 2*i + 2
        parent      = (i-1)/2

5) IMPORTANT OPERATIONS
   - Insert → O(log n)
   - Delete (root) → O(log n)
   - Heapify → O(log n)
   - Build Heap → O(n)

6) INSERT LOGIC
   - Insert at last position
   - Move upward (heapify up) until heap property satisfied

7) DELETE LOGIC (ROOT)
   - Replace root with last element
   - Remove last element
   - Heapify downward

============================================================
*/

#include <iostream>
using namespace std;

class MaxHeap {
public:
    int *arr;
    int size;
    int capacity;

    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

/*
------------------------------------------------------------
INSERT OPERATION (Heapify Up)
------------------------------------------------------------
Steps:
1) Insert element at last index
2) Compare with parent
3) Swap if greater than parent
4) Repeat until root or correct position
------------------------------------------------------------
*/

    void insert(int value) {

        if(size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // move upward
        while(index > 0 && arr[(index-1)/2] < arr[index]) {
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }

        cout << value << " is inserted into the heap\n";
    }

/*
------------------------------------------------------------
HEAPIFY (DOWNWARD)
------------------------------------------------------------
Used after deletion

Steps:
1) Compare parent with children
2) Find largest among them
3) Swap if needed
4) Repeat for affected subtree
------------------------------------------------------------
*/

    void heapify(int index) {

        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < size && arr[left] > arr[largest])
            largest = left;

        if(right < size && arr[right] > arr[largest])
            largest = right;

        if(largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

/*
------------------------------------------------------------
DELETE ROOT
------------------------------------------------------------
Steps:
1) Replace root with last element
2) Reduce size
3) Apply heapify from root
------------------------------------------------------------
*/

    void deleteRoot() {

        if(size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << arr[0] << " deleted from heap\n";

        arr[0] = arr[size-1];
        size--;

        heapify(0);
    }

/*
------------------------------------------------------------
PRINT HEAP
------------------------------------------------------------
*/

    void print() {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

/*
------------------------------------------------------------
MAIN FUNCTION
------------------------------------------------------------
*/

int main() {

    MaxHeap H(20);

    H.insert(4);
    H.insert(14);
    H.insert(11);

    H.deleteRoot();

    H.print();

    H.insert(114);
    H.insert(24);
    H.insert(1);
    H.insert(10);

    H.print();

    return 0;
}

/*
============================================================
EXTRA NOTES (REVISION)

- Heap is NOT a BST
- Only parent-child relation matters
- Root always gives:
    Max Heap → Maximum element
    Min Heap → Minimum element

- Used in:
    Priority Queue
    Heap Sort
    Dijkstra Algorithm

============================================================
*/
/*
============================================================
HEIGHT OF HEAP
============================================================

- Heap is a Complete Binary Tree (CBT)

- Height = number of levels - 1
- OR simply: floor(log2(n))

Example:
n = 6 → height = 2
n = 9 → height = 3

------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int heapHeight(int n, int arr[]) {

        // if only one node
        if(n == 1)
            return 1;

        int height = 0;

        // keep dividing by 2 (levels in CBT)
        while(n > 1) {
            height++;
            n = n / 2;
        }

        return height;
    }
};

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main() {

    Solution obj;

    int arr1[] = {1,3,6,5,9,8};
    cout << obj.heapHeight(6, arr1) << endl; // 2

    int arr2[] = {3,6,9,2,15,10,14,5,12};
    cout << obj.heapHeight(9, arr2) << endl; // 3

    return 0;
}

/*
============================================================
REVISION

- Height of heap = floor(log2(n))
- Use repeated division by 2
- Based on CBT structure

============================================================
*/
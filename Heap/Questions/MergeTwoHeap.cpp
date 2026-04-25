/*
============================================================
MERGE TWO BINARY MAX HEAPS
============================================================

- Given two max heaps (arrays), merge them into one max heap

STEPS:
1) Insert all elements of both arrays into a single vector
2) Convert that vector into a Max Heap using Heapify

- Use Bottom-Up Heap Construction

TIME COMPLEXITY:
- O(n + m)

============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void Heapify(vector<int>& ans, int index, int n)
    {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < n && ans[left] > ans[largest])
            largest = left;

        if(right < n && ans[right] > ans[largest])
            largest = right;

        if(largest != index)
        {
            swap(ans[index], ans[largest]);
            Heapify(ans, largest, n);
        }
    }

    vector<int> mergeHeaps(vector<int>& a, vector<int>& b)
    {
        vector<int> ans;

        int n = a.size();
        int m = b.size();

        // step 1: merge arrays
        for(int i = 0; i < n; i++)
            ans.push_back(a[i]);

        for(int i = 0; i < m; i++)
            ans.push_back(b[i]);

        // step 2: build max heap
        int size = ans.size();

        for(int i = size/2 - 1; i >= 0; i--)
        {
            Heapify(ans, i, size);
        }

        return ans;
    }
};

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main()
{
    Solution obj;

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> res = obj.mergeHeaps(a, b);

    for(int x : res)
        cout << x << " ";

    return 0;
}

/*
============================================================
REVISION

- Merge → then Build Heap
- Start heapify from n/2 - 1
- Bottom-up approach
- Faster than inserting one by one

============================================================
*/
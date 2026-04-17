/*
============================================================
MINIMUM COST OF ROPES
============================================================

- We always combine the two smallest ropes first
- Use Min Heap (priority queue)

- Why?
  -> To minimize total cost (greedy)

Steps:
1) Insert all elements into min heap
2) Take two smallest elements
3) Add their sum to total cost
4) Push sum back into heap
5) Repeat until one element remains

Time Complexity: O(n log n)

============================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr) {

        // min heap
        priority_queue<long long, vector<long long>, greater<long long>> p;

        // push all elements
        for(long long i = 0; i < arr.size(); i++)
            p.push(arr[i]);

        long long cost = 0;

        // process
        while(p.size() > 1) {

            long long first = p.top();
            p.pop();

            long long second = p.top();
            p.pop();

            long long rope = first + second;

            cost += rope;

            p.push(rope);
        }

        return cost;
    }
};

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main() {

    Solution obj;

    vector<int> arr1 = {4, 3, 2, 6};
    cout << obj.minCost(arr1) << endl; // 29

    vector<int> arr2 = {4, 2, 7, 6, 9};
    cout << obj.minCost(arr2) << endl; // 62

    return 0;
}

/*
============================================================
REVISION

- Always pick 2 smallest → Min Heap
- Greedy approach
- Same pattern used in Huffman Coding

============================================================
*/
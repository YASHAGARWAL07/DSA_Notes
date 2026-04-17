/*
============================================================
LAST STONE WEIGHT (HEAP / PRIORITY QUEUE)
============================================================

Given:
- stones[i] → weight of stones

At each step:
1) Pick two heaviest stones (x, y)
2) If x == y → both destroyed
3) If x != y → push (y - x)

Goal:
- Return last remaining stone (or 0)

------------------------------------------------------------

IDEA
-----
- Always pick two largest → Max Heap

------------------------------------------------------------

TIME COMPLEXITY
---------------
- Each operation: log N
- Total: O(n log n)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {

    priority_queue<int> pq;

    for(int x : stones)
        pq.push(x);

    while(pq.size() > 1) {

        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if(first != second)
            pq.push(first - second);
    }

    return pq.empty() ? 0 : pq.top();
}

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main() {

    vector<int> stones = {2,7,4,1,8,1};

    cout << lastStoneWeight(stones) << endl;

    return 0;
}

/*
============================================================
REVISION

- Max Heap (priority_queue)
- Pick two largest
- Push difference
- Greedy + Heap

============================================================
*/
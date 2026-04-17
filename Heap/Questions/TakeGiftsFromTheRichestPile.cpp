/*
============================================================
TAKE GIFTS FROM THE RICHEST PILE (HEAP)
============================================================

Given:
- gifts[i] → number of gifts in each pile
- k seconds

Each second:
1) Pick pile with maximum gifts
2) Replace it with floor(sqrt(x))

Goal:
- Return total remaining gifts after k operations

------------------------------------------------------------

IDEA
-----
- Always pick max → Max Heap
- Replace with sqrt value

------------------------------------------------------------

TIME COMPLEXITY
---------------
- Each operation: log N
- Total: O(k log N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long pickGifts(vector<int>& gifts, int k) {

    priority_queue<int> pq;

    for(int x : gifts)
        pq.push(x);

    while(k--) {
        int top = pq.top();
        pq.pop();

        pq.push(sqrt(top));
    }

    long long sum = 0;

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main() {

    vector<int> gifts = {25,64,9,4,100};
    int k = 4;

    cout << pickGifts(gifts, k) << endl;

    return 0;
}

/*
============================================================
REVISION

- Max Heap (priority_queue)
- Always pick max
- Replace with sqrt
- Greedy + Heap

============================================================
*/
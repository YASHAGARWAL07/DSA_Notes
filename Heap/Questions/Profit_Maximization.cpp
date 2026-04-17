/*
============================================================
PROFIT MAXIMISATION (HEAP / PRIORITY QUEUE)
============================================================

Given:
- Array A → seats in each row
- B → number of people

Each time:
1) Sell ticket from row with max seats
2) Profit += seats
3) Seats decrease by 1
4) Push updated value back

Goal:
- Maximize profit

------------------------------------------------------------

IDEA
-----
- Always pick maximum → Max Heap
- Greedy choice (take best available)

------------------------------------------------------------

TIME COMPLEXITY
---------------
- Each operation: log N
- Total: O(B log N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(vector<int> &A, int B) {

    priority_queue<int> pq;

    for(int x : A)
        pq.push(x);

    int profit = 0;

    while(B > 0 && !pq.empty()) {

        int top = pq.top();
        pq.pop();

        profit += top;

        if(top - 1 > 0)
            pq.push(top - 1);

        B--;
    }

    return profit;
}

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main() {

    vector<int> A = {2, 3};
    int B = 3;

    cout << solve(A, B) << endl;

    return 0;
}

/*
============================================================
REVISION

- Max Heap (priority_queue)
- Always pick max
- Decrease and push back
- Greedy + Heap

============================================================
*/
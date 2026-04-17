/*
============================================================
MAGICIAN AND CHOCOLATES (HEAP / PRIORITY QUEUE)
============================================================

Given:
- N bags, each with Bi chocolates
- A units of time

At each step:
1) Pick the bag with maximum chocolates
2) Eat all chocolates
3) Put back floor(Bi/2)

Goal:
- Maximize chocolates eaten

------------------------------------------------------------

IDEA
-----
- Always pick maximum → use Max Heap
- After eating, push back reduced value

------------------------------------------------------------

TIME COMPLEXITY
---------------
- Each operation: log N
- Total: O(A log N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nchoc(int A, vector<int> &B) {
    
    priority_queue<int> pq;  // max heap
    
    for(int x : B)
        pq.push(x);
    
    long long total = 0;
    int mod = 1000000007;
    
    while(A > 0 && !pq.empty()) {
        
        int top = pq.top();
        pq.pop();
        
        total = (total + top) % mod;
        
        pq.push(top / 2);
        
        A--;
    }
    
    return total % mod;
}

/*
------------------------------------------------------------
MAIN (for testing)
------------------------------------------------------------
*/

int main() {
    
    int A = 3;
    vector<int> B = {6, 5};
    
    cout << nchoc(A, B) << endl;
    
    return 0;
}

/*
============================================================
REVISION

- Use max heap (priority_queue)
- Always pick max element
- Push back floor(x/2)
- Greedy + Heap

============================================================
*/
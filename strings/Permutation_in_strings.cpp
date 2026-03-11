/*
============================================================
LEETCODE 46 : PERMUTATIONS
BACKTRACKING APPROACH
============================================================
*/

#include <iostream>
#include <vector>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given an array of DISTINCT integers,
return all possible permutations.

Example:

Input:
nums = [1,2,3]

Output:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]

Total permutations = n!

Where n = size of array
*/


/*
------------------------------------------------------------
2. INTUITION
------------------------------------------------------------

Permutation means arranging elements
in every possible order.

Example:

[1,2,3]

Fix each element at first position
and recursively arrange remaining elements.

Tree representation:

                []
        /        |        \
      1          2         3
    /   \      /   \     /   \
  2      3    1     3   1     2
 /        \  /       \ /       \
3          2 3       1 2       1

We generate permutations using
BACKTRACKING.
*/


/*
------------------------------------------------------------
3. BACKTRACKING IDEA
------------------------------------------------------------

Steps:

1. Maintain a temporary vector (temp)
   to store current permutation.

2. Maintain a visited array
   to track used elements.

3. For every index:
      if not visited:
         include element
         recurse
         undo choice (backtrack)

4. When temp size == n
   we found a permutation.
*/


class Solution {
public:

    void permu(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& temp,
               vector<bool>& visited)
    {

        // BASE CONDITION
        if(temp.size() == visited.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                // choose element
                visited[i] = 1;
                temp.push_back(nums[i]);

                // recursion
                permu(nums, ans, temp, visited);

                // backtracking
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),0);

        permu(nums,ans,temp,visited);

        return ans;
    }
};


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

nums = [1,2,3]

temp = []

choose 1
temp = [1]

choose 2
temp = [1,2]

choose 3
temp = [1,2,3]
store answer

backtrack

temp = [1,3,2]

store answer
...


This continues until all permutations are generated.
*/


/*
------------------------------------------------------------
5. TIME COMPLEXITY
------------------------------------------------------------

Number of permutations = n!

Each permutation takes O(n)

Total Time Complexity:

O(n * n!)

Example:

n = 3

3! = 6 permutations
*/


/*
------------------------------------------------------------
6. SPACE COMPLEXITY
------------------------------------------------------------

Recursion stack → O(n)

Auxiliary structures:
visited array → O(n)
temp vector → O(n)

Total:

O(n)
*/


/*
------------------------------------------------------------
7. IMPORTANT INTERVIEW POINTS
------------------------------------------------------------

1. This is a classic BACKTRACKING problem.

2. Used in:
   - permutations
   - combinations
   - subsets
   - sudoku
   - n queens

3. Key idea:

Choose
Explore
Unchoose (Backtrack)
*/


/*
------------------------------------------------------------
8. ALTERNATIVE APPROACH
------------------------------------------------------------

Instead of visited array,
we can generate permutations using

SWAP METHOD

Time Complexity remains:

O(n * n!)
*/


/*
============================================================
END OF FILE
============================================================
*/
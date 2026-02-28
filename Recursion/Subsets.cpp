/*
============================================================
GENERATE ALL SUBSETS (POWER SET) USING RECURSION
============================================================
*/

#include <iostream>
#include <vector>
using namespace std;


/*
------------------------------------------------------------
1. PROBLEM STATEMENT
------------------------------------------------------------

Given an integer array nums,
return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

Example:

Input:
nums = {1,2,3}

Output:
{}
{1}
{2}
{3}
{1,2}
{1,3}
{2,3}
{1,2,3}

Total subsets = 2^n
*/


/*
------------------------------------------------------------
2. CORE IDEA (INCLUDE / EXCLUDE PATTERN)
------------------------------------------------------------

For every element we have two choices:

1. Do NOT include it
2. Include it

This forms a recursion tree of height n.

At each level:
- First call → exclude
- Second call → include

When index == size,
we push the current subset into answer.

This pattern is also called:
Binary Recursion Tree
*/


void generateSubsets(vector<int>& arr,
                     int index,
                     int size,
                     vector<vector<int>>& ans,
                     vector<int> temp)
{
    // Base Case
    if(index == size)
    {
        ans.push_back(temp);
        return;
    }

    // Case 1: Not Include current element
    generateSubsets(arr, index + 1, size, ans, temp);

    // Case 2: Include current element
    temp.push_back(arr[index]);
    generateSubsets(arr, index + 1, size, ans, temp);
}


/*
------------------------------------------------------------
3. MAIN SUBSETS FUNCTION
------------------------------------------------------------
*/

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> temp;

    int n = nums.size();

    generateSubsets(nums, 0, n, ans, temp);

    return ans;
}


/*
------------------------------------------------------------
4. DRY RUN
------------------------------------------------------------

Input:
{1,2}

Recursion Tree:

index=0
        []
       /   \
exclude    include(1)
   |            |
index=1       index=1
  []            [1]
  / \           /  \
 []  [2]      [1]  [1,2]

Final subsets:
[]
[2]
[1]
[1,2]

Total = 4 = 2^2
*/


/*
------------------------------------------------------------
5. TIME COMPLEXITY ANALYSIS
------------------------------------------------------------

At each index we branch into 2 calls.

Total nodes in recursion tree = 2^n

Each subset can take up to O(n) time to copy.

Therefore:

Time Complexity = O(n * 2^n)
*/


/*
------------------------------------------------------------
6. SPACE COMPLEXITY ANALYSIS
------------------------------------------------------------

Recursive stack depth = n

Auxiliary Space = O(n)

Total space for storing subsets = O(n * 2^n)
*/


/*
------------------------------------------------------------
7. IMPORTANT NOTES
------------------------------------------------------------

1. Passing temp by value creates a copy.
   This avoids manual backtracking (pop_back).

2. If temp is passed by reference,
   then we must use pop_back() after recursive call.

3. Total subsets of n elements = 2^n.

4. This is standard pattern for:
   - Subsets
   - Binary decision problems
   - Include/Exclude recursion
*/


/*
------------------------------------------------------------
8. PRINT FUNCTION
------------------------------------------------------------
*/

void printSubsets(vector<vector<int>>& ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout << "{ ";
        for(int j = 0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }
}


/*
------------------------------------------------------------
9. MAIN FUNCTION
------------------------------------------------------------
*/

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    cout << "All Subsets:" << endl;
    printSubsets(result);

    return 0;
}


/*
============================================================
END OF FILE
============================================================
*/
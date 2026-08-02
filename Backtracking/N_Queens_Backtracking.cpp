/*
====================================================================================================
                                   N-QUEENS (BACKTRACKING)
====================================================================================================

PROBLEM:
LeetCode 51 - N Queens

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

The N-Queens puzzle is the problem of placing N queens on an N × N chessboard
such that no two queens attack each other.

A queen can attack

• Horizontally
• Vertically
• Left Diagonally
• Right Diagonally

Return all distinct possible board configurations.

====================================================================================================
PREREQUISITES
====================================================================================================

• Recursion

• Backtracking

• Matrix Traversal

• DFS

====================================================================================================
INTUITION
====================================================================================================

We place exactly one queen in every row.

For the current row,

try placing the queen in every column.

Before placing,

check whether

• The column is free.

• The left diagonal is free.

• The right diagonal is free.

If the position is safe,

place the queen,

mark the corresponding column and diagonals,

and recursively solve the next row.

If later we cannot place queens in future rows,

remove the queen,

unmark everything,

and try another column.

This process is called

Backtracking.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Create an empty chessboard.

↓

Step 2

Maintain three helper arrays.

• column[]

• leftDiag[]

• rightDiag[]

↓

Step 3

Start placing queens from Row 0.

↓

Step 4

Traverse every column.

↓

Step 5

Check whether

column[j]

leftDiag[n-1+j-row]

rightDiag[row+j]

are free.

↓

If yes,

place the queen.

↓

Step 6

Mark

column

leftDiag

rightDiag

↓

Step 7

Move to the next row recursively.

↓

Step 8

If all rows are completed,

store the board.

↓

Step 9

Backtrack.

Remove the queen.

Unmark

column

leftDiag

rightDiag.

====================================================================================================
ALGORITHM
====================================================================================================

Start from Row 0

↓

Try every Column

↓

Safe ?

↓

YES

↓

Place Queen

↓

Mark

column

leftDiag

rightDiag

↓

Move to Next Row

↓

Reached row == n ?

↓

Store Answer

↓

Backtrack

↓

Remove Queen

↓

Unmark Arrays

↓

Try Next Column

====================================================================================================
WHY THREE ARRAYS?
====================================================================================================

Instead of scanning the board every time,

your solution maintains three arrays.

--------------------------------------------

1.

column[]

Stores whether a queen already exists
in a column.

Time

O(1)

--------------------------------------------

2.

leftDiag[]

Represents

Top Left

↓

Bottom Right

Diagonal

Formula

leftDiag[n-1+col-row]

--------------------------------------------

3.

rightDiag[]

Represents

Top Right

↓

Bottom Left

Diagonal

Formula

rightDiag[row+col]

--------------------------------------------

Hence,

every safety check becomes

O(1)

instead of

O(n).

====================================================================================================
DIAGONAL FORMULAS
====================================================================================================

Left Diagonal

Index

n - 1 + column - row

--------------------------------------------

Right Diagonal

Index

row + column

Example

Suppose

n = 4

Cell

(row,col)

=

(2,3)

Left Diagonal

3 + 3 - 2 = 4

Right Diagonal

2 + 3 = 5

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Function

find()

Purpose

Recursive Backtracking Function.

Parameters

row

Current Row.

n

Board Size.

ans

Stores all valid boards.

Board

Current Chessboard.

column

Occupied Columns.

leftDiag

Occupied Left Diagonals.

rightDiag

Occupied Right Diagonals.

--------------------------------------------

Base Condition

If

row == n

Store the board

and return.

--------------------------------------------

Recursive Step

Traverse every column.

If

column[j]==0

&&

leftDiag[n-1+j-row]==0

&&

rightDiag[row+j]==0

then

Place Queen.

Mark all arrays.

Solve next row.

Backtrack.

====================================================================================================
solveNQueens()
====================================================================================================

Creates

• Answer Vector

• Chessboard

• Column Array

• Left Diagonal Array

• Right Diagonal Array

Starts recursion from

Row 0.

Returns all possible solutions.

====================================================================================================
BACKTRACKING STEP
====================================================================================================

Place Queen

↓

column[j]=1

Board[row][j]='Q'

leftDiag[n-1+j-row]=1

rightDiag[row+j]=1

↓

Recursive Call

↓

Return

↓

column[j]=0

Board[row][j]='.'

leftDiag[n-1+j-row]=0

rightDiag[row+j]=0

This restores the board and allows trying another column.

====================================================================================================
BASE CONDITION
====================================================================================================

If

row == n

All queens have been placed successfully.

Store the current board.

Return.

====================================================================================================
DRY RUN
====================================================================================================

Suppose

n = 4

Initially

. . . .

. . . .

. . . .

. . . .

----------------------------------------

Row 0

Place Queen

Column 1

. Q . .

. . . .

. . . .

. . . .

----------------------------------------

Row 1

Place Queen

Column 3

. Q . .

. . . Q

. . . .

. . . .

----------------------------------------

Row 2

Place Queen

Column 0

. Q . .

. . . Q

Q . . .

. . . .

----------------------------------------

Row 3

Place Queen

Column 2

. Q . .

. . . Q

Q . . .

. . Q .

Valid Solution Found.

Store it.

Backtrack and continue searching.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Worst Case

O(N!)

Backtracking prunes many invalid states.

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

Board

O(N²)

Column Array

O(N)

Left Diagonal Array

O(2N-1)

Right Diagonal Array

O(2N-1)

Recursion Stack

O(N)

Overall

O(N²)

====================================================================================================
EDGE CASES
====================================================================================================

✓ n = 1

✓ n = 2 (No Solution)

✓ n = 3 (No Solution)

✓ n ≥ 4

====================================================================================================
WHY BACKTRACKING WORKS
====================================================================================================

Whenever a queen placement prevents placing queens in future rows,

we simply

remove the queen,

restore the arrays,

and try another position.

Eventually,

every valid configuration gets explored.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why use Backtracking?

Because every row may have multiple possible choices.

--------------------------------------------

Q2.

Why use three arrays?

To perform safety checking in O(1).

--------------------------------------------

Q3.

Can we scan the board instead?

Yes.

But scanning every time makes the algorithm slower.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Backtracking Problem

✓ One Queen Per Row

✓ O(1) Safety Checking

✓ Uses Three Helper Arrays

✓ Generates All Possible Solutions

✓ Backtracking = Place → Explore → Remove

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• Sudoku Solver

• Rat in a Maze

• Word Search

• M-Coloring Problem

• Hamiltonian Path

• Combination Sum

• Permutations

• Generate Parentheses

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ One of the most important Backtracking problems.

✓ Three arrays reduce safety checking from O(N) to O(1).

✓ Recursion places queens row by row.

✓ Backtracking restores the board after every recursive call.

✓ Generates every valid board configuration.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void find(int row, int n,
              vector<vector<string>>& ans,
              vector<string>& Board,
              vector<bool>& column,
              vector<bool>& leftDiag,
              vector<bool>& rightDiag)
    {
        // Base Condition
        if (row == n)
        {
            ans.push_back(Board);
            return;
        }

        // Put Queen at any n position
        // LeftDiag : n-1 + col-row
        // RightDiag : row+col

        for (int j = 0; j < n; j++)
        {
            if (column[j] == 0 &&
                leftDiag[n - 1 + j - row] == 0 &&
                rightDiag[j + row] == 0)
            {
                column[j] = 1;
                Board[row][j] = 'Q';
                leftDiag[n - 1 + j - row] = 1;
                rightDiag[j + row] = 1;

                find(row + 1, n, ans, Board, column, leftDiag, rightDiag);

                column[j] = 0;
                Board[row][j] = '.';
                leftDiag[n - 1 + j - row] = 0;
                rightDiag[j + row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> Board(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                Board[i].push_back('.');

        vector<bool> leftDiag(2 * n - 1, 0);
        vector<bool> rightDiag(2 * n - 1, 0);

        vector<bool> column(n, 0);

        find(0, n, ans, Board, column, leftDiag, rightDiag);

        return ans;
    }
};

int main() {

    int n = 4;

    Solution obj;

    vector<vector<string>> ans = obj.solveNQueens(n);

    cout << "Total Solutions = " << ans.size() << "\n\n";

    for (int k = 0; k < ans.size(); k++) {

        cout << "Solution " << k + 1 << ":\n";

        for (auto row : ans[k]) {
            cout << row << "\n";
        }

        cout << "\n";
    }

    return 0;
}

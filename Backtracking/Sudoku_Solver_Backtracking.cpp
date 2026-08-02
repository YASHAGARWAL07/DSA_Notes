/*
====================================================================================================
                                  SUDOKU SOLVER (BACKTRACKING)
====================================================================================================

PROBLEM:
LeetCode 37 - Sudoku Solver

====================================================================================================
PROBLEM STATEMENT
====================================================================================================

Given a partially filled 9 × 9 Sudoku board, fill all the empty cells ('.')
such that the completed board satisfies all Sudoku rules.

Sudoku Rules:

1. Every row must contain digits 1 to 9 exactly once.

2. Every column must contain digits 1 to 9 exactly once.

3. Every 3 × 3 sub-grid must contain digits 1 to 9 exactly once.

There will always be one unique solution.

====================================================================================================
PREREQUISITES
====================================================================================================

• Recursion
• Backtracking
• Matrix Traversal
• DFS Thinking

====================================================================================================
INTUITION
====================================================================================================

Whenever we encounter an empty cell,

instead of deciding immediately,

we try every possible digit from

1 → 9.

For every digit,

check whether placing it keeps the Sudoku valid.

If yes,

place the digit

and recursively solve the remaining board.

If later we realize this decision cannot lead to the final solution,

remove the digit

and try another one.

This "Try → Explore → Undo"

is Backtracking.

====================================================================================================
APPROACH
====================================================================================================

Step 1

Traverse the board.

↓

Step 2

If current cell already contains a digit,

move to next cell.

↓

Step 3

If current cell is empty,

try digits

1 to 9.

↓

Step 4

For every digit,

check

• Row

• Column

• 3×3 Box

↓

Step 5

If valid,

place the digit.

↓

Step 6

Recursively solve remaining cells.

↓

Step 7

If recursion succeeds,

return true.

↓

Otherwise,

remove that digit

(backtrack)

and try another one.

====================================================================================================
ALGORITHM
====================================================================================================

find(row,col)

↓

Reached end?

Return true.

↓

Cell already filled?

Move to next cell.

↓

Try numbers

1 → 9

↓

Is number safe?

↓

YES

↓

Place number

↓

Solve remaining board

↓

Success?

YES

Return true

↓

NO

Undo placement

↓

Try next number

====================================================================================================
HOW SAFE CHECK WORKS
====================================================================================================

For every candidate digit,

perform three checks.

1.

Same Row

The digit should not already exist.

-------------------------------------

2.

Same Column

The digit should not already exist.

-------------------------------------

3.

Same 3×3 Box

The digit should not already exist.

Only if all three checks pass,

we place the digit.

====================================================================================================
HOW TO FIND THE 3×3 BOX
====================================================================================================

Suppose current cell is

(i , j)

Then

Starting Row

(i/3)*3

Starting Column

(j/3)*3

Example

Cell = (5,7)

Row Start = 3

Column Start = 6

The corresponding box is

Rows

3 to 5

Columns

6 to 8

====================================================================================================
YOUR IMPLEMENTATION
====================================================================================================

Functions Used

1.

check()

Checks whether a digit can be placed.

Checks

• Row

• Column

• 3×3 Box

------------------------------------

2.

find()

Recursive Backtracking Function.

Moves cell by cell.

Places digits.

Backtracks whenever necessary.

------------------------------------

3.

solveSudoku()

Driver function.

Starts recursion from

(0,0).

====================================================================================================
RECURSION FLOW
====================================================================================================

Empty Cell

↓

Try 1

↓

Invalid

↓

Try 2

↓

Invalid

↓

Try 3

↓

Valid

↓

Place 3

↓

Solve Remaining Board

↓

Failure

↓

Undo

↓

Try 4

↓

Continue...

====================================================================================================
BACKTRACKING STEP
====================================================================================================

board[i][j]='0'+num;

↓

Recursive Call

↓

Failed?

↓

board[i][j]='.';

This restores the original board.

====================================================================================================
BASE CASE
====================================================================================================

If

row == 9

Entire Sudoku has been solved.

Return true.

====================================================================================================
DRY RUN
====================================================================================================

Suppose

board[0][2]='.'

Try

1

Row already has 1

Reject

↓

Try

2

Column already has 2

Reject

↓

Try

3

Box already has 3

Reject

↓

Try

4

Valid

↓

Place 4

↓

Continue recursion.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Worst Case

O(9^(Empty Cells))

Although theoretical complexity is huge,

Backtracking prunes many invalid states.

====================================================================================================
SPACE COMPLEXITY
====================================================================================================

O(Empty Cells)

Recursive stack only.

No extra board is created.

====================================================================================================
EDGE CASES
====================================================================================================

✓ Completely solved board

✓ Nearly empty board

✓ One empty cell

✓ Multiple recursive backtracks

✓ Valid unique solution

====================================================================================================
WHY BACKTRACKING WORKS
====================================================================================================

Whenever a wrong decision is made,

we undo that decision

and explore another possibility.

Eventually,

the only valid configuration remains.

====================================================================================================
WHEN TO USE BACKTRACKING
====================================================================================================

Use Backtracking when

• Need one valid solution

• Need all possible solutions

• Need exhaustive search

Examples

• Sudoku Solver

• N Queens

• Rat in a Maze

• Word Search

• Crossword Puzzle

• M Coloring Problem

• Hamiltonian Path

• Combination Sum

• Permutations

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1.

Why not Greedy?

Because one locally correct decision
may fail later.

------------------------------------

Q2.

Why recursion?

Need to explore all possible choices.

------------------------------------

Q3.

Can Sudoku be optimized?

Yes.

Using

• Bitmasking

• Row Hash

• Column Hash

• Box Hash

instead of scanning entire rows and columns.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Classic Backtracking Problem

✓ DFS + Recursion

✓ Try all digits

✓ Check validity before placing

✓ Undo after failure

✓ Stop immediately after finding solution

====================================================================================================
SIMILAR PROBLEMS
====================================================================================================

• N Queens

• Rat in a Maze

• Word Search

• M Coloring Problem

• Hamiltonian Path

• Crossword Puzzle

• Combination Sum

• Generate Parentheses

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ One of the most important Backtracking problems.

✓ Uses recursion and DFS together.

✓ Backtracking = Try → Explore → Undo.

✓ Always validate before placing a digit.

✓ Restore the board if recursion fails.

✓ Eventually reaches the unique valid solution.

====================================================================================================
VS CODE RUNNABLE IMPLEMENTATION
====================================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(int num, vector<vector<char>>& board, int i, int j){

        char c = '0' + num;

        // Check same row
        for(int col = 0; col < 9; col++){
            if(board[i][col] == c)
                return false;
        }

        // Check same column
        for(int row = 0; row < 9; row++){
            if(board[row][j] == c)
                return false;
        }

        // Check same 3×3 box
        int row = (i / 3) * 3;
        int col = (j / 3) * 3;

        for(int a = row; a < row + 3; a++){
            for(int b = col; b < col + 3; b++){
                if(board[a][b] == c)
                    return false;
            }
        }

        return true;
    }

    bool find(int i, int j, vector<vector<char>>& board){

        // Base Condition
        if(i == 9)
            return true;

        if(j == 9)
            return find(i + 1, 0, board);

        if(board[i][j] != '.')
            return find(i, j + 1, board);

        for(int num = 1; num <= 9; num++){

            if(check(num, board, i, j)){

                board[i][j] = '0' + num;

                if(find(i, j + 1, board))
                    return true;

                // Backtrack
                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board){
        find(0, 0, board);
    }
};

int main(){

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);

    cout << "Solved Sudoku:\n\n";

    for(auto &row : board){
        for(char x : row)
            cout << x << " ";
        cout << '\n';
    }

    return 0;
}
/*
============================================================
        C++ OBJECT SIZE, PADDING & ALIGNMENT – NOTES
============================================================

------------------------------------------------------------
1) WHAT IS PADDING?
------------------------------------------------------------
Padding means:
- Extra unused bytes added by the COMPILER
- Added automatically (not written by programmer)
- Used to satisfy MEMORY ALIGNMENT rules

Padding improves PERFORMANCE, not memory usage.

------------------------------------------------------------
2) WHY PADDING IS REQUIRED?
------------------------------------------------------------
CPU does NOT read memory byte-by-byte.
CPU reads memory in CHUNKS (cycles).

To read data in ONE CPU cycle:
- Data must be properly ALIGNED

If not aligned:
- CPU needs MULTIPLE cycles (slow)

------------------------------------------------------------
3) ALIGNMENT RULES (COMMON)
------------------------------------------------------------
Data Type     Size     Alignment
--------------------------------
char          1 byte   1
short         2 bytes  2
int           4 bytes  4
float         4 bytes  4
double        8 bytes  8
--------------------------------

Rule:
A data type must start at an address
that is a MULTIPLE of its alignment.

------------------------------------------------------------
4) SIMPLE PADDING EXAMPLE
------------------------------------------------------------

struct A {
    char c;   // 1 byte
    int  a;   // 4 bytes
};

Memory Layout (32/64-bit):

Address:  0   1   2   3   4   5   6   7
          | c | P | P | P | a | a | a | a |

Explanation:
- char uses 1 byte
- int needs alignment of 4
- Padding added = 3 bytes

Total size = 8 bytes (NOT 5)

------------------------------------------------------------
5) MULTIPLE MEMBERS PADDING
------------------------------------------------------------

struct B {
    char c;   // 1 byte
    char b;   // 1 byte
    int  a;   // 4 bytes
};

Memory Layout:

Address:  0   1   2   3   4   5   6   7
          | c | b | P | P | a | a | a | a |

Padding:
- 2 bytes added before int

Total size = 8 bytes

------------------------------------------------------------
6) BAD ORDER CAUSES MORE PADDING
------------------------------------------------------------

struct Bad {
    char c;   // 1
    int  a;   // 4
    char b;   // 1
};

Memory:
c (1) + 3 padding
a (4)
b (1) + 3 padding
---------------------
Total = 12 bytes ❌

------------------------------------------------------------
7) GOOD ORDER (GREEDY ALIGNMENT)
------------------------------------------------------------

struct Good {
    int  a;   // 4
    char c;   // 1
    char b;   // 1
};

Memory:
a (4)
c (1)
b (1)
padding (2)
---------------------
Total = 8 bytes ✔

RULE:
Always place BIGGER data types FIRST.

------------------------------------------------------------
8) GREEDY ALIGNMENT RULE
------------------------------------------------------------
Structure alignment =
Alignment of LARGEST data type inside struct

Example:
int → alignment 4
double → alignment 8

Structure size must be MULTIPLE of alignment.

------------------------------------------------------------
9) EXAMPLE (FROM CLASS NOTES – 8 BYTE)
------------------------------------------------------------

struct C {
    char c;   // 1
    char b;   // 1
    int  a;   // 4
};

Used bytes = 6
Padding = 2
Final size = 8 bytes ✔

------------------------------------------------------------
10) EXAMPLE (FROM CLASS NOTES – 12 BYTE)
------------------------------------------------------------

struct D {
    char c;   // 1
    int  a;   // 4
    char b;   // 1
};

Memory:
c (1) + 3 padding
a (4)
b (1) + 3 padding
---------------------
Total = 12 bytes ❌

------------------------------------------------------------
11) EMPTY CLASS SIZE = 1 (VERY IMPORTANT)
------------------------------------------------------------

class Empty {};

sizeof(Empty) == 1

Reason:
- Every object must have UNIQUE address
- Size 0 would cause address conflict
- Compiler assigns minimum size = 1 byte

------------------------------------------------------------
12) PADDING vs ALIGNMENT
------------------------------------------------------------
Alignment:
- RULE where data SHOULD start

Padding:
- EXTRA bytes added to FOLLOW alignment

Alignment = Cause
Padding   = Effect

------------------------------------------------------------
13) 32-bit vs 64-bit SYSTEM
------------------------------------------------------------
- 32-bit OS: alignment mostly up to 4 bytes
- 64-bit OS: alignment can go up to 8 bytes

BUT:
char, int, float sizes remain same
(pointer size changes)

------------------------------------------------------------
14) HOW TO REDUCE PADDING?
------------------------------------------------------------
1) Reorder data members
2) Place largest data type first
3) Avoid char → int → char patterns

------------------------------------------------------------
15) INTERVIEW / EXAM POINTS
------------------------------------------------------------
✔ Padding is compiler dependent
✔ Structure size is multiple of largest data type
✔ Proper order saves memory
✔ Padding improves performance
✔ Empty class size is 1

------------------------------------------------------------
16) FINAL GOLDEN RULE
------------------------------------------------------------
Think like a COMPILER:
"Where will this variable sit in memory?"

Memory optimization =
Correct order + Alignment awareness

============================================================
                    END OF NOTES
============================================================
*/

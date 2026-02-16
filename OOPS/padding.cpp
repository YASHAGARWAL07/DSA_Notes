/************************************************************
        C++ OBJECT SIZE, PADDING & ALIGNMENT
************************************************************/

/*
============================================================
1. WHAT IS PADDING
------------------------------------------------------------
Padding means extra unused bytes added by the compiler
to satisfy memory alignment rules.

- Added automatically
- Not written by programmer
- Improves performance
============================================================
*/

/*
============================================================
2. WHY PADDING IS REQUIRED
------------------------------------------------------------
CPU does not read memory byte-by-byte.
It reads memory in fixed-size chunks.

For efficient access:
Data must be properly aligned.

If data is misaligned:
- CPU needs multiple cycles
- Performance decreases
============================================================
*/

/*
============================================================
3. ALIGNMENT RULES (COMMON)
------------------------------------------------------------

Data Type    Size    Alignment
--------------------------------
char         1       1
short        2       2
int          4       4
float        4       4
double       8       8
--------------------------------

Rule:
A data type must start at an address
that is a multiple of its alignment.
============================================================
*/

/*
============================================================
4. SIMPLE PADDING EXAMPLE
============================================================
*/

struct A {
    char c;   // 1 byte
    int  a;   // 4 bytes
};

/*
Memory Layout:

| c | P | P | P | a | a | a | a |

- char uses 1 byte
- int needs 4-byte alignment
- 3 bytes padding added

Total size = 8 bytes (not 5)
============================================================
*/

/*
============================================================
5. MULTIPLE MEMBERS PADDING
============================================================
*/

struct B {
    char c;   // 1 byte
    char b;   // 1 byte
    int  a;   // 4 bytes
};

/*
Layout:

| c | b | P | P | a | a | a | a |

Padding = 2 bytes
Total size = 8 bytes
============================================================
*/

/*
============================================================
6. BAD ORDER CAUSES MORE PADDING
============================================================
*/

struct Bad {
    char c;   // 1
    int  a;   // 4
    char b;   // 1
};

/*
Layout:
c (1) + 3 padding
a (4)
b (1) + 3 padding

Total = 12 bytes
============================================================
*/

/*
============================================================
7. GOOD ORDER (GREEDY ALIGNMENT)
============================================================
*/

struct Good {
    int  a;   // 4
    char c;   // 1
    char b;   // 1
};

/*
Layout:
a (4)
c (1)
b (1)
padding (2)

Total = 8 bytes

Rule:
Place larger data types first.
============================================================
*/

/*
============================================================
8. STRUCTURE ALIGNMENT RULE
------------------------------------------------------------
Structure alignment equals alignment of
largest data type inside it.

Structure size must be multiple of
largest alignment.
============================================================
*/

/*
============================================================
9. EXAMPLE – 8 BYTE STRUCT
============================================================
*/

struct C {
    char c;   // 1
    char b;   // 1
    int  a;   // 4
};

/*
Used bytes = 6
Padding = 2
Final size = 8 bytes
============================================================
*/

/*
============================================================
10. EXAMPLE – 12 BYTE STRUCT
============================================================
*/

struct D {
    char c;   // 1
    int  a;   // 4
    char b;   // 1
};

/*
c (1) + 3 padding
a (4)
b (1) + 3 padding

Total = 12 bytes
============================================================
*/

/*
============================================================
11. EMPTY CLASS SIZE
============================================================
*/

class Empty {};

/*
sizeof(Empty) = 1

Reason:
- Every object must have unique address
- Size 0 would cause address conflict
- Compiler assigns minimum size = 1 byte
============================================================
*/

/*
============================================================
12. PADDING VS ALIGNMENT
------------------------------------------------------------
Alignment:
Rule that decides where data should start.

Padding:
Extra bytes added to satisfy alignment.

Alignment = Cause
Padding   = Effect
============================================================
*/

/*
============================================================
13. 32-BIT VS 64-BIT SYSTEM
------------------------------------------------------------
- 32-bit systems: alignment often up to 4 bytes
- 64-bit systems: alignment can be up to 8 bytes
- Primitive type sizes remain same
- Pointer size changes (4 vs 8 bytes)
============================================================
*/

/*
============================================================
14. HOW TO REDUCE PADDING
------------------------------------------------------------
1) Reorder data members
2) Place largest type first
3) Avoid patterns like char-int-char
============================================================
*/

/*
============================================================
15. IMPORTANT EXAM POINTS
------------------------------------------------------------
- Padding is compiler dependent
- Structure size is multiple of largest alignment
- Proper ordering saves memory
- Padding improves performance
- Empty class size is 1 byte
============================================================
*/

/*
============================================================
16. FINAL RULE
------------------------------------------------------------
Think like the compiler:
Where will this variable sit in memory?

Memory optimization =
Correct ordering + Alignment awareness
============================================================
*/

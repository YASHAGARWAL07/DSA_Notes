/*
====================================================================================================
                                       HASHING BASICS
====================================================================================================

====================================================================================================
INTRODUCTION TO HASHING
====================================================================================================

Hashing is a technique used to store, search and retrieve data efficiently.

Instead of searching elements one by one, hashing computes the storage location
using a Hash Function.

Searching, Insertion and Deletion are performed in O(1) average time.

====================================================================================================
WHY HASHING?
====================================================================================================

Suppose we have 1,000,000 numbers and want to search 752143.

Linear Search  → O(N)

Binary Search  → O(log N) (Requires sorted data)

Hashing        → O(1) Average

Hence, hashing is one of the fastest searching techniques.

====================================================================================================
UNDERSTANDING HASHING USING A QUESTION
====================================================================================================

Question

Array = {2,5,8,5,1,8,2,5}

Find frequency of every element.

Without Hashing

Traverse the complete array for every element.

Time Complexity = O(N²)

Using Hashing

2 → 2

5 → 3

8 → 2

1 → 1

Time Complexity = O(N)

Hashing converts many O(N²) problems into O(N).

====================================================================================================
WHAT IS HASHING?
====================================================================================================

Hashing converts a

Key

↓

Hash Function

↓

Hash Value

↓

Index

↓

Hash Table

Instead of storing data randomly, it stores data at a calculated position.

====================================================================================================
TERMINOLOGY
====================================================================================================

Key
→ Value to be stored or searched.

Hash Function
→ Converts a key into an index.

Hash Value
→ Output of the Hash Function.

Hash Table
→ Array where data is stored.

Bucket
→ Each position inside the Hash Table.

====================================================================================================
HASH FUNCTION
====================================================================================================

A Hash Function converts

Key → Index

Example

Hash(x) = x % 10

Key = 42

Index = 2

====================================================================================================
CHARACTERISTICS OF A GOOD HASH FUNCTION
====================================================================================================

✓ Deterministic
→ Same input always gives the same output.

✓ Fast
→ Computes quickly.

✓ Uniform Distribution
→ Keys should spread uniformly.

✓ Minimum Collisions
→ Different keys should ideally map to different indices.

====================================================================================================
HOW HASHING WORKS
====================================================================================================

Store 25

Hash(25) = 25 % 10 = 5

Store at

HashTable[5]

Searching

25

↓

Hash(25)

↓

5

↓

Directly check HashTable[5]

====================================================================================================
INDEX MAPPING
====================================================================================================

Hash(x) = x % 10

21 → 1

45 → 5

62 → 2

99 → 9

====================================================================================================
REAL LIFE EXAMPLES
====================================================================================================

• Phone Contacts

Name → Phone Number

• Dictionary

Word → Meaning

• Student Database

Roll Number → Student Record

• Password Storage

Password → Hash Value

====================================================================================================
DRY RUN
====================================================================================================

Hash Function

Hash(x) = x % 10

Insert

12 → Bucket 2

25 → Bucket 5

38 → Bucket 8

91 → Bucket 1

Final Hash Table

1 → 91

2 → 12

5 → 25

8 → 38

====================================================================================================
BASIC APPLICATIONS
====================================================================================================

• Frequency Counting

• Searching

• Duplicate Detection

• Dictionary

• Phone Directory

• Database Indexing

• Compiler Symbol Table

• Caching

====================================================================================================
/*
/*
====================================================================================================
ADVANTAGES OF HASHING
====================================================================================================

Hashing is widely used because of its fast performance.

Some major advantages are:

✓ Average Search Time      → O(1)

✓ Average Insertion Time   → O(1)

✓ Average Deletion Time    → O(1)

✓ No need to sort the data.

✓ Very efficient for Frequency Counting.

✓ Fast duplicate detection.

✓ Direct access to data using keys.

✓ Used extensively in real-world software and databases.

====================================================================================================
LIMITATIONS OF HASHING
====================================================================================================

Although hashing is very fast, it also has some drawbacks.

✗ Collisions cannot be completely avoided.

✗ Worst Case Complexity becomes O(N).

✗ Requires additional memory for Hash Table.

✗ unordered_map does not maintain sorted order.

✗ Performance depends on the quality of the Hash Function.

====================================================================================================
HASHING vs LINEAR SEARCH
====================================================================================================

Linear Search

• Checks every element one by one.

• Does not require extra memory.

• Works on unsorted data.

• Time Complexity

Search = O(N)

--------------------------------------------

Hashing

• Computes storage location directly.

• Requires extra memory.

• Average Search = O(1)

• Much faster for repeated searching.

====================================================================================================
HASHING vs BINARY SEARCH
====================================================================================================

Binary Search

• Works only on sorted data.

• Time Complexity

Search = O(log N)

--------------------------------------------

Hashing

• Sorting is not required.

• Average Search = O(1)

• Better for fast lookup.

====================================================================================================
WHEN SHOULD WE USE HASHING?
====================================================================================================

Hashing should be preferred when

✓ Fast Searching is required.

✓ Fast Insertion is required.

✓ Fast Deletion is required.

✓ Frequency Counting is required.

✓ Duplicate Detection is required.

✓ Key-Value Mapping is needed.

====================================================================================================
COMMON HASHING PROBLEMS
====================================================================================================

Some of the most frequently asked interview problems are:

✓ Frequency of Elements

✓ Two Sum

✓ Contains Duplicate

✓ Longest Consecutive Sequence

✓ Longest Subarray with Sum K

✓ Subarray Sum Equals K

✓ First Non-Repeating Character

✓ Group Anagrams

✓ Happy Number

✓ Valid Sudoku

====================================================================================================
REAL-WORLD APPLICATIONS
====================================================================================================

Hashing is used in many real-world systems.

Some common applications are

• Database Indexing

• Phone Directory

• Dictionary

• Caching

• Compiler Symbol Table

• Password Storage

• Routing Tables

• DNS Lookup

• Blockchain

• Spell Checker

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1. What is Hashing?

Hashing is the process of mapping a key to an index using a Hash Function.

--------------------------------------------

Q2. Why is Hashing faster than Linear Search?

Because it directly computes the storage location instead of checking every
element.

--------------------------------------------

Q3. Does Hashing always work in O(1)?

No.

Average Case

O(1)

Worst Case

O(N)

due to collisions.

--------------------------------------------

Q4. Can Hashing replace Binary Search?

No.

Binary Search is useful when sorted order is required.

Hashing is useful when fast lookup is required.

--------------------------------------------

Q5. What are the disadvantages of Hashing?

• Collision

• Extra Memory

• Worst Case O(N)

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Hashing provides Average O(1) searching.

✓ Hash Function computes the storage location.

✓ Hash Table stores the data.

✓ Good Hash Functions reduce collisions.

✓ Hashing is one of the most important interview topics.

✓ Frequency Counting is the most common use of Hashing.

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Hashing converts a Key into an Index.

✓ Hash Function determines where data is stored.

✓ Hash Table stores elements at computed locations.

✓ Average Search, Insert and Delete are O(1).

✓ Collisions are unavoidable but can be minimized.

✓ Hashing is much faster than Linear Search.

✓ unordered_map and unordered_set are based on Hash Tables.

✓ Hashing is widely used in databases, caching, compilers and competitive
programming.

====================================================================================================
*/
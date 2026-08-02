/*
====================================================================================================
                              HASHING INTERVIEW NOTES
====================================================================================================

====================================================================================================
MOST IMPORTANT INTERVIEW TOPICS
====================================================================================================

Before appearing in coding interviews, every student should be comfortable with

✓ Hash Function

✓ Hash Table

✓ Collision

✓ Collision Resolution Techniques

✓ Load Factor

✓ Rehashing

✓ unordered_map

✓ unordered_set

✓ map

✓ set

✓ Time Complexities

✓ Frequency Counting

✓ String Hashing

✓ Cryptographic Hashing

====================================================================================================
COMMON HASHING PATTERNS
====================================================================================================

1. Frequency Counting

Store the frequency of every element.

Example

unordered_map<int,int> freq;

for(auto x : arr)

freq[x]++;

------------------------------------------------------------

2. Fast Searching

Instead of Linear Search,

store elements inside a Hash Table.

Searching becomes

Average O(1).

------------------------------------------------------------

3. Duplicate Detection

Insert every element into

unordered_set.

If insertion fails,

duplicate exists.

------------------------------------------------------------

4. Key-Value Mapping

Use

unordered_map

whenever one value depends on another.

Examples

Student → Marks

Employee → Salary

Country → Capital

====================================================================================================
MOST ASKED LEETCODE QUESTIONS
====================================================================================================

✓ Two Sum

✓ Contains Duplicate

✓ Valid Anagram

✓ Group Anagrams

✓ Happy Number

✓ Top K Frequent Elements

✓ Longest Consecutive Sequence

✓ Isomorphic Strings

✓ Word Pattern

✓ Valid Sudoku

✓ Find All Anagrams in a String

✓ Subarray Sum Equals K

✓ Longest Subarray with Sum K

====================================================================================================
MOST ASKED GFG QUESTIONS
====================================================================================================

✓ Frequency of Array Elements

✓ Count Distinct Elements

✓ Pair with Given Sum

✓ Zero Sum Subarray

✓ Largest Subarray with Sum Zero

✓ First Repeating Element

✓ First Non-Repeating Element

✓ Count Pairs with Given Sum

====================================================================================================
COMMON MISTAKES
====================================================================================================

✗ Using map when ordering is not required.

Prefer

unordered_map.

------------------------------------------------------------

✗ Forgetting that unordered_map does not maintain order.

------------------------------------------------------------

✗ Ignoring Hash Collisions.

Worst Case Complexity becomes

O(N).

------------------------------------------------------------

✗ Using operator[]

for searching.

Example

mp[key]

creates a new key if it does not exist.

Use

find()

instead.

------------------------------------------------------------

✗ Forgetting to handle duplicate keys.

====================================================================================================
BEST PRACTICES
====================================================================================================

✓ Use unordered_map for Frequency Counting.

✓ Use unordered_set for Duplicate Detection.

✓ Use map when sorted order is required.

✓ Reserve larger Hash Tables for huge datasets.

✓ Choose good Hash Functions.

✓ Avoid unnecessary collisions.

====================================================================================================
WHEN TO USE WHICH CONTAINER?
====================================================================================================

Need Fast Lookup

↓

unordered_map

------------------------------------------------------------

Need Sorted Key-Value Pairs

↓

map

------------------------------------------------------------

Need Fast Unique Elements

↓

unordered_set

------------------------------------------------------------

Need Sorted Unique Elements

↓

set

====================================================================================================
TIME COMPLEXITY SUMMARY
====================================================================================================

unordered_map

Insertion

Average O(1)

Worst O(N)

--------------------------------------------

Searching

Average O(1)

Worst O(N)

--------------------------------------------

Deletion

Average O(1)

Worst O(N)

====================================================================================================

unordered_set

Insertion

Average O(1)

Worst O(N)

--------------------------------------------

Searching

Average O(1)

Worst O(N)

--------------------------------------------

Deletion

Average O(1)

Worst O(N)

====================================================================================================

map

Insertion

O(log N)

Searching

O(log N)

Deletion

O(log N)

====================================================================================================

set

Insertion

O(log N)

Searching

O(log N)

Deletion

O(log N)

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1. What is Hashing?

Mapping a key to an index using a Hash Function.

------------------------------------------------------------

Q2. Why is Hashing faster than Linear Search?

Because it directly computes the storage location instead of checking every
element.

------------------------------------------------------------

Q3. What is a Collision?

When two different keys generate the same Hash Value.

------------------------------------------------------------

Q4. Which collision handling technique is used in unordered_map?

Separate Chaining
(Implementation dependent)

------------------------------------------------------------

Q5. Difference between map and unordered_map?

map

• Red-Black Tree

• Sorted

• O(log N)

unordered_map

• Hash Table

• Unordered

• Average O(1)

------------------------------------------------------------

Q6. Difference between set and unordered_set?

set

• Sorted

• O(log N)

unordered_set

• Unordered

• Average O(1)

------------------------------------------------------------

Q7. What is Rehashing?

Increasing the Hash Table size and reinserting all elements to reduce collisions.

------------------------------------------------------------

Q8. What is Load Factor?

Load Factor = Number of Elements / Number of Buckets

------------------------------------------------------------

Q9. Why are good Hash Functions important?

They reduce collisions and improve overall performance.

------------------------------------------------------------

Q10. Why should passwords be hashed?

To improve security and prevent storing passwords in plain text.

====================================================================================================
INTERVIEW TIPS
====================================================================================================

✓ Always explain Average and Worst Case complexities.

✓ Mention Collision Handling whenever discussing Hash Tables.

✓ Prefer unordered_map unless sorted order is required.

✓ Explain why map uses Red-Black Tree.

✓ Remember that Hashing provides Average O(1), not guaranteed O(1).

✓ Mention Rehashing whenever discussing performance degradation.

====================================================================================================
REVISION CHECKLIST
====================================================================================================

□ Hash Function

□ Hash Table

□ Buckets

□ Hash Code

□ Collision

□ Separate Chaining

□ Linear Probing

□ Quadratic Probing

□ Double Hashing

□ Load Factor

□ Rehashing

□ unordered_map

□ unordered_set

□ map

□ set

□ String Hashing

□ Polynomial Hashing

□ Cryptographic Hashing

□ Digital Signature

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Hashing is one of the most important interview topics.

✓ Average complexity of Hash Table operations is O(1).

✓ Collisions are unavoidable but manageable.

✓ unordered_map is the most frequently used STL container in Competitive Programming.

✓ map and set maintain sorted order using Red-Black Trees.

✓ Hashing is used in databases, compilers, caching, networking, operating systems,
blockchain, cryptography, and modern software systems.

✓ Choosing the correct STL container improves both performance and code quality.

====================================================================================================
*/
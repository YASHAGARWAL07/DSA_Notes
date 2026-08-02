/*
====================================================================================================
                               HASHING PROBLEM PATTERNS
====================================================================================================

====================================================================================================
INTRODUCTION
====================================================================================================

Most Hashing problems asked in coding interviews follow a few common patterns.

Instead of memorizing individual problems, learn these patterns.

Once you identify the pattern, choosing the correct Hashing data structure
becomes much easier.

====================================================================================================
PATTERN 1 : FREQUENCY COUNTING
====================================================================================================

Use

unordered_map<Key, Frequency>

whenever the problem asks

• Count occurrences

• Frequency of elements

• Most frequent element

• Least frequent element

Example Problems

✓ Frequency of Array Elements

✓ Top K Frequent Elements

✓ Majority Element

✓ Sort Characters by Frequency

====================================================================================================
PATTERN 2 : FAST LOOKUP
====================================================================================================

Use

unordered_set

or

unordered_map

when frequent searching is required.

Instead of Linear Search,

store every element inside a Hash Table.

Searching becomes

Average O(1).

Example Problems

✓ Contains Duplicate

✓ Two Sum

✓ Happy Number

✓ Longest Consecutive Sequence

====================================================================================================
PATTERN 3 : DUPLICATE DETECTION
====================================================================================================

Store visited elements inside

unordered_set.

If insertion fails,

the element has already appeared.

Example Problems

✓ Contains Duplicate

✓ Find Duplicate Number

✓ First Repeating Element

====================================================================================================
PATTERN 4 : KEY → VALUE MAPPING
====================================================================================================

Use

unordered_map

whenever one value depends on another.

Examples

Student → Marks

Country → Capital

Employee → Salary

Character → Frequency

====================================================================================================
PATTERN 5 : PREFIX SUM + HASH MAP
====================================================================================================

Store

Prefix Sum

↓

Index/Frequency

Useful for

✓ Subarray Sum Equals K

✓ Longest Subarray with Sum K

✓ Zero Sum Subarray

====================================================================================================
PATTERN 6 : CHARACTER HASHING
====================================================================================================

Store frequency of characters.

Example

unordered_map<char,int>

Useful for

✓ Valid Anagram

✓ Group Anagrams

✓ First Unique Character

✓ Ransom Note

====================================================================================================
PATTERN 7 : STRING HASHING
====================================================================================================

Instead of comparing complete strings,

compare their Hash Values.

Applications

✓ Rabin-Karp

✓ Duplicate Strings

✓ Longest Common Substring

====================================================================================================
WHICH CONTAINER SHOULD I CHOOSE?
====================================================================================================

Need Fast Key-Value Lookup

↓

unordered_map

------------------------------------------------------------

Need Unique Elements

↓

unordered_set

------------------------------------------------------------

Need Sorted Keys

↓

map

------------------------------------------------------------

Need Sorted Unique Elements

↓

set

====================================================================================================
MOST IMPORTANT HASHING PROBLEMS
====================================================================================================

Easy

✓ Two Sum

✓ Contains Duplicate

✓ Valid Anagram

✓ Intersection of Two Arrays

✓ Happy Number

--------------------------------------------

Medium

✓ Group Anagrams

✓ Top K Frequent Elements

✓ Longest Consecutive Sequence

✓ Subarray Sum Equals K

✓ Isomorphic Strings

--------------------------------------------

Hard

✓ Minimum Window Substring

✓ Sliding Window Median

✓ Find All Anagrams in a String

✓ Longest Duplicate Substring

====================================================================================================
HOW TO IDENTIFY A HASHING PROBLEM?
====================================================================================================

If the question contains words like

• Frequency

• Count

• Duplicate

• Fast Search

• Distinct

• Lookup

• Mapping

• Visited

• Pair Sum

there is a high chance that Hashing can be used.

====================================================================================================
COMMON MISTAKES
====================================================================================================

✗ Using map instead of unordered_map without needing sorted order.

✗ Forgetting that operator[] creates a key if it does not exist.

✗ Ignoring Worst Case O(N) complexity due to collisions.

✗ Assuming unordered containers preserve insertion order.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Hashing is mainly used to reduce time complexity.

✓ unordered_map is the most commonly used hashing container.

✓ Frequency Counting is the most common Hashing pattern.

✓ Prefix Sum + Hash Map is one of the most important interview techniques.

✓ Always choose the container according to the problem requirements.

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Learn patterns instead of memorizing problems.

✓ Identify whether the problem needs Frequency, Lookup or Mapping.

✓ Practice Prefix Sum + Hashing extensively.

✓ Master unordered_map and unordered_set before moving to advanced topics.

✓ Hashing is one of the highest-frequency topics in coding interviews.

====================================================================================================
*/
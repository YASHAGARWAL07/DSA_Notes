/*
====================================================================================================
                                 ADVANCED HASHING CONCEPTS
====================================================================================================

====================================================================================================
WHY ARE HASH FUNCTIONS IMPORTANT?
====================================================================================================

A Hash Function is the heart of every Hash Table.

Its job is to convert a key into an index where the data will be stored.

Instead of searching every location one by one, the Hash Function directly
calculates the correct bucket.

General Flow

Key

↓

Hash Function

↓

Bucket Number

↓

Store/Search/Delete

Without a Hash Function,

Hash Tables cannot work efficiently.

====================================================================================================
WHY DO WE NEED A GOOD HASH FUNCTION?
====================================================================================================

Suppose we have a Hash Table of size 10.

Hash Function

Hash(x) = x % 10

Now insert

12

22

32

42

52

All values are stored in

Bucket 2.

This creates multiple collisions.

Searching becomes slower because we now have to traverse all elements stored
inside Bucket 2.

A poor Hash Function results in

✓ More Collisions

✓ Poor Performance

✓ Increased Searching Time

A good Hash Function distributes elements uniformly across all buckets.

====================================================================================================
CHARACTERISTICS OF A GOOD HASH FUNCTION
====================================================================================================

A good Hash Function should satisfy the following properties.

1. Deterministic

The same key should always produce the same hash value.

Example

Hash(25)

must always return

5.

------------------------------------------------------------

2. Fast Computation

Computing the Hash Function should take very little time.

If computing the hash itself becomes expensive,

overall performance decreases.

------------------------------------------------------------

3. Uniform Distribution

Keys should be distributed evenly across all buckets.

Good Distribution

Bucket

0 → 15

1 → 41

2 → 22

3 → 53

4 → 94

Every bucket contains almost equal elements.

Bad Distribution

Bucket

0

↓

15

25

35

45

55

Only one bucket is being used.

This increases collisions.

------------------------------------------------------------

4. Minimum Collisions

Different keys should ideally map to different buckets.

Although collisions cannot be completely avoided,

they should occur as rarely as possible.

------------------------------------------------------------

5. Uses Entire Hash Table

A good Hash Function should utilize all available buckets.

If only a few buckets are used,

memory gets wasted and collisions increase.

====================================================================================================
DESIGNING A GOOD HASH FUNCTION
====================================================================================================

Designing a good Hash Function is one of the most important tasks while
implementing a Hash Table.

A poorly designed function can make a Hash Table perform almost like
Linear Search.

Some commonly used techniques are

✓ Division Method

✓ Multiplication Method

✓ Folding Method

✓ Mid-Square Method

====================================================================================================
1. DIVISION METHOD
====================================================================================================

The most commonly used Hash Function.

Formula

Hash(key) = key % TableSize

Example

Table Size = 10

Key

23

↓

23 % 10

↓

3

Store at Bucket 3.

Advantages

✓ Very simple

✓ Fast

✓ Easy to implement

Disadvantages

✗ Poor choice of Table Size can increase collisions.

====================================================================================================
2. MULTIPLICATION METHOD
====================================================================================================

Instead of using modulo directly,

the key is multiplied by a constant.

General Formula

Hash(key)

=

⌊TableSize × Fractional Part(Key × A)⌋

where

0 < A < 1

This method often gives a better distribution than simple modulo hashing.

====================================================================================================
3. FOLDING METHOD
====================================================================================================

Large keys are divided into smaller parts.

These parts are added together.

The final sum is used as the hash value.

Example

Key

12345678

Split into

12

34

56

78

Sum

12 + 34 + 56 + 78

=

180

Hash Value

180 % TableSize

This method is commonly used for very large numerical keys.

====================================================================================================
4. MID-SQUARE METHOD
====================================================================================================

The key is squared.

Then the middle digits are extracted.

Example

Key

25

↓

Square

625

↓

Middle Digit

2

↓

Hash Value

2

This method produces a fairly uniform distribution for many inputs.

====================================================================================================
UNIFORM DISTRIBUTION
====================================================================================================

Uniform Distribution means

every bucket should receive approximately the same number of elements.

Good Distribution

Bucket

0 → 1 Element

1 → 2 Elements

2 → 1 Element

3 → 2 Elements

4 → 1 Element

Searching remains efficient.

====================================================================================================
POOR DISTRIBUTION
====================================================================================================

Bucket

0 → 20 Elements

1 → 0

2 → 0

3 → 0

4 → 0

Searching becomes almost

O(N)

because one bucket stores nearly every element.

====================================================================================================
WHY UNIFORM DISTRIBUTION MATTERS?
====================================================================================================

Uniform Distribution

↓

Fewer Collisions

↓

Shorter Chains

↓

Faster Searching

↓

Better Performance

====================================================================================================
REAL LIFE EXAMPLES
====================================================================================================

Phone Directory

Name

↓

Hash Function

↓

Bucket

↓

Phone Number

--------------------------------------------

Database

Primary Key

↓

Hash Function

↓

Bucket

↓

Record

--------------------------------------------

Compiler

Variable Name

↓

Hash Function

↓

Symbol Table

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ A Hash Function converts a key into a bucket index.

✓ Good Hash Functions reduce collisions.

✓ Uniform Distribution improves performance.

✓ A poor Hash Function can make Hash Tables as slow as Linear Search.

✓ Division Method is the most commonly used hashing technique.

✓ Different applications may require different Hash Functions.

====================================================================================================
*/
/*
====================================================================================================
HASH CODES
====================================================================================================

A Hash Code is the numerical value produced by a Hash Function.

Instead of storing the original key directly,

the Hash Function first converts it into a Hash Code.

This Hash Code is then used to determine the bucket where the element will
be stored.

General Flow

Key

↓

Hash Function

↓

Hash Code

↓

Bucket Number

↓

Store Element

Example

Key

"APPLE"

↓

Hash Function

↓

Hash Code

458723

↓

Bucket

458723 % TableSize

Every programming language internally generates Hash Codes for objects before
storing them inside a Hash Table.

====================================================================================================
WHY DO WE NEED HASH CODES?
====================================================================================================

Suppose we want to store

"Yash"

inside an unordered_map.

Strings cannot directly act as array indices.

Therefore,

the string is first converted into an integer called

Hash Code.

That integer is then mapped to a bucket.

Without Hash Codes,

storing strings, objects and custom data types inside a Hash Table would not
be possible.

====================================================================================================
STRING HASHING
====================================================================================================

String Hashing converts an entire string into a single integer value.

Instead of comparing complete strings repeatedly,

their Hash Values are compared.

This makes searching and comparison much faster.

Example

"apple"

↓

Hash Value

12345678

Now,

instead of comparing

"a"

"p"

"p"

"l"

"e"

we simply compare

12345678

This significantly reduces computation.

====================================================================================================
WHY STRING HASHING?
====================================================================================================

Suppose we have

100000 strings.

Searching every string character by character is expensive.

Instead,

we compute one Hash Value for every string.

Comparison becomes

Hash Value

↓

Hash Value

rather than

Character

↓

Character

This improves performance in many algorithms.

====================================================================================================
POLYNOMIAL HASHING
====================================================================================================

Polynomial Hashing is one of the most commonly used String Hashing techniques.

It is widely used in

Competitive Programming,

Pattern Matching,

and

Rabin-Karp Algorithm.

Formula

Hash(s)

=

(s₀ × p⁰)

+

(s₁ × p¹)

+

(s₂ × p²)

+ ...

mod M

where

p

=

Prime Number

Example

31

53

M

=

Large Prime

Example

1e9+7

====================================================================================================
EXAMPLE
====================================================================================================

String

"abc"

Assign Values

a = 1

b = 2

c = 3

Choose

p = 31

Hash

=

1 × 31⁰

+

2 × 31¹

+

3 × 31²

This produces a unique numerical representation of the string.

====================================================================================================
ADVANTAGES OF POLYNOMIAL HASHING
====================================================================================================

✓ Fast String Comparison.

✓ Efficient Pattern Matching.

✓ Supports Prefix Hashing.

✓ Used in Rabin-Karp Algorithm.

✓ Reduces repeated character comparisons.

====================================================================================================
LIMITATIONS
====================================================================================================

✗ Different strings may still generate the same Hash Value.

This situation is called

Hash Collision.

Therefore,

String Hashing is usually combined with

Large Prime Numbers

or

Double Hashing

to reduce collisions.

====================================================================================================
APPLICATIONS OF STRING HASHING
====================================================================================================

✓ Rabin-Karp Pattern Searching

✓ Duplicate String Detection

✓ Longest Common Substring

✓ String Matching

✓ Dictionary Applications

✓ Spell Checkers

✓ DNA Sequence Matching

✓ Competitive Programming

====================================================================================================
DRY RUN
====================================================================================================

String

"cat"

Assign

c = 3

a = 1

t = 20

Using

p = 31

Hash

=

3 × 31⁰

+

1 × 31¹

+

20 × 31²

↓

Single Integer Value

Instead of comparing

c

a

t

individually,

only one Hash Value is compared.

This makes searching significantly faster.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Hash Code is an integer generated by a Hash Function.

✓ Strings are usually converted into Hash Codes before storage.

✓ Polynomial Hashing is the most commonly used String Hashing technique.

✓ Large Prime Numbers help reduce collisions.

✓ String Hashing is widely used in Competitive Programming.

====================================================================================================
*/
/*
====================================================================================================
                              HASH COLLISION HANDLING
====================================================================================================

====================================================================================================
WHAT IS A HASH COLLISION?
====================================================================================================

A Hash Collision occurs when two or more different keys produce the same
Hash Value (same bucket/index).

Since the Hash Table has a fixed number of buckets but the number of possible
keys is much larger, collisions are unavoidable.

Example

Hash Function

Hash(x) = x % 10

25 → 5

35 → 5

45 → 5

All three keys are mapped to Bucket 5.

This situation is called a Hash Collision.

It does NOT mean the Hash Function is incorrect.

It simply means multiple keys have generated the same index.

====================================================================================================
WHY DO COLLISIONS OCCUR?
====================================================================================================

Collisions mainly occur because of two reasons.

1. Limited Hash Table Size

Suppose the Hash Table has only 10 buckets.

Possible keys can be

1

10

100

1000

10000

...

Millions of keys have to fit inside only 10 buckets.

Naturally, different keys will eventually map to the same bucket.

------------------------------------------------------------

2. Simple Hash Function

Example

Hash(x)=x%10

11 → 1

21 → 1

31 → 1

41 → 1

Every key ends at Bucket 1.

A poor Hash Function increases collisions.

A good Hash Function distributes keys more uniformly.

====================================================================================================
WHY ARE COLLISIONS A PROBLEM?
====================================================================================================

Without collisions,

Searching

Insertion

Deletion

can be performed directly.

Average Complexity

O(1)

------------------------------------------------------------

After collisions,

multiple elements exist in the same bucket.

Now we must search among those elements.

Searching becomes slower.

Worst Case

O(N)

Therefore,

collision handling is one of the most important parts of Hashing.

====================================================================================================
COLLISION RESOLUTION TECHNIQUES
====================================================================================================

There are two major approaches.

1. Separate Chaining

Store multiple elements in the same bucket.

--------------------------------------------

2. Open Addressing

Store the element in another empty bucket.

Open Addressing includes

• Linear Probing

• Quadratic Probing

• Double Hashing

====================================================================================================
1. SEPARATE CHAINING
====================================================================================================

Separate Chaining is the simplest and most commonly used collision handling
technique.

Instead of storing only one element,

every bucket stores a Linked List (or Vector).

Whenever multiple keys map to the same bucket,

they are stored one after another.

Example

Hash Function

Hash(x)=x%10

25 → Bucket 5

35 → Bucket 5

45 → Bucket 5

Bucket 5

25 → 35 → 45

Every element remains accessible.

No element is discarded.

====================================================================================================
HOW SEPARATE CHAINING WORKS
====================================================================================================

Insert

25

↓

Bucket 5

25

--------------------------------------------

Insert

35

↓

Bucket 5 already contains 25.

Append

35

Bucket 5

25 → 35

--------------------------------------------

Insert

45

↓

Bucket 5

25 → 35 → 45

Searching

35

↓

Hash(35)

↓

Bucket 5

↓

Traverse only Bucket 5

↓

35 Found

Notice that

the entire Hash Table is never searched.

Only one bucket is traversed.

====================================================================================================
ADVANTAGES OF SEPARATE CHAINING
====================================================================================================

✓ Very easy to implement.

✓ Supports unlimited insertions.

✓ Table never becomes completely full.

✓ Deletion is simple.

✓ Performance remains good when collisions are low.

====================================================================================================
DISADVANTAGES OF SEPARATE CHAINING
====================================================================================================

✗ Requires extra memory for Linked Lists.

✗ Cache locality is poor.

✗ Long Linked Lists increase search time.

✗ Worst Case Complexity becomes O(N).

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Insertion

Average

O(1)

Worst

O(N)

--------------------------------------------

Searching

Average

O(1)

Worst

O(N)

--------------------------------------------

Deletion

Average

O(1)

Worst

O(N)

====================================================================================================
WHERE IS SEPARATE CHAINING USED?
====================================================================================================

Separate Chaining is widely used because of its simplicity.

Examples

✓ unordered_map (implementation dependent)

✓ unordered_set (implementation dependent)

✓ Symbol Tables

✓ Compiler Design

✓ Database Indexing

====================================================================================================
2. LINEAR PROBING
====================================================================================================

Linear Probing is the simplest Open Addressing technique.

Instead of storing multiple elements in the same bucket,

we search for the next available bucket.

If one position is occupied,

check the next position,

then the next,

until an empty bucket is found.

Formula

New Index

(Hash + i) % Table Size

where

i = 0,1,2,3,...

====================================================================================================
WORKING OF LINEAR PROBING
====================================================================================================

Hash Function

Hash(x)=x%10

Insert

25

↓

Bucket 5

--------------------------------------------

Insert

35

↓

Bucket 5 Occupied

↓

Check Bucket 6

↓

Empty

↓

Store at Bucket 6

--------------------------------------------

Insert

45

↓

Bucket 5 Occupied

↓

Bucket 6 Occupied

↓

Bucket 7 Empty

↓

Store at Bucket 7

Searching follows exactly the same path until the key is found.

====================================================================================================
/*
====================================================================================================
LINEAR PROBING - SEARCH OPERATION
====================================================================================================

Searching in Linear Probing follows the same path used during insertion.

Example

Hash Function

Hash(x) = x % 10

Hash Table

Index

5 → 25

6 → 35

7 → 45

Search

45

↓

Hash(45)

↓

Bucket 5

↓

25 ≠ 45

↓

Move to Bucket 6

↓

35 ≠ 45

↓

Move to Bucket 7

↓

45 Found

The search continues until

• Required key is found.

OR

• An empty bucket is encountered.

====================================================================================================
PRIMARY CLUSTERING
====================================================================================================

One major drawback of Linear Probing is

Primary Clustering.

When consecutive buckets become occupied,

they form a continuous block called a Cluster.

Example

Index

5 → 25

6 → 35

7 → 45

8 → 55

9 → 65

Now suppose another element hashes to Bucket 5.

It has to check

5

↓

6

↓

7

↓

8

↓

9

before finding an empty bucket.

As the cluster grows,

searching and insertion become slower.

This phenomenon is called

Primary Clustering.

====================================================================================================
ADVANTAGES OF LINEAR PROBING
====================================================================================================

✓ Very easy to implement.

✓ No extra memory required.

✓ Better cache locality than Linked Lists.

✓ Faster when the Load Factor is low.

====================================================================================================
DISADVANTAGES OF LINEAR PROBING
====================================================================================================

✗ Suffers from Primary Clustering.

✗ Performance decreases rapidly when the table becomes crowded.

✗ Searching may require checking multiple buckets.

✗ Table can become completely full.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Insertion

Average

O(1)

Worst

O(N)

--------------------------------------------

Searching

Average

O(1)

Worst

O(N)

--------------------------------------------

Deletion

Average

O(1)

Worst

O(N)

====================================================================================================
2. QUADRATIC PROBING
====================================================================================================

Quadratic Probing is another Open Addressing technique.

Instead of checking consecutive buckets,

it jumps according to square values.

Formula

New Index

(Hash + i²) % Table Size

where

i = 0,1,2,3,...

Because the jumps increase quadratically,

elements spread farther apart,

reducing clustering.

====================================================================================================
WORKING OF QUADRATIC PROBING
====================================================================================================

Hash Function

Hash(x)=x%10

Insert

25

↓

Bucket 5

--------------------------------------------

Insert

35

↓

Bucket 5 Occupied

↓

5 + 1² = 6

↓

Store at Bucket 6

--------------------------------------------

Insert

45

↓

Bucket 5 Occupied

↓

Bucket 6 Occupied

↓

5 + 2² = 9

↓

Store at Bucket 9

Notice that

Bucket 7

and

Bucket 8

were skipped.

This reduces consecutive occupied buckets.

====================================================================================================
SEARCH OPERATION
====================================================================================================

Searching follows the same quadratic jumps.

Example

Search

45

↓

Bucket 5

↓

Bucket 6

↓

Bucket 9

↓

Found

====================================================================================================
SECONDARY CLUSTERING
====================================================================================================

Quadratic Probing removes

Primary Clustering,

but another problem still exists.

If two keys generate the same initial hash value,

both follow exactly the same quadratic sequence.

Example

25

35

45

All hash to Bucket 5.

Their probing sequence becomes

5

↓

6

↓

9

↓

...

This is called

Secondary Clustering.

Although better than Linear Probing,

it still cannot eliminate all collisions.

====================================================================================================
ADVANTAGES OF QUADRATIC PROBING
====================================================================================================

✓ Reduces Primary Clustering.

✓ Better distribution of elements.

✓ No extra memory required.

✓ Better performance than Linear Probing in crowded tables.

====================================================================================================
DISADVANTAGES OF QUADRATIC PROBING
====================================================================================================

✗ Secondary Clustering still exists.

✗ Slightly more complex implementation.

✗ Some buckets may never be visited.

✗ Performance decreases when Load Factor becomes high.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Insertion

Average

O(1)

Worst

O(N)

--------------------------------------------

Searching

Average

O(1)

Worst

O(N)

--------------------------------------------

Deletion

Average

O(1)

Worst

O(N)

====================================================================================================
COMPARISON
====================================================================================================

Linear Probing

• Consecutive buckets checked.

• Suffers from Primary Clustering.

• Very simple implementation.

--------------------------------------------

Quadratic Probing

• Square jumps.

• Removes Primary Clustering.

• Secondary Clustering still exists.

• Better distribution of elements.

====================================================================================================
*/
/*
====================================================================================================
3. DOUBLE HASHING
====================================================================================================

Double Hashing is an Open Addressing technique that uses two Hash Functions
instead of one.

When a collision occurs, instead of checking consecutive or quadratic positions,
a second Hash Function determines the next bucket to be checked.

Because of this, elements are distributed much more uniformly throughout the
Hash Table.

It is considered one of the best collision resolution techniques.

====================================================================================================
HOW DOUBLE HASHING WORKS
====================================================================================================

Two Hash Functions are used.

Primary Hash Function

H1(key)

Finds the initial bucket.

--------------------------------------------

Secondary Hash Function

H2(key)

Determines the jump size.

Formula

Index = (H1(key) + i × H2(key)) % Table Size

where

i = 0,1,2,...

====================================================================================================
EXAMPLE
====================================================================================================

Suppose

Table Size = 10

Primary Hash Function

H1(x) = x % 10

Secondary Hash Function

H2(x) = 7 - (x % 7)

------------------------------------------------------------

Insert

25

H1(25)

↓

5

Bucket 5 is empty.

Store there.

------------------------------------------------------------

Insert

35

H1(35)

↓

5

Collision occurs.

Now compute

H2(35)

↓

7 - (35 % 7)

↓

7

New Position

(5 + 1 × 7) % 10

↓

2

Store at Bucket 2.

Instead of checking Bucket 6,

Double Hashing jumps directly to Bucket 2.

====================================================================================================
ADVANTAGES
====================================================================================================

✓ Best distribution among Open Addressing techniques.

✓ Eliminates Primary Clustering.

✓ Greatly reduces Secondary Clustering.

✓ Better searching performance.

✓ More efficient for larger Hash Tables.

====================================================================================================
DISADVANTAGES
====================================================================================================

✗ Requires two Hash Functions.

✗ More difficult to implement.

✗ Slightly slower computation than Linear Probing.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Insertion

Average

O(1)

Worst

O(N)

--------------------------------------------

Searching

Average

O(1)

Worst

O(N)

--------------------------------------------

Deletion

Average

O(1)

Worst

O(N)

====================================================================================================
LOAD FACTOR
====================================================================================================

Load Factor tells us how full a Hash Table is.

Formula

Load Factor (α)

=

Number of Stored Elements

/

Total Number of Buckets

Example

Elements = 8

Buckets = 10

Load Factor

=

8 / 10

=

0.8

====================================================================================================
WHY IS LOAD FACTOR IMPORTANT?
====================================================================================================

As the Load Factor increases,

more buckets become occupied.

This increases the probability of collisions.

Higher Load Factor

↓

More Collisions

↓

Longer Searching Time

↓

Reduced Performance

Therefore,

maintaining a low Load Factor keeps Hash Tables efficient.

====================================================================================================
REHASHING
====================================================================================================

When the Load Factor becomes too large,

the Hash Table size is increased.

Every existing element is inserted again into the new table using the
Hash Function.

This process is called

Rehashing.

Example

Old Table Size

10

↓

New Table Size

20

↓

Recompute Hash Values

↓

Insert Every Element Again

Although Rehashing is expensive,

it happens rarely and helps maintain O(1) average complexity.

====================================================================================================
WHEN IS REHASHING PERFORMED?
====================================================================================================

Most programming languages automatically perform Rehashing when the Load
Factor exceeds a threshold.

Typical Threshold

0.75

or

1.0

depending on the implementation.

====================================================================================================
COMPARISON OF COLLISION RESOLUTION TECHNIQUES
====================================================================================================

Separate Chaining

• Uses Linked Lists or Vectors.

• Extra memory required.

• Simple implementation.

• Easy deletion.

--------------------------------------------

Linear Probing

• Checks consecutive buckets.

• No extra memory.

• Suffers from Primary Clustering.

--------------------------------------------

Quadratic Probing

• Uses square jumps.

• Removes Primary Clustering.

• Suffers from Secondary Clustering.

--------------------------------------------

Double Hashing

• Uses two Hash Functions.

• Best distribution.

• Least clustering.

• Most efficient among Open Addressing techniques.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1. Why can't collisions be completely avoided?

Because the number of possible keys is much larger than the number of buckets
available in a Hash Table.

--------------------------------------------

Q2. Which collision handling technique is used by unordered_map?

Most implementations use

Separate Chaining.

--------------------------------------------

Q3. Which probing technique suffers from Primary Clustering?

Linear Probing.

--------------------------------------------

Q4. Which probing technique reduces Primary Clustering?

Quadratic Probing.

--------------------------------------------

Q5. Which collision handling technique gives the best distribution?

Double Hashing.

--------------------------------------------

Q6. What is the purpose of Rehashing?

To reduce collisions and maintain efficient Hash Table performance.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Collisions are unavoidable.

✓ A good Hash Function minimizes collisions.

✓ Separate Chaining stores multiple elements in one bucket.

✓ Linear Probing checks consecutive buckets.

✓ Quadratic Probing uses square jumps.

✓ Double Hashing uses two Hash Functions.

✓ Load Factor determines how full a Hash Table is.

✓ Rehashing improves performance by increasing the table size.

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Collision means multiple keys map to the same bucket.

✓ Four major collision handling techniques are used.

✓ Separate Chaining is simple and widely used.

✓ Linear Probing is easy but suffers from clustering.

✓ Quadratic Probing reduces clustering.

✓ Double Hashing provides the best distribution.

✓ Load Factor directly affects performance.

✓ Rehashing keeps Hash Tables efficient as they grow.

====================================================================================================
*/

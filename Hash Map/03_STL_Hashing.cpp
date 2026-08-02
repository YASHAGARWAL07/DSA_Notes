/*
====================================================================================================
                                         STL HASHING
====================================================================================================

====================================================================================================
INTRODUCTION
====================================================================================================

The C++ Standard Template Library (STL) provides four important associative
containers for storing and searching data efficiently.

These containers are

1. unordered_map

2. unordered_set

3. map

4. set

Although all of them are used to store data, their internal implementation
and performance are different.

The first two are based on

Hash Tables.

The last two are based on

Red-Black Trees (Self Balancing Binary Search Trees).

Choosing the correct container is important because it directly affects
the performance of your program.

====================================================================================================
1. unordered_map
====================================================================================================

unordered_map is an associative container that stores data in the form of

<Key, Value>

pairs.

Each key must be unique.

However, multiple keys can have the same value.

Internally, unordered_map uses a

Hash Table

to store elements.

When a new key is inserted,

the Hash Function computes the bucket where the element should be stored.

If two keys generate the same bucket,

Separate Chaining is generally used to handle the collision.

Unlike map,

unordered_map does NOT maintain elements in sorted order.

The traversal order may change after insertion or rehashing.

====================================================================================================
SYNTAX
====================================================================================================

unordered_map<KeyType, ValueType> mp;

Example

unordered_map<int,int> freq;

unordered_map<string,int> marks;

====================================================================================================
INSERTING ELEMENTS
====================================================================================================

Method 1

Using []

mp[5] = 100;

mp[10] = 200;

------------------------------------------------------------

Method 2

Using insert()

mp.insert({20,300});

====================================================================================================
UPDATING VALUES
====================================================================================================

If a key already exists,

assigning a new value updates the previous value.

Example

mp[5] = 100;

mp[5] = 250;

Final Value

5 → 250

====================================================================================================
ACCESSING VALUES
====================================================================================================

Using []

cout << mp[5];

--------------------------------------------

Using at()

cout << mp.at(5);

Note

at() throws an exception if the key does not exist.

====================================================================================================
SEARCHING
====================================================================================================

Search is performed using

find()

Example

if(mp.find(10) != mp.end())

{

cout<<"Key Found";

}

else

{

cout<<"Key Not Found";

}

find() returns an iterator.

If the key is absent,

it returns

mp.end().

====================================================================================================
DELETING ELEMENTS
====================================================================================================

Delete a particular key

mp.erase(5);

--------------------------------------------

Delete all elements

mp.clear();

====================================================================================================
OTHER USEFUL FUNCTIONS
====================================================================================================

Size

mp.size()

Returns the number of key-value pairs.

--------------------------------------------

Check Empty

mp.empty()

Returns true if the map is empty.

====================================================================================================
ITERATING OVER unordered_map
====================================================================================================

Method 1

Range Based Loop

for(auto it : mp)

{

cout << it.first << " " << it.second << endl;

}

Here

it.first

represents

Key

it.second

represents

Value

--------------------------------------------

Method 2

Iterator

for(auto it = mp.begin(); it != mp.end(); it++)

{

cout << it->first << " " << it->second;

}

====================================================================================================
WORKING OF unordered_map
====================================================================================================

Suppose we insert

10

20

35

Hash Function

Hash(x) = x % 10

Then

10 → Bucket 0

20 → Bucket 0

35 → Bucket 5

Since

10

and

20

map to the same bucket,

Separate Chaining stores both values in that bucket.

Bucket 0

10 → 20

Bucket 5

35

Searching

20

↓

Hash(20)

↓

Bucket 0

↓

Traverse Bucket

↓

Found

Instead of searching the entire table,

only one bucket is searched.

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

Worst-case complexity occurs when many keys collide into the same bucket.

====================================================================================================
APPLICATIONS OF unordered_map
====================================================================================================

unordered_map is one of the most frequently used STL containers in
Competitive Programming and Technical Interviews.

Common applications include

✓ Frequency Counting

✓ Two Sum

✓ Prefix Sum Problems

✓ Counting Distinct Elements

✓ Graph Representation

✓ Memoization

✓ Caching

✓ Database Indexing

✓ Word Frequency Analysis

====================================================================================================
WHEN SHOULD YOU USE unordered_map?
====================================================================================================

Use unordered_map when

✓ Fast lookup is required.

✓ Ordering of keys is NOT important.

✓ Average O(1) operations are preferred.

✓ Key-Value mapping is needed.

====================================================================================================
*/
/*
====================================================================================================
2. unordered_set
====================================================================================================

unordered_set is an associative container that stores only unique elements.

Unlike unordered_map,

it stores only values,

not Key-Value pairs.

Internally,

unordered_set also uses a Hash Table.

Duplicate elements are automatically ignored.

The order of elements is NOT guaranteed.

====================================================================================================
SYNTAX
====================================================================================================

unordered_set<DataType> st;

Example

unordered_set<int> st;

unordered_set<string> names;

====================================================================================================
INSERTING ELEMENTS
====================================================================================================

st.insert(10);

st.insert(20);

st.insert(30);

If we insert

st.insert(20);

again,

nothing happens because duplicate values are not allowed.

Final Set

10

20

30

====================================================================================================
SEARCHING ELEMENTS
====================================================================================================

if(st.find(20) != st.end())

{

cout<<"Element Found";

}

else

{

cout<<"Element Not Found";

}

Searching is performed using Hashing.

Average Time Complexity

O(1)

====================================================================================================
DELETING ELEMENTS
====================================================================================================

Delete a particular element

st.erase(20);

--------------------------------------------

Delete everything

st.clear();

====================================================================================================
OTHER USEFUL FUNCTIONS
====================================================================================================

Size

st.size()

--------------------------------------------

Check Empty

st.empty()

--------------------------------------------

Count

st.count(20)

Returns

1

if element exists,

otherwise

0.

====================================================================================================
ITERATION
====================================================================================================

for(auto x : st)

{

cout<<x<<" ";

}

Since unordered_set is unordered,

elements may appear in any order.

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
APPLICATIONS OF unordered_set
====================================================================================================

✓ Remove Duplicate Elements

✓ Fast Membership Checking

✓ Detect Duplicate Values

✓ Distinct Elements Problems

✓ Graph Algorithms

====================================================================================================
WHEN SHOULD YOU USE unordered_set?
====================================================================================================

Use unordered_set when

✓ Only unique elements are required.

✓ Ordering is not important.

✓ Fast searching is required.

====================================================================================================
3. map
====================================================================================================

map stores data in the form of

<Key, Value>

pairs.

Unlike unordered_map,

map always stores keys in sorted order.

Internally,

map is implemented using a

Red-Black Tree,

which is a Self-Balancing Binary Search Tree.

Since tree operations take logarithmic time,

all operations have

O(log N)

complexity.

====================================================================================================
SYNTAX
====================================================================================================

map<KeyType, ValueType> mp;

Example

map<int,int> marks;

map<string,int> age;

====================================================================================================
INSERTING ELEMENTS
====================================================================================================

mp[5]=100;

mp[2]=50;

mp[8]=200;

Stored Order

2 → 50

5 → 100

8 → 200

Notice that

elements are automatically sorted according to the key.

====================================================================================================
SEARCHING
====================================================================================================

if(mp.find(5)!=mp.end())

{

cout<<"Found";

}

Searching follows the Red-Black Tree.

Time Complexity

O(log N)

====================================================================================================
DELETING
====================================================================================================

mp.erase(5);

Removes the key-value pair whose key is

5.

====================================================================================================
ITERATION
====================================================================================================

for(auto it : mp)

{

cout<<it.first<<" "<<it.second;

}

Traversal is always

Sorted according to Keys.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Insertion

O(log N)

--------------------------------------------

Searching

O(log N)

--------------------------------------------

Deletion

O(log N)

====================================================================================================
WHEN SHOULD YOU USE map?
====================================================================================================

Use map when

✓ Sorted keys are required.

✓ Ordered traversal is needed.

✓ lower_bound()

or

upper_bound()

operations are required.

====================================================================================================
4. set
====================================================================================================

set stores

only unique elements.

Unlike unordered_set,

elements are automatically stored in sorted order.

Internally,

set also uses a

Red-Black Tree.

====================================================================================================
SYNTAX
====================================================================================================

set<int> st;

====================================================================================================
INSERTING ELEMENTS
====================================================================================================

st.insert(30);

st.insert(10);

st.insert(20);

st.insert(10);

Final Set

10

20

30

Duplicate elements are ignored.

====================================================================================================
SEARCHING
====================================================================================================

st.find(20);

Time Complexity

O(log N)

====================================================================================================
DELETING
====================================================================================================

st.erase(20);

Deletes the specified element.

====================================================================================================
ITERATION
====================================================================================================

for(auto x : st)

{

cout<<x<<" ";

}

Traversal is always

Sorted.

====================================================================================================
TIME COMPLEXITY
====================================================================================================

Insertion

O(log N)

--------------------------------------------

Searching

O(log N)

--------------------------------------------

Deletion

O(log N)

====================================================================================================
WHEN SHOULD YOU USE set?
====================================================================================================

✓ Unique elements required.

✓ Sorted traversal required.

✓ Binary Search Tree operations are needed.

====================================================================================================
*/
/*
====================================================================================================
HOW unordered_map WORKS INTERNALLY
====================================================================================================

Internally, unordered_map is implemented using a Hash Table.

Whenever a key is inserted,

the Hash Function computes an index (bucket number).

The element is then stored inside that bucket.

If multiple keys map to the same bucket,

Separate Chaining is used to store all of them.

General Flow

Key

↓

Hash Function

↓

Bucket Number

↓

Hash Table

↓

Store Element

Example

Hash Function

Hash(x) = x % 10

Insert

15

↓

Bucket 5

Insert

25

↓

Bucket 5

Collision Occurs

Bucket 5

15 → 25

Searching

25

↓

Hash(25)

↓

Bucket 5

↓

Traverse only Bucket 5

↓

Found

Instead of searching the complete table,

only one bucket is searched.

This is why unordered_map provides O(1) average complexity.

====================================================================================================
map vs unordered_map
====================================================================================================

Both containers store

<Key, Value>

pairs,

but their internal implementations are completely different.

------------------------------------------------------------

unordered_map

• Uses Hash Table

• Keys are NOT sorted

• Average Search = O(1)

• Faster for lookup

• Uses more memory

------------------------------------------------------------

map

• Uses Red-Black Tree

• Keys remain sorted

• Search = O(log N)

• Slower than unordered_map

• Supports ordered traversal

====================================================================================================
set vs unordered_set
====================================================================================================

Both containers store only unique elements.

Difference lies in ordering and implementation.

------------------------------------------------------------

unordered_set

• Uses Hash Table

• Elements are unordered

• Average Search = O(1)

• Faster

------------------------------------------------------------

set

• Uses Red-Black Tree

• Elements remain sorted

• Search = O(log N)

• Supports ordered traversal

====================================================================================================
COMPARISON TABLE
====================================================================================================

Container         Internal DS          Order          Search

unordered_map     Hash Table           No             O(1)*

unordered_set     Hash Table           No             O(1)*

map               Red-Black Tree       Yes            O(log N)

set               Red-Black Tree       Yes            O(log N)

*Average Case

Worst Case for Hash Table based containers

O(N)

====================================================================================================
WHICH CONTAINER SHOULD YOU USE?
====================================================================================================

Need Fast Lookup

↓

unordered_map

------------------------------------------------------------

Need Key-Value Pairs in Sorted Order

↓

map

------------------------------------------------------------

Need Unique Elements

↓

unordered_set

------------------------------------------------------------

Need Unique Elements in Sorted Order

↓

set

====================================================================================================
COMMON MISTAKES
====================================================================================================

✗ Using map when ordering is not required.

This increases complexity unnecessarily.

------------------------------------------------------------

✗ Assuming unordered_map stores keys in insertion order.

It does NOT.

Traversal order is implementation dependent.

------------------------------------------------------------

✗ Forgetting that duplicate keys are not allowed.

In unordered_map and map,

assigning a value to an existing key updates the value.

------------------------------------------------------------

✗ Expecting unordered_set to maintain sorted order.

It stores elements in arbitrary order.

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1. Which STL containers use Hash Tables?

✓ unordered_map

✓ unordered_set

------------------------------------------------------------

Q2. Which STL containers use Red-Black Trees?

✓ map

✓ set

------------------------------------------------------------

Q3. Why is unordered_map generally faster than map?

Because Hash Tables provide

Average O(1)

operations,

whereas Red-Black Trees require

O(log N).

------------------------------------------------------------

Q4. Which container should be used for frequency counting?

unordered_map

because ordering is not required and lookup is faster.

------------------------------------------------------------

Q5. Why is map preferred in some problems?

Because it keeps keys sorted,

making ordered traversal and range-based operations easier.

------------------------------------------------------------

Q6. Can duplicate keys exist in map or unordered_map?

No.

Every key must be unique.

Assigning a new value to an existing key simply updates its value.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ unordered_map stores Key-Value pairs using Hash Tables.

✓ unordered_set stores only unique values.

✓ map stores Key-Value pairs in sorted order.

✓ set stores sorted unique values.

✓ Hash Tables provide Average O(1) operations.

✓ Red-Black Trees provide O(log N) operations.

✓ Choose the container according to the problem requirement.

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ unordered_map → Fast Key-Value Storage.

✓ unordered_set → Fast Unique Element Storage.

✓ map → Sorted Key-Value Storage.

✓ set → Sorted Unique Elements.

✓ Hash Table based containers are generally faster.

✓ Tree based containers maintain sorted order.

✓ Selecting the correct STL container improves both performance
and code readability.

====================================================================================================
*/
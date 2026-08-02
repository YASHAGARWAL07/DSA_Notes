/*
====================================================================================================
                                CRYPTOGRAPHIC HASHING
====================================================================================================

====================================================================================================
INTRODUCTION
====================================================================================================

Cryptographic Hashing is a special type of hashing used to provide

✓ Data Security

✓ Data Integrity

✓ Authentication

✓ Digital Signatures

Unlike normal Hashing,

whose main goal is fast searching,

Cryptographic Hashing focuses on security.

A Cryptographic Hash Function converts data of any size into a fixed-size
hash value called a Digest.

Example

Input

Hello World

↓

SHA-256

↓

A94A8FE5CCB19BA61C4...

The output always has a fixed length irrespective of the input size.

====================================================================================================
CHARACTERISTICS OF A CRYPTOGRAPHIC HASH FUNCTION
====================================================================================================

A good Cryptographic Hash Function should satisfy the following properties.

1. Deterministic

Same input

↓

Same output

------------------------------------------------------------

2. Fixed Length Output

Small input

↓

256-bit Hash

Large input

↓

256-bit Hash

Output size never changes.

------------------------------------------------------------

3. Fast Computation

Hash generation should be efficient.

------------------------------------------------------------

4. One-Way Function

Given the Hash Value,

it should be practically impossible to recover the original data.

------------------------------------------------------------

5. Collision Resistant

It should be extremely difficult to find two different inputs
that generate the same Hash Value.

------------------------------------------------------------

6. Avalanche Effect

A tiny change in input should completely change the Hash Value.

Example

HELLO

↓

ABC123...

Hello

↓

9F7D22...

Only one character changed,

but the Hash becomes completely different.

====================================================================================================
COMMON CRYPTOGRAPHIC HASH FUNCTIONS
====================================================================================================

1. MD5

Produces

128-bit Hash

Very fast.

Not considered secure today because collisions can be generated.

Used only for basic checksum verification.

------------------------------------------------------------

2. SHA-1

Produces

160-bit Hash.

More secure than MD5,

but also considered insecure today.

------------------------------------------------------------

3. SHA-256

Member of the SHA-2 family.

Produces

256-bit Hash.

Widely used for

✓ Password Storage

✓ SSL Certificates

✓ Blockchain

✓ Digital Signatures

------------------------------------------------------------

4. SHA-512

Produces

512-bit Hash.

Provides higher security than SHA-256.

====================================================================================================
PASSWORD HASHING
====================================================================================================

Passwords should never be stored directly.

Wrong

Password

↓

Database

Correct

Password

↓

Hash Function

↓

Hash Value

↓

Database

During Login

Entered Password

↓

Hash Again

↓

Compare Hash Values

If both hashes match,

authentication succeeds.

====================================================================================================
SALTING
====================================================================================================

A Salt is a random value added before hashing.

Password

+

Random Salt

↓

Hash Function

↓

Store Hash

Even if two users have the same password,

their stored hashes become different.

Salting protects against

✓ Rainbow Table Attacks

✓ Dictionary Attacks

====================================================================================================
DIGITAL SIGNATURE
====================================================================================================

A Digital Signature is used to verify

✓ Identity

✓ Authenticity

✓ Data Integrity

Working

Message

↓

Hash Function

↓

Hash Value

↓

Encrypt Hash using Sender's Private Key

↓

Digital Signature

Receiver

↓

Decrypt Signature

↓

Generate Hash Again

↓

Compare Both Hashes

If both hashes match,

the message has not been modified.

====================================================================================================
BLOCKCHAIN AND HASHING
====================================================================================================

Blockchain relies heavily on Cryptographic Hash Functions.

Each block stores

• Transaction Data

• Previous Block Hash

• Current Block Hash

If someone modifies one block,

its Hash changes.

This breaks the chain,

making tampering easy to detect.

====================================================================================================
APPLICATIONS OF CRYPTOGRAPHIC HASHING
====================================================================================================

✓ Password Storage

✓ Digital Signatures

✓ Blockchain

✓ SSL/TLS Certificates

✓ Data Integrity Verification

✓ File Checksum Verification

✓ Software Downloads

✓ Banking Systems

✓ Secure Communication

====================================================================================================
NORMAL HASHING vs CRYPTOGRAPHIC HASHING
====================================================================================================

Normal Hashing

• Fast Searching

• Data Storage

• Hash Tables

• Average O(1) Operations

--------------------------------------------

Cryptographic Hashing

• Data Security

• Authentication

• Digital Signatures

• Password Protection

====================================================================================================
INTERVIEW QUESTIONS
====================================================================================================

Q1. Why can't passwords be stored directly?

Because anyone with database access could read them.

--------------------------------------------

Q2. What is Salting?

Adding a random value before hashing to improve security.

--------------------------------------------

Q3. Which Hash Function is commonly used today?

SHA-256

--------------------------------------------

Q4. Is MD5 secure?

No.

It is vulnerable to collision attacks.

--------------------------------------------

Q5. Why is SHA-256 preferred?

Because it provides strong collision resistance
and is currently considered secure for most applications.

====================================================================================================
IMPORTANT POINTS
====================================================================================================

✓ Cryptographic Hashing focuses on security, not searching.

✓ Output length is fixed.

✓ Hash Functions are one-way.

✓ Small input changes produce completely different outputs.

✓ Passwords should always be hashed before storage.

✓ Salting provides additional security.

✓ SHA-256 is widely used in modern applications.

====================================================================================================
KEY TAKEAWAYS
====================================================================================================

✓ Cryptographic Hashing protects sensitive data.

✓ MD5 and SHA-1 are outdated for security purposes.

✓ SHA-256 and SHA-512 are widely used.

✓ Digital Signatures use Hash Functions for integrity verification.

✓ Blockchain depends on Cryptographic Hashing.

====================================================================================================
*/

---
layout: page
title: Intro to Database Systems
description: Introduction to databases, learning relational algebra, entity diagrams and relations, SQL, etc. 
date: '2024-07-03'
permalink: /databases/
categories: DB
tags:
- Databases
- SQL
---

### ACID Transactions 

Atomicity: All-or-nothing transactions. Ensures data integrity by completing everything or reverting all changes.

Consistency: Predictable data changes. Transactions maintain valid table states and prevent corruption.

Isolation: Concurrent access without conflicts. Transactions appear to happen one at a time, even when happening simultaneously.

Durability: Permanent data changes. Committed transactions survive system failures.

### CRUD - Actions that the database should support

Create - add entry

Read - get entry 

Update - modify entry

Delete - remove entry

### Keys and entities 

Weak Entities: Entities needing a foreign key (often a primary key from another table) to be uniquely identified.

Foreign Keys: Link columns between tables (e.g., table1.colA -> table2.colB).

Primary Key - The actual key for the data in the database, Non null and unique (minimal set of identifying information to still be unique)

Composite key

* Key based on 2 (or more) items, and make up the primary key

* Example: street name and address or name and address 

* Each independently are not unique 

* Not really a foreign key as not composite

* Not a weak entity either as uses parent key

### Arrows and quantity 

* —- n 

* —> 0 or 1

    * Filled in arrow

    * —----) exactly once

    * Closed Arrow - Limiting factor 

Cardinalities

* One to one

* One to many 

* Many to many


Data models (levels)

* Logic

* Physical

* Conceptual

Schema

* Layout of relationship

* How it is structured and represented

### Relational Algebra Symbols

| Type             | Operator          | Symbol                              | Min rows                         | Max rows (R first has n Tuples)                       | Duplications                                                                                                          | Notes                                                                                                        | Returns                                                                    |  |
| ---------------- | ----------------- | ----------------------------------- | -------------------------------- | ----------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------- |  |
| Unary            | Project           | π pi                                | 1, can be 0 if relation is empty | n                                                     | When done projection won't give duplicate of same information                                                         | Subscript of projection are some of attributes in relation's schema,                                         | results in relation containing only the columns specified (1 field/column) |  |
| Select           | σ sigma           | 0                                   | n                                |                                                       | Give me this , when                                                                                                   | Returns tuples from Relation that match the Condition, schema of output is same as schema of input           |                                                                            |
| Auxillary        | Rename            | ρ roe                               |                                  |                                                       |                                                                                                                       | break up long expressions, resolve conflicts in attribute names, same arg name order as title header         | returns relation with new schema but same tuples                           |  |
| Binary           | Cartesian product | X                                   |                                  | m\*n (rxt)                                            |                                                                                                                       | tuple for each pair of tuples from two input relations, # of tuples is product of # of tuples in R and in S. |                                                                            |
| Union            | U                 | max(m,n)                            | n+m                              | no duplicated values in end result                    | Combine 2 tables, only works for comptible relations (with same schema), # of rows doesn't matter                     | Contains all tuples that are in at least one of the relations                                                |                                                                            |
| Difference       | \-                | n-m, unless m > n then = 0          | n (ie if 2nd set is empty)       |                                                       | Only for compatible relations (same schema)                                                                           | Result contains all tuples in R that are not in S                                                            |                                                                            |
| Intersection     | ∩                 | 0 (disjoint)                        | min(n,m)                         |                                                       | Needs to be for compatible relations R - (R-S) = R ∩ S                                                                 | returns all tuples in both R and S                                                                          |                                                                            |
| Conditional Join | ⋈c                |                                     |                                  |                                                       | Boolean condition over pairs of attributes from R and S - cartesian product with condition…. Selection of … join - CJ |                                                                                                              |
| Natural Join     | ⋈ bowtie         | 0 - nothing matches                 | n\*m                             |                                                       | condition is there automatically - if one col = same it looks at it .same schema , same columns                       |                                                                                                              |
| Division         | ÷                 | 0 - can be empty table (no results) |                                  | Schema of 2nd relation must be subset of the first R/S | Result contains tuples (a1,….,an) st for all (b1,…bm) in S, (a1,..an,b1,..,bm) is in R                                |                                                                                                              |
|                  |                   |                                     |                                  |                                                       |                                                                                                                       |                                                                                                              |                                                                            |  |
|                  | Equivalence       | ≡                                   |                                  |                                                       |                                                                                                                       | For all instances of the relations in E1and E2, they return the same result                                  |                                                                            |

| Relational algebra                               | SQL                                        |
| ------------------------------------------------ | ------------------------------------------ |
| set of tuples                                    | multiset of tuples                         |
| no null - no unknown values                      | Can have null values                       |
|                                                  |                                            |
| 2 valued logic for conditions true/false (logic) | unknown, true, false                       |
| not turing complete - limited                    | turing complete (many additional features) |


#### Nulls and Unknowns



Truth table for unknowns


| A       | Not A   |
| ------- | ------- |
| TRUE    | FALSE   |
| Unknown | Unknown |

More conclusive - I skipped entries ie where B is true and A is false etc (it's repetitive)

| A       | B       | A and B | A or B  |
| ------- | ------- | ------- | ------- |
| TRUE    | TRUE    | TRUE    | TRUE    |
| TRUE    | FALSE   | FALSE   | TRUE    |
| FALSE   | FALSE   | FALSE   | FALSE   |
| TRUE    | Unknown | Unknown | TRUE    |
| FALSE   | Unknown | FALSE   | Unknown |
| Unknown | Unknown | Unknown | Unknown |


Actions with or about Nulls and return values

| Action       | Return        | Example                              |
| ----------- | ------------- | ------------------------------------ |
| Operating on Null  | Null          | Null+1, Null\*7                      |
| Comparing with Null  | Unknown       | Null > 10, Null <> Null, Null = Null |
| Is Null     | True if Null  | x IS NULL                            |
| Is Not Null | False if Null | X IS NOT NULL                        |

  ```sql

        -- INIT database
        CREATE TABLE Parents (
        
        Child VARCHAR(20),
        Parent VARCHAR(20)
        );

        INSERT INTO Parents VALUES ('sarah', 'yitz');
        -- QUERY database
        SELECT * FROM Parents;

  ```

---
layout: page
title: Intro to Databases
description: DSA2 course dealing with hash tables, b trees, topological sort using dfs, etc.  
date: '2024-07-02'
permalink: /databases/
categories: DB
tags:
- Databases
- SQL
---

### ACID

Atomicity - each statement in a transaction (to read, write, update or delete data) is treated as a single unit. Either the entire statement is executed, or none of it is executed. This property prevents data loss and corruption from occurring if, for example, if your streaming data source fails mid-stream.
Consistency - ensures that transactions only make changes to tables in predefined, predictable ways. Transactional consistency ensures that corruption or errors in your data do not create unintended consequences for the integrity of your table.
Isolation - when multiple users are reading and writing from the same table all at once, isolation of their transactions ensures that the concurrent transactions don't interfere with or affect one another. Each request can occur as though they were occurring one by one, even though they're actually occurring simultaneously.
Durability - ensures that changes to your data made by successfully executed transactions will be saved, even in the event of system failure.

Data Independence
### CRUD
Create
Read
Update
Delete

### Weak Entity

A foreign key is a column or columns in a database that (e.g. table_1.column_a) that are linked to a column in a different table (table_2.column_b).

In a relational database, a weak entity is an entity that cannot be uniquely identified by its attributes alone; therefore, it must use a foreign key in conjunction with its attributes to create a primary key. The foreign key is typically a primary key of an entity it is related to.


Closed Arrow - Limiting factor 

| Relational algebra                               | SQL                                        |
| ------------------------------------------------ | ------------------------------------------ |
| set of tuples                                    | multiset of tupils                         |
| no null - no unknown values                      | Can have null values                       |
|                                                  |                                            |
| 2 valued logic for conditions true/false (logic) | unknown, true, falae                       |
| not turing complete - limited                    | turing complete (many additional features) |

Cardinalities

* One to one

* One to many 

* Many to many

Data models

* Logic

* Physical

* Conceptual

Schema

* Layout of relationship

* How it is structured and represented

Composite key

* Key based on 2 (or more) items , and are the primary key

* EX: street name and address or Name and address 

* Each independently are not unique 

* Not really a foreign key as not composite

* Not a weak entity either as uses parent key

Arrows and quantity 

* —- n 

* —> 0 or 1

    * Filled in arrow
    * —----) exactly once

* Primary key  

    * The actual key for the data in the database, Non null and unique

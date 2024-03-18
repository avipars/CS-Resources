---
layout: page
title: Advanced Data Structures and Algorithms (DSA2)
description: DSA2 course dealing with hash tables, b trees, topological sort using dfs, etc.  
date: '2024-03-18'
permalink: /data_struct2/
image: /static/post-image/bigo.png
categories: DSA
tags:
- DataStruct
- Algos
- DataStructures2
---

## Advanced Data Structures and Algorithms (DSA2)

#### My (incomplete) notes for DSA2 

### Recurrences 

Differential equation
- K = 2
- Only positive coefficients (b…bk)
- A*T(n-1) + B*T(n-2)

Master theorem:
- Constants: a >= 1, b > 1
- F(n) > 0 
- Check n^log(b,a) _ f(n)
- Case 3: 
  - a*f(n/b) <= c*f(n) then t(n) = Θ(f(n))
    - for c < 1
    - regularity check 


### Adjacency representation (for graphs)

| Representation | Find Edge | Insert Edge | Delete Edge | Memory     |
| -------------- | --------- | ----------- | ----------- | ---------- |
| List           | `O(|V|)`    | `O(1)`        | `O(|V|)`      | `Θ(|V|+|E|)` |
| Matrix         | `O(1)`      | `O(1)`        | `O(1)`        | `Θ(|V|^2)`   |

- In (binary) matrix form, every row/column cooresponds to a vertex. The index will be switched from 0 to 1 if there is an edge between those wo vertices. 

- If we are using a (linked) list, we insert an edge at the head of the list. Otherwise, we just go to the respective row and column in the matrix and flip the bit from 0 to 1

### Vertex colors

- **White:** unprocessed/undiscovered
- **Grey:** processing/not finished
- **Black:** done/finished

### Edge types

- Let U be the parent, and V be the descendent 

- **Tree Edge**
  - Parent to a child
  - Goes to undiscovered vertex
  - V finishes before U
  - U is grey, V is white

- **Back Edge**
  - To an ancestor
    - Of a vertex (parent, grandparent, etc.)
  - Adding a back edge to tree edge makes a cycle
    - To discovered but unfinished vertex
  - In DFS, every back edge completes a cycle
    - Removing back edges from a graph removes all cycles
  - Self-edge = back edge
  - V finishes after U

- **Forward Edge**
  - To a non-child descendant
    - To a finished vertex discovered after the current vertex
    - Indirect descendant (not child)
  - V finishes before U
  - U is grey and V is black

- **Cross Edge**
  - Everything else
    - To a vertex finished before the current vertex's discovery
  - One branch to another tree, or one tree to another (ie 1 component to another)
  - V finishes before U
  - U is grey and V is black

White Path Lemma
- \( V \) descends \( U \) iff at time \( d[u] \) there exists a path from \( u \) to \( v \) composed completely of white vertices.

DAG (Directed Acyclic Graph)
- Directed graph G is acyclic iff DFS produces no back edges

Topological Sort in DAG
- Order relation

Sparse Graph
- \( `|E| = O(|V|)` \)

Dense Graph
- \( `|E| = Θ(|V|^2)` \)
- more vertices than edges (by an order of magnitude)

Complete Graph
- Edge between every 2 vertices (in undirected graph)

Connected Components
- Maximal, connected subgraph
- Maximal means no more vertices can be added to the subgraph to still be connected 

Tree
- Acyclic and connected graph
- Connected components of a forest = a tree

Forest
- Acyclic graph
- a tree is a forest, but a forest isn't always a tree 
- its a graph and not a set of trees 
- a subgraph of a forest = always a forest

B tree:
- Number of keys in each node = from ceil(m/2) – 1 to m-1 
- Number of children = number of keys + 1
- Minimal # of children = (ceil(m/2) – 1 (h+1)) / (ceil(m/2) -1)
- Maximal # of children = (m(h+1)) / (m-1)
- Number of leaves = from 2(ceil(m/2))^h to m^(h+1) -1 


#### more resources

[YouTube Playlist](https://www.youtube.com/playlist?list=PL9DdgseuDZgI4iVxPbjXJy4bMG-8DILVq)

[Data Structure Visualizations](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)

[AlgoVis](https://visualgo.net/en)
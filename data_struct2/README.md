---
layout: page
title: Advanced Data Structures and Algorithms (DSA2)
description: DSA2 course dealing with hash tables, b trees, topological sort using dfs, etc.  
date: '2024-03-19'
permalink: /data_struct2/
image: /static/post-image/master.png
categories: DSA
tags:
- DataStruct
- Algos
- DataStructures2
- BTree
- Mastertheorem
- Hashtable
---


#### My (incomplete) notes for DSA2 

### Recurrences 

Differential equation
- K = 2
- Only positive coefficients (b…bk)
- A*T(n-1) + B*T(n-2)

Master theorem
![Master theorem types]({{ site.url }}{{ page.image }})
- Constants: a >= 1, b > 1
- F(n) > 0 
- Check n^log(b,a) _ f(n)
- Case 3: 
  - a*f(n/b) <= c*f(n) then t(n) = Θ(f(n))
    - for c < 1
    - regularity check 

### Background for graphs
- Edge is a pair of 2 vertices 
- G = (V,E) 
  - Graph G is defined as the ordered pair of a group of vertices V and edges E
- Directed graph
  - Every edge is an ordered pair 
  - (v,u) != (u,v)
  - we use arrows to differentiate and know the direction
  - v -> u means a edge from v to u (but if we are in u, there is no way to get to v here, unless we add another edge)
- Undirected graph
  - Every edge is an unordered pair 
  - {v,u} = {u,v}
- `|V|` denotes the number of vertices in a graph
- `|E|` denotes the number of edges in a graph
- d[u] denotes the detection/discovery time of vertex u
- f[u] denotes the finishing time of vertex u 
-  π[v] denotes an array containing the predecessors of vertex v.

- Path = set of vertices (if undirected graph, the set will be unordered), where every edge between 2 vertices is a pair. 
- Simple Path = path where every vertex in path appears only once
- Cycle = path where V0 = Vn (first vertex is the same as the last vertex)
  - smallest path that can make a cycle will have 3 vertices (if we don't allow self loops)
- Simple Cycle = a cycle but the only repeated vertex is V0 = Vn 
- Subgraph G' = (V',E')
  - where V' ⊆ V, E' ⊆ E
  - All the vertices in the subgraph have to exist also in the original Graph (same as edges)
  - Meaning we cannot add any vertex/edge to G' that wasn't already in G 
- Spanning subgraph of G
  - is a subgraph of G where V' = V
  - Graph G can be it's own spanning subgraph
  - may have fewer edges than G, but it has to cover all of the vertices of G 
- Connected Graph
  - In an undirected graph where there exists a path between every 2 vertices (ie E - B)
- Strongly Connected Graph
  - In a directed graph, exists a path between every 2 vertices  (E <-> B)
- Sparse Graph =  \(`|E| = O(|V|)`\)
  - Can remove edges, and as long as the number of edges is the same order of magnitude as the number of vertices... still will be sparse
- Dense Graph = \(`|E| = Θ(|V|^2)`\)
  - More vertices than edges (by an order of magnitude)
- Complete Graph = 
  - Edge between every 2 vertices (in undirected graph)
- Connected Components
  - Maximal, connected subgraph
  - Maximal means no more vertices can be added to the subgraph to still be connected 
- Tree
  - Acyclic and connected graph
  - Connected components of a forest = a tree
  - Graph G = (V,E) is a tree iff G is acyclic and  `|E|` =  `|V| - 1 `
  - Height of any complete tree is log(n) - base depends on # of children allowed

- Forest
  - Acyclic graph
  - a tree is a forest, but a forest isn't always a tree 
  - its a graph and not a set of trees 
  - a subgraph of a forest = always a forest

### Adjacency representation (for graphs)

| Representation | Find Edge (search) | Insert Edge (add) | Delete Edge (remove) | Memory (space)    |
| -------------- | --------- | ----------- | ----------- | ---------- |
| List           | `O(|V|)`    | `O(1)`        | `O(|V|)`      | `Θ(|V|+|E|)` |
| Matrix         | `O(1)`      | `O(1)`        | `O(1)`        | `Θ(|V|^2)`   |

- List = for every vertex u in the graph, u has a list of vertices connected to it (node to neighbor)

- In (binary) 2 dimensional matrix form, every row/column cooresponds to a vertex. The index will be 0 if there is not an edge between those two vertices. 

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
- Uses depth first search

B tree:

- Rules:
  - Root node can have a minimum of 2 children (1 key is fine)
  - Every node must fill at least half of their children ceil(m/2), node with degree 10 needs to have 5 children
  - All leaf nodes must be at the same level
  - Creation of nodes is bottom up (insertion) and grows upwards

- Stats:
  - Number of keys in each node = from ceil(m/2) – 1 to m-1 
  - Number of children = number of keys + 1
  - Minimal # of children = (ceil(m/2) – 1 (h+1)) / (ceil(m/2) -1)
  - Maximal # of children = (m(h+1)) / (m-1)
  - Number of leaves = from 2(ceil(m/2))^h to m^(h+1) -1 

### Hash Table & Functions:
- 
- m = size of table 
- h1(key) is the function that returns the index in the array for given item
- Table is indexed from 0 to m-1
- There are a lot of hashing functions, but the simplest used is usually h(key) = key % m 
    - the % m part assures that you cannot exceed the bounds of the table... given your key you will end up within the range of 0 to m-1
- Load factor of a hash table = total number of items stored / size of array = α
- Normally, each spot in the table can only hold a single element (and it's key) - this is called direct addressing 
    - additionally, your key cannot end up in other slots  

- With chaining specifically (part of open addressing):
  - each spot has a linked list (empty by default), upon insertion, element becomes the new head of the list
  - upon collision, the newer item gets put at the head of the list for the respestive spot and the previous item in the list becomes the node after the head. 
- Open addressing allows your key to go to almost (if not all) of the slots by using a probe/step function
  - i.e. for linear/quadratic probing we have a step function in addition to the original hash function, with a coefficient i/i^2 respective to the type of probe. Initially it will be 0, but after every collision we will increment by 1

- Double hashing:
    - given two hash functions, h1, h2, and i which starts at 0
    - h = (h1(key) + i*h2(key)) % m
    - this is how you would usually map a item to a spot in the hash table
    - if there is a collision, i gets incremented by 1 and compute the index via h again 
    - keep on doing this till you find an empty spot.
    - if h2 is chosen/created in a poor manner (or h1, or table is small, or not sparse) etc... you can end up in an infinite loop looking for an open slot


#### More resources

[My DSA2 calculator (WIP)](https://avi.is-a.dev/dsa/)

[YouTube Playlist](https://www.youtube.com/playlist?list=PL9DdgseuDZgI4iVxPbjXJy4bMG-8DILVq)

[Data Structure Visualizations](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)

[AlgoVis](https://visualgo.net/en)

[DSA Code Challenge in JS](https://github.com/bradtraversy/traversy-js-challenges/)
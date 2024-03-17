---
layout: page
title: Advanced Data Structures and Algorithms (DSA2)
description: Linked Lists, Trees, Queues, Heaps, Stacks, etc. 
date: '2024-03-17 12:24:11 -0400'
permalink: /data_struct2/
image: /static/post-image/bigo.png
categories: DSA
tags:
- DataStruct
- Algos
- DataStructures2
---

## Advanced Data Structures and Algorithms (DSA2)

Adjacency representation (for graphs)

| Representation | Find Edge | Insert Edge | Delete Edge | Memory         |
|----------------|-----------|-------------|-------------|----------------|
| List           | O(|V|)    | O(1)        | O(|V|)      | Θ(|V|+|E|)    |
| Matrix         | O(1)      | O(1)        | O(1)        | Θ(|V|^2)      |

### Vertex colors

- **White:** unprocessed/undiscovered
- **Grey:** processing/not finished
- **Black:** done/finished

### Edge types

- **Tree Edge**
  - Parent to a child
  - Goes to undiscovered vertex
  - V finishes before U

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

- **Cross Edge**
  - Everything else
    - To a vertex finished before the current vertex's discovery
  - One branch to another tree, or one tree to another
  - V finishes before U


[YouTube Playlist](https://www.youtube.com/playlist?list=PL9DdgseuDZgI4iVxPbjXJy4bMG-8DILVq)
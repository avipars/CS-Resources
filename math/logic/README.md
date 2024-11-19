---
layout: page
title: Mathematical Logic
description: "intro to math formalization, deduction, formal
proof, and concepts of mathematical logic. There is a little graph theory at the end of the course as well"
permalink: /math/logic/
date: '2024-11-19'
categories: math
tags:
- Logic
- Math
- Graphs
image: 
sitemap:
  priority: 0.7
  changefreq: "monthly"
  
---

Some digital systems content, sentential logic, predicate logic, graph theory

Read: "Discrete Mathematics and Its Applications" by Kenneth H. Rosen (not required by the course)

# Notes:

- We studied sentential logic as part of the course, but it is often referred to as Propositional logic/calculus

- We also used a system called L arrow which exists in sentential logic (sometimes called Language PC or System PC)

- I advise reading the Rosen Discrete Math Book, in the first few hundred pages... it covers most of what the course does.

- This is not my exhaustive list of notes (& proofs), there are topics not covered in the course on this page, so do not use this as your main source of notes

## Math Logic

### Symbol Refresher

Here are some stuff worth knowing (on top of the basic gates/symbols)

- A ∨ B = OR

- A ∧ B = AND

- ¬A = Not A = Negation

- F = Cconstant false = ⊥

- T = Constant true

- A ⇒ B

  - When A is true and B is false, the sentence gets the False truth value, otherwise it will always get the True truth value

  - Called If then, Implies (IMP), or Conditional

- A ↑ B = ¬(A ∧ B) = NAND

- A ↓ B = ¬(A ∨ B) = NOR

- A ↔ B = A ⊙ B ≡ (A ⇒ B) ∧ (B ⇒ A)

  - Bidirectional = If and only if = XNOR ⊙

- A ⊕ B ≡ (A ∧ ¬B) ∨ (¬A ∧ B)

  - XOR ⊕ = Exclusive Or = Either A or B (but not both)

### Truth Tables for the non-trivial logic symbols

| A | B | A ⇒ B | A ↔ B | A ↑ B | A ↓  B | A ⊕ B |
| - | - | ----- | ----- | ----- | ------ | ----- |
| T | T | T     | T     | F     | F      | F     |
| T | F | F     | F     | T     | F      | T     |
| F | T | T     | F     | T     | F      | T     |
| F | F | T     | T     | T     | T      | F     |


#### Quantifiers

- ∀x - Universal quantifier - For all x

  * ∀x(S(x) ⇒ P(x)) translates to "All S are P"

- ∃x - Existential quantifier - There exists x

  * ∃x(S(x) ∧ P(x)) translates to "There exists S that are P"

- Example: There exists a planar graph that isn't connected ≡ Not all planar graphs are connected

  * ∃x¬C(X) ≡ ¬∀xC(x)

- Example: There doesn't exist a blue swan ≡ All swans aren't blue

  * ¬∃xS(x) ≡ ∀x¬S(x)

#### Meta-Logic

Implication: A ⇒ B

- A implies B (If A then B)

  - A ⇒ B is false when A is true and B is false, but otherwise it's true

  - We get B from A

Meta-Deduction: A ⊢ B

- A proves B

  - B can be proved using A as premise

- ⊢ A

  - A is a tautology (every premise can deduce A)

Meta-implication: A ⊨ B

- A entails B

  - B is true in every structure where A is true

  - In every model, it is not the case that A is true and B is false

  - AKA Logical implication

- If A ⊢ B then A ⊨ B (soundness theorem)

    - All theorems are true

- If A ⊨ B then A ⊢ B (completeness theorem)

    - Prove all true statements

A formula is satisfiable if it is true under some assignment of values to its variables (not always a tautology)

A formula is valid if every assignment of values to variables make the formula true.

A sentence is a formula without free variables (AKA with only bound variables).

A set of sentences is consistent if and only if it's possible for all sentences in the set to be true at the same time (together).

A set of premises Γ is inconistent only if Γ implies some contradiction

Contradiction = False under any truth assignment 

Tautology = True under every truth assignment 

### English to Logic

| Sentential Logic Sentence | A ↔ B                     | A → B                  | ¬B → A           | ¬(A → B) = A ∧ ¬B               | A ∧ B           | A ∨ B                | A ↑ B                          | A ↓ B           | (A → B) ∧ (¬A → C)                 | (¬B → A) ∧ (B → C)                |
| ------------------------- | ------------------------- | ---------------------- | ---------------- | ------------------------------- | --------------- | -------------------- | ------------------------------ | --------------- | ---------------------------------- | --------------------------------- |
|                           |                           |                        |                  |                                 |                 |                      |                                |                 |                                    |                                   |
| English                   | A if and only if B        | A only if B            | A unless B       | A is not sufficient for B       | A but B         | A or (else) B        | not the case that both A and B | Neither a nor b | if A, then B, and if not A, then C | if not B, then A, and if B then C |
|                           | A just when B             | If A then B            | A if not B       | it is not true that if A then B | A who B         | Bring A or B or both |                                |                 | if A, then B; otherwise C          | A unless B, in which case C       |
|                           | If A then B and vis-versa | B if A                 | unless B,A       |                                 | A and B         | Either A or (else) B |                                |                 |                                    |                                   |
|                           | A is equivalent to B      | B because A            | if not B, then A |                                 | Both A and B    | A unless B           |                                |                 |                                    |                                   |
|                           |                           | A hence B              |                  |                                 | Although A, B   |                      |                                |                 |                                    |                                   |
|                           |                           | A implies B            |                  |                                 | A even though B |                      |                                |                 |                                    |                                   |
|                           |                           | B in case A            |                  |                                 | A however B     |                      |                                |                 |                                    |                                   |
|                           |                           | in case A,B            |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | If A,B                 |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | on condition that A, B |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | B on condition that A  |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | not A if not B         |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | B is necessary for A   |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | Only if B are/then A   |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | B provided that A      |                  |                                 |                 |                      |                                |                 |                                    |                                   |
|                           |                           | B when A               |                  |                                 |                 |                      |                                |                 |                                    |

| Predicate Logic Sentence | ∀x        | ∃x               | ¬(∃x...) | ¬(∀𝑥 … )    | ∀𝑥 𝑃 (𝑥) → 𝑄(𝑥)              | ∃𝑥 𝑃 (𝑥) ∧ 𝑄(𝑥)             | (∃x (∃y ((B(x) ∧ B(y)) ∧ x ≠ y))) | (∀x (∀y ((B(x) ∧ B(y)) → (x = y))))    | ((∃x B(x)) ∧ (∀x (∀y ((B(x) ∧ B(y)) → (x = y))))) |
| ------------------------ | --------- | ---------------- | -------- | ----------- | ---------------------------- | --------------------------- | --------------------------------- | -------------------------------------- | ------------------------------------------------- |
|                          |           |                  |          |             |                              |                             |                                   | (¬(∃x (∃y ((B(x) ∧ B(y)) ∧ (x ≠ y))))) | (∃x (B(x) ∧ (∀y (B(y) → (x = y)))))               |
| English                  | Every x   | Exists x         | None     | Not every x | Every P-ish x has property Q | Some P-ish x has property Q | There are at least two X's        |                                        | There are exactly one x                           |
|                          | For all x | At least one x   | No x     | Not all     |                              |                             |                                   | There are at most one x                |                                                   |
|                          | Each x    | Some x           |          |             |                              |                             |                                   |                                        |                                                   |
|                          | Any x     | There is a x     |          |             |                              |                             |                                   |                                        |                                                   |
|                          |           | There exists a x |          |             |                              |                             |                                   |                                        |                                                   |
|                          |           | One or more      |          |             |                              |                             |                                   |                                        |

### Functional completeness

- Any functionally complete set of logical symbols (gates) can be used to create any other gate

- Functionally complete sets that are good to know for exams and homework, here is a non exhaustive list of some basic ones

- IMP = Implication

#### Main 5

- AND, OR, NOT : {∧, ∨, ¬}

- NAND : {↑}

- NOR : {↓}

- AND, NOT : {∧, ¬}

- OR, NOT : {∨, ¬}

#### Additional ones

  - IMP, NOT : {⇒, ¬}

  - XOR, IMP : {⊕, ⇒}

  - AND, BIDIRECTIONAL, FALSE : {∧, ↔, F}

  - OR, BIDIRECTIONAL, FALSE : {∨, ↔, F}


### Normal Forms:

- CNF (Conjunctive Normal Form) 

    - Goal is to get into a form like this: (A ∨ ¬B ∨ C) ∧ (A ∨ B ∨ ¬C) ∧ (¬A ∨ B ∨ ¬C)

    - Get rid of arrows (⇒,↔) using equivalences (E20,E22)

    - Move negations in = Push all negations down to the atomic propositions via De-Morgan's laws (E16, E17) and double negations  (E9) 

    - Use distributive law (E14) to push ORs in and ANDs out

    - Remove any contradictory clauses (E8)

    - Or via truth table, look at all rows that end in F, negate values...

- DNF (Disjunctive Normal Form)

  - Goal is to get into form like this:  (A ∧ B ∧ ¬C) ∨ (A ∧ ¬B ∧ ¬C) ∨ (¬A ∧ B ∧ C) 

  - Similar to CNF but use distributive law (E15) to push ANDs in and ORs out

  - Or via truth table, look at all rows that end in T, take the values as is

- PNF (Prenex Normal Form)

  - Get rid of arrows (⇒,↔) using equivalences (E20,E22)

  - Put negation ¬ close to predicates via De-Morgan's laws

  - Change name of free variables to bounded variables

  - Use equivalences to extract quantifiers 


## Graphs:

### Table 1: Graph Terminology

| Word                        | Definition                                                                                                                                                                                     | Notation                    |
| --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------- |
| Graph                       | Set of vertices and set of edges                                                                                                                                                               | G=(V,E)                     |
| Vertex                      | Unique node                                                                                                                                                                                    | v ∈ V                       |
| Edge                        | Pair of 2 vertices (linked)                                                                                                                                                                    | e ∈ E                       |
| Adjacent vertices/Neighbors | f there is an edge from one vertex to the other i.e. v-u or v<->u, so v and u are adjacent to each other ... but v->u v is adjacent to u but u isn't adjacent to v                             |                             |
| Degree                      | Number of edges touching that vertex (in undirected graph)                                                                                                                                     | d(v)                        |
| in-degree                   | number of edges coming into vertex v<sub>x</sub>... i.e. v<sub>3</sub>->v<sub>x</sub>->v<sub>2</sub> ,v<sub>x</sub> has in-degree of 1 (from v<sub>3</sub coming in) (directed graph)          | Din(v) AKA D<sup>-</sup>    |
| out-degree                  | number of edges leaving vertex v<sub>x</sub> (directed graph)                                                                                                                                  | Dout(v) AKA D<sup>+</sup>   |
| Connected vertices          | In an undirected graph, an unordered pair of vertices {x, y} is called connected if a path leads from x to y (path exists between them). Otherwise, the unordered pair is called disconnected.  |                             |
| Strongly Connected vertices          | In a directed graph, an ordered pair of vertices {x, y} is called strongly connected if a path leads from x to y and a path from y to x. |                             |
| Reachibility          | If there is a path from vertex U to vertex V, then V is reachable from U (in directed graph, U isn't necessarily reachable from V)  | (U⇝V)                            |
| Path                        | sequence of vertices connected by edges.                                                                                                                                                       | {v1,....,v4}                |
| Cycle                       | A cycle is a path that starts and ends at the same vertex.                                                                                                                                     | {v1,v2,...v1........vn, v1} |
| Simple path                 | path that doesn't repeat any vertices                                                                                                                                                          |                             |
| Simple Cycle                | A simple cycle is a cycle that repeats no vertices except that the first vertex is also the last (in undirected graphs, no edge can be repeated)                                               |                             |
| Euler path                  | Path that uses every edge of graph exactly once                                                                                                                                                |                             |
| Euler cycle                 | a cycle that uses each edge exactly once (undirected graph)                                                                                                                                    |                             |
| Hamilton path               | path that visits each vertex exactly once - traceable                                                                                                                                          |                             |
| Hamilton cycle              | cycle that visits each vertex exactly once (besides for the first vertex = last vertex)                                                                                                                                                     |                             |
| Depth                       | \# of edges in path from root to that node                                                                                                                                                     |                             |
| Distance                    | length of shortest path having vertices v,u at the endpoints                                                                                                                                   |                             |
| Diameter                    | in connected graph it is maximum length of shortest path - max of distances between pairs of vertices in graph                                                                                 |                             |
| Path length                 | \# of edges in a path                                                                                                                                                                          |                             |
| Component                   | subset of vertices Vi ⊆ V                                                                                                                                                                      |                             |
| Connected component         | subset of vertices Vi ⊆ V that is connected                                                                                                                                                    |                             |
| Strongly Connected component         | A strongly connected component of a directed graph is a maximal set of vertices C ⊆ V such that for every pair of vertices u and v in C, u and v are mutully reachable (both u⇝v and v⇝u) u can reach v and v can reach u                                                                                                                                                    |                             |

### Table 2: Graph Attributes

| Word                  | Definition                                                                                                                                                                                                                                                                                                                                                       | Notation                            |
| --------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------- |
| Undirected Graph      | {v1,v2} = {v2,v1} ... if v1 shares an edge with v2 (we draw a line for the edge)<br>                                                                                                                                                                                                                                                                             |                                     |
| Directed Graph        | (v1,v2) means v1 -> v2 ... but we cannot go from v2 -> v1 unless another edge exists (v2,v1)                                                                                                                                                                                                                                                                     |                                     |
| Subgraph              | A subgraph of a graph G is a graph whose vertices and edges are subsets of the vertices and edges of G, respectively                                                                                                                                                                                                                                             | H ⊆ G                               |
| Induced Subgraph      | An induced subgraph of a graph G is a subset of vertices V' and all edges E whose endpoints are both in V'                                                                                                                                                                                                                                                         | G[V'].                              |
| Simple                | a graph that does not contain more than one edge between the pair of vertices                                                                                                                                                                                                                                                                                    |                                     |
| Complete              | each pair of vertices is joined by an edge. A complete graph contains all possible edges.                                                                                                                                                                                                                                                                        |                                     |
| Regular               | each vertex has same degree (same number of edges touching it)                                                                                                                                                                                                                                                                                                                                     |                                     |
| K-regular             | regular graph where each vertex has degree K                                                                                                                                                                                                                                                                                                                     |                                     |
| Bipartite             | a graph where the vertices can be divided into two disjoint sets such that all edges connect a vertex in one set to a vertex in another set. There are no edges between vertices in the disjoint sets.                                                                                                                                                           |                                     |
| Planar                | A planar graph is a graph that can be drawn in the plane without any edges crossing.                                                                                                                                                                                                                                                                             |                                     |
| Complete bipartite    | a special bipartite graph where every vertex on one side of the bipartition is connected to every vertex on the other side                                                                                                                                                                                                                                       |                                     |
| Clique                | a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. an induced subgraph of G that is complete.                                                                                                                                                                                                         |                                     |
| Peterson              | non-planar, Hamilton path, no Hamilton cycle                                                                                                                                                                                                                                                                                                                     |                                     |
| Connected             | if (in an undirected graph), for each pair of vertices, there exists at least one single path which joins them                                                                                                                                                                                                                                                   |
| Strongly Connected    | if (in an directed graph), for each pair of vertices, there exists a path between them                                                                                                                                                                                                                                                                           |
| Acyclic               | a graph with no cycles                                                                                                                                                                                                                                                                                                                                           |                                     |
| Hamiltonian-connected | if for every pair of vertices there is a Hamilton path between the two vertices.                                                                                                                                                                                                                                                                                 |                                     |
| DAG                   | Directed graph without any cycles                                                                                                                                                                                                                                                                                                                                |                                     |
| Tree                  | Connected, Undirected, and Acyclic Graph with n vertices, and n-1 edges (or add edge = makes a cycle, or remove edge disconnects graph)                                                                                                                                                                                                                          |  T<sub>G</sub>                                   |
| Forest                  | Undirected, and Acyclic Graph, n - m = number of trees in said forest                                                                                                                                                                                                                          |                                    |
| K<sub>n</sub>         | Complete (clique) graph on n vertices, has $$ \binom{n}{2}$$ edges                                                                                                                                                                                                                                                                                                        |                                     |
| Cycle graph           | a graph that consists of a single cycle, or in other words, some number of vertices (at least 3, if the graph is simple) connected in a closed chain.                                                                                                                                                                                                            |                                     |
| C<sub>n</sub>         | Cycle graph on n vertices (\|n\| = # of vertices = # edges in this case)                                                                                                                                                                                                                                                                                         |                                     |
| K<sub>a,b</sub>       | is a complete bipartite graph that consists of two disjoint sets of n vertices each, with every vertex in the first set connected to every vertex in the second set. In other words, if we have two sets of vertices U and V, each with n vertices, then <sub>a,b</sub> has an edge between every pair of vertices u ∈ U and v ∈ V. Has a\*b edges, a+b vertices |                                     |
| G<sup>c</sup>         | a graph G' (complement) on the same set of vertices as of G such that there will be an edge between two vertices (v, e) in G', if and only if there is no edge in between (v, e) in G                                                                                                                                                                            | G'(v, e')                           |
| G<sup>T</sup>         | a graph G<sup>T</sup> (transpose) where V is the same set of vertices as in G, but E<sup>T</sup> is the set of edges E but with directions reversed (directed graph), if e = (v,u), e<sup>T</sup> = (u,v)                                                                                                                                                        | G<sup>T</sup> = (V, E<sup>T</sup> ) |

### More graph properties:

- In the course, we usually substitute f = number of faces, n = number of vertices, m = number of edges (important for formula sheet)

- Euler's formula: n+f-m = 2 (holds for planar graphs)

- If a graph is planar and connected: m <= 3n-6

- If a graph is planar, bipartite, and connected: m <= 2n-4

- If a graph is planar, then there exists a vertex with a degree of at most 5 

- Not all planar graphs are connected 

- A tree has 1 face 

- Every tree with at least 2 vertices has a leaf (vertex of degree 1)

- aA graph is bipartite if and only if all cycles have even length

- Any complete graph has a Hamilton cycle

- The number of vertices of odd degree in graph G is always even

- A graph with m >= n-1 edges, n >= 3 vertices will have a cycle

- If and only if all vertices in graph have even degrees, then there is a Euler cycle in the graph 

- A graph has an Euler path if and only if there are at most two vertices with odd degree.

- A Hamiltonian path that starts and ends at adjacent vertices can be completed by adding one more edge to form a Hamiltonian cycle, and removing any edge from a Hamiltonian cycle produces a Hamiltonian path

- The complement of a connected graph can be connected or disconnected 

- Max number of edges in undirected graph is n*(n-1)/2

- Max number of edges in undirected graph is n*(n-1)

- K<sub>n</sub>: 

    - if n is even, then there will be no Euler cycle

    - if n is odd, there will be a Euler cycle

    - for n <= 4, it is planar (homeomorph of K5 or K3,3)

    - Every pair of vertices joined by an edge

    - Number of different Hamiltonian cycles is (n-1)!/2 

    - K<sub>5</sub> - Complete graph with 5 vertices, not bipartite and not planar

      ![K5 graph](k5.png)

      $ \binom{5}{2}$ = 10 edges

    - K<sub>3,3</sub> - Non-planar graph that has 3 vertices on top, 3 on bottom that is bipartite and complete (sometimes split left and right)

    ![K3,3 graph](k3.png)

    - Any complete graph (a graph in which each vertex is connected to every other vertex) with > 5 vertices is not planar: it is homeomorphic of K<sub>5</sub> or K<sub>3,3</sub>


- Q<sub>n</sub> - graph of n-dimensional hypercube

  - is bipartite for n >= 1

  - Always has 2<sup>n</sup> vertices, n*2<sup>n-1</sup> edges

    - it is a regular graph, each vertex has degree of n

  - for even n, it will have a Euler cycle

  - for graph with n > 1

    - has hamiltonian cycle

    - is planar for 1 < n <= 3

  - Q1 is a line, Q2 is a square, Q3 is a cube, higher dimensions are harder to visualize


##### Terms you may see elsewhere

First order logic = Predicate logic/calculus (For all, There exists)

Propositional logic = Sentential Logic (L arrow and L2)

Cycle = Circuit = Tour

Path = Trail

Edge = Arc

##### Course Links

- [Syllabus](/static/post-image/logic_syllabus.pdf)

- [Formula Sheet](/static/post-image/logic_formula_sheet.pdf)

##### Useful Links

- [YouTube Playlist](https://www.youtube.com/playlist?list=PL9DdgseuDZgKbu9DeqWJTbETQ8ZOIR2wO)

- [Propositional Logic](https://iep.utm.edu/prop-log/)

- [A Brief Overview of Logic](http://www.math.hawaii.edu/~ramsey/Logic.html)

- [Math Logic Course - Stonybrook](https://www3.cs.stonybrook.edu/~cse541/)

- [Hebrew Discrete Math Book](https://www.cs.mta.ac.il/staff/Michal_Parnas/publications.html)

<!-- * [Discrete Math Course - Tel Aviv U](http://courses.cs.tau.ac.il/bdida/06b/bdida06b.html) -->

- [Truth Tables, Tautologies, and Logical Equivalences](https://sites.millersville.edu/bikenaga/math-proof/truth-tables/truth-tables.html)

- [Explaining Quantifiers](https://www.whitman.edu/mathematics/higher_math_online/section01.02.html)

- [Deductions](https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec15-logic-contd/lec15.html)

#### Calculators and tools

- [Truth Table Generator](https://web.stanford.edu/class/cs103/tools/truth-table-tool/)

- [Logic Calculator: Truth Tables](https://www.erpelstolz.at/gateway/TruthTable.html)

- [Another logic calculator - quite good](https://sheabunge.github.io/boolcalc/)

- [Tree Proof Generator](https://www.umsu.de/trees/)

- [SymPy - python library for logic](https://www.sympy.org/en/index.html)

Python and programming aren't required for the course but its a good way to check your work!
and view my sample program for testing logic \* [here](/math/logic/program.py)
using the SymPy library

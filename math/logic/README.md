---
layout: page
title: Mathematical Logic
description: "intro to mathformalization, deduction, formal
proof, and concepts of mathematical logic"
permalink: /math/logic/
date: '2024-04-01'
categories: math
tags:
- Logic
- Math
image: 
sitemap:
  priority: 0.7
  changefreq: "monthly"
  
---

Some digital systems content, sentinal logic, prediate logic, graph theory 

Read: Discrete Mathematics and Its Applications by Kenneth H. Rosen (not required by the course)

* [Syllabus](/static/post-image/logic_syllabus.pdf)


* [Formula Sheet](/static/post-image/logic_formula_sheet.pdf)


* [YouTube Playlist](https://www.youtube.com/playlist?list=PL9DdgseuDZgKbu9DeqWJTbETQ8ZOIR2wO)

### Notes: 

- We studied sentential logic as part of the course, but it is often referred to as Propositional logic/calculus

- We also used a system called L arrow which exists in sentential logic (sometimes called language PC) 

- I advise reading the Rosen Discrete Math Book, in the first few hundred pages... it covers most of what the course does.

- Functionally complete sets that are good to know for exams and homeworks, here is a non exhaustive list of some basic ones

![Functionally complete sets](fc_sets.png)

##### Graphs: 

- In the course, we usually substitute F = number of faces,  n = number of vertices, m = number of edges

- Graph is bipartite iff it only has cycles of even length 

- Any complete graph (a graph in which each vertex is connected to every other vertex) with > 5 vertices is not planar: homeomorph of K5 or K3,3

- Any complete graph has a hamilton cycle 

- Graph with m >= n-1 edges, n >= 3 vertices will have a cycle

- Regular graph = each vertex has the same degree (same number of edges touching it)

- Qn - graph of n-domensional hypercube 

  * Q3 is a cube, higher dimensions are harder to visualize

  * always has 2<sup>n</sup> vertices, n*2<sup>n-1</sup>

    - it is a regular graph, each vertex has degree of n

K5 - Graph with 5 vertices all realized (complete)

![K5 graph](k5.png)

K3,3 - Graph that has 3 vertices on left, 3 on right that is bipartite and complete 

![K3,3 graph](k3.png)

#### Good to know 

Implication: A ⇒ B

  * A implies B (If A then B)

    - A ⇒ B is false when A is true and B is false, but otherwise it's true

Meta-Deduction: A ⊢ B

  * A proves B

    - B can be proved using A as premise

  * ⊢ A

    - A is a tautology (every premise can deduce A)

Meta-implication: A ⊨ B

  * A entails B

    - B is true in every structure where A is true

    - In every model, it is not the case that A is true and B is false

First order logic = Predicate logic (For all, There exists)

* If A ⊢ B then A ⊨ B (soundness theorem)

* If A ⊨ B then A ⊢ B (completeness theorem)

Propositional logic = sentential logic (L arrow and L2)


### Useful Links

* [Propositional Logic](https://iep.utm.edu/prop-log/)


* [A Brief Overview of Logic](http://www.math.hawaii.edu/~ramsey/Logic.html)


* [Math Logic Course - Stonybrook](https://www3.cs.stonybrook.edu/~cse541/)


* [Hebrew Discrete Math Book](https://www.cs.mta.ac.il/staff/Michal_Parnas/publications.html)

<!-- * [Discrete Math Course - Tel Aviv U](http://courses.cs.tau.ac.il/bdida/06b/bdida06b.html) -->

* [Truth Tables, Tautologies, and Logical Equivalences](https://sites.millersville.edu/bikenaga/math-proof/truth-tables/truth-tables.html)

* [Explaining Quantifiers](https://www.whitman.edu/mathematics/higher_math_online/section01.02.html)

* [Deductions](https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec15-logic-contd/lec15.html)


### Calculators and tools

* [Truth Table Generator](https://web.stanford.edu/class/cs103/tools/truth-table-tool/)


* [Logic Calculator: Truth Tables](https://www.erpelstolz.at/gateway/TruthTable.html)


* [Another logic calculator - quite good](https://sheabunge.github.io/boolcalc/)


* [Tree Proof Generator](https://www.umsu.de/trees/)


* [SymPy - python library for logic](https://www.sympy.org/en/index.html)

Python and programming aren't required for the course but its a good way to check your work!
and view my sample program for testing logic * [here](/math/logic/program.py)
using the SymPy library
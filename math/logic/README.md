---
layout: page
title: Mathematical Logic
description: "intro to mathformalization, deduction, formal
proof, and concepts of mathematical logic"
permalink: /math/logic/
date: '2024-03-14'
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

Read: Discrete Mathematics and Its Applications by Kenneth H. Rosen 

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

- Non-Planar Graphs:

K5 - Graph with 5 vertices all realized (complete)

![K5 graph](k5.png)

K3,3 - Graph that has 3 vertices on left, 3 on right that is bipartite and complete 

![K3,3 graph](k3.png)

### Useful Links

* [Propositional Logic](https://iep.utm.edu/prop-log/)


* [A Brief Overview of Logic](http://www.math.hawaii.edu/~ramsey/Logic.html)


* [Math Logic Course - Stonybrook](https://www3.cs.stonybrook.edu/~cse541/)


* [Hebrew Discrete Math Book](https://www.cs.mta.ac.il/staff/Michal_Parnas/publications.html)

<!-- * [Discrete Math Course - Tel Aviv U](http://courses.cs.tau.ac.il/bdida/06b/bdida06b.html) -->

* [Truth Tables, Tautologies, and Logical Equivalences](https://sites.millersville.edu/bikenaga/math-proof/truth-tables/truth-tables.html)

* [Explaining Quantifiers](https://www.whitman.edu/mathematics/higher_math_online/section01.02.html)


* [Deductions](https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec15-logic-contd/lec15.html)

#### Wikipedia Articles relevant to subject 

https://en.wikipedia.org/wiki/Propositional_calculus (Sentential Logic, L-> and L2)

https://en.wikipedia.org/wiki/Hilbert_system

https://en.wikipedia.org/wiki/Formal_system#Logical_system

https://en.wikipedia.org/wiki/First-order_logic (For all, There exists, predicate logic)



### Calculators and tools

* [Truth Table Generator](https://web.stanford.edu/class/cs103/tools/truth-table-tool/)


* [Logic Calculator: Truth Tables](https://www.erpelstolz.at/gateway/TruthTable.html)


* [Another logic calculator - quite good](https://sheabunge.github.io/boolcalc/)


* [Tree Proof Generator](https://www.umsu.de/trees/)


* [SymPy - python library for logic](https://www.sympy.org/en/index.html)

Python and programming aren't required for the course but its a good way to check your work!
and view my sample program for testing logic * [here](/math/logic/program.py)
using the SymPy library
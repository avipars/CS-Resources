---
layout: page
title: Discrete Math
permalink: /math/discrete/
description: Discrete Math course and tips
date: '2024-3-19'
categories: Discrete
tags:
- Discrete
- Math
- Sets
- Combinatorics
---


#### Set theory

- A, B are both sets such that:

    * A ∪ B = {x ∈ A or x ∈ B or both}

    * A ∩ B = {x ∈ A and x ∈ B}

    * A ⊕ B = (A - B) ∪ (B - A) = (A ∪ B) - (A ∩ B)

    * A - B = A ∩ Bᶜ = {x ∈ A and x ∉ B}

    - Demorgan's laws:

        * (A ∪ B)ᶜ = Aᶜ ∩ Bᶜ

        * (A ∩ B)ᶜ = Aᶜ ∪ Bᶜ

    - Associativity: 

        * A ∪ (B ∪ C) = (A ∪ B) ∪ C = A ∪ B ∪ C

    - Distributivity;

        * A ∪ (B ∩ C) = (A ∪ B) ∩ (A ∪ C)

        * A ∩ (B ∪ C) = (A ∩ B) ∪ (A ∩ C)


- Subsets: 

    * A ⊆ A ∪ B = B ∪ A

    * B ⊆ A ∪ B

    * If A ⊆ B, then A ∪ B = B

    * A ∩ B ⊆ A ⊆ A ∪ B

    * B ∩ A ⊆ B ⊆ A ∪ B

- Universal Set = U:

    for any finite set A

    * `U = { x ∈ U | x ∉ A }`

    * Aᶜ = U - A

    * (Aᶜ)ᶜ = A

    * Uᶜ = ∅

    * ∅ᶜ = U
 
 - Bidirectional inclusion:

    * To prove A = B, need to prove both B ⊆ A and A ⊆ B

- Power-set:

 * The power set of A is denoted as P(A) or 2^A

 * A ∈ P(A), ∅ ∈ P(A)

 * `If |A| = n, then |P(A)| = 2^n`

 * `|P(A)|` = 2<sup>|A|</sup>

 * If A = ∅, then P(A) = {∅}

 * If A = {1,2}, then P(A) = {∅, {1}, {2}, {1, 2}}


#### Links

* [Unions and Intersections](https://proofwiki.org/wiki/Union_Distributes_over_Intersection)


* [Union in Set Theory](https://en.wikipedia.org/wiki/Union_(set_theory))


* [Discrete Math](https://www.tutorialspoint.com/discrete_mathematics/discrete_mathematics_sets.htm)


* [Logic and Sets](https://www.whitman.edu/mathematics/higher_math_online/section01.05.html)


* [Defining relations on sets](https://math.libretexts.org/Courses/Monroe_Community_College/MTH_220_Discrete_Math/6%3A_Relations/6.1%3A_Relations_on_Sets)


#### Programs/Calculators

* [Another logic calculator - quite good](https://sheabunge.github.io/boolcalc/)


* [SymPy - python library for logic](https://www.sympy.org/en/index.html)


* [Power Set Calculator](https://www.wolframalpha.com/input?i=power+set+%7B%7B1%2C2%7D%2C%7B3%2C4%7D%2C+%285%2C6%29%7D)
---
layout: page
title: Discrete Math
permalink: /math/discrete/
description: Discrete Math course and tips
date: '2024-3-20'
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

 * `If |A| = n, then |P(A)|` = 2<sup>n</sup>

 * `|P(A)|` = 2<sup>|A|</sup>

 * If A = ∅, then P(A) = {∅}

 * If A = {1,2}, then P(A) = {∅, {1}, {2}, {1, 2}}

- Cartesian product:

 * `A × B = { (a, b) | a ∈ A and b ∈ B }`

    - an unordered set of sets of ordered pairs where a is in A, b is in B
    
    - if A = {1,2}, B = {2,3}, then A × B = {(1,2), (1,3), (2,2), (2,3)}

 * A × B ≠ B × A (unless A = B)

 * A ∩ (A × B) = ∅

 * `|A × B| = |A| × |B|`

 - Distribution:

    * A × (B ∪ C) = (A × B) ∪ (A × C)

    * A × (B ∩ C) = (A × B) ∩ (A × C)

#### Relations

- ARB = (a,b) ∈ R

- Identity: Ia = (a,a) 

    * Ex: {(1,1),(2,2),(3,3), ... } 

- Relation on set itself: R ⊆ A × A

    * ARA is another way to write it too. 

- Empty relation when R = ∅

    * implies that the relation R is empty, meaning it does not hold between any two pairs. It's essentially a relation with no elements.

- Complete relation when R = A × B

    * implies that the relation R contains all possible pairs that can be formed by taking one element from set A and one element from set B. It's a relation where every element of A is related to every element of B.

- Inverse relation is R⁻¹ = `{ (b, a) | (a, b) ∈ R }`

    * R consists of all pairs in R but with their elements reversed. If (a,b) is in R, then (b,a) is in R⁻¹

- Composition of relations:

    * R ∘ S = `{ (a, c) | ∃ b : (a, b) ∈ R and (b, c) ∈ S }`

    * Set of pairs (a,c) such that exists an element b for which both (a,b) is in R and (b,c) is in S

    * R ∘ R = R<sup>2</sup> is a relation composed with itself
    
    * (R ∘ S) ∘ T = R ∘ (S ∘ T) i.e it is associative (but not communitive)

- Important relations:

    1. **Reflexive:**
    - Shorthand: \( R ⊆ \{(a, a) \| a ∈ A\} \)
    - Meaning: Every element is related to itself. Ia ⊆ R
        - for all a ∈ A, aRa holds

    2. **Transitive:**
    - Shorthand: \( R ∘ R ⊆ R \)
    - Meaning: If \( (a, b) ∈ R \) and \( (b, c) ∈ R \), then \( (a, c) ∈ R \).
        - (aRb and bRc) -> aRc

    3. **Symmetric:**
    - Shorthand: \( R = R⁻¹ \)
    - Meaning: If \( (a, b) ∈ R \), then \( (b, a) ∈ R \).
        - When aRb <=> bRa

    4. **Antisymmetric:**
    - Shorthand: \( R ∩ R⁻¹ ⊆ \{(a, a) \| a ∈ A\} \)
    - Meaning: If \( (a, b) ∈ R \) and \( (b, a) ∈ R \), then \( a = b \).
        - (aRb and bRa) -> (a = b)
    - This does not mean not-symmetric 

- Equivalence relation

    -  is one where 1,2,3 all hold

- Order relation 
  
    - Partial order IFF 1,2,4 all hold
        * clear hasse diagram can be drawn 
            - items for which the relation doesn't hold will be drawn but not connected to the others in the diagram
    
    - Total/Linear order:
        * Partial order holds
        * Totality: For any \( a, b ∈ A \), either \( (a, b) ∈ R \) or \( (b, a) ∈ R \).
         - In other words: For any two distinct elements a and b, either a is related to b (a ≤ b), or b is related to a (b ≤ a).
        * hasse diagram would be a straight line (all elements relate to one another in this set)

    - Terms:
        * Minimal: An element a is minimal if there is no b such that b precedes a.
            -  Elements with nothing less than them (no predacessors)
        * Minimum: An element a is a minimum if for all b, a precedes b.
            -  Element that is less than everything else (either a set has 1 minimum or no minimum element)
        * Maximal: An element a is maximal if there is no b such that a precedes b.
            - follows from minimal
        * Maximum: An element a is a maximum if for all b, b precedes a.
            - follows from minimum

#### Functions

Let f,g be two functions, (f:A -> B) , (g:B -> A)

| Function f          | Horizontal line test    | Clasification | Invertibility    | G is \_ inverse of f | Definition                                                                      |                                                                                                        |
| ------------------- | ----------------------- | ------------- | ---------------- | ---------------------- | ------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| Onto                | Hits at least 1 point   | Surjective    | Right invertible | f ∘ g = Ib             | {f(a) | a ∈ A} = B every element in range (B) has a source                      | function that maps one or more elements of A to the same element of B                                |
| One to One          | Hits at most 1 point    | Injective     | Left Invertible  | g ∘ f = Ia             | if a1 != a2 then f(a1) != f(a2) or contrapositive if f(a1) = f(a2) then a1 = a2 | function that always maps the distinct element of its domain to the distinct element of its codomain |
| Onto and One to One | Hits exactly at 1 point | Bijective     | Invertible       | g ∘ f = Ia, f ∘ g = Ib | f⁻¹ = g                                                                         | function that is both injective and surjective                                                       |
| Identity Ia         | Hits exactly at 1 point | Bijective     | Invertible       | f ∘ Ia = f = Ib ∘ f    | f(a) = a                                                                        |                                                                 

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
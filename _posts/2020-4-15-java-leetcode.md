---
title: 'Number of Steps to Reduce a Number to Zero — Coding Interview Question in Java'
layout: post

external: true
blog: Medium
blog_link: https://medium.com/avi-parshan-studios/number-of-steps-to-reduce-a-number-to-zero-coding-interview-question-in-java-1a92fe414ea1

categories: post
tags:
- Java
- Leetcode
---

I wanted to answer some code interview questions to test myself. I found this question online and want to go explain my solution to try to help you. I tried doing this in a simple manner, but it my not have the best performance. If you have a more concise and fast solution, please leave it in the comments.

Question: Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

Here are the sample test cases:

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:

Input: num = 123
Output: 12
and here is my solution:


The question was pretty simple, but I’ll do my best to explain everything in more detail. We get a number, if it is even we divide it by two then continue. But, if it is odd, we subtract one and then continue.

I placed the “algorithm” in a while loop, because it is quite simple and short. In plain english, it would say, while number does not equal zero continue. If it is equal to zero, it exits the loop and then returns the amount of steps we took to get it down to the zero.

if(num % 2 == 0)

This is the central part of the algorithm. It is only true if the value is even. The modulo operator is a cool function in most programming languages. It finds the remainder after division of one number by another. In standard math, it would function as follows:

14 is even because 14/2 is equal to 7 without a remainder.
while: 
27 is odd, because 27/2 is equal to 13.5 or 13 remainder 1
step++;

is a simple way to add 1 to the value of step. You can also do step — ; to subtract 1. This is instead of writing out step=step+1;

I hope this explanation helped you learn java and some basic coding principles. Please clap if you found this useful!
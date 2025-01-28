---
title: 'My dive into Computer Architecture (Quick look at MIPS and the MARS Simulator)'
layout: post

external: true
blog: Everything Tech Review
blog_link: https://tech.aviparshan.com/2022/06/my-dive-into-computer-architecture.html

categories: post
tags:
- MIPS
- Architecture
---

MIPS CPU

Intro and Overview:
 While taking 2 courses on Computer Architecture (lab and lecture) with MIPS, I decided to compile the best resources that I could find and share some fun things I learned and built! 

I also built several interesting programs including a calculator, implemented bubble sort, and much more... I will share all the code at the end of the semester! 

MIPS is a RISC processer (reduced instruction set), the opposite would be CISC (complex), with processers such as the Intel Core and AMD Ryzen CPUS. 

The practical course primarily dealt with integers, which makes life way easier. We coded in the MIPS Mars Simulator (which has some cool tricks to it). Towards the end of the theoretical course we did cover Floating Point Conversions and Booth's Algorithm for multiplication. 

Prerequisites: 
Courses: 
Firstly, Digital Systems is a requirement for this course: 
You need to understand all the basic logic gates, registers, ALUs, conversion between bases, sign magnitude ,2s complement, Boolean addition, subtraction, and multiplication. 
Next, I advise you to take an Intro to Computer Science course before starting a Computer Architecture course.

This will allow you to understand the bigger picture in addition to assisting you with programming in the MIPS language. 
Additional subject matter:
Math Required:
Thankfully these courses don't require a high level of math, with that being said... you should know your powers of 2...
including 2^0 and the negative exponents.
this is because we are constantly using binary digits and need to convert easily 
Basic addition, long division, multiplication. 
Mainly for converting between different bases.
The Fun Part:
I came with prior coding experience but never dealt with assembly or anything remotely close to it before. I enjoyed learning about the instruction set and converting the logic I had previously into a program with assembly. For example, a for loop looks quite different than it would in C++ or Java.
        
        li $t0, 10 #run loop 10 times 
        li $t1, 0 #init counter 
 loop: #loop through all items
 beq $t1, $t0, result #reached end
 
 #do action
 
 addi $t1, $t1, 1 #increment counter
                 j loop #jump back to loop
        result:
                #perform action after ending the loop

Thankfully, MIPS is a reduced instruction set processer (referred to as RISC, even though MIPS might not technically be a RISC compatible processer), so there are a handful of commands that you will often use vs. thousands on a CISC (complex instruction set computer). While the code might look foreign now, there isn't much of a learning curve.

In addition, it was interesting to learn how the data-path and a computer works on the most basic level, even to just add two integers together. In addition, they had a lot of optimizations. Such as if you wanted to check that one number is equal to another... on the basic level, you just subtract one number from the other... and if the result is a 0, then they are equivalent.  
Another note - The lecture portion: 
There are two segments to the computer architecture class... a lab and lecture. The lab involves programming in assembly and submitting code as assignments. The lecture is on the architecture, how the data-path works, etc. 

For example, what happens when a command gets executed on the hardware level. This is more abstract and not-hands on. Nonetheless, it is quite important to learn how these micro-processers work. 
Cool trick below:

Using the MARS Simulator, I was able to visualize how the internals of the MIPS chip would work (it is an oversimplification of the data-path but still helpful). If you don't have the tool installed, I linked to it further down in the article (under resources). 
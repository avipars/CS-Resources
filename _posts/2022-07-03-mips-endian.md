---
title: 'MIPS and the Little Endians - Tips and an FAQ to help ace your computer architecture class and have fun doing so!'
layout: post

external: true
blog: Everything Tech Review
blog_link: https://tech.aviparshan.com/2022/07/mips-and-little-endians-tips-and-faq-to.html

categories: post
tags:
- CS
- MIPS
---

Cool tricks I found in the MIPS architecture and the MARS Simulator! Here are some tips and tricks to learning and coding in MIPS and with the MARS Simulator, most if not all these commands and tricks will also work in other IDEs. In addition, I have added other useful computer architecture formulas and information. 

Last updated: 7/5/2022

First, make sure to read this post before proceeding... once you finish, come back here and enjoy!
Q: Is MIPS little or big endian? What does that mean?
And what about the MARS Simulator?
A: According to the Patterson and Hennessey book (Computer Organization and Design: the Hardware/Software Interface), 

On page 70 :


MIPS is in the big endian camp. Since the order matters only if you access the identical data both as a word and as four bytes, few need to be aware of the endianness.
Newer versions of the MIPS chip can support both big and little endian (bi-endian?), unlike the previous versions. Nonetheless, MIPS is classically referred to as big endian. 

As for the MARS simulator, It is considered little-endian. 

How to check: You can test this, in the data segment (`.data`)  write:

    .data

    store: .byte 0,0,0,1 #load 4 entries, each a byte long

    store2: .byte 2,0,0,0 #I loaded a 2 here to avoid confusion. 

and when you proceed to assemble the code, you can see how they are stored in the data segment. Pay attention to the Value+0 (0x01000000) and Value+4 (0x00000002) 
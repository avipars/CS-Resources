---
layout: page
title: Intro to Data Security
description: "intro to data security, hacking, cyber warfare stuff!"
permalink: /intro_sec/
date: '2022-09-13 11:12:11 -0400'
categories: Security
tags:
- Security
- CS
- Cyber
- Data
sitemap:
  priority: 0.7
  changefreq: "weekly"
  
---

### Tips

Basic understanding of Python, and Linux will help a lot...
Install a virtual machine manager such as virtual box for windows, download ISO files for an OS you want to use such as windows, ubuntu, or kali... and get that set up! 

Prerequesites for the cousre: 

1. [Workshop in C/C++](https://cs.aviparshan.com/cpp_workshop/)

2. [Computer Architecture](https://cs.aviparshan.com/mips/)

### Scripts and fun

I will be adding some python and linux tips and tricks, for starters... we are using john the ripper to crack passcodes, here is my modified config file which can be downloaded with wget on Linux (WSL too)!

The rules are kept in /etc/john/john.conf. First copy it over to the local directory with cp /etc/john/john.conf .
Edit and copy back using sudo cp ./john.conf /etc/john/john.conf

wget https://cs.aviparshan.com//static/security-notes/jonh.conf

or download manually: 

[John Ripper Rules](/static/security-notes/jonh.conf)


Edit as you see fit, then with sudo cp it to john's directory!
### Notes 

[Lecture 1 Notes](/static/security-notes/Lesson1_Data.pdf)

[Lecture 2 Notes](/static/security-notes/Lesson2_Data.pdf)

[Lecture 3 Notes](/static/security-notes/Lesson3_Data.pdf)

[Lecture 4 Notes](/static/security-notes/Lesson4_Data.pdf)

[Lecture 5 Notes](/static/security-notes/Lesson5_Data.pdf)

// i will be adding more notes throughout the semester!

### Videos

[YouTube Playlist](https://www.youtube.com/playlist?list=PL9DdgseuDZgIRJSfMHG0GOHC4iM70pTQ1)


[Cryptography Video](https://www.youtube.com/watch?v=rfqOBzh-6j4)

### Useful Links

[Frequency Analysis](https://inventwithpython.com/hacking/chapter20.html)


[PGP Intro](https://users.ece.cmu.edu/~adrian/630-f04/PGP-intro.html)


and read "William Stallings, Lawrie Brown - Computer Security  Principles and Practice-Pearson (2014)"
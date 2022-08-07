---
layout: page
title: C++ Practice Exam 2022 Moed B
description: 5782 - תשפב 2022 Moed B Semester Bet Answers
date: '2022-08-04 16:05:11 -0400'
permalink: /cpp_workshop/Moed_B_2022/
categories: cpp
tags:
- Coding
- CPP
- OOP
- Exam
---

5782 - תשפב 2022 Moed B Semester Bet Answers:

[View Test (not tofes 0)](https://github.com/avipars/CS-Resources/blob/main/cpp_workshop/Moed_B_2022/test.pdf)

### Part A: 

Q1 B

 * cannot iterate over cat object, we need to define and overload a method to do so

Q2 A

 * First, it creates parent object (flower), then petal. Next it calls a method with value (not reference, so it needs the CC). Now, it utlizes the move constructor when returning the object... In the main method, the return value isn't being used, so it destroys the instance as it went out of scope. Pf and A are destoryed. Then it prints "main", and now the compiler knows that the program is about to end, so it calls the destructor on the rest of the items (in reverse order to creation).

Q3 D

 * A: This is how we declare pure virtual classes with = 0;

 * B: Abstract implies that there is one method that is pure virtual. And when there is a pure virtual function, you cannot make an instance of that class.

 * C: Yes, a single pure virtual method causes the whole class to be abstract.

 * D: False, any class that inherits from an abstract class and doesn't implement those pure virtual functions is still abstract and legal. 

 * E: Abstract base classes are useful for creating polymorphic programs. An abstract base class defines an interface without an implementation.

Q4 E

 * Static variables/members are on a per class level. Meaning, that B's num is not the same as A's num. In addition, because B uses a * (pointer), it doesn't actually instantiate the class. Therefore, it is set to zero. Regarding A's num, it instantiates 5 objects because of how we set it up in the array. 


Q5 B 

 * printVal() is a virtual function in addition to print(). Firstly, we call print() in the Father class which then calls printVal() also of the same object. 

Q6 C 

 * In the 1st program, we successfully write to the file. But we only write a single character and the rating. This is because 'char * name;' is used but not 'char name[20];', and as we know the pointer just links to the first element in the array. 

 * Now, when we go to read from the file, it fails to access the Restaurant's name field. 

Q7 A 

 * We are using the OR command with a 1, this essentially always passes a 1 into the Y variable in addition to whatever was held in X. Because it is also unsigned, it will always be >= 1. Now we shift that number 31 spots. This will result in an enourmous number which is 2<sup>31</sup> in decimal. And that translates to 2147483648 which is equal to 0x80000000 in Hex. As this either hits or exceeds the max limit of an INT, it will always be equal to that number. 


[View Code for Part A](https://github.com/avipars/CS-Resources/blob/main/cpp_workshop/Moed_B_2022/A)

### Part B and C
Part B and C will be uploaded here in the upcoming days (feel free to reach out with feedback, ideas, etc. either by openign a github issue or tweeting me).

Part B: 

[View Code for Part B](https://github.dev/avipars/CS-Resources/blob/main/cpp_workshop/Moed_B_2022/B)

All is live except for Q11 Part B (is in progress, feel free to submit a pull request). 


Part C:

<!-- [View Code for Part C](https://github.dev/avipars/CS-Resources/blob/main/cpp_workshop/Moed_B_2022/C) --> -->

Q12 is in progress, feel free to submit a pull request
<!-- תשובות לחלק מהם:
1 - ב
2 - א
4 - ה
5 -ב
6-ג
7-ה
9- ידפיס:
exception in day
---we finish
יעוף

הערך של months[0]->days לא יהיה מאותחל -->
---
layout: page
title: C++ Practice Exam 2022
date: '2022-07-24 17:12:11 -0400'
permalink: /cpp_workshop/Exam_2022
categories: CPP
tags:
- Coding
- CPP
- OOP
---

5782 - תשפב 2022 Moed A Semester Bet Answers

Hebrew PDF of the original final is here (not tofes 0 - where all answers would be A):  קובץ מקורי - שאלון (לא טופס א)
[Original Questionnaire שאלון מקורי](https://github.com/avipars/CS-Resources/blob/main/cpp_workshop/Exam_2022/test_2022.pdf)

Part A: (Multiple choice, choose 6 out of 7)  חלק A - שאלות אמריקאיות 
היה דרישה לענות על 6 מתוך 7 מהם

Answers Below: 


#### Q1: 
  A 

  6 Times due to the 

  ```cpp
  Animal m_myFriend;
  ```

  private data member



#### Q2
  D

By making the Five* const, we then are forced to only use const methods to avoid changing the instances. There is an error when we try to call the print method because it isn't const, therefore can theoretically modify the object. 
  אם פרינט היא לא const אס אי אפשר לקרוא לה ממתודה שהיא const



#### Q3
  A

  By adding 

   ```cpp
   friend class b; 
   ```
   to A, we are allowing B to access private data members and methods of A and thefore making 

  ```cpp
   cout << a.field;
   ```

   work.




#### Q4
  A

  (some people chose E and got partial credit - due to misunderstanding of move constructor) 
חלק מהסטודנטים ענו הל ה וקיבלו חלק מהנקודות בגלל שלא למדו את הmove contructor כמו שצריך



#### Q5
  D

  Pay attention the use use of virtual for show2() but not for show1().
  Also, we created an instance of B and then threw it. We were able to catch the error as an A* because B inherits from A and can act as an instance of A. show1() calls A because that's what normally happens (show1() isn't aware that this A* happens to be of type B). On the other hand, show2() is using the virtual keyword. Now, the call first goes to show2() of the A class, but then it doesn't go into the body of the method, rather it jumps to show2() of the child. The child then prints B2 and calls the parent method show2(). Now it jumps into the parent's show2() and prints it. Then the default destructor is called and then program ends. 


#### Q6
  C

  ofstream and ifstream are both inlcuded in fstream. We can already use process of elimination to get rid of D and E as:

  
  ```cpp
   sizeof(Student) is equal to  sizeof(firstStudent)
   ```


The size of the instance is determined by it's fields (int and a char array in our case). How would you determine the size of a class? It turns out, that in C++, a class can be called a (user-defined) type, when we run sizeof(char), we can see that char is a type and (probably) has it's own class in C++. So the same goes for our type, Student!  

They are both 20 bytes, 4 for int and 16 for the char array (probably, because it includes the null terminator). We can get rid of B because it's totally possible to open and close a file in the same program. Lastly, we have either A or C... as there is no computer allowed on the test we need to resort to memory when we wrote and read from files... In my book, it does print "avi" to the console and you can run it yourself to see!


#### Q7
  B

  We need to know some bitwise operators in this case, specifically the left shift and the AND operators. In the first line of the program, we are performing a bitmask... essentially only odd numbers have the LSB in the 0's place be a 1. Just recall the 8 4 2 1 trick... any number between 0 to 15 (unsigned) can be represented in 4 bits. An even number has no use for the #1. TL;DR, the first line of code will &AND your number with 1. Odd numbers will result in y = 1, even will be y = 0. Lastly, in the next line we shift the nummber y left by 31 places. If Y was 0, then shifting it left or right doesn't change the number... it will still be 0, which translates to false in C++'s boolean logic, but if y was equal to 1, left shifitng it will just increase it's value by a power of 2 each time... in our case 2<sup>31</sup> == 2,147,483,648 an arbitrarily large number which just boils down to true.


<!-- Q1 A

Q2 D

Q3 A

Q4 A (some people chose E and got partial credit - due to misunderstanding of move constructor) 
חלק מהסטודנטים ענו הל ה וקיבלו חלק מהנקודות בגלל שלא למדו את הmove contructor כמו שצריך

Q5 D

Q6 C

Q7 B -->

I typed out the code for the multiple choice questions as well, and they will be in the same directory. 
Note that the code is not necessarily one-to-one with the final exam, the changes that I may have made are very minor and easy to revert. Feel free to fork this or copy the code, run it, and make changes! 


[Code for multiple choice questions  קוד לחלק A](https://github.com/avipars/CS-Resources/tree/main/cpp_workshop/Exam_2022)

[Code for open ended and fill in blank questions קוד לחלק ב וג](https://github.com/avipars/CS-Resources/tree/main/cpp_workshop/Exam_2022/open)
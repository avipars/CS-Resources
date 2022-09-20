---
title: "Stack smashing and buffer overflows with C/C++ Programs"
layout: post
deescription: "For another assignment, we are given some vulnerable C and C++ programs which the user or a hacker can exploit with a buffer overflow attack (stack smashing)"
image: /static/post-image/stack.png
categories: post
tags:
- BufferOverflow
- Security
- StackSmash
- Hashing
---


For another assignment, we are given some vulnerable C and C++ programs which the user or a hacker can exploit with a buffer overflow attack (stack smashing). Thankfully, most modern compilers have built in protections (such as canaries) to avoid stack smashing attacks. 

<img src="{{ site.url }}{{ page.image }}" alt="Dall-e Stack Smashing" width="500" />


But for the homework, we are asked to compile the code wihtout protections (or to find an old compiler that didn't implement protections)... and then exploit it!

I tried both on my windows machine as well as an ubunutu vm wiht some flags/tricks to get it to work...

I'll share them here to help you if you are in a similar situation. 

In linux, you can use the terminal and GCC (compiler) to package your code... switch the "yourprogram" name to the actual name of your program and run this in the same directory where the program is....

```console

gcc yourprogram.c -o theprogram -zexecstack -fno-stack-protector -g

```

"theprogram" is an arbitrarily set name for the compiled C/C++ code... you can keep it or change it... but you must remember it..

Now to run the code, you can write "./theprogram" (without quotes) and it will execute the main() function. If you want to add an argument, then just do as follows:  "./theprogram your argument here". in the challenges we are using, you may have to fill the char buffer[64] before you can cause the overflow and execute your attack. In that case, fill the argument with at least 64 characters... if you want to save time, you can have a pytho program pipe in the characters.

For example: 

```console

python3 -c "print('A'*64)" | ./theprogram 

```


This will place 64 A's into the argument of your program. 

Another useful trick is to use the object dump:

```console

 objdump -D ./theprogram | grep functionName

```

If you want to find the address of your function "functionName" which will come in handy for some of the challenges. 

Another useful source is to just find n old VM to run the attack in... this one is quite common, we used the protostar one 

https://exploit-exercises.com/download/

Then you don't need to run gcc with the special flags...
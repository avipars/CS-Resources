---
title: 'What are Template Functions and Classes in C++ and how can I use them?'
layout: post

external: true
blog: Everything Tech Review
blog_link: https://tech.aviparshan.com/2022/07/learn-c-and-oop-easily-template.html

categories: post
tags:
- CPP
- Templates
---

C++ gave us a new superpower which is generic programming! We an make a class and/or function which can handle any data type a user throws at it. 

Template Classes: 
Note that there are some restrictions to this: you need to always write template <typename  T> before each function (in addition to the top of the file), or template <class T> also works instead. T is an arbitrary type, feel free to rename it with something else but keep it consistent. In addition, C++ handles template classes during the pre-processing stage. This means that we need to put the template class in a header file (.h) in order for it to be recognized and dealt with by the compiler. 
Here is a sample I built which uses the Stack Data Structure implemented via a Linked List. You can also implement a stack in another way such as via an array, for example. 

https://github.com/avipars/CS-Resources/blob/main/cpp_workshop/Stack_Linked_list.h

It is up to the compiler to convert the template to the data type the user/developer wants. 

For example, Vector is an STL container that does in fact use templates! When we call vector<int> data (14,5); , under the hood the vector template class is used, the data type becomes int from T in all the functions and data members. 

Note that if you have vector<int> and vector<float> in the same main.cpp file, it will work perfectly fine. For every different data type used, the template generates a new class to handle it. This also means that if we modify the vector<int> array, it doesn't change the vector<float> array. In addition, all the data members are kept separate to each respective type. 

In the following example, you can see that we can make a less-generic template given a specific type. This can come in handy if we have a generic template function or class but want to handle a given data type differently. In this case, the compiler will try to first go to the specific implementation (if it exists) before defaulting to the generic one. 


#include<iostream>

using namespace std;

template<class Type>

class A{

 Type a;

public:

A(Type a);


};

template<>A<float>::A(float a){

    a=12.5;

    cout<<a<<endl;

}

//template for int type specific

template<>A<int>::A(int a){

    a=8;

    cout<<a<<endl;

}

template<class Type>A<Type>::A(Type a1){

 this->a=a1;

 cout<<a<<endl;

}

int main(){

 int a=2;

 float b=3.5;

 double c=7.5;

 A<int>ob1(a);

 A<float>ob2(b);

 A<double>ob3(c);

    return 0;

}

//output: 8

//12.5

//7.5

In this case, we provided a specific template for int and float values, but not double. So the compiler correctly used our specific functions for int and float... but the generic function for double. 

Template Functions:
In your main.cpp file, you can also have template functions! In addition, they can have multiple parameters. It comes in handy if you want to save on writing code to handle all the different possible types that would need a swap function. They operate similarly to template classes...
template <typename A> //swap should occur between two variables of the same type

void swap(A &a, A &b) //by reference so that we actually modify the variables

{

    A temp = a;

    a = b;

    b = temp;


}

template <class A,class B> //in this case we can accept two different types

double test(A x,B y){ //i decided to return a double to have the most accurate result, but you can return type A or B as well

    return (x+y)/2;

}

int main(){ //main function to test the actual template implementation

    int a = 1;

    int b = 2;

    swap(a, b); //now we call it with 2 ints


    cout << a << " " << b << endl;

    cout << "test" << endl;

    double d1 = 1.0;

    int d2 = 2.0;

    cout << test<double,int>(d1,d2) << endl;

    return 0; }



Thank you for reading, please share the article and follow me on twitter for more resources and guides!
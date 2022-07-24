/*
	Course: C++ Workshop
	Excersice: 3, Week 3
	Description: Header file with the declaration of the class
*/
#pragma once // to avoid multiple inclusions

#include <iostream>
using namespace std;
class MyString
{
	private: 
		int len = 0; // length of string
		char *str;	 // string array

	public:
		MyString() : str(nullptr), len(0) {}	 // explicit empty constructor
		MyString(const char *s);				 // constructor
		MyString(const MyString &ms);			 // copy constructor
		MyString &operator=(const MyString &ms); // assignment operator
		~MyString();							 // destructor

		MyString(MyString &&ms);			// move constructor
		MyString &operator=(MyString &&ms); // move assignment operator

		bool operator==(const MyString &ms) const;
		MyString operator+(const MyString &ms) const;
		MyString operator*(const int) const;

		friend ostream &operator<<(ostream &os, const MyString &ms);
		friend istream &operator>>(istream &is, MyString &ms);

		// additional methods - handcoded by me ;) 
		char &operator[](int); // index operator - R/W
		const char &operator[](int) const; // index - Read only
		// first retrieves and updates, 2nd only retrieves

		MyString insert(int index, const char *str); //insert substring 
		// comparisons 
		bool operator>(const MyString &) const;
		bool operator<(const MyString &) const;

		bool operator>=(const MyString &) const;
		bool operator<=(const MyString &) const;
		bool operator!=(const MyString &ms) const;
		bool isEmptyOrNull() const; //tells if string is empty or null, like in c#

};

/*
Sample Run:
in main.cpp
*/
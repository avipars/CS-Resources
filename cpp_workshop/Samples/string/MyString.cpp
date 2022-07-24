/*
    Course: C++ Workshop
    Excersice: 3, Week 3
    Description: The actual string class with all the functions - comparison, concatenation, etc.
    Note that I changed the MA and CA to avoid a self assignment, in addition I had to change my insert function in order to get it to call the Move Constructor properly 
*/

// due to moodle issues, the strcpy_s method isnt working, so I swapped with with strcpy
#include <cstring>
#include "MyString.h"

MyString::MyString(const char *s) // default constructor
{
    if (s) // s!=0
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    else
    {
        str = NULL;
        len = 0;
    }
}

MyString::MyString(const MyString &ms) : MyString(ms.str) // copy constructor
{
    // from the github
}

MyString::MyString(MyString &&ms) // move constructor
{
    len = ms.len;
    str = ms.str;  // steal (dont copy) rvalue's data
    ms.str = NULL; // very important!!!

    cout << "move ctor" << endl;
}

MyString &MyString::operator=(const MyString &ms) // copy assign
{
    if (this != &ms) // check for self assignment
    {
        len = ms.len;

        if (str)
        {
            delete[] str; // free the memory
        }

        if (ms.str) // not null/zero
        {
            len = strlen(ms.str);
            str = new char[len + 1];
            strcpy(str, ms.str);
        }
        else
        {
            str = NULL;
        }
    }
    return *this;
}

MyString &MyString::operator=(MyString &&ms) // move assignment operator
{
    if (this != &ms) // make sure it isnt stealing from itself
    {
        if (str) // not null/zero
        {
            delete[] str; // free the memory
        }

        len = ms.len; // take length
        str = ms.str; // steal (dont copy) rvalue's data
        ms.str = NULL;

        cout << "move assign" << endl;
    }
    return *this;
}

MyString::~MyString() // destructor
{
    if (str) // very important!!!
    {
        delete[] str;
    }
    str = NULL; // nullify
}

MyString MyString::operator+(const MyString &ms) const // addition operator / combining 2 strings
{
    int sizeI = len;
    int sizeII = ms.len;
    char *temp = new char[sizeI + sizeII + 1];

    strcpy(temp, str);
    strcpy(temp + sizeI, ms.str);

    MyString x(temp);

    return x;
}

bool MyString::operator==(const MyString &ms) const
{
    return !strcmp(str, ms.str); // 0 = equal
}

MyString MyString::operator*(const int num) const
{
    char *temp;
    temp = new char[len * num + 1];

    for (int i = 0; i < num; i++)
    {
        strcpy(temp + i * len, str);
    }
    MyString s(temp);

    return s;
}

// friends! - cout
ostream &operator<<(ostream &os, const MyString &ms)
{
    if (ms.str)
    {
        os << ms.str;
    }

    return os;
}
// cin
istream &operator>>(istream &is, MyString &ms)
{
    is >> ms.len; // get input length

    ms.str = new char[ms.len + 1]; // new string
    is >> ms.str;                  // get input

    return is; // return the input
}
//----end of provided code -----

// my improvements 

//method to verify if a string is empty or not
bool MyString::isEmptyOrNull() const //took the idea from C#, comes in handy as it saves code 
{
    return (len == 0 || str == NULL);
}

// comparison
bool MyString::operator!=(const MyString &ms) const
{
    return !(str == ms.str); // 0 = equal
}

// greater than lexographically
bool MyString::operator>(const MyString &ms) const
{
    return strcmp(str, ms.str) > 0; // 0 = equal
}

// less than lexographically
bool MyString::operator<(const MyString &ms) const
{
    return (ms.str > str); // flip the sign and use the greater than operator
}

// less than or equal to lexographicallsy
bool MyString::operator<=(const MyString &ms) const
{
    return !(str > ms.str); // not greater than
}

// greater than or equal to lexographically
bool MyString::operator>=(const MyString &ms) const
{
    return !(str < ms.str); // not less than
}

//subscript operators - get a single char from a string (index) R/W
char &MyString::operator[](int index) // retrieve and update
{
    if (index >= len || index < 0 || len <= 0)
    {                            // index out of range
        cout << "ERROR" << endl; // overflow or underflow
        exit(0);                 // nothing to return as it would be illegal character
        return str[0];           // return first character
    }
    return str[index]; // returns a single character at index
}

//subscript operators - get a single char from a string (index) READ ONLY
const char &MyString::operator[](int index) const // retrieive only - [] operator
{
    if (index >= len || index < 0 || len <= 0)
    {                            // index out of range
        cout << "ERROR" << endl; // overflow or underflow
        exit(0);
        return str[0]; // return first character
    }
    return str[index]; // returns a single character at index
}

// insert a string wihtin a string - I had to modify my method for it to call the MC properly, due to copy elision 
//we spoke to Mr. Shendowitz about this issue 
MyString MyString::insert(int index, const char *newstr) 
{
    int modStrLen = strlen(newstr); // get length of new string

    int totalLen = len + modStrLen;           // total length of both
    char *newString = new char[totalLen + 1]; // create new string
    if (index > len || index < 0 || len <= 0) // error cases  - empty string, underflow or overflow
    {
        cout << "ERROR" << endl;
        MyString myNewString(""); // empty string to trigger move ctor
        return myNewString;       // return empty string 
    }

    int i; //need this later for the for loop
    for (i = 0; i < index; ++i) // copy as usual till hit index
    {
        newString[i] = str[i]; // copy characters
    }

    int j, k = 0;  // index for new string
    for (j = index; j < modStrLen + index; ++j, ++k) // overwrite the null
    {   // copy new changes - can handle more than a character!
        newString[j] = newstr[k];
    }

    while (j < totalLen) // copy rest of string
    {
        newString[j] = str[i]; // copy rest of original string
        ++j;                   // increment counters
        ++i;
    }

    newString[totalLen] = '\0'; // add null terminator at end
    // it isnt the best code, but it order to trigger the MC, this had to be done
    MyString myNewString(newString); // assign new string to myNewString - I had to call this in order to use the move constructor
    delete[] newString;              // free memory
    return myNewString;              // return new
}

/*
Sample Run:
in main.cpp
*/
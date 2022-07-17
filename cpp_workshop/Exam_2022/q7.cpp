// q7
#include <iostream>
using namespace std;

bool f(int x)
{                                   // not defined for negative numbers
    unsigned int y = x & 0x0000001; // bit mask
    y <<= 31;                       // shift left 31 bits (same as y = y << 31;)

    return y;
}

// convert 0 and 1 to text (t/f)
void prettyPrint(bool x)
{
    cout << ((x) ? "true" : "false") << endl;
}

// bonus funct. not related to question
void print(int count)
{ // provided a #, the print function goes from 0 to that number and calls the mystery funct.

    for (int i = 0; i < count; i++)
    {
        /* code to print if T or F (rather than a 1 or 0) */
        cout << i << ' ';
        prettyPrint(f(i));
        cout << ' ';
    }
}

int main()
{

    int num;
    cout << "Enter a number to check: " << endl;

    cin >> num;

    if (num < 0)
    {
        cout << "not defined for x < 0" << endl;
        return 1; // return 1 to indicate error
    }

    prettyPrint(f(num));
    cout << ' ';

    cout << "Test all numbers from 0 to " << num << endl;
    print(num);
    return 0;
}
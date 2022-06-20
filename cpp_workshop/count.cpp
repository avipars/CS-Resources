//code from 2017 midterm 
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class C
{
    static int counter;

public:
    C() { counter++; }
    C(int size)
    {
        counter++;
    }
    C(C &other)
    {
        cout << ++counter << ' ' << endl;
    }
    ~C()
    {
        counter--;
        cout << "dtor: " << counter << endl;
    }
    C operator+(C c)
    {
        C tmp;
        return tmp;
    }
    //no call by reference = obj copy
    bool operator==(C c)
    {
        return true;
    }
};
int C::counter = 0;
int maineddd()
{
    C c1(4);
    C c2;
    C c3(c1);
    if (c1 == c2)
    {
        cout << "c1 == c2" << endl;
        c1 = c1 + c2;
    }
}
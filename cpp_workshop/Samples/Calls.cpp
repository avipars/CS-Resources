//operator overload 
#include <iostream>
#include<vector>
using namespace std;
class A
{
private:
    int n;

public:
    A()
    {
        cout << "Default Constructor: Start " << n << endl;
        n = 0;
        cout << "Default Constructor: End " << n << endl;
    }
    A(int _n)
    {
        cout << "Assign Constructor: Start " << n << endl;
        n = _n;
        cout << "Assign Constructor: End " << n << endl;
    }
    A(const A &a) //copy ctor
    {
        cout << "Copy Constructor: Start " << n << endl;
        n = a.n;
        cout << "Copy Constructor: End " << n << endl;
    }
    A(A &&a) //move ctor
    {
        cout << "Move Constructor: Start " << n << endl;
        n = a.n;
        cout << "Move Constructor: End " << n << endl;
    }
    A &operator=(const A &a) //copy assign
    {
        cout << "C operator=: Start " << n << endl;
        n = a.n;
        cout << "C operator=: End " << n << endl;
        return *this;
    }
    A &operator=(A &&a) //move assign
    {
        cout << "M operator=: Start " << n << endl;
        n = a.n;
        cout << "M operator=: End " << n << endl;
        return *this;
    }
    A &operator+=(A &a)
    {
        n += a.n;
        return *this;
    }
    A &operator-=(A &a)
    {
        n -= a.n;
        return *this;
    }
    A operator*=(A &a)
    {
        n *= a.n;
        return *this;
    }
    A operator/=(A &a)
    {
        if(a.n == 0)
           { throw "Division by zero";}
        n /= a.n;
        return *this;
    }
    A operator+(A a)
    {
        n += a.n;
        return *this;
    }
    A operator-(A &a)
    {
        n -= a.n;
        return *this;
    }
    A operator*(A &a)
    {
        n *= a.n;
        return *this;
    }
    A operator/(A a)
    {
        if(a.n == 0)
           { throw "Division by zero";}

        n /= a.n;
        return *this;
    }
    A& operator++() //prefix
    {
        n++;
        return *this;
    }
    A operator++(int) //postfix
    {
        A temp(n);
        n++;
        return temp;
    }
    A& operator--()
    {
        n--;
        return *this;
    }
    A operator--(int) //post
    {
        A temp(n);
        n--;
        return temp;
    }
    //compare 
    bool operator==(A &a) const
    {
        if(n == a.n)
            return true;
        else
            return false;
    }
    bool operator!=(A &a) const
    {
        if(n != a.n)
            return true;
        else
            return false;
    }
    bool operator<(A &a) const
    {
        if(n < a.n)
            return true;
        else
            return false;
    }
    bool operator>(A &a) const
    {
        if(n > a.n)
            return true;
        else
            return false;
    }
    bool operator<=(A &a) const
    {
        if(n <= a.n)
            return true;
        else
            return false;
    }
    bool operator>=(A &a) const
    {
        if(n >= a.n)
            return true;
        else
            return false;
    }    
    friend ostream &operator<<(ostream &out, A a)
    {
        out << a.n;
        return out;
    }
    friend istream &operator>>(istream &in, A &a)
    {
        in >> a.n;
        return in;
    }
    void print() const
    {
        cout << "print: ";
        cout << n  << endl;
    }
    ~A()
    {
        cout << "Destructor called: " << n << endl;
        n = 0;
    }
};


int main()
{
   
    try{
        A a(6), b(7); ; 

        a = b; //copy assign

        cout << "Testing CTORS " << endl;
        vector <A> v;
        v.push_back(a);
        v.push_back(A{55});

    }
    catch(const char *msg){
        cout << msg << endl;
    }


    return 0;
}

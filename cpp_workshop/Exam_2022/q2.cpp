//q2
#include <iostream>
using namespace std;

class Five
{
public:
    virtual void print() const
    {
        cout << 1;
    }
};

class Four : public Five
{
public:
    void print() const override
    {
        cout << 2;
    }
};

class Three : public Five
{
private:
    Four a;

public:
    void print() const
    {
        a.print();
        cout << 3;
    }
};

int main()
{
    const Five *sentence[2] = {new Four(), new Three()};

    for (int i = 0; i < 2; ++i)
    {
        sentence[i]->print();
    }

    for (int i = 0; i < 2; ++i)
    {
        delete sentence[i];
    }
}
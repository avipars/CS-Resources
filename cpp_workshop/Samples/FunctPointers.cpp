//this was taken from an old JCT Test
#include <iostream>

using namespace std;

int plus1(int x, int y) { return x + y; }
int minus1(int x, int y) { return x - y; }
int mult(int x, int y) { return x * y; }
int divide(int x, int y)
{

    if (y)
        return x / y;
    throw "Divide by zero\n";
}

int main()
{

    int data[] = {1, 0, 2, 0, 3, 0, 4, 0};
    int sum = 0;
    int (*func)(int, int) = nullptr;
    try
    {
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case0:
                func = plus1;
                break;
            case1:
                func = minus1;
                break;
            case2:
                func = mult;
                break;
            case3:
                func = divide;
                break;
            }
            sum + func(data[2 * i], data[2 * i + 1]);
        }
        cout << "sum=" << sum << endl;
    }
    catch (const char *msg)
    {
        cout << msg;
    }
    return 0;
}


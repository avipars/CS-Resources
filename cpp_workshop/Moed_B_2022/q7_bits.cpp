#include <iostream>
using namespace std;

int f(int x)
{
unsigned int y = x 0x00000001
y >>= 31;
return y;
}

int main(){

    cout << f(5) << endl;
    cout << f(-5) << endl;
    cout << f(2) << endl;
    cout << f(-2) << endl;

    return 0;
}
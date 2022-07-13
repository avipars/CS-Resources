#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    //Question 9 (7 points) 5778 moed aleph
    cout << " sevens " << endl;
    for(int i = 10; i < 100; ++i)
    { //print only 2 digit number with 7 or divisible by 7 
        if((i % 7 ==0) || (i / 10 == 7) || (i % 10 == 7))
        {
            cout << i << endl;
        }
    }
    return 0; 
}

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;

    int count = 0;
    bool prime = false; 
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            count++;
            prime = false;
        }
        else
        {
            prime = true;
        }
    }
    cout << prime << endl;
    cout << "The number of " << num << " factors is: " << count << endl;
    return 0; 
}
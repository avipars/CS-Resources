#include <iostream>
#include <ctime>
using namespace std;
// Question 10 (7 points)
// Given the following definition of an array called arr:
// char arr[100];
// Initially all elements of arr contain the character ‘Y’. Write code that replaces the character ‘Y’ with the character ‘X’ in 5 different random elements of the array. 
// Note, you may assume that the array has been previously properly initialized, and that all the necessary libraries have already been included in the program.

int main()
{
    char arr[100] = {'Y'}; 
    int i = 0;
    while(i < 100){
        arr[i] = 'Y';
        i++;
    }

    srand(time(nullptr));
    for(int i = 0; i < 5; ++i)
    {
        int index = rand() % 100;
        arr[index] = 'X';
    }
    
    for(int i = 0; i < 100; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <ctime>
using namespace std;
//question 11 5778 
// An array called numbers contains a list of integers in some random order. The last number in the list is marked with a 0 (0 can be an element of the sequence).

// Write code that performs the following:
// a.	finds the longest sequence of strictly increasing numbers
// b.	prints the length of the sequence found in the part a.

// You must use pointers only. A solution which uses array indices will not receive any points!

// As an example, on the following array,

int main()
{
    int numbers[11] = {50,62,-3,2,1,5,7,9,4,6,0};
    // int numbers[11] = {1,2,3,-6,5,5,7,8,9,10,0};

    //find the longest sequence of strictly increasing numbers
    int longest = 0;
    int temp = 1; 
    for(int *p = numbers; *p != 0; ++p)
    {
        if(*p < *(p+1))
        { //if the next number is bigger than the current number
            temp++;
        }
        else
        {
            if(temp > longest) //current seq longer than last 
            {
                longest = temp;
            }
            temp = 1;
        }
       
    }
    cout << "the longest sequence of strictly increasing numbers is " << longest << endl;


    return 0;
}
/*
    Question1AB.cpp
    This program takes in a number and using recursion prints that number A times and then B times
    Week 11
 */

#include <iostream>

using namespace std;

//function prototype
void printABs(int);

//code provided by the homework assignment
int main()
{
    cout << "Enter a number:" << endl;

    int num; //number variable 

    cin >> num;

    printABs(num); //call recursive function

    return 0;
}

//num = user input number 
//recursive function to print out a and b the amount of times that num is equal to
void printABs(int num)
{
    if (num <= 0) //if number hits zero or a negative  
    {
        return; //escapes the function and doesn't run the recursive code
    }
    else
    {
        cout << "a"; //prints the letter A, 1 time

        printABs(num - 1); //now # decreases by 1 ... and run through the recursive fn yet again... 

        cout << "b"; //finally get to B - called after - so it prints cleanly 
    }
}

/*
sample run: 
Enter a number:
6
aaaaaabbbbbb
Enter a number:
1
ab
Enter a number:
0
*/
/*
    Course: C++ Workshop
    Excersice: 3, Week 3
    Main file for handling and testing different string operations
*/
#include "MyString.h"
#define MAX_SPACE 20 //max size for the char arrays to avoid more dynamic alloc 
using namespace std; 

int main()
{
    // MyString first, second; //init both to empty string
    char a[MAX_SPACE], b[MAX_SPACE]; 
    int n; //for the size of the string
    cin >> a; //get all the strings
    cin >> b; 
    cin >> n; 

    MyString first(a), second(b);  //create both instances
    cout << "a";     //lexographic relationships

    if(first == second){
        cout << "=";
    } else if(first < second){
        cout << "<";
    } else { //first must be greater than second as both other options have been ruled out 
        cout << ">"; 
    }
    cout << "b" << endl; 

    //move ctor
    //move assign 
    MyString newObj; //new object
    newObj = second.insert(n,a);  //insert first string into second
    if(!newObj.isEmptyOrNull()) //possible case of error with input 
    {
        cout << newObj << endl;  //avoid case where it would print a blank line
    }

    char letter; 
    cin >> letter; //take a letter
    int index; 
    cin >> index; //take an index to place it in 

    newObj[index] = letter;  //change a character
    cout << newObj << endl; //print results 
    return 0; 
}

/*
Sample Run:
Hello
World
8
a<b      
ERROR    
move ctor
move assign
J
3
ERROR
Hey
There
3
a<b
move ctor
move assign
TheHeyre
#
4
TheH#yre
Purim
Purim
3
a=b
move ctor
move assign
PurPurimim
4
4
PurP4rimim
*/ 
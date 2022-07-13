#include <iostream>
#include <fstream>

//q 12 5778 moed a
// The function split receives as one of its parameters an array of characters (string) called sentence. The string may contain upper case letters, lower case letters, digits, or other characters.

// Write a function that returns two new arrays of characters (strings) such that the first string contains all the upper-case letters in sentence, and the second string contains all the digit characters in sentence.

// You may assume that there already exists a function called countLetters which returns the number of upper case letters in the string that it was passed, and a function called countNumbers which returns the number of digits in the string that it was passed. You may use these functions in your code.

// For example, if sentence contains the following array of characters:

// \0	!	A	,	6	D	q	F	A	8	7
// 	9	8	7	6	5	4	3	2	1	0
// then after calling the function split as follows:
//     split(sentence, letters, numbers);

// the array letters will contain:

using namespace std;



void reverser(char *sentence, int size)
{
    for(int i = size; i > 0; i--)
    {
        cout << sentence[i];
    }
}

int countNumbers(const char *arr){
    int i = 0;
    int num =0;
    while(*(arr + i) != '\0')
    {
        if((*(arr + i)) >= '0' && (*(arr + i)) <= '9') //numbers 
        {
            num++;
        }
        i++;
    }
    return num;
}

int countLetters(const char *arr){
    int i = 0;
    int letter =0;
    while(*(arr + i) != '\0')
    {
        if((*(arr + i)) >= 'A' && (*(arr + i)) <= 'Z') //upper only
        {
            letter++;
        }
        i++;
    }
    return letter;
}

void split(char *&sentence, char *&letters, char *&numbers)
{
    //the question didnt specify whther these arrays were allocated properly 
    //to play it safe, i reallocate them - as their size isnt known at compile time, it needs to be dynamic 
    letters = new char[countLetters(sentence)]; //allocate memory for letters
    numbers = new char[countNumbers(sentence)];

    int letSize = 0, numSize = 0; //used for incrementing arrays at right point 

    int i =0; //used for traversing the array
    while(*(sentence +i) != '\0'){
        if((*(sentence + i)) >= 'A' && (*(sentence + i)) <= 'Z') //upper only
        {
            *(letters + letSize) = *(sentence + i);
            letSize++;
        }
        else if((*(sentence + i)) >= '0' && (*(sentence + i)) <= '9') //numbers 
        {
            // int number = *(sentence + i) - '0'; //either do the conversion properly or can make the number array a char one rather than int
            *(numbers + numSize) = *(sentence + i);
            //convert char to int 
            numSize++;
        }
        ++i; 
    }

    *(letters + letSize) = '\0'; //null terminate the array
    *(numbers + numSize) = '\0'; 
    
    delete [] letters;
    delete [] numbers;
}

int main()
{
    char *sentence = {"78AFqD6,A!"};
    char *letters; 
    char *numbers;
    split(sentence, letters, numbers);
    cout << "Letters: ";
    for(int i = 0; i < countLetters(sentence); i++)
    {
        cout << *(letters + i);
    }
    cout << endl;
    cout << "Numbers: ";
    for(int i = 0; i < countNumbers(sentence); i++)
    {
        cout << *(numbers + i);
    }
    cout << endl;
    //original sentence
    cout << "Sentence: ";
    for(int i = 0; *(sentence + i) != '\0'; i++)
    {
        cout << *(sentence + i);
    }


    return 0; 
}

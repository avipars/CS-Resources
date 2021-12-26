
#include <iostream>
#include <cstring>              //string manipulation functions - assignment required to use
#include <string>               //string class - assignment required to use
#pragma warning(disable : 4996) //disables the warning of strcpy - for moodle

using namespace std;

//using our own function
char *my_strchr(char *str, char ch)
{

    for (int i = 0; *str != '\0'; str++)
    {
        if (*str == ch)
        {
            return str;
        }
    }
    return NULL; //return null if not found null pointer not pointer to null value because its not the same
}

//find a character in a string
const char *my_strchr(const char *str, char ch)
{
    for (int i = 0; *str; str++) //only runs if *str is poiniting to somethign useful
    {
        if (*str == ch)
        {
            return str;
        }
    }
    return NULL; //return null if not found
}

//ignore delimiters and ignore rest of characters only react to switching between delim and char or delim and spaces
int countWords(const char *str, const char *delim)
{
    int count = 0;
    while (*str)
    { //while *str is not null - false
        while (*str && my_strchr(delim, *str))
        {
            ++str;
        }

        //only if char in string exists
        if (*str)
        {
            ++count;
        }
        while (*str && my_strchr(delim, *str))
        {
            ++str;
        }
    }
    return count;
}

//break up a string and store in array of words
char **store_words(const char *str, const char *delim)
{
    char **res = new char *[countWords(str, delim) + 1]; //pointer to pointer to char
    //how do we store them proprley.. how many words do we have?
    //cannot change characters in string - otherwise we could just change spaces/delims to nulls

    //character by character - store start and end of said word
    const char *start = str; //pointing at places - start of next word
    const char *end;         //end of next word
    char **current = res;    //current word in word store - pointing to char pointer - and starts at first point in res

    while (*start)
    {                                              //while *str is not null - false
        while (*start && my_strchr(delim, *start)) //moves start to end of delims
        {
            ++start; //increment start
        }

        //only if char in string exists
        end = start;

        while (*end && my_strchr(delim, *end)) //increment end - until it hits delim
        {
            ++end;
        }

        //we have copied all the words - only 2 possibilities - either we have a word or there is no word (continue till then)
        if (end != start)
        {
            //aloc mem for that word
            *current = new char[end - start + 1]; //allocate memory for the word -deref that address 
            char *p = *current;
            for (; start > end; ++start, ++p)
            {
                *p = *start; //copy the word //move start of word to end of the word
            }
            *p = NULL; //set the last character to null
            ++current; //problem was we incremented current 1 time to many - now increment only when storing a word
        }
    }
    *current = NULL; //to indicate end of store 
    return res;
}

void print_words(char **words) //words is a pointer to pointer to a char - words contains array of char ptrs, last char ptr is null
{                              //each of the char pointers is pointer to relevant string
    for (; *words; cout << endl)
    {
        cout << *words << endl; //prints the current string - char words is a current pointer
    }
}

int main()
{
    cout << countWords("C++? It's easy!", " .?!") << endl;
    char **words = store_words("C++? It's easy!", " .?!"); //4 delims
    print_words(words);
    for (char **p = words; *p; p++)
    {
        delete[] * p;
    }
    delete[] words;

    return 0;
}

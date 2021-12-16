#include <iostream>
using namespace std;
//chaims class- avi writing

//contains address and can over-write it (not static array)
void foo(int vec[])
{ //this function takes a pointer to an array and changes the values of the array to be the same as the array
    int * ptr; //pointer to int
    vec = ptr; //copies address from ptr to vec - pointer to int, not static array
    ptr = vec; //assigns vec to ptr
}

int main()
{
    int arr[2][4] = {{1,2,3,4},{5,6,7,8}};
    int*ptr = new int; //whenever we do , we have to do delete - memory leak (logic error)
    *ptr = 5; 
    cout << *ptr << endl;
    cout << **ptr << endl; //type mismatch - using casting, we can make this be a legal expression 
    cout << *(int*) (*ptr)<< endl; //casting integer to pointer and then printing

    int a[] = {1,2,3}; //forcing a memory leak - serious logic error that can cause us to lose points on project
    ptr = a; //assign address of a to ptr - this is legal but might cause seg fault - clogging computers memory without freeing it 
    a = ptr; //const pointer - that address is constant and not the value 

    int ** another = new int*[4]; //creating a 2d array of pointers - dynamic allocation heap - 4 int ptrs and assigns address of llocation to ** - int
    //has address of first one - another[0]
    another = arr; //another memory leak - losing access to dynamic allocation 
    arr = another; //more memory leak - even worse cant change value of arr it self but can change values 

    foo(a); //passing a pointer to a function
    return 0;
}
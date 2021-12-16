#include <iostream>
using namespace std;
//chaims class- avi writing
int main()
{
    int arr[14] = {1,2,3,4,5,10,20,30,40,50,60,70,80,90};
    int *ptr1; 
    int *ptr2;
    for(ptr1=ptr2=arr; ptr1-ptr2 < 10; ptr1+=2) //assigns ptr1 and 2 to beginign to array
    //change 5 elements 
    {
        *ptr1=*ptr2; //then moves ptr 1 two elements forward - as long as difference is less than 10 
    }
    *(ptr2+12)=110; //13th element 80 goes to 110 
    for(int i = 0; i < 14; i++) //prints all elements
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
    return 0; 
}
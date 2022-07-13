#include <iostream>
using namespace std;

#define SIZE 7 // Size of the array
void cyclicalShift(int arr[], int n,int, char k);
void print(int[], int);
//turn everything clockwise - cyclical shift
int main()
{
    int size = 5;
    int arr[SIZE];
    int rotate;
    cout << "Enter " <<  SIZE << " integers: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter rotations: ";
    cin >> rotate;

    char dir = 'L'; //or right
    cout << "Enter direction(L/R): ";
    cin >> dir;

    cyclic(arr, SIZE, rotate, dir);
    print(arr, SIZE);

    return 0;
}

void rcyclic(int arr[], int size)
{
    int start = size - 1, end = 0;
    int d = -1;
    //save last element
    int temp = arr[start];
    for (int i = start; i * d < end * d; i += d)
    /// i*d < end*d only changes the first function
    //start from end to begining so we dont overwrite
    {
        arr[i] = arr[i + d];
    }
    arr[end] = temp;
}

void lcyclic(int arr[], int size)
{
    int start = 0, end = size - 1;
    int d = 1;
    //save last element
    int temp = arr[start];
    for (int i = start; i * d < end * d; i += d)
    //start from begining to end to not overwrite
    {
        arr[i] = arr[i + d];
    }
    arr[end] = temp;
}

//no code repition
void lrcyclic(int arr[], int size, char dir)
{

    int start = (dir == 'R' || 'r' ? size - 1 : 0);
    int end = (dir == 'R' || 'r' ? 0 : size - 1);
    int d = (dir == 'R' || 'r' ? -1 : 1);

    // int end = size - 1;
    // int d = 1;
    //save last element
    int temp = arr[start];
    for (int i = start; i * d < end * d; i += d)
    //start from begining to end to not overwrite
    {
        arr[i] = arr[i + d];
    }
    arr[end] = temp;
}

void cyclic(int arr[], int size, int rotate, char dir)
{
    int bound = rotate % size; //dont do calculation in each iteration
    for (int i = 0; i < bound; ++i) //we can avoid a loop if we use arithmatic properly 
    { //time saver
        lrcyclic(arr, size, dir); //doesnt work with prime numbers if two together
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

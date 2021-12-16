#include <iostream>
#include <ctime> 
using namespace std;

//make triangle - doesnt work with static arrays
//2d array, so it needs a ptr to ptr
int **makeTriangle(int n)
{
    srand((unsigned)time(NULL)); //some compilers need this to seed random number generator

    int **triangle = new int *[n]; //creating a 2d array of pointers 
    //- dynamic allocation heap - 4 int ptrs and assigns address of llocation to ** - int
    for (int i = 0; i < n; i++)
    {
        *(triangle+i) = new int[i+1]; //creating a 1d array of ints

        // triangle[i] = new int[i + 1]; same answer

        for (int j = 0; j <= i ; j++)
        {
            *(*(triangle+i)+j) = rand() % 900 + 100; //assigning random number to each element - 3 digit number
            // triangle[i][j] = j + 1;
        }
    }
    return triangle;
}

//address of array of pointers, each of those is an address of array of ints
void printTriangle(int **triangle, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++) //same as j < i +1
        {
            // cout << triangle[i][j] << " ";
            //3 digit numbers - only problem would be when it gets wider than screen
            cout << *(*(triangle + i) + j) << " "; 
            //dereferences - then dereferences again - *(triangle + i) is the address of the array of ints
        }
        cout << endl;
    }
}

int main()
{
    int **tri;
    int n;

    cout << "Enter the size of the triangle: ";
    cin >> n;

    tri = makeTriangle(n); //gets address - mem alloc
    printTriangle(tri, n);

    //address exists in main program - so it can be used in other functions - so it can be passed as a parameter
    // only scope-dependent are static variables
    //freeing all inner arrays 
    for (int i = 0; i < n; i++)
    {
        delete [] *(tri + i); //deletes the array of ints
    }
    delete [] tri; //deletes the array of pointers

    return 0;
}
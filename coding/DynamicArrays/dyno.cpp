#include <iostream>
using namespace std;
// the following is an example demonstrating the 9 we saw in class
// for changing the size of a dynamic array 
// written by meir komar - last update 8 tevet 5781

int main()
{
	int size, newsize;
	cin >> size;
	int* arr = new int[size];			// step 1
	for (int i = 0; i < size; i++)
		arr[i] = rand();				// step 2
	newsize = size + 1;					// step 3
	int* help = new int[newsize];       // step 4
	
	for (int i = 0; i < size; i++)
		help[i] = arr[i];				// step 5
	help[newsize - 1] = rand();         // for example we added a new number to the array

	delete[] arr;						// step 6
	arr = help;							// step 7
	size = newsize;						// step 8
	
	
	delete[] arr;						// step 9

	return 0;
}
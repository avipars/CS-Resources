/*
    Q1BinarySearch.cpp
    This file takes in an array and a user value, then returns the index in the array where the item is through a binary search
 */
#include <iostream>
using namespace std;

#define ARR_SIZE 10 //change the size of the array once, and it will propogate throughout the program

//function declarations 
bool isAscending(const int arr[], int size = ARR_SIZE);
void printArray(const int arr[], int size = ARR_SIZE);
void userInput(int arr[], int size = ARR_SIZE);
int binarySearch(const int arr[], int size = ARR_SIZE, int userNum = 1);

int main()
{
    int arr[ARR_SIZE]; //user array with 10 values

    cout << "Enter " << ARR_SIZE << " numbers: " << endl; //10 numbers

    bool runLoop = true; //start condition flag for while loop

    while (runLoop)
    {
        userInput(arr, ARR_SIZE); //collect user input

        if (isAscending(arr, ARR_SIZE)) //if input is valid, exit loop
        {
            runLoop = false;
        }
        else //otherwise: input is not in ascending order, continue the loop
        {
            cout << "ERROR " << endl;
            runLoop = true;
        }
    }

    int userNum = 1; //re-using variables for user input

    cout << "Enter " << userNum << " number: " << endl;

    cin >> userNum; //collect user input

    int index = binarySearch(arr, ARR_SIZE, userNum); //calls binary search and returns the index of the user input in the array

    if (index == -1) //-1 means that the input wasn't found
    {
        cout << "Not found " << endl;
    }
    else //congrats! we found the user input 
    {
        cout << "The number " << userNum << " was found at index " << index << endl;
    }

    return 0;
}

//simple for loop to collect user input for arrays
void userInput(int arr[], int size) 
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

//we don't want to modify the array, so we set as constant
bool isAscending(const int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        //if the next element is smaller than current number, we can already quit the for loop 
        //sample: if next element is 11 and current is 22: 11<22 is false
        if (arr[i + 1] < arr[i]) 
        {
            return false;
        }
    }

    return true; //otherwise, the array is valid (ie: in ascending order)
}

int binarySearch(const int arr[], int size, int userNum)
{
    //initialize left(low) and right(high) indexes
    int low = 0; 
    int high = size - 1;

    //make sure there is no overlap
    while (low <= high)
    {
        //we cut the array into half - in this case our array size is 10, so it splits perfectly
        int mid = (low + high) / 2;

        // item is in the middle slot
        if (arr[mid] == userNum)
        {
            return mid; //we succeeded and now we return the index of the slot 
        }

        //search high half if middle slot is bigger than userNum, otherwise, we search the lower half 
        (arr[mid] < userNum) ? low = mid + 1 : high = mid - 1;

        //then we go back to the while loop, check again if there's no overlap and split the middle again
    }

    return -1; //not found
}

/*
sample run:
Enter 10 numbers:
1 2 3 4 5 6 7 8 9 10
Enter 1 number:
-5
Not found

Enter 10 numbers:
2 5 6 3 4 5 9
52 2
3
ERROR:
Enter 10 numbers:
200 202 301 302 400 401 403 404 418 500
Enter 1 number: 
418
The number 418 was found at index 8 
 */

// quicksort algo - recursive and lets you chose pivot location

#include <iostream>
using namespace std;

void print(int arr[], int size);

void quickSort(int arr[], int start, int size);

// partition
int partition(int arr[], int low, int high);

int main()
{
  int arr[] = {2, 7, 4, 3, 1, 5, 6, 8};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array: " << endl;
  print(arr, size);

  quickSort(arr, 0, size - 1);
  cout << "Sorted array: " << endl;
  print(arr, size);

  return 0;
}

void print(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl;
}

void quickSort(int arr[], int start, int end)
{

  // base case
  if (start >= end)
  {
    return;
  }

  // partitioning the array
  int p = partition(arr, start, end);
  cout << "part:" << p + 1 << "|";
  print(arr, 8);
  quickSort(arr, p + 1, end);
  quickSort(arr, start, p - 1);

}

int partition(int arr[], int start, int end)
{
  int x = arr[end];  // end is the pivot
  int i = start - 1; // start is the index of the first element
  for (int j = start; j < end; j++)
  {
    if (arr[j] <= x)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[end]);
  return i + 1;
}

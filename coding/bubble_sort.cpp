#include <iostream>
#include <ctime>

#define SIZE 7
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//if we are in specific location, we can not swap
void swap(int arr[SIZE][SIZE], int r1, int c1, int r2, int c2)
{
    int quad_Size = SIZE / 2;
    int r1_quad = r1 / quad_Size;
    int r2_quad = r2 / quad_Size;
    int c1_quad = c1 / quad_Size;
    int c2_quad = c2 / quad_Size;

    if (r1_quad != r2_quad || c1_quad != c2_quad)
    {
        return; // we can not swap
    }
    int temp = arr[r1][c1];
    arr[r1][c1] = arr[r2][c2];
    arr[r2][c2] = temp;
}

//or swap to sort by column
//check quadarant and then go on
int get_row(int j)
{
    int quad_Size = SIZE / 2;
    int quadrant = j / 4;   //0,1,2,3
    int num_inquad = j % 4; //0,1,2,3 number inside quadarant
    int row_inquad = num_inquad / quad_Size;
    // int col_inquad = num_inquad % quad_Size;
    int quad_row = quadrant / 2;
    return quad_row * quad_Size + row_inquad;
    ;
}

//but how to sort by quadrants?
int get_col(int j)
{
    int quad_Size = SIZE / 2;
    int quadrant = j / 4;   //0,1,2,3
    int num_inquad = j % 4; //0,1,2,3 number inside quadarant
    int row_inquad = num_inquad % quad_Size;
    // int col_inquad = num_inquad % quad_Size;
    int quad_row = quadrant % 2;
    return quad_row * quad_Size + row_inquad;
    ;
}

bool cmp(int i, int j)
{
    //  if(i% 2 && j % 2 ==0){ //first even then odd
    //      return true;
    //  }
    return i > j;
}

int get_i(int j)
{
    // return (j*2)%SIZE; //returns the index - only works if size is a prime number
    return j;
}

void bubble_sort(int arr[SIZE][SIZE])
{
    bool swapped;
    int n = SIZE * SIZE;
    int i = n;
    do
    {
        swapped = false;
        for (int j = 0; j < i - 1; j++)
        {
            if (cmp(arr[get_row(j)][get_col(j)] ,  arr[get_row(j+1)][get_col(j+1)]))
                {
                    swap(arr[get_row(j)][get_col(j)], arr[get_row(j + 1)][get_col(j + 1)]);
                    swapped = true;
                }
        }
        i--;
    } while (swapped);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void print(int arr[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        print(arr[i], SIZE);
    // cout << arr[i] << " ";
    cout << endl;
}
//sort bubble in squares (2 dimensional array)
//not so efficient
int main()
{
    int arr[SIZE][SIZE]{{1, 16, 2, 3}, {5, 13, 5, 1}, {2, 40, 17, 2}, {1, 70, 1, 6}};

    bubble_sort(arr);
    print(arr);
    // srand(time(nullptr));

    return 0;
}

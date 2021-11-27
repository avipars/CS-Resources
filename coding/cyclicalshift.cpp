#include <iostream>
using namespace std;

#define SIZE 5
bool is_latin(int[SIZE][SIZE]); //first one doesnt matter

//latin square 100 ints
int main()
{
    int mat[SIZE][SIZE];

    cout << "Enter numbers:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> mat[i][j];
        }
    }

    if (is_latin(mat))
    {
        cout << "is latin" << endl;
    }
    else
    {
        cout << "is not latin" << endl;
    }

    return 0;
}

bool is_latin(int mat[SIZE][SIZE])
{
    bool res = true;
    for (int i = 0; i < SIZE && res; ++i)
    {
        for (int num = 1; num <= SIZE && res; ++num)
        {
            bool testx = false, testy = false;
            for (int j = 0; j < SIZE; ++j)
            {
                if (mat[i][j] == num)
                {
                    testx = true;
                }
                if (mat[j][i] == num)
                {
                    testy = true;
                }
            }
            if (!testx || !testy)
            {
                res = false;
            }
        }
        return res;
    }

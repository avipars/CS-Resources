#include <iostream>

using namespace std;
// Question 14 (16 points) 5778 moed a
// An instructor uses 3 arrays to store data about students in a course. The first array stores student ids, the second array stores homework averages, and the third array stores exam averages.

// The final course grade for a student is computed as 80% of his exam average plus 20% of his homework average.

// The arrays are maintained in such a way that the index in the three arrays describes a single student. For example, if index 2 of the first array contains the id of some student Moshe, then index 2 in the second array contains Moshe’s homework average, and index 2 in the third array contains Moshe’s exam average.

//helper function to calculate average based on hw and exam 
double findAvg(double *hw, double *exam, int pos)
{
    double hwg = *(hw + pos), exg = *(exam + pos);
    double avg = (hwg * 0.2 + exg * 0.8);
    return avg;
}

void sortData(int *id, double *hw, double *exam, int sizeID, int sizeHw, int sizeEx)
{
    if (sizeID != sizeHw || sizeHw != sizeEx) //if size is not the same, then it will certainly be a problem as different indexes will be leftover
    {
        cout << "Error: sizes do not match" << endl;
        return;
    }

    double average;
 
    for (int i = 0; i < sizeID; ++i) //increment through array
    {
        average = findAvg(hw, exam, i); //calculate average of current element
        //now swap but keep all three arrays intact
        for (int j = i; j > 0; --j)
        {
            if (average > findAvg(hw, exam, j - 1)) //compare average to previous one 
            {
                double hwG, exGr;  //temporary variables for swap 
                int stID;

                hwG = *(hw + j); 
                exGr = *(exam + j);
                stID = *(id + j);

                *(hw + j) = *(hw + j - 1); 
                *(exam + j) = *(exam + j - 1);
                *(id + j) = *(id + j - 1);

                *(hw + j - 1) = hwG;
                *(exam + j - 1) = exGr;
                *(id + j - 1) = stID;
            }
        }
    }
}

int main()
{
    int id[5] = {90, 78, 56, 34, 12};
    double hw[5] = {85, 70, 80, 40, 90};
    double exam[5] = {60, 80, 87, 90, 50};

    for (int i = 0; i < 5; ++i)
    {
        cout << id[i] << " " << hw[i] << " " << exam[i] << endl;
    }

    cout << "after" << endl;
    sortData(id, hw, exam, 5, 5, 5);
    for (int i = 0; i < 5; ++i)
    {
        cout << id[i] << " " << hw[i] << " " << exam[i] << endl;
    }
    return 0;
}

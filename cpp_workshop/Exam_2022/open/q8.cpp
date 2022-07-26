//q8

#include <algorithm>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

struct Month //struct - public by default
{
    string name;
    bool isHot;
    double degrees;
};

// not included on exam nor required, feel free to ignore
void init(Month **months)
{ 
    // fill the array up with random temp data
    srand(time(NULL)); // random seed
    for (int i = 0; i < 12; i++)
    {
        months[i] = new Month; // new allocation
        months[i]->name = 'a' + i; //no point in adding each month manually, as this is just a test question, take advantage of the ascii table
        // months[i]->isHot = rand() % 2; //0 or 1 - the lambda will take care of this
        months[i]->degrees = (rand() % 90) - 10; //-10 to 80 degrees
    }
}
// also not included on exam nor required, feel free to ignore
void printMonths(Month **months)
{ 
    for (int i = 0; i < 12; i++)
    {
        cout << months[i]->name << ": ";
        if (months[i]->isHot)
        {
            cout << "hot";
        }
        else
        {
            cout << "cold";
        }
        cout << " " << months[i]->degrees << endl;

        if (months[i] != nullptr)
        {
            delete months[i];    // free memory
            months[i] = nullptr; // set to null
        }
    }
}

int main()
{
    Month *months[12];
    init(months);
    int countHotMonths = 0;

    // capture list, either & for all by ref, or &var for tat specific variable by ref
    // no iterators, just use common sense
    // void is optional but know that the lamdba doesn't return anything
    
    for_each(months, months + 12, [&countHotMonths](Month *month) -> void { // filled in by student
        if (month->degrees > 30)
        {                        // if > 30 degrees
            countHotMonths++;    // increment count
            month->isHot = true; // UPDATE field
        }
        else
        {
            month->isHot = false; //otherwise set as not hot 
        }
    });


    //int hot = count_if(months, months + 12, [](Month *month) { return month->isHot; }); //if month is hot, return true, else false

    cout << "number of hot months: " << countHotMonths << endl;

    printMonths(months);
    return 0;
}
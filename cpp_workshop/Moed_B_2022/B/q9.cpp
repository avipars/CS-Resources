#include <algorithm>
#include <iostream>
using namespace std;
enum SEASON
{
    WINTER = 1,
    SPRING,
    SUMMER,
    FALL
};
class Month
{
    int days = 30;
    SEASON type = (SEASON)SUMMER;

public:
    class dayException
    {
    };
    class seasonException
    {
    };
    Month(int myday, int mytype)
    {
        if ((myday < 28) || (myday > 31))
            throw dayException();
        if ((mytype < 1) || (mytype > 4))
            throw seasonException();
        days = myday;
        type = (SEASON)mytype;
    };
};
void initMonth(Month **months)
{
    for_each(months, months + 12, [](Month *month){
        int day, type;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter season: ";
        cin >> type;
        // cin >> day >> type;
        month = new Month(day, type);
     });
    cout << " ok \n";
    cout << months[0]->days << endl; // הערך של months[0]->days לא יהיה מאותחל 

}

int main()
{

    try
    {
        Month **months = new Month *[12];
        initMonth(months);
    }
    catch (Month)
    {
        cout << "exception in month \n";
    }
    catch (Month::seasonException)
    {
        cout << " exception in season \n";
    }
    catch (Month::dayException)
    {
        cout << "exception in day \n";
    }
    catch (...)
    {
        cout << "you have a problem \n";
        cout << " we finish \n";
    }
    return 0;
}
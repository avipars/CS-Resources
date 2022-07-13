#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//5778 moed bet bus

struct Bus
{
    int lineNum;
    char driverName[25];
    int stops;
};

//takes in old array, and empty new array then dynamically makes a new array and copies values over, then returns the full array
//we get in new array, so we can delete it in the main function at the end
void resizeArray(Bus *&arr, int oldSize, int newSize)
{
    Bus *oldDB = arr;       //save the old array in a new variable
    arr = new Bus[newSize]; //create a new array with the new size

    //copy the old array to the new array - leaving an empty slot at the end
    for (int i = 0; i < oldSize; ++i)
    {
        *(arr + i) = *(oldDB + i);
    }

    if (oldDB != NULL)
    {
        delete[] oldDB; //free the space from the old array
        oldDB = NULL;   //set the pointer to NULL (for moodle compiler - as it doesn't always work with nullptr)
    }
}

int search(Bus *bus, int size, int lineNum, char *driverName)
{
    for (int i = 0; i < size; i++)
    {
        if (bus[i].lineNum == lineNum && strcmp(bus[i].driverName, driverName) == 0)
        {
            return i; //position
        }
    }
    return -1; //not found
}

bool deleteLine(Bus *&bus, int &size, int lineNum, char *driverName)
{
    int index = search(bus, size, lineNum, driverName); //index of the bus to be deleted
    if (index == -1)
    {
        return false; //doesnt exist
    }


    //shift all the buses after the deleted bus to the left
    for (int i = index; i < size - 1; i++) //moves other bus lines down
    {
        bus[i] = bus[i + 1];
    }

    

    //shrink the array by 1
    resizeArray(bus, size, size - 1);
    size--;

    return true; //deleted and send back the info to main
}

void print(Bus *bus, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Line Number: " << bus[i].lineNum << endl;
        cout << "Driver Name: " << bus[i].driverName << endl;
        cout << "Number of Stops: " << bus[i].stops << endl;
        cout << endl;
    }
}

int main()
{
    int size = 2;
    Bus *bus = new Bus[size];
    bus[0].lineNum = 1;
    strcpy(bus[0].driverName, "John");
    bus[0].stops = 5;

    bus[1].lineNum = 2;
    strcpy(bus[1].driverName, "Mary");
    bus[1].stops = 3;

    cout << "printing" << endl;
    print(bus, size);

    cout << "searching" << endl;

    cout << search(bus, size, 1, "John") << endl;
    cout << search(bus, size, 2, "Mary") << endl;

    cout << "deleting" << endl;
    cout << deleteLine(bus, size, 1, "John") << endl;
    cout << "printing" << endl;
    print(bus, size);
    cout << deleteLine(bus, size, 2, "Mary") << endl;
    cout << "printing" << endl;
    print(bus, size);
    cout << deleteLine(bus, size, 1, "John") << endl;

    return 0;
}

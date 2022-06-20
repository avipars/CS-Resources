#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

void printList(list<int> lst)
{
    cout << "printLAM" << endl;
    for_each(lst.begin(), lst.end(), [](int i)
             { cout << i << " "; }); // lambda function
    cout << endl;

    cout << "printReg" << endl;
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{
    // add items to list, print it then sort and reprint

    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(6);
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(7);

    printList(lst);
    lst.sort();
    printList(lst);

    return 0;
}
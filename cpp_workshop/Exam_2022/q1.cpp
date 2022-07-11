//q1
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        inst++;
        cout << "animCtr " << inst << endl;
    };
    Animal(int x) { inst + x; 
        cout << "animCtr2 " << inst << endl;
    };
    static int inst;
};

class Dog : public Animal
{
public:
    Dog(){
        cout << "dogCtr " << inst << endl;
    };
    Dog(bool isGuide) : m_isGuide(isGuide)
    {
        Animal a;
                cout << "a  " << inst << endl;

        m_myFriend = a;
        cout << "fr " << inst << endl;
        cout << "dogCtr2  " << inst << endl;

    }   

private:
    bool m_isGuide;
    Animal m_myFriend;
    
};

int Animal::inst = 0;

int maiddodon()
{
    Animal a1;
    Dog d1;
    Dog d2(true);
    cout << a1.inst;
}

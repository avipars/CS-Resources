#define _CRT_SECURE_NO_DEPRECATE // strings
#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;

#define SCREENX 80
#define SCREENY 25
#define MINHP 15
#define MAXHP 1500

class Monster
{ // object is monster
private:
    int x;
    int y;
    int HP;        // health
    char name[25]; // string 24 spaces

    // good oop requires all fields to be private
    // only public fns have access to these variables

    // methods - either external or private if only used in this class
public:
    void create() // similar to a constructor
    {
        // create monster
        x = rand() % SCREENX;
        y = rand() % SCREENY;
        HP = rand() % (MAXHP - MINHP) + MINHP;
        strcpy(name, "Unnamed");
    }
    void draw() const // fn draw doesnt change any of the fields
    {
        cout << name << ": (" << x << "," << y << ") HP: " << HP << endl;
    }
    void moveto(int _x, int _y) // changes values of fields
    {
        x = _x; // fields within class
        y = _y;
    }
    bool is_alive() const // returns true if HP > 0
    {
        return HP > 0;
    }
}; // need semicolon to end - similar to structs

int main()
{
    // dragon is object of class Monster
    Monster dragon; // access fields, run methods (not just the pointer/structs)
    // before we create it , it has garbage values in those fields

    srand((unsigned)time(NULL)); // set random seed
    dragon.create();
    dragon.draw();
    dragon.moveto(10, 25);
    dragon.draw();

    return 0;
}
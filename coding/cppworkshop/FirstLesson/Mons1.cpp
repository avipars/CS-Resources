#define _CRT_SECURE_NO_DEPRECATE // strings
#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;

#define SCREENX 80
#define SCREENY 25
#define MINHP 15
#define MAXHP 1500

class Monster1
{ // object is Monster1
private:
    int x;
    int y;
    int HP;        // health
    char name[25]; // string 24 spaces

    // good oop requires all fields to be private
    // only public fns have access to these variables

    // methods - either external or private if only used in this class
public:
    Monster1();
    Monster1(const char *); // constructor

    void create(); // similar to a constructor

    void draw() const; // fn draw doesnt change any of the fields

    void moveto(int _x, int _y); // changes values of fields

    bool is_alive() const; // returns true if HP > 0

    int GetX() const;
    int GetY() const; // basic getters

    void set_name(const char *_name); // basic setters
    char *get_name() const;

}; // need semicolon to end - similar to structs

Monster1::Monster1() // default constructor - to delete the original one and avoids compiler error
{
    create(); // overrides the default one
}

Monster1::Monster1(const char *_name) // with paramaters
{
    create();
    set_name(_name);
}

int Monster1::GetX() const
{
    return x;
}

// gety
int Monster1::GetY() const
{
    return y;
}

// setter for name field
void Monster1::set_name(const char *_name)
{
    if (strlen(_name) > 24) // cover for safety issue strcpy has to avoid overflow
    {
        return;
    }

    strcpy(name, _name);
}

char *Monster1::get_name() const
{
    char *res = new char[strlen(name) + 1]; //+1 for null terminator - need to free the dynamic allocation
    strcpy(res, name);                      // use with care, dont add if we dont need as it makes the program harder to follow
    return res;
}

// getter for name field
void Monster1::draw() const // fn draw doesnt change any of the fields
{
    cout << name << ": (" << x << "," << y << ") HP: " << HP << endl;
}

void Monster1::moveto(int _x, int _y) // changes values of fields
{
    x = _x; // fields within class
    y = _y;
}

bool Monster1::is_alive() const // returns true if HP > 0
{
    return HP > 0;
}

void Monster1::create() // similar to a constructor
{
    // create Monster1
    x = rand() % SCREENX;
    y = rand() % SCREENY;
    HP = rand() % (MAXHP - MINHP) + MINHP;
    strcpy(name, "Unnamed");
}

int main()
{
    // dragon is object of class Monster1
    Monster1 dragon; // access fields, run methods (not just the pointer/structs)
    // before we create it , it has garbage values in those fields

    srand((unsigned)time(NULL)); // set random seed
    dragon.create();
    dragon.draw();
    dragon.set_name("Puff");
    dragon.moveto(10, 25);
    dragon.draw();

    Monster1 baddy("Wolf"); //functional way to call constr - simplest way
    baddy.draw();
    //constructor with 1 arg can also use assingment way

    Monster1 wolf = "Babby"; //only works with 1 arg
    wolf.draw();

    //uniform way to call constructor  hard to confuse it 
    Monster1 wow = { "Puffy" };
    wow.draw();
    //podlike way to call constructor
    Monster1 *puffy = new Monster1("Puffy");

    //pod like way to call constructor
    Monster1 *puffy2 = new Monster1;
    return 0;
}
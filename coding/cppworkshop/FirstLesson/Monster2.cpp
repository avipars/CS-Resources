#include "Monster2.h" // header file

Monster2::Monster2() // default constructor - to delete the original one and avoids compiler error
{
    create(); // overrides the default one
}

Monster2::Monster2(const char *_name) // with paramaters
{
    create();
    set_name(_name);
}

int Monster2::GetX() const
{
    return x;
}

// gety
int Monster2::GetY() const
{
    return y;
}

// setter for name field
void Monster2::set_name(const char *_name)
{
    if (strlen(_name) > 24) // cover for safety issue strcpy has to avoid overflow
    {
        return;
    }

    strcpy(name, _name);
}

char *Monster2::get_name() const
{
    char *res = new char[strlen(name) + 1]; //+1 for null terminator - need to free the dynamic allocation
    strcpy(res, name);                      // use with care, dont add if we dont need as it makes the program harder to follow
    return res;
}

// getter for name field
void Monster2::draw() const // fn draw doesnt change any of the fields
{
    cout << name << ": (" << x << "," << y << ") HP: " << HP << endl;
}

void Monster2::moveto(int _x, int _y) // changes values of fields
{
    x = _x; // fields within class
    y = _y;
}

bool Monster2::is_alive() const // returns true if HP > 0
{
    return HP > 0;
}

void Monster2::create() // similar to a constructor
{
    // create Monster1
    x = rand() % SCREENX;
    y = rand() % SCREENY;
    HP = rand() % (MAXHP - MINHP) + MINHP;
    strcpy(name, "Unnamed");
}

int main()
{
    return 0;
}

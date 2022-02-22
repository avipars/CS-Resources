#ifndef MONSTER_H //if its not defined yet 
#define MONSTER_H //then define it 

#define _CRT_SECURE_NO_DEPRECATE // strings
#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;

#define SCREENX 80
#define SCREENY 25
#define MINHP 15
#define MAXHP 1500

class Monster2
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
    Monster2();
    Monster2(const char *); // constructor

    void create(); // similar to a constructor

    void draw() const; // fn draw doesnt change any of the fields

    void moveto(int _x, int _y); // changes values of fields

    bool is_alive() const; // returns true if HP > 0

    int GetX() const;
    int GetY() const; // basic getters

    void set_name(const char *_name); // basic setters
    char *get_name() const;

}; // need semicolon to end - similar to structs

// only define if not already defined - creitical part 
#endif 
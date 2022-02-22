#ifndef GAME_H
#define GAME_H

#define _CRT_SECURE_NO_DEPRECATE // strings
#include <iostream>
#include "Player.h"
#include "Monster2.h"

using namespace std;

class Game
{
private:
    Player me;
    Monster2 them[15];

public:
    void start();
    void display(); //if we display game, do we play it 
};

#endif
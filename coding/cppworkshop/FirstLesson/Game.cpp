#include "Game.h"

void Game::start()
{
    me.getMe.Create(); //dependency of dependency - so it works! 
    me.getMe.setName("Player");

    for (int i = 0; i < 5; i++)
    {
        char name[25];
        strcpy (name, "Monster");

        name[8] = i + '1';
        name[9] = NULL; 

        them[i].create();
        them[i].setName(name);
    }
}

void Game::display(){
    me.getMe.draw();
    for (int i = 0; i < 5; i++)
    {
        them[i].draw();
    }
}
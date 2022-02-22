#ifndef PLAYER_H
#define PLAYER_H

#include "Monster2.h"

class Player
{
    Monster2 me; 

private:
    /* data */
public:
    Monster2& getMe(); //now we can utilize Monsters class attributes
};


#endif // PLAYER_H
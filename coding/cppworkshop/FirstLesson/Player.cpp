#include "Player.h"

Monster2& Player::getMe()
{
    return me; //we use a reference so we can change the actual details 
}
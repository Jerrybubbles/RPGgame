#include "player.h"
#include <iostream>
#include <string.h>

//Constructor
Player::Player() : Entity{0,0,0}
{

}
//Destructor
Player::~Player()
{
    std::cout << "DECONSTRUCTED!!!!!!!!!!!" << std::endl;
}


void Player::printInfo()
{
    std::cout << "Dit is een player met hitpoints: " << getHitpoints() << " en een damage van " << getMinDamage() << " tot " << getMaxDamage() << "." << std::endl;
}

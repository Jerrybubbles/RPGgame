#include "player.h"
#include <iostream>
#include <string.h>

//Constructor
Player::Player()
{
    hitpoints = 0;
    damage = 0;
}
//Destructor
Player::~Player()
{
    std::cout << "DECONSTRUCTED!!!!!!!!!!!" << std::endl;
}
//Getters and setters
int Player::getHitpoints()
{
    return this->hitpoints;
}
void Player::setHitpoints(int newHitpoints)
{
    this->hitpoints = newHitpoints;
}
int Player::getDamage()
{
    return this->damage;
}
void Player::setDamage(int newDamage)
{
    this->damage = newDamage;
}
//Functions
void Player::hit(int hit)
{
    this->hitpoints -= hit;
}
void Player::heal()
{
    this->hitpoints += 10;
}

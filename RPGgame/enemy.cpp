#include "enemy.h"
#include <string>



//Constructor
Enemy::Enemy()
{

}
//Destructor
//dynamic memory removing (delete)
Enemy::~Enemy()
{

}
//everything in one or more self-made namespace(s)
Enemy::Enemy(std :: string name, int hitpoints, int damage)
{
    //useful useage of "this" (if the code does not work without it)
    this->name = name;
    this->hitpoints = hitpoints;
    this->damage = damage;
}
//Getters and setters
std::string Enemy::getName()
{
    return this->name;
}
void Enemy::setName(std::string newName)
{
    this->name = newName;
}
int Enemy::getHitpoints()
{
    return this->hitpoints;
}
void Enemy::setHitpoints(int newHitpoints)
{
    this->hitpoints = newHitpoints;
}
int Enemy::getDamage()
{
    return this->damage;
}
void Enemy::setDamage(int newDamage)
{
    this->damage = newDamage;
}
//Functions
//useful member function
void Enemy::hit(int hit)
{
    this->hitpoints -= hit;
}

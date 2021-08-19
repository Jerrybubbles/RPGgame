#include "enemy.h"
#include <string>
#include <iostream>

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
Enemy::Enemy(std :: string name, int hitpoints, int mindamage, int maxdamage) : Entity{hitpoints, mindamage, maxdamage}, name{name}
{

}
//Getters and setters
std::string Enemy::getName() const
{
    return this->name;
}
void Enemy::setName(std::string newName)
{
    this->name = newName;
}

void Enemy::printInfo()
{
    std::cout << "Dit is een schurk met naam " << getName() << " en een HP van " << getHitpoints() << " , de damage moet je zelf uitzoeken in de game!" << std::endl;
}

bool Enemy::operator==(const Enemy &other) const
{
    return this->getName() == other.getName();
}

bool Enemy::operator<(const Enemy &other) const
{
    return this->getHitpoints() < other.getHitpoints();
}

bool Enemy::operator>(const Enemy &other) const
{
    return this->getHitpoints() > other.getHitpoints();
}

bool Enemy::operator>=(const Enemy &other) const
{
    return this->getHitpoints() >= other.getHitpoints();
}

bool Enemy::operator<=(const Enemy &other) const
{
    return this->getHitpoints() <= other.getHitpoints();
}



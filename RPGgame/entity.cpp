#include "entity.h"

Entity::Entity()
{

}

Entity::Entity(int hp, int minDamage, int maxDamage) : hitpoints{hp}, minDamage{minDamage}, maxDamage{maxDamage}
{

}

Entity::~Entity(){

}


void Entity::setHitpoints(int hitpoints)
{
    this->hitpoints = hitpoints;
}


void Entity::setMinDamage(int minDamage)
{
    this->minDamage = minDamage;
}

void Entity::setMaxDamage(int maxDamage)
{
    this->maxDamage = maxDamage;
}

void Entity::hit(int hit)
{
    this->hitpoints -= hit;
}

void Entity::heal(int healPoints)
{
    this->hitpoints += healPoints;
}


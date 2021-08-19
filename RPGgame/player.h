#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

class Player : public Entity
{
public:
    //Constructor
    Player();
    //Destructor
    ~Player();
    //member initialization in constructors (the stuff behind a colon)
    Player(int ahitpoints, int mindamage, int maxdamage) : Entity{ahitpoints, mindamage, maxdamage} {}
    void printInfo();
};

#endif // PLAYER_H

#ifndef BATTLE_H
#define BATTLE_H
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <string.h>
using namespace std;

class Battle
{
public:
    Battle();

    void Battletime();


private:
    int action;
};

#endif // BATTLE_H

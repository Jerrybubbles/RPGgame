#ifndef GAME_H
#define GAME_H
#include "battle.h"
#include <iostream>
#include <string.h>
using namespace std;

class Game
{
public:
    Game();
    void Start();

private:
    int choice;
};

#endif // GAME_H

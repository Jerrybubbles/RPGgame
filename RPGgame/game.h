#ifndef GAME_H
#define GAME_H
#include "battle.h"
#include <iostream>
#include <string.h>

using namespace std;

class Game
{
public:
    Game(string path);
    void Start();
    void maakMonster(string fileNaam);
    void printMonsters(string fileNaam);
    string getPath() {return path;};
private:
    string path;
};

#endif // GAME_H

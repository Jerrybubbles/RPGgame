#ifndef BATTLE_H
#define BATTLE_H
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Battle
{
public:
    Battle(string path);
    ~Battle();
    void Battletime();
    void loadMonsters();
    void sortMonsters();
    string getPath() {return path;};
private:
    string path;
    int action;
    vector <Enemy*> monsterlijst;
    Player player1{30,5,8};
};

#endif // BATTLE_H

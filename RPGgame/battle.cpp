#include "battle.h"
#include <vector>
#include <experimental/random>
#include <stdlib.h>
#include <time.h>

Battle::Battle()
{

}

void Battle::Battletime()
{
    //dynamic memory allocation (new)
    Player player1{30,5};
    Enemy* enemy1ptr = new Enemy("slang",50,5);
    Enemy* enemy2ptr = new Enemy("rat",30,1);
    Enemy* enemy3ptr = new Enemy("fairy",10,-5);
    Enemy enemy4{"hobo",15,8};
    Enemy* enemy4ptr = &enemy4;
    Enemy enemy5{"draak",80,11};
    Enemy* enemy5ptr = &enemy5;
    Enemy enemy;
    //useful container class
    std::vector <Enemy*> enemylijst;
    enemylijst.push_back(enemy1ptr);
    enemylijst.push_back(enemy2ptr);
    enemylijst.push_back(enemy3ptr);
    enemylijst.push_back(enemy4ptr);
    enemylijst.push_back(enemy5ptr);
    srand (time(NULL));
    for(int i = 1; i <= 3; i++)
    {

    int random_number = rand() % 4;
        switch (i)
        {
        case 1 : case 2:
            enemy = *enemylijst[random_number];
            cout << "Een " << enemy.getName() << " springt voor je, deze heeft " << enemy.getHitpoints() << " levenspunten." << endl;
            while(enemy.getHitpoints() > 0 && player1.getHitpoints() > 0)
            {
                cout << "Jij hebt " << player1.getHitpoints() << " levenspunten. De vijand heeft er " << enemy.getHitpoints() << "." << endl;
                cin >> action;
                if (action == 1)
                {
                    cout << "aanval" << endl;
                    enemy.hit(player1.getDamage());
                }
                else
                {
                    cout << "genees";
                    player1.heal();
                }
                    player1.hit(enemy.getDamage());

            }
            if (enemy.getHitpoints() <= 0)
            {
                cout << "Je hebt gewonnen, hier komt de volgende vijand!" << endl << endl;
            } else
            {
              cout << "Je bent dood!" << endl;
              i = 3;
            }

            break;

        case 3:
            enemy = *enemylijst[4];
            cout << "Een " << enemy.getName() << " springt voor je, deze heeft " << enemy.getHitpoints() << " levenspunten." << endl;
            while(enemy.getHitpoints() > 0 && player1.getHitpoints() > 0)
            {
                cout << "Jij hebt " << player1.getHitpoints() << " levenspunten. De vijand heeft er " << enemy.getHitpoints() << "." << endl;
                cin >> action;
                if (action == 1)
                {
                    cout << "aanval" << endl;
                    enemy.hit(player1.getDamage());
                }
                else
                {
                    cout << "genees";
                    player1.heal();
                }
                    player1.hit(enemy.getDamage());

            }
            if (enemy.getHitpoints() <= 0)
            {
                cout << "Je hebt gewonnen, de draak is verslagen!" << endl << endl;
            } else
            {
              cout << "Je bent dood!" << endl;
              i = 3;
            }
        }


    }
     cout << "einde!" << endl;

}

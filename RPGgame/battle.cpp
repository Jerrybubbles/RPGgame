#include "battle.h"
#include "enemy.h"
#include <vector>
#include <experimental/random>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>

void menu(){
    cout << "a) attack\nb) heal\nUw keuze:" << endl;
}

Battle::Battle(string path): path{path}
{
    loadMonsters();
}

Battle::~Battle()
{
    for (unsigned long i = 0; i < monsterlijst.size(); i++)
    {
        delete monsterlijst[i];
        monsterlijst[i] = nullptr;
    }
    monsterlijst.clear();
    std::cout << "each monster deconstructed" << std::endl;
}
void Battle::loadMonsters()
{
    string fileNaam = getPath();
    string gelezenRij = " ",kolom,temp;
    fstream fileIn;
    vector<string> rij;
    fileIn.open(fileNaam, ios::in);

    while(gelezenRij != ""){
        rij.clear();

        getline(fileIn, gelezenRij);

        if( fileIn.eof() ){
            break;
        }

        stringstream strstrm(gelezenRij);
        while (getline(strstrm, kolom, ','))
        {
            rij.push_back(kolom);
        }

        string name = rij[0];
        int hp = stoi(rij[1],nullptr,0), mindmg = stoi(rij[2],nullptr,0), maxdmg = stoi(rij[3],nullptr,0);
        Enemy * enemyptr = new Enemy{rij[0], hp, mindmg, maxdmg};

        monsterlijst.push_back(enemyptr);

    }
}

// lambda
void Battle::sortMonsters(){
    sort(monsterlijst.begin(), monsterlijst.end(), [](Enemy * enemy1, Enemy * enemy2)
    {
        return *enemy2 < *enemy1;
    });
}

void Battle::Battletime()
{
    Enemy enemy;

    Entity * newEnemy = new Enemy{"heks", 10,0,0};
    newEnemy->setMaxDamage(5);
    newEnemy ->printInfo();


    //To show the operator overloading
    Enemy testEnemy{"dummy", 50,5,5}, testEnemy2{"dummy",45,5,5}, testEnemy3{"nietDummy", 55,5,5};
    cout << ((testEnemy==testEnemy2)?"true":"false") << ((testEnemy==testEnemy3)?"true":"false") << endl;


    srand (time(NULL));

    unsigned char action;

    for(int i = 1; i <= 3; i++)
    {

    int random_number = (rand() % (monsterlijst.size()-1))+1;
        switch (i)
        {
        case 1: case 2:

            sortMonsters();
            enemy = *monsterlijst[random_number];
            cout << "Een " << enemy.getName() << " springt voor je, deze heeft " << enemy.getHitpoints() << " levenspunten." << endl;
            while(enemy.getHitpoints() > 0 && player1.getHitpoints() > 0)
            {
                cout << "Jij hebt " << player1.getHitpoints() << " levenspunten. De "<< enemy.getName() <<" heeft er " << enemy.getHitpoints() << "." << endl;
                menu();
                cin >> action;
                while (cin.fail() || (action != 'a' && action != 'b')){
                    cin.clear();
                    cin.ignore();
                    cout << "Geef een correcte input!" << endl;
                    cin >> action;
                }
                if (action == 'a')
                {
                    int attackValue;
                    int roll = rand() % 5;
                    if (roll >= 4)
                    {
                        attackValue = rand() % (player1.getMaxDamage() - player1.getMinDamage() +1) +player1.getMinDamage();
                        attackValue *= 2;
                        cout << "Crit Attack! Je valt aan voor " << attackValue << endl;
                    }
                    else
                    {
                        attackValue = rand() % (player1.getMaxDamage() - player1.getMinDamage() +1) +player1.getMinDamage(); //+1 to include the max damage;
                        cout << "Je valt aan voor " << attackValue << endl;
                    }

                    enemy.hit(attackValue);
                }
                else
                {
                    int randomValue;
                    randomValue = rand() % 8 + 6;
                    player1.heal(randomValue);
                    cout << "Je geneest voor " << randomValue << endl;
                }
                int attackValue;
                attackValue = rand() % (enemy.getMaxDamage() - enemy.getMinDamage() +1) +enemy.getMinDamage();
                cout << "De "<< enemy.getName() <<" valt aan voor " << attackValue << endl;
                player1.hit(attackValue);

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

            enemy = *monsterlijst[0];
            cout << "Een " << enemy.getName() << " springt voor je, deze heeft " << enemy.getHitpoints() << " levenspunten." << endl;
            while(enemy.getHitpoints() > 0 && player1.getHitpoints() > 0)
            {
                cout << "Jij hebt " << player1.getHitpoints() << " levenspunten. De " << enemy.getName() <<" heeft er " << enemy.getHitpoints() << "." << endl;
                menu();
                cin >> action;
                if (action == 'a')
                {
                    int attackValue;
                    int roll = rand() % 5;
                    if (roll >= 4)
                    {
                        attackValue = rand() % (player1.getMaxDamage() - player1.getMinDamage() +1) +player1.getMinDamage();
                        attackValue *= 2;
                        cout << "Crit Attack! Je valt aan voor " << attackValue << endl;
                    }
                    else
                    {
                        attackValue = rand() % (player1.getMaxDamage() - player1.getMinDamage() +1) +player1.getMinDamage(); //+1 to include the max damage;
                        cout << "Je valt aan voor " << attackValue << endl;
                    }

                    enemy.hit(attackValue);
                }
                else
                {
                    cout << "genees" << endl;
                    int randomValue;
                    randomValue = rand() % 8 + 3;
                    player1.heal(randomValue);
                }
                int attackValue;
                attackValue = rand() % (enemy.getMaxDamage() - enemy.getMinDamage() +1) +enemy.getMinDamage();
                cout << "De "<< enemy.getName() <<" valt aan voor " << attackValue << endl;
                player1.hit(attackValue);
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

    delete newEnemy;

}



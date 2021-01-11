#ifndef ENEMY_H
#define ENEMY_H
#include <string>

    //correct base class

class Enemy
{
    //useful and correct encapsulation (explain why)
public:
    //Constructor
    Enemy();
    Enemy(std :: string name, int hitpoints, int damage);
    //Destructor
    ~Enemy();
    //Getters and setters
    std::string getName();
    void setName(std::string newName);
    int getHitpoints();
    void setHitpoints(int newHitpoints);
    int getDamage();
    void setDamage(int newDamage);
    //Functions
    void hit(int hit);
private:
    //useful member variabel
   std :: string name;
   int hitpoints;
   int damage;


};

#endif // ENEMY_H

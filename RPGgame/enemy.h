#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "entity.h"


class Enemy : public Entity
{
    //useful and correct encapsulation (explain why)
public:
    //Constructor
    Enemy();
    Enemy(std :: string name, int hitpoints, int mindamage, int maxdamage);
    //Destructor
    ~Enemy();
    //Getters and setters
    std::string getName() const;
    void setName(std::string newName);
    void printInfo();

    bool operator==(const Enemy & other) const;
    bool operator<(const Enemy & other) const;
    bool operator>(const Enemy & other) const;
    bool operator>=(const Enemy & other) const;
    bool operator<=(const Enemy & other) const;

private:
    //useful member variabel
   std :: string name;
};

#endif // ENEMY_H

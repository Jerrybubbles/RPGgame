#ifndef ENTITY_H
#define ENTITY_H

    //correct base class
class Entity
{
public:
    //constructors definitions
    Entity();
    virtual ~Entity() = 0;
    Entity(int hp, int minDamage, int maxDamage);


    //getters and setters
    int getHitpoints() const {return hitpoints;}; //inline function
    void setHitpoints(int newHitpoints);
    int getMinDamage() const {return minDamage;};
    void setMinDamage(int newDamage);
    int getMaxDamage() const {return maxDamage;};
    void setMaxDamage(int newDamage);

    //functions
    virtual void printInfo() = 0;
    void hit(int hit);
    void heal(int healPoints);

private:
    int hitpoints;
    int minDamage;
    int maxDamage;
};

#endif // ENTITY_H

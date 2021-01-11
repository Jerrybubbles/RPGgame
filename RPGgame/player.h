#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    //Construcot
    Player();
    //Destructor
    ~Player();
    //member initialization in constructors (the stuff behind a colon)
    Player(int ahitpoints, int adamage) : hitpoints (ahitpoints) , damage (adamage) {}
    //Getters and setters
    int getHitpoints();
    void setHitpoints(int newHitpoints);
    int getDamage();
    void setDamage(int newDamage);
    //Functions
    void hit(int hit);
    void heal();

private:
    int hitpoints;
    int damage;
};

#endif // PLAYER_H

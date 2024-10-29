#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {

    public:
        Character(int, std::string, const int *); // ID, name, stats(MAX_HP, ATK, DEF, MGA, MGD, SPD)
        void die();
        void printStats();
        void takeDamage(int);
        int getID();
        std::string getName();
        int getHP();
        void setHP(int);
        int getStat(int);
        void setStat(int, int);
        bool isDead();
        void changeStats(int, int, bool); // Stat to change, amount to change, length to change (-1 for infinite)

    protected:
        int ID;
        std::string name;
        int hp;
        int stats[6];
        int temporaryStatChanges[6];
        bool dead;
        int actions[4];


};

#endif
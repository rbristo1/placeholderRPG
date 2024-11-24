#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Weapon.h"
#include <string>


class Player : public Character {
    friend class Game;
    public:
        Player(std::string, int);
        void resetBasicAttack();
        void learnNewMove(int);
        void print();
        
    protected:
        int inventory[8];
        int playerClass; // 0 - Barbarian   1 - Fighter    2 - Archer   3 - Mage

        std::string className;
        Weapon weapon;
        


};
#endif

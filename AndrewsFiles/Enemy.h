#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Character.h"

class Enemy : public Character {
    public:
        Enemy(int);
        int chooseMove();
        
};
#endif
#ifndef GAME_H
#define GAME_H

#include <string>

class Game {

    public:
        Game(int);
        int Battle(Player*, Enemy*);
        int damageCalc(int, int, int);
        void attackPlayer(Enemy*, Player*, bool, int, int);
        void attackEnemy(Player*, Enemy*, bool, int, int);
        void Overworld();
    private:
        
};
#endif
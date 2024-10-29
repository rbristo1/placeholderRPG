#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>


class Player : public Character {
    friend class Game;
    public:
        Player(std::string);
        

    protected:
        int inventory[8];
        


};
#endif

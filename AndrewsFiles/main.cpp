#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Game mainGame(0);
    Enemy slime(0);
    slime.printStats();
    Player player("greg");
    player.printStats();
    mainGame.Battle(&player, &slime);
}
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string playerName) : Character(-1, playerName, nullptr) {
    
    // Set stats
    hp = 20;
    stats[0] = 20; // Set max hp to 20
    for (size_t i = 1; i < sizeof(stats) / sizeof(stats[0]); i++) {
        stats[i] = 10; // Set all other stats to 10
    }

    // Set inventory
    for (size_t i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        inventory[i] = -1;
    }
}
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string playerName, int pclass) : Character(-1, playerName, nullptr) {
    
    // Set stats
    hp = 20;
    stats[0] = 20; // Set max hp to 20
    for (size_t i = 1; i < sizeof(stats) / sizeof(stats[0]); i++) {
        stats[i] = 5; // Set all other stats to 10
    }

    // Set inventory
    for (size_t i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        inventory[i] = -1;
    }

    // Set the player's class
    playerClass = pclass; // 0 - Barbarian  1 - Knight  2 - Archer  3 - Mage

    if (playerClass == 0) {
        className = "Barbarian";
        weapon.reconstruct(0);

        actions[0].reconstruct(0);
        actions[0].setName("Bash");
        actions[0].setPower(weapon.getDamage());
    }

    if (playerClass == 1) {
        className = "Knight";
        weapon.reconstruct(4);
        
        actions[0].reconstruct(0);
        actions[0].setName("Stab");
        actions[0].setPower(weapon.getDamage());
    }

    if (playerClass == 2) {
        className = "Archer";
        weapon.reconstruct(8);

        actions[0].reconstruct(0);
        actions[0].setName("Shoot");
        actions[0].setPower(weapon.getDamage());
    }

    if (playerClass == 3) {
        className = "Mage";
        weapon.reconstruct(12);

        actions[0].reconstruct(0);
        actions[0].setName("Blast");
        actions[0].setPower(weapon.getDamage());
    }



}

void Player::resetBasicAttack(){
    actions[0].setPower(weapon.getDamage());
}

void Player::learnNewMove(int toLearn){
    for (int i = 0; i < sizeof(actions) / sizeof(actions[0]); i++) {
        if (actions[i].getID() == -1) {
            actions[i].reconstruct(toLearn);
            return;
        }
    }
    cout << "You can't learn any more moves!" << endl;
    return;
}

void Player::print() {
    cout << "ID: " << ID << endl << "Name: " << name << endl << "Class: " << className << endl  << endl << "HP: " << hp << "/" << stats[0] << endl << "ATK: " 
         << stats[1] << endl << "DEF: " << stats[2] << endl << "MGA: " << stats[3] << endl << "MGD: " << stats[4] << endl << "SPD: " << stats[5] << endl << endl;
    weapon.print();
    cout << endl;
    actions[0].print();
    actions[1].print();
    actions[2].print();
    actions[3].print();
}
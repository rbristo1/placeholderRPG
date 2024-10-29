#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character(int id, string characterName, const int* statArray){

    ID = id;

    // Set player name
    name = characterName;
    
    // Set stats
    if (statArray != nullptr) {
        hp = statArray[0];
    }
    for (size_t i = 0; i < sizeof(stats) / sizeof(stats[0]); i++) {
        if (statArray != nullptr) {
            stats[i] = statArray[i]; // Set all other stats
        }
        temporaryStatChanges[i] = 0;
    }

    dead = false;
    
}

void Character::die() {
    cout << name << " died!" << endl;
    dead = true;
}

void Character::printStats() {
    cout << "ID: " << ID << "    Name: " << name << "    HP: " << hp << "/" << stats[0] << "    ATK: " << stats[1] << " + " << temporaryStatChanges[1] <<
    "    DEF: " << stats[2] << " + " << temporaryStatChanges[2] << "    MGA: " << stats[3] << " + " << temporaryStatChanges[3] << "    MGD: " << stats[4] <<
    " + " << temporaryStatChanges[4] << "    SPD: " << stats[5] << " + " << temporaryStatChanges[5] << endl;
}


void Character::takeDamage(int amount) {
    hp -= amount;
    if (hp <= 0) {
        die();
    }
}

int Character::getID() {
    return ID;
}

string Character::getName() {
    return name;
}

int Character::getHP() {
    return hp;
}

void Character::setHP(int value) {
    hp = value;
}

int Character::getStat(int id) {
    return stats[id] + temporaryStatChanges[id];
}

void Character::setStat(int id, int value) {
    stats[id] = value;
}

bool Character::isDead() {
    return dead;
}

void Character::changeStats(int stat, int amount, bool permenant) {
    if (permenant) {
        stats[stat] += amount;
    } else {
        temporaryStatChanges[stat] += amount;
    }
}
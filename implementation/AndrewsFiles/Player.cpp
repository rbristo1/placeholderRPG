// TODO List: 211, 224





#include "Player.h"
#include "Character.h"
#include "Weapon.h"
#include "Item.h"
#include <iostream>

using namespace std;

Player::Player(string playerName, int pclass) : Character(-1, playerName, nullptr) {
    
    // Set stats

    hp = 20;
    stats[0] = 20; // Set max hp to 20

    numLearned = 0; // Player has not yet learned any class specific actions yet

    // Set the player's class
    playerClass = pclass; // 0 - Barbarian  1 - Knight  2 - Archer  3 - Mage

    if (playerClass == 0) {
        className = "Barbarian";
        weapon.reconstruct(0); // Sets weapon to Club

        actions[0].reconstruct(0); // Reconstruct the basic attack with new weapon, and change it to be named Bash
        actions[0].setName("Bash");
        actions[0].setPower(weapon.getDamage());

        // Set stats
        stats[1] = 7; // ATK
        stats[2] = 5; // DEF
        stats[3] = 3; // MGA
        stats[4] = 4; // MGD
        stats[5] = 6; // SPD

        // Set action pool
        learnableActions[0] = 1;
        learnableActions[1] = 2;
        learnableActions[2] = 3;
        learnableActions[3] = 4;

        unlearnedActions.push_back(1);
        unlearnedActions.push_back(2);
        unlearnedActions.push_back(3);
        unlearnedActions.push_back(4);
    }

    if (playerClass == 1) {
        className = "Knight";
        weapon.reconstruct(4); // Sets weapon to dagger
        
        actions[0].reconstruct(0); // Reconstruct the basic attack with new weapon, and change it to be named Stab
        actions[0].setName("Stab");
        actions[0].setPower(weapon.getDamage());

        // Set stats
        stats[1] = 5; // ATK
        stats[2] = 7; // DEF
        stats[3] = 4; // MGA
        stats[4] = 6; // MGD
        stats[5] = 3; // SPD

        // Set action pool
        learnableActions[0] = 5;
        learnableActions[1] = 6;
        learnableActions[2] = 7;
        learnableActions[3] = 8;

        unlearnedActions.push_back(5);
        unlearnedActions.push_back(6);
        unlearnedActions.push_back(7);
        unlearnedActions.push_back(8);
    }

    if (playerClass == 2) {
        className = "Archer";
        weapon.reconstruct(8); // Sets weapon to shortbow

        actions[0].reconstruct(0); // Reconstruct the basic attack with new weapon, and change it to be named Shoot
        actions[0].setName("Shoot");
        actions[0].setPower(weapon.getDamage());

        // Set stats
        stats[1] = 6; // ATK
        stats[2] = 5; // DEF
        stats[3] = 4; // MGA
        stats[4] = 3; // MGD
        stats[5] = 7; // SPD

        // Set action pool
        learnableActions[0] = 9;
        learnableActions[1] = 10;
        learnableActions[2] = 11;
        learnableActions[3] = 12;

        unlearnedActions.push_back(9);
        unlearnedActions.push_back(10);
        unlearnedActions.push_back(11);
        unlearnedActions.push_back(12);
    }

    if (playerClass == 3) {
        className = "Mage";
        weapon.reconstruct(12); // Sets weapon to wand

        actions[0].reconstruct(0); // Reconstruct the basic attack with new weapon, and change it to be named Blast
        actions[0].setName("Blast");
        actions[0].setPower(weapon.getDamage());

        // Set stats
        stats[1] = 3; // ATK
        stats[2] = 4; // DEF
        stats[3] = 7; // MGA
        stats[4] = 6; // MGD
        stats[5] = 5; // SPD

        // Set action pool
        learnableActions[0] = 13;
        learnableActions[1] = 14;
        learnableActions[2] = 15;
        learnableActions[3] = 16;

        unlearnedActions.push_back(13);
        unlearnedActions.push_back(14);
        unlearnedActions.push_back(15);
        unlearnedActions.push_back(16);
    }

}

void Player::resetBasicAttack(){
    actions[0].setPower(weapon.getDamage());
}

string Player::learnNewMove(int toLearn){
    int index = -1;

    for (size_t i = 0; i < unlearnedActions.size(); i++) {
        if (unlearnedActions[i] == toLearn) {
            index = i;
        }
    }

    if (index == -1) {
        return name + " can't learn this move!";
    }

    for (int i = 0; i < 4; i++) {
        if (actions[i].getID() == -1) {
            actions[i].reconstruct(toLearn);
            numLearned++;
            unlearnedActions.erase(unlearnedActions.begin() + index); // Remove from unlearned actions list
            return name + " learned " + actions[i].getName() + "!";
        }
    }
    return name + " can't learn any more moves!";
}

string Player::learnRandomMove() {
    int toLearn = chooseUnlearnedAction();
    return learnNewMove(toLearn);
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

int Player::chooseUnlearnedAction() {
    if (numLearned == 3) { // If all moves are learned, return -1
        return -1;
    }

    // If there are any unlearned actions, choose one at random
    int randIndex = rand() % unlearnedActions.size();
    return unlearnedActions[randIndex]; // Return a random unlearned action
}

string Player::getInventoryName(int index) {
    return inventory[index].getName();
}

int Player::getInventoryID(int index) {
    return inventory[index].getID();
}

string Player::gainItem(int ID) {
    int index = -1;
    for (int i = 0; i < 4; i++) {
        if (inventory[i].getID() == -1) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return "Inventory Full!\n";
    }

    // TODO: Add system to replace item in inventory with new Item

    inventory[index].reconstruct(ID);

    return name + " gained " + inventory[index].getName() + "!\n";
}

void Player::gainRandomItem() {
    gainItem(rand() % 12);
}

string Player::useItem(int index) {

    // TODO: differentiate between using items on the map (Skill scrolls, hp scrolls, ect) vs items used in battle (ATK potions, ect), vs items used in both (Healing, scroll of seg fault)

    if (inventory[index].getID() != -1) {
        
        int effect = inventory[index].getEffect();
        string returnText = name + " used " + inventory[index].getName() + "! ";


        if (effect == 0) { // Heal
            int amount = hp / 2;
            hp += amount;
            if (hp > stats[0]) {
                hp = stats[0];
            }
            returnText += name + " was healed for " + to_string(amount) + " HP!"; // Heal 50% of hp
        }

        if (effect == 1) { // Increase Temp ATK
            returnText += applyStatus(0, 2, true);
        }

        if (effect == 2) { // Increase Temp DEF
            returnText += applyStatus(1, 2, true);
        }

        if (effect == 3) { // Increase Temp MGA
            returnText += applyStatus(3, 2, true);
        }

        if (effect == 4) { // Increase Temp MGD
            returnText += applyStatus(4, 2, true);
        }

        if (effect == 5) { // Increase Max HP
            returnText += name + "'s maximum HP increased!\n";
            changeStats(0, 5, true);
            heal(5); // Heal 1 hp exactly, to corespond with max hp increase
        }

        if (effect == 6) { // Increase ATK
            returnText += name + "'s ATK increased!\n";
            changeStats(1, 1, true);
        }

        if (effect == 7) { // Increase DEF
            returnText += name + "'s DEF increased!\n";
            changeStats(2, 1, true);
        }

        if (effect == 8) { // Increase MGA
            returnText += name + "'s MGA increased!\n";
            changeStats(3, 1, true);
        }

        if (effect == 9) { // Increase MGD
            returnText += name + "'s MGD increased!\n";
            
            changeStats(4, 1, true);
        }

        if (effect == 10) { // Increase SPD
            returnText += name + "'s SPD increased!\n";
            changeStats(5, 1, true);
        }

        if (effect == 11) { // Learn New Skill
            returnText += learnRandomMove();
        }

        if (effect == 12) { // Scroll of Seg Fault

            // When trying to seperate this string into 2 lines, I kept getting warnings, so I just left it as one line
            returnText += "You feel the power of the Scroll of Seg Fault swirl around you. You begin to lift into the air. The power surges through you, and your eyes begin to glow. Your limbs go numb, and you feel the ultimate power you have always desired in your grasp, and then it happens. You...";
        }

        inventory[index].reconstruct(-1);

        return returnText;

    }

    return "";
}
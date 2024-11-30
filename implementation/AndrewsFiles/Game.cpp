#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include "Action.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Game::Game(int i){
    srand(time(NULL));
}

int Game::damageCalc(int attackerATK, int targetDEF, int power) {
    int damageDealt = (attackerATK / targetDEF) * power;
    if (damageDealt == 0) {
        damageDealt = 1;
    }
    return damageDealt;

}

void Game::attack(Character *attacker, Character *target, Action attack) {
    int attackerATK;
    int targetDEF;
    int damage = 0;
    int power = attack.getPower();
    int effectID = attack.getStatus();
    float modifier = attack.getModifier();
    string attackName = attack.getName();
    if (attack.isMagic()) {
        attackerATK = attacker->getStat(3); // Get MGA
        targetDEF = target->getStat(4); // Get MGD
    } else {
        attackerATK = attacker->getStat(1); // Get ATK
        targetDEF = target->getStat(2); // Get DEF
    }

    if (target->isDefending()) {
        targetDEF *= 2;
    }

    cout << attacker->getName() << " used " << attackName << "!" << endl;
    
    if (power != 0) {
        damage = damageCalc(attackerATK, targetDEF, power);
        cout << target->getName() << " takes " << damage << " damage!" << endl;
    }

    cout << target->applyStatus(effectID, modifier, false);
    cout << attacker->applyStatus(effectID, modifier, true);
    
    target->takeDamage(damage);
    
}

bool Game::BattleOver(/*Player *player, Enemy *enemy*/){
    /*if (player->isDead()) {
        //cout << player->getName() << " loses!" << endl;
        return true;
    } else if (enemy->isDead()) {
        cout << player->getName() << " wins!" << endl;
        player->gainRandomItem();
        return true;
    }*/
    return false;
}

int Game::Battle(Player *player, Enemy *enemy){
    int playerTurn;
    bool fled = false;
    bool death = false;
    int turnCount = 0;
    char currentTurn;
    int playerAction;
    int enemyAction;
    bool paralyzed;
    Action enemyMove;
    
    if (player->getStat(5) >= enemy->getStat(5)){
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }

    while (!death && !fled) {
        if(turnCount % 2 == playerTurn) {
            currentTurn = 'p'; // It is currently the player's turn
        } else {
            currentTurn = 'e'; // It is currently the enemy's turn
        }

        if (currentTurn == 'p') {
            cout << player->getName() << "'s turn!" << endl; // Change to Ryan's format

            if (player->isDefending()) { // Only defend for 1 turn
                player->stopDefending();
            }

            cout << player->activateStatus(paralyzed); // Activate any status condition the player may have (paralyzed is true if the player is full para'd)
            death = BattleOver(player, enemy); // Here in case the player dies from status conditions
            
            if (paralyzed != true) { // Only act if not full para'd
                cout << "HP: " << player->getHP() << endl;
                cout << "What would you like to do?" << endl << "1. Attack" << endl << "2. Defend" << endl << "3. Item" << endl << "4. Flee" << endl; // Get rid of options
                cin >> playerAction; // Get rid of

                if (playerAction == 1) { // Change input system

                    cout << "What attack would you like to use?" << endl; // Get rid of
                    for (int i = 0; i < 4; i++) { // Use the option 1, option 2... ect buttons for this
                        cout << i + 1 << ". " << player->getAction(i).getName() << endl << endl;
                    }
                    cin >> playerAction; // Get rid of
                    attack(player, enemy, player->getAction(playerAction - 1));

                } else if (playerAction == 2) {

                    cout << endl << player->getName() << " defended!" << endl << endl; // Change to Ryan's format
                    player->defend(); // Halves incoming damage

                } else if (playerAction == 3) {

                    cout << "What item would you like to use?" << endl; // Get rid of
                    for (int i = 0; i < 4; i++) { // Use the option 1, option 2... ect buttons for this
                        cout << i + 1 << ". " << player->getInventoryName(i) << endl << endl;
                    }
                    cin >> playerAction; // Get rid of
                    cout << player->useItem(playerAction - 1);

                } else if (playerAction == 4) {
                    flee(player, enemy, fled);
                } else if (playerAction == 0) {
                    player->printStats(); // Secret dev option, can get rid of in game (unless you decide to implement it properly into the interface)
                }
            }

            paralyzed = false;
        }



        if (currentTurn == 'e') {
            cout << enemy->getName() << "'s turn!" << endl << endl;

            if (enemy->isDefending()) {
                enemy->stopDefending();
            }

            cout << enemy->activateStatus(paralyzed);
            death = BattleOver(player, enemy);

            if (paralyzed != true) {
                enemyAction = rand() % 4;
                if(enemyAction != 0) {
                    enemyMove = enemy->chooseMove();
                    attack(enemy, player, enemyMove);
                } else {
                    cout << enemy->getName() << " defended!" << endl << endl;
                    enemy->defend();
                }
            }

            paralyzed = false;
            
        }
        
        death = BattleOver(player, enemy);



        
        cout << endl;
        turnCount++;
    }
    return 0;
}

string Game::flee(Player *player, Enemy *enemy, bool &fled) {
    int fleeChance = min(100, max(0, (player->getStat(5) / enemy->getStat(5)) * 50)); // Min an Max make sure that minimum flee chance is 0%, and max flee chance is 100%
    int chance = rand() % 100;
    if (chance < fleeChance) {
        fled = true;
        return player->getName() + " fled!";
    }
    return player->getName() + " couldn't flee!";

}

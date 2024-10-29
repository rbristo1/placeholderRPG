#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

Game::Game(int i){}

int Game::damageCalc(int attackerATK, int targetDEF, int power) {
    int damageDealt = (attackerATK / targetDEF) * power;
    if (damageDealt == 0) {
        damageDealt = 1;
    }
    return damageDealt;
}

void Game::attackPlayer(Enemy *enemy, Player *player, bool magic, int power, int effectID){
    int enemyATK;
    int playerDEF;
    if (magic) {
        enemyATK = enemy->getStat(3); // Get MGA
        playerDEF = player->getStat(4); // Get MGD
    } else {
        enemyATK = enemy->getStat(1); // Get ATK
        playerDEF = player->getStat(2); // Get DEF
    }

    
    int damage = damageCalc(enemyATK, playerDEF, power);

    cout << player->getName() << " takes " << damage << " damage!" << endl;

    if (effectID > 0) {
        cout << "Effect " << effectID << " was applied!";
    }

    player->takeDamage(damage);
}

void Game::attackEnemy(Player *player, Enemy *enemy, bool magic, int power, int effectID){
    int playerATK;
    int enemyDEF;
    if (magic) {
        playerATK = player->getStat(3);
        enemyDEF = enemy->getStat(4);
    } else {
        playerATK = player->getStat(1);
        enemyDEF = enemy->getStat(2);
    }

    
    int damage = damageCalc(playerATK, enemyDEF, power);
    cout << enemy->getName() << " takes " << damage << " damage!" << endl;

    if (effectID > 0) {
        cout << "Effect " << effectID << " was applied!";
    }

    enemy->takeDamage(damage);
}

int Game::Battle(Player *player, Enemy *enemy){
    int playerTurn;
    bool death = false;
    int turnCount = 0;
    char currentTurn;
    char playerAction;
    int enemyAction;
    
    if (player->getStat(5) >= enemy->getStat(5)){
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }

    while (!death) {
        if(turnCount % 2 == playerTurn) {
            currentTurn = 'p'; // It is currently the player's turn
        } else {
            currentTurn = 'e'; // It is currently the enemy's turn
        }

        if (currentTurn == 'p') {
            cout << player->getName() << "'s turn! What would you like to do? (a to attack, d to defend) ";
            cin >> playerAction;

            if (playerAction == 'a' || playerAction == 'A') {
                cout << endl << player->getName() << " attacked!" << endl;
                attackEnemy(player, enemy, false, 3, -1);
            } else if (playerAction == 'd' || playerAction == 'D') {
                cout << endl << player->getName() << " defended!" << endl;
            } else if (playerAction == 'p') {
                player->printStats();
                cout << "hi" << endl;
            }
        }



        if (currentTurn == 'e') {
            cout << enemy->getName() << "'s turn!" << endl;
            enemyAction = rand() % 2;
            cout << "Enemy action: " << enemyAction << endl;
            if(enemyAction == 0) {
                cout << enemy->getName() << " attacked!" << endl;
                attackPlayer(enemy, player, false, 3, -1);
            } else if (enemyAction == 1) {
                cout << enemy->getName() << " defended!" << endl;
            }
        }
        




        if(player->isDead()) {
            cout << player->getName() << " loses!" << endl;
            death = true;
        } else if (enemy->isDead()) {
            cout << player->getName() << " wins!" << endl;
            death = true;
        }
        cout << endl;
        turnCount++;
    }
    return 0;
}

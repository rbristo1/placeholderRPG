#include "battle.h"
#include "enemies.h"
#include "screenManip.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include "AndrewsFiles/Character.h"
#include "AndrewsFiles/Enemy.h"
#include "AndrewsFiles/Player.h"
#include "AndrewsFiles/Game.h"
#include "AndrewsFiles/Action.h"
#include <cctype>


using namespace std;

const vector<vector<string> > battle::battleInterfaceStates = 
{
    {
        "    \x1B[31m┌─────────────────────────────┐\033[0m    ┌─────────────────────────────┐    ┌─────────────────────────────┐    ┌─────────────────────────────┐    ", 
        "    \x1B[31m│\033[0m    _  _   _           _     \x1B[31m│\033[0m    │ ___       __              _ │    │     ___ _                   │    │        ___ _                │    ", 
        "    \x1B[31m│\033[0m   /_\\| |_| |_ __ _ __| |__  \x1B[31m│\033[0m    │|   \\ ___ / _|___ _ _  ___| |│    │     |_ _| |_ ___ _ __       │    │       | __| |___ ___        │    ",
        "    \x1B[31m│\033[0m  / _ \\  _|  _/ _` / _| / /  \x1B[31m│\033[0m    │| |) / -_)  _/ -_) ' \\/ _ ` |│    │      | ||  _/ -_) '  \\      │    │       | _|| / -_) -_)       │    ",
        "    \x1B[31m│\033[0m /_/ \\_\\__|\\__\\__,_\\__|_\\_\\  \x1B[31m│\033[0m    │|___/\\___|_| \\___|_||_\\___,_|│    │     |___|\\__\\___|_|_|_|     │    │       |_| |_\\___\\___|       │    ",
        "    \x1B[31m│\033[0m                             \x1B[31m│\033[0m    │                             │    │                             │    │                             │    ",
        "    \x1B[31m└─────────────────────────────┘\033[0m    └─────────────────────────────┘    └─────────────────────────────┘    └─────────────────────────────┘    "
    },
    {
        "    ┌─────────────────────────────┐    \x1B[31m┌─────────────────────────────┐\033[0m    ┌─────────────────────────────┐    ┌─────────────────────────────┐    ", 
        "    │    _  _   _           _     │    \x1B[31m│\033[0m ___       __              _ \x1B[31m│\033[0m    │     ___ _                   │    │        ___ _                │    ", 
        "    │   /_\\| |_| |_ __ _ __| |__  │    \x1B[31m│\033[0m|   \\ ___ / _|___ _ _  ___| |\x1B[31m│\033[0m    │     |_ _| |_ ___ _ __       │    │       | __| |___ ___        │    ",
        "    │  / _ \\  _|  _/ _` / _| / /  │    \x1B[31m│\033[0m| |) / -_)  _/ -_) ' \\/ _ ` |\x1B[31m│\033[0m    │      | ||  _/ -_) '  \\      │    │       | _|| / -_) -_)       │    ",
        "    │ /_/ \\_\\__|\\__\\__,_\\__|_\\_\\  │    \x1B[31m│\033[0m|___/\\___|_| \\___|_||_\\___,_|\x1B[31m│\033[0m    │     |___|\\__\\___|_|_|_|     │    │       |_| |_\\___\\___|       │    ",
        "    │                             │    \x1B[31m│\033[0m                             \x1B[31m│\033[0m    │                             │    │                             │    ",
        "    └─────────────────────────────┘    \x1B[31m└─────────────────────────────┘\033[0m    └─────────────────────────────┘    └─────────────────────────────┘    "
    },
    {
        "    ┌─────────────────────────────┐    ┌─────────────────────────────┐    \x1B[31m┌─────────────────────────────┐\033[0m    ┌─────────────────────────────┐    ", 
        "    │    _  _   _           _     │    │ ___       __              _ │    \x1B[31m│\033[0m     ___ _                   \x1B[31m│\033[0m    │        ___ _                │    ", 
        "    │   /_\\| |_| |_ __ _ __| |__  │    │|   \\ ___ / _|___ _ _  ___| |│    \x1B[31m│\033[0m     |_ _| |_ ___ _ __       \x1B[31m│\033[0m    │       | __| |___ ___        │    ",
        "    │  / _ \\  _|  _/ _` / _| / /  │    │| |) / -_)  _/ -_) ' \\/ _ ` |│    \x1B[31m│\033[0m      | ||  _/ -_) '  \\      \x1B[31m│\033[0m    │       | _|| / -_) -_)       │    ",
        "    │ /_/ \\_\\__|\\__\\__,_\\__|_\\_\\  │    │|___/\\___|_| \\___|_||_\\___,_|│    \x1B[31m│\033[0m     |___|\\__\\___|_|_|_|     \x1B[31m│\033[0m    │       |_| |_\\___\\___|       │    ",
        "    │                             │    │                             │    \x1B[31m│\033[0m                             \x1B[31m│\033[0m    │                             │    ",
        "    └─────────────────────────────┘    └─────────────────────────────┘    \x1B[31m└─────────────────────────────┘\033[0m    └─────────────────────────────┘    "
    },{
        "    ┌─────────────────────────────┐    ┌─────────────────────────────┐    ┌─────────────────────────────┐    \x1B[31m┌─────────────────────────────┐\033[0m    ", 
        "    │    _  _   _           _     │    │ ___       __              _ │    │     ___ _                   │    \x1B[31m│\033[0m        ___ _                \x1B[31m│\033[0m    ", 
        "    │   /_\\| |_| |_ __ _ __| |__  │    │|   \\ ___ / _|___ _ _  ___| |│    │     |_ _| |_ ___ _ __       │    \x1B[31m│\033[0m       | __| |___ ___        \x1B[31m│\033[0m    ",
        "    │  / _ \\  _|  _/ _` / _| / /  │    │| |) / -_)  _/ -_) ' \\/ _ ` |│    │      | ||  _/ -_) '  \\      │    \x1B[31m│\033[0m       | _|| / -_) -_)       \x1B[31m│\033[0m    ",
        "    │ /_/ \\_\\__|\\__\\__,_\\__|_\\_\\  │    │|___/\\___|_| \\___|_||_\\___,_|│    │     |___|\\__\\___|_|_|_|     │    \x1B[31m│\033[0m       |_| |_\\___\\___|       \x1B[31m│\033[0m    ",
        "    │                             │    │                             │    │                             │    \x1B[31m│\033[0m                             \x1B[31m│\033[0m    ",
        "    └─────────────────────────────┘    └─────────────────────────────┘    └─────────────────────────────┘    \x1B[31m└─────────────────────────────┘\033[0m    "
    }
};
vector<string> battleSubMenuInterface {
    "            > option1                             option2                             option3                             option4               ",
    "              option1                           > option2                             option3                             option4               ",
    "              option1                             option2                           > option3                             option4               ",
    "              option1                             option2                             option3                           > option4               "
};

bool battle::BattleOver(Player *player, Enemy *enemy){
    if (player->isDead()) {
        //cout << player->getName() << " loses!" << endl;
        return true;
    } else if (enemy->isDead()) {
        //cout << player->getName() << " wins!" << endl;
        return true;
    
    }
    return false;
}
int battle::damageCalc(int attackerATK, int targetDEF, int power) {
    int damageDealt = (attackerATK / targetDEF) * power;
    if (damageDealt == 0) {
        damageDealt = 1;
    }
    return damageDealt;

}

int battle::attack(Character *attacker, Character *target, Action attack) {
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
    cout << "test";
    target->applyStatus(effectID, modifier, false);
    attacker->applyStatus(effectID, modifier, true);
    cout << "test";
    
    target->takeDamage(damage);
    return damage;
}

//loads the battle interface into the screen vector
void battle::loadBattleInterface(vector<string> * screen, int battleInterfaceState, int enemyNumber, Enemy * enemy, Player * player) {
    
    screenManip sm;
    enemyVector ev;
    //finds the size of the enemy art
    int size = ev.enemies[enemyNumber].size();

    //maximum size for an enemy on the screen
    if (size > 35) {
        size = 35;
    }

    //sets the enemy window to the proper enemy art
    for (int i = 2; i<size+2; i++) {
        screen->at(i) = "                        " + ev.enemies[enemyNumber][i-2] + "                        "; //"                        "
    }
    //top border for text window
    screen -> at(36) = "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────";

    //bottom border for text window
    screen -> at(40) = "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────";

    //loads player options at the bottom of the screen
    for (int i = 0; i<battleInterfaceStates[0].size(); i++) {
        screen->at(42+i) = battleInterfaceStates[battleInterfaceState][i];
    }
    int decrease = 0;
    string HPstats = "Your HP: ";
    HPstats += to_string(player->getHP());
    if (player->getHP() < 10 && player->getHP() >= 0) {
        HPstats += " ";
    }

    HPstats += "                                                                                                                         ";
    HPstats += "Enemy HP: ";
    HPstats += to_string(enemy->getHP());
    if (enemy->getHP() < 10 && enemy->getHP() >= 0) {
        HPstats += " ";
    }
    screen->at(49) = HPstats;

    //prints
    sm.printScreen(screen);
    return;
}

int battle::battleStart(int enemyNumber, Player * player) {
    int playerTurn;
    bool death = false;
    int turnCount = 0;
    char currentTurn;
    int playerAction;
    int enemyAction;
    bool paralyzed;
    Action playerMove;
    Action enemyMove;
    Enemy enemy(enemyNumber);
    //Game mainGame(0);
    (void) playerMove;
    
    if (player->getStat(5) >= enemy.getStat(5)){
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }

    vector<string> screen2;
    screen2.resize(50);
    
    
    screenManip sm;
    battle bt;
    sm.clearScreen(&screen2);
    bt.loadBattleInterface(&screen2, 0, enemyNumber, &enemy, player);
    bt.buildBattleInterface(player);
    string initInput = "A ";
    initInput += enemy.getName();
    initInput += " moves to attack!";
    bt.printBattleText(&screen2, initInput);
    sm.printScreen(&screen2);
    for (int i =0; i< 4; i++) {
        cout << battleSubMenuInterface[i] << endl;
    }
    int lastInput = 0;
    int lastInput2 = 0;
    int submenu = 0;
    
    do{
        bt.loadBattleInterface(&screen2, lastInput, enemyNumber, &enemy, player);
        if(turnCount % 2 == playerTurn) {
            currentTurn = 'p'; // It is currently the player's turn
        } else {
            currentTurn = 'e'; // It is currently the enemy's turn
        }
        if (currentTurn == 'p') {

            if (player->isDefending()) {
                player->stopDefending();
            }

            player->activateStatus(paralyzed);
            death = BattleOver(player, &enemy);
            bt.loadBattleInterface(&screen2, lastInput, enemyNumber, &enemy, player);
            
            if (paralyzed != true) {
                //cout << "What would you like to do?" << endl << "1. Attack" << endl << "2. Defend" << endl;
                //cin >> playerAction;
                do {
                    double microsecond = 1000000;
                    usleep(0.03125 * microsecond);//sleeps for 3 second
                    char input = getchar();
    
                    

                    if (input == 'd' && lastInput != 3 && submenu == 0) {
                        lastInput++;
                        bt.loadBattleInterface(&screen2, lastInput, enemyNumber, &enemy, player);
                        //printScreen(&screen);
                    }
                    else if (input == 'a' && lastInput != 0 && submenu == 0) {
                        lastInput--;
                        bt.loadBattleInterface(&screen2, lastInput, enemyNumber, &enemy, player);
                        
                    }
                    else if (input == 'd' && lastInput2 != 3 && submenu == 1) {
                        lastInput2++;
                        bt.printBattleText(&screen2, battleSubMenuInterface[lastInput2]);
                        sm.printScreen(&screen2);
                    }
                    else if (input == 'a' && lastInput2 != 0 && submenu == 1) {
                        lastInput2--;
                        bt.printBattleText(&screen2, battleSubMenuInterface[lastInput2]);
                        sm.printScreen(&screen2);
                    }
                    else if (input == 'q' && submenu == 1) {
                        bt.printBattleText(&screen2, "");
                        sm.printScreen(&screen2);
                        lastInput2 = 0;
                        submenu = 0;
                    }
                    //0 = attack state, 1 = defend state, 2 = item state, 3 = flee state
                    else if (input == '\n' && submenu == 0) {
                        if (lastInput == 0) {
                            bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                            sm.printScreen(&screen2);
                            submenu = 1;

                            continue;
                        }
                        else if (lastInput == 1) {
                            player->defend();
                            lastInput = 0;
                            lastInput2 = 0;
                            submenu = 0;
                            /*bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                            sm.printScreen(&screen2);
                            submenu = 1;*/

                            break;
                        }
                        else if (lastInput == 2) {
                            lastInput = 0;
                            lastInput2 = 0;
                            submenu = 0;
                            /*bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                            sm.printScreen(&screen2);
                            submenu = 1;*/

                            break;
                        }
                        else {
                            lastInput = 0;
                            lastInput2 = 0;
                            submenu = 0;
                            /*bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                            sm.printScreen(&screen2);
                            submenu = 1;*/

                            return 1;
                        }
                    }
                    else if (input == '\n' && submenu == 1) {
                        //attack(player, &enemy, player->getAction(lastInput2));
                        string temp = player->getName();
                        temp += " attacked with ";
                        temp += player->getAction(lastInput2).getName();
                        temp += ", dealing ";
                        int HPbefore = player->getHP();

                        temp += to_string(attack(player, &enemy, player->getAction(lastInput2)));
                        int HPafter = player->getHP();
                        temp += " damage";
                        if (player->getAction(lastInput2).getStatus() == 10) {
                        temp += " and inflicting paralysis!";
                        }
                        else if (player->getAction(lastInput2).getStatus() == 11) {
                            temp += " and inflicting bleed!";
                        }
                        else if (player->getAction(lastInput2).getStatus() == 12) {
                            temp += " and inflicting burn!";
                        }
                        else if (player->getAction(lastInput2).getStatus() == 14) {
                            temp += " and receieved ";
                            temp += to_string(HPbefore-HPafter);
                            temp += " damage in recoil";
                        }
                        else if (player->getAction(lastInput2).getStatus() == 15) {
                            temp += " and inflicting slow!";
                        }
                        else {
                            temp += "!";
                        }
                        printBattleText(&screen2, temp);
                        bt.loadBattleInterface(&screen2, lastInput, enemyNumber, &enemy, player);
                        usleep(3*microsecond);
                        lastInput = 0;
                        lastInput2 = 0;
                        submenu = 0;
                        break;
                    }
                } while (true);
            }
            

            paralyzed = false;
        }
        if (currentTurn == 'e') {
            //cout << enemy->getName() << "'s turn!" << endl << endl;

            if (enemy.isDefending()) {
                enemy.stopDefending();
            }

            enemy.activateStatus(paralyzed);
            death = BattleOver(player, &enemy);

            if (paralyzed != true) {
                enemyAction = rand() % 4;
                if(enemyAction != 0) {
                    enemyMove = enemy.chooseMove();
                    string temp = enemy.getName();
                    temp += " attacked with ";
                    temp += enemyMove.getName();
                    temp+= ", dealing ";
                    temp += to_string(attack(&enemy, player, enemyMove));
                    temp += " damage";
                    if (enemyMove.getStatus() == 10) {
                        temp += " and inflicting paralysis!";
                    }
                    else if (enemyMove.getStatus() == 11) {
                        temp += " and inflicting bleed!";
                    }
                    else if (enemyMove.getStatus() == 12) {
                        temp += " and inflicting burn!";
                    }
                    else if (enemyMove.getStatus() >= 15) {
                        temp += " and inflicting slow!";
                    }
                    else {
                        temp += "!";
                    }
                    printBattleText(&screen2, temp);
                } else {
                    string temp = enemy.getName();
                    temp += " Defended!";
                    printBattleText(&screen2, temp);
                    enemy.defend();
                }
            }
            else {
                string temp = enemy.getName();
                temp += " is paralyzed!";
                printBattleText(&screen2, temp);
            }

            paralyzed = false;
            
        }
        cout << "test";
        death = BattleOver(player, &enemy);
        cout << "test";


        
        cout << "test";
        turnCount++;
        
        

    } while (!death);
    string temp = enemy.getName();
    temp += " has been slain!";
    printBattleText(&screen2, temp);
    bt.loadBattleInterface(&screen2, lastInput, enemyNumber, &enemy, player);
    usleep(3*1000000);



    return 0;
}
void battle::printBattleText(vector<string> * screen, string text) {
    screen -> at(38) = "";
    for (int i = 0; i < (144-text.size())/2; i++) {
        screen->at(38) += " ";
    }
    screen->at(38) += text;
    if (text.size() % 2 == 0) {
        for (int i = 0; i < (144-text.size())/2; i++) {
            screen->at(38) += " ";
        }
    }
    else {
        for (int i = 0; i < ((144-text.size())/2)+1; i++) {
            screen->at(38) += " ";
        }
    }
}
void battle::buildBattleInterface(Player * player) {
    for (int i = 0; i<4; i++) {
        battleSubMenuInterface[i] = "";
        /*for (int j = 0; j < (34-player->getAction(0).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }*/
        if (i == 0) {
            battleSubMenuInterface[i] += "> ";
        }
        else {
            battleSubMenuInterface[i] += "  ";
        }
        battleSubMenuInterface[i] += player->getAction(0).getName();
        for (int j = 0; j < (36-player->getAction(0).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }

        for (int j = 0; j < (34-player->getAction(1).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }
        if (i == 1) {
            battleSubMenuInterface[i] += "> ";
        }
        else {
            battleSubMenuInterface[i] += "  ";
        }
        battleSubMenuInterface[i] += player->getAction(1).getName();
        for (int j = 0; j < (36-player->getAction(1).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }

        for (int j = 0; j < (34-player->getAction(2).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }
        if (i == 2) {
            battleSubMenuInterface[i] += "> ";
        }
        else {
            battleSubMenuInterface[i] += "  ";
        }
        battleSubMenuInterface[i] += player->getAction(2).getName();
        for (int j = 0; j < (36-player->getAction(2).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }

        for (int j = 0; j < (34-player->getAction(3).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }
        if (i == 3) {
            battleSubMenuInterface[i] += "> ";
        }
        else {
            battleSubMenuInterface[i] += "  ";
        }
        battleSubMenuInterface[i] += player->getAction(3).getName();
        /*for (int j = 0; j < (36-player->getAction(3).getName().size())/2; j++) {
            battleSubMenuInterface[i] += " ";

        }*/
        

    }
    
}


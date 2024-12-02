#include "mapMovements.h"
#include "battle.h"
#include "screenManip.h"
#include <iostream>
#include <unistd.h>
#include "AndrewsFiles/Character.h"
#include "AndrewsFiles/Enemy.h"
#include "AndrewsFiles/Player.h"
#include "AndrewsFiles/Game.h"
#include "AndrewsFiles/Action.h"

using namespace std;

vector<vector<string>> mapMovements::maps = 
    {
        {
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                "
        },
        {
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                            o                                                                                                                   ",
            "#                                                                                                                                               ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                           LLLL                                                                 ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                           kkkk                                                                 ",
            "                                                                                                                                                ",
            "                                                                           www                                                                  ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                       \x1B[31mp\033[0m                                                                        ",
            "                                                                       sccccccc                                                                 ",
            "                                                                                                                                                "
        },
        {
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                               #",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                "
        }
    };

    vector<vector<int>> xcolliders = 
    {
        {},
        {0, 143, 0, 143},
        {}
    };
    vector<vector<int>> xcollidersWidth = 
    {
        {},
        {1, 1, 1, 1},
        {}
    };

    vector<vector<int>> ycolliders = 
    {
        {},
        {0, 49, 49, 0},
        {}
    };
    vector<vector<int>> ycollidersWidth = 
    {
        {},
        {1, 1, 1, 1},
        {}
    };

    vector<vector<int>> enemyCollidersType = 
    {
        {},
        {1,0,1,0},
        {}
    };

    vector<vector<int>> activeColliders = 
    {
        {},
        {1,1,1,1},
        {}
    };
    //WNES
    vector<vector<int>> connectedRooms = 
    {
        {-1, -1, -1, -1},
        {2, -1, -1, -1},
        {-1, -1, 1, -1}
    };
    vector<vector<int>> chestItems = 
    {
        {},
        {0, 0, 0, 0, 0, },
        {}
    };
    int keysCollected = 0;
    int keysUsed = 0;
    
    vector<int> chestItemsCollected = {0, 0, 0};

vector<string> mapMovements::mapText(vector<string> * screen, string temp) {
    vector<string> itemGet = (*screen);
    itemGet[40] = "────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────";
    for (int i = 41; i<49; i++) {
        itemGet[i] = "                                                                                                                                                ";
    }
    itemGet[45] = "";
    for (int i = 0; i < (144-temp.size())/2; i++) {
        itemGet[45] += " ";
    }
    itemGet[45] += temp;
    if (temp.size() % 2 == 0) {
        for (int i = 0; i < (144-temp.size())/2; i++) {
            itemGet[45] += " ";
        }
    }
    else {
        for (int i = 0; i < ((144-temp.size())/2)+1; i++) {
            itemGet[45] += " ";
        }
    }
    return itemGet;
}

void mapMovements::gameStart(vector<string> * screen) {
    screenManip sm;
    battle bt;
    Action attack(0);
    Game mainGame(0);
    //Enemy enemy(0);
    int choice;
    string playerName;
    vector<string> classSelect = maps[0];
    classSelect[10] = "                                                               Choose Your Class!                                                               ";
    classSelect[11] = "                                                                  1. Barbarian                                                                  ";
    classSelect[12] = "                                                                   2. Knight                                                                    ";
    classSelect[13] = "                                                                   3. Archer                                                                    ";
    classSelect[14] = "                                                                    4. Mage                                                                     ";
    sm.printScreen(&classSelect);
    while (true) {
        char input = getchar();
        if (input == '1' || input == '2' || input == '3' || input == '4') {
            choice = input-'0';
            break;
        }
    }

    classSelect = maps[0];
    classSelect[10] = "                                                          Type Your Character's Name:                                                           ";
    sm.printScreen(&classSelect);
    cin >> playerName;
    Player player(playerName, choice - 1);
    player.print();
    player.learnNewMove(4);
    player.learnNewMove(1);
    player.learnNewMove(2);
    player.learnNewMove(3);

    //mainGame.Battle(&player, &slime);
    int currentMap = 1;
    screen = &maps[currentMap];
    /*for (int i = 0; i < screen->size(); i++) {
        cout << i;
        screen -> at(i) = maps[0][i];
    }*/
    sm.printScreen(screen);
    int playerx = 71;
    int playery = 47;
    
    do{
        double microsecond = 1000000;
        usleep(0.03125 * microsecond);//sleeps for 3 second

        char input = getchar();

        if (input == 'd' && playerx != 143) {
            string tempString = screen->at(playery);
            screen->at(playery).replace(playerx, 10, " ");

            if (screen->at(playery)[playerx+1] == ' ') {
                for (size_t i = 0; i < xcolliders[currentMap].size(); i++) {
                    if (activeColliders[currentMap][i] == 1 && abs(playery - ycolliders[currentMap][i]) <= ycollidersWidth[currentMap][i] && abs(playerx+1 - xcolliders[currentMap][i]) <= xcollidersWidth[currentMap][i]) {
                        activeColliders[currentMap][i] = bt.battleStart(enemyCollidersType[currentMap][i], &player);
                        if (player.isDead()) {
                            return;
                        }
                    }
                }
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 'w') {
                screen -> at(playery) = tempString;
                vector<string> itemGet;
                string temp = player.getNextWeapon();
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(3*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 'k') {
                screen -> at(playery) = tempString;
                vector<string> itemGet;
                keysCollected++;
                string temp = "You found a key!";
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(3*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 'L') {
                screen -> at(playery) = tempString;
                vector<string> itemGet;
                keysCollected--;
                keysUsed++;

                string temp = "You unlocked a Lock!";
                if (keysUsed == 4) {
                    keysUsed = 0;
                    temp += " A hatch opens in the floor leading to the next level!";
                    maps[currentMap][24][71] = '+';
                }
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(3*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 's'){
                screen -> at(playery) = tempString;
                bt.battleStart(2, &player);
                if (player.isDead()) {
                    return;
                }
                screen->at(playery).replace(playerx, 10, " ");
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 'c'){
                //string temp = player.gainItem(chestItems[currentMap][chestItemsCollected[currentMap]]);
                int temp2 = rand() % 100;
                string temp = "";
                if (temp2 < 90) {
                    temp = player.gainRandomItem();
                }
                if (temp == "Inventory Full!") {
                    screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                }
                else {
                    //cout <<"wrong path" << endl;
                    screen -> at(playery) = tempString;
                    screen->at(playery).replace(playerx, 10, " ");
                    playerx++;
                    screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                    chestItemsCollected[currentMap]=chestItemsCollected[currentMap]+1;
                }
                vector<string> itemGet;
                if (temp2 < 90) {
                    itemGet = mapText(screen, temp);
                }
                else {
                    itemGet = mapText(screen, "You find nothing but disappoimtment");
                }
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == '#'){
                if (connectedRooms[currentMap][2] != -1) {
                    screen -> at(playery) = tempString;
                    screen->at(playery).replace(playerx, 10, " ");
                    screen = &maps[connectedRooms[currentMap][2]];
                    currentMap = connectedRooms[currentMap][2];
                    screen->at(playery).replace(1, 1, "\033[31mp\033[0m");
                    playerx=1;
                }
                sm.printScreen(screen);
            }
            else {
                screen -> at(playery) = tempString;
            }
            
            
        }
        else if (input == 'a' && playerx != 0) {
            if (screen->at(playery)[playerx-1] == ' ') {
                for (size_t i = 0; i < xcolliders[currentMap].size(); i++) {
                    if (activeColliders[currentMap][i] == 1 && abs(playery - ycolliders[currentMap][i]) <= ycollidersWidth[currentMap][i] && abs(playerx-1 - xcolliders[currentMap][i]) <= xcollidersWidth[currentMap][i]/*activeColliders[currentMap][i] == 1 && playery == ycolliders[currentMap][i] && playerx-1 == xcolliders[currentMap][i]*/) {
                        activeColliders[currentMap][i] = bt.battleStart(enemyCollidersType[currentMap][i], &player);
                        if (player.isDead()) {
                            return;
                        }
                    }
                }
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == 'c'){
                //string temp = player.gainItem(chestItems[currentMap][chestItemsCollected[currentMap]]);
                int temp2 = rand() % 100;
                string temp = "";
                if (temp2 < 90) {
                    temp = player.gainRandomItem();
                }
                if (temp == "Inventory Full!") {
                }
                else {
                    //cout <<"wrong path" << endl;
                    screen->at(playery).replace(playerx, 10, " ");
                    playerx--;
                    screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                    chestItemsCollected[currentMap]=chestItemsCollected[currentMap]+1;
                }
                vector<string> itemGet;
                if (temp2 < 90) {
                    itemGet = mapText(screen, temp);
                }
                else {
                    itemGet = mapText(screen, "You find nothing but disappoimtment");
                }
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);

            }
            else if (screen->at(playery)[playerx-1] == 'L') {
                vector<string> itemGet;
                keysCollected--;
                keysUsed++;

                string temp = "You unlocked a Lock!";
                if (keysUsed == 4) {
                    keysUsed = 0;
                    temp += " A hatch opens in the floor leading to the next level!";
                    maps[currentMap][24][71] = '+';
                }
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == 'k') {
                vector<string> itemGet;
                keysCollected++;
                string temp = "You found a key!";
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == 'w') {
                vector<string> itemGet;
                string temp = player.getNextWeapon();
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == 's'){
                bt.battleStart(2, &player);
                if (player.isDead()) {
                    return;
                }
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == '#'){
                if (connectedRooms[currentMap][0] != -1) {
                    screen->at(playery).replace(playerx, 10, " ");
                    screen = &maps[connectedRooms[currentMap][0]];
                    currentMap = connectedRooms[currentMap][0];
                    screen->at(playery).replace(142, 1, "\033[31mp\033[0m");
                    playerx=142;
                }
                sm.printScreen(screen);
            }
            
        }
        else if (input == 's' && playery != 49) {
            if (screen->at(playery+1)[playerx] == ' ') {
                for (size_t i = 0; i < xcolliders[currentMap].size(); i++) {
                    if (activeColliders[currentMap][i] == 1 && abs(playery+1 - ycolliders[currentMap][i]) <= ycollidersWidth[currentMap][i] && abs(playerx - xcolliders[currentMap][i]) <= xcollidersWidth[currentMap][i]) {
                        activeColliders[currentMap][i] = bt.battleStart(enemyCollidersType[currentMap][i], &player);
                        if (player.isDead()) {
                            return;
                        }
                    }
                }
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == 'c'){
                //string temp = player.gainItem(chestItems[currentMap][chestItemsCollected[currentMap]]);
                int temp2 = rand() % 100;
                string temp = "";
                if (temp2 < 90) {
                    temp = player.gainRandomItem();
                }
                if (temp == "Inventory Full!") {
                }
                else {
                    //cout <<"wrong path" << endl;
                    screen->at(playery).replace(playerx, 10, " ");
                    playery++;
                    screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                    chestItemsCollected[currentMap]=chestItemsCollected[currentMap]+1;
                }
                vector<string> itemGet;
                if (temp2 < 90) {
                    itemGet = mapText(screen, temp);
                }
                else {
                    itemGet = mapText(screen, "You find nothing but disappoimtment");
                }
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);

            }
            else if (screen->at(playery+1)[playerx] == 'w') {
                vector<string> itemGet;
                string temp = player.getNextWeapon();
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == 'L') {
                vector<string> itemGet;
                keysCollected--;
                keysUsed++;
                string temp = "You unlocked a Lock!";
                if (keysUsed == 4) {
                    keysUsed = 0;
                    temp += " A hatch opens in the floor leading to the next level!";
                    maps[currentMap][24][71] = '+';
                }
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == 'k') {
                vector<string> itemGet;
                keysCollected++;
                string temp = "You found a key!";
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == 's'){
                bt.battleStart(2, &player);
                if (player.isDead()) {
                    return;
                }
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == '#'){
                if (connectedRooms[currentMap][3] != -1) {
                    screen->at(playery).replace(playerx, 10, " ");
                    screen = &maps[connectedRooms[currentMap][3]];
                    currentMap = connectedRooms[currentMap][3];
                    screen->at(1).replace(playerx, 1, "\033[31mp\033[0m");
                    playery=1;
                }
                sm.printScreen(screen);
            }
            
        }
        else if (input == 'w' && playery != 0) {
            if (screen->at(playery-1)[playerx] == ' ') {
                for (size_t i = 0; i < xcolliders[currentMap].size(); i++) {
                    if (activeColliders[currentMap][i] == 1 && abs(playery-1 - ycolliders[currentMap][i]) <= ycollidersWidth[currentMap][i] && abs(playerx - xcolliders[currentMap][i]) <= xcollidersWidth[currentMap][i]) {
                        activeColliders[currentMap][i] = bt.battleStart(enemyCollidersType[currentMap][i], &player);
                        if (player.isDead()) {
                            return;
                        }
                    }
                }
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            
            else if (screen->at(playery-1)[playerx] == 'c'){
                //string temp = player.gainItem(chestItems[currentMap][chestItemsCollected[currentMap]]);
                int temp2 = rand() % 100;
                string temp = "";
                if (temp2 < 90) {
                    temp = player.gainRandomItem();
                }
                if (temp == "Inventory Full!") {
                }
                else {
                    //cout <<"wrong path" << endl;
                    screen->at(playery).replace(playerx, 10, " ");
                    playery--;
                    screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                    chestItemsCollected[currentMap]=chestItemsCollected[currentMap]+1;
                }
                vector<string> itemGet;
                if (temp2 < 90) {
                    itemGet = mapText(screen, temp);
                }
                else {
                    itemGet = mapText(screen, "You find nothing but disappoimtment");
                }
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);

            }
            else if (screen->at(playery-1)[playerx] == 'L') {
                vector<string> itemGet;
                keysCollected--;
                keysUsed++;

                string temp = "You unlocked a Lock!";
                if (keysUsed == 4) {
                    keysUsed = 0;
                    temp += " A hatch opens in the floor leading to the next level!";
                    maps[currentMap][24][71] = '+';
                }
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery-1)[playerx] == 'k') {
                vector<string> itemGet;
                keysCollected++;
                string temp = "You found a key!";
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery-1)[playerx] == 'w') {
                vector<string> itemGet;
                string temp = player.getNextWeapon();
                itemGet = mapText(screen, temp);
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(&itemGet);
                usleep(2*microsecond);
                sm.printScreen(screen);
            }
            else if (screen->at(playery-1)[playerx] == 's'){
                bt.battleStart(2, &player);
                if (player.isDead()) {
                    return;
                }
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery-1)[playerx] == '#'){
                if (connectedRooms[currentMap][1] != -1) {
                    screen->at(playery).replace(playerx, 10, " ");
                    screen = &maps[connectedRooms[currentMap][1]];
                    currentMap = connectedRooms[currentMap][1];
                    screen->at(48).replace(playerx, 1, "\033[31mp\033[0m");
                    playery=48;
                }
                sm.printScreen(screen);
            }
            
        }
        else if (input == 'i') {
            
            vector<string> inventory = maps[0];
            inventory[10] = "                                                  Inventory: (numbers to use item, q to exit)                                                   ";

            for (int j = 0; j<4; j++) {
                string temp = player.getInventoryName(j);
                if (temp == "Invalid Item") {
                    inventory[15+j] = "                                                                  " + to_string(j+1) + ". Empty                                                                      ";
                }
                else {
                    inventory[15+j] = " ";
                    for (int i = 0; i < (144-temp.size()-3)/2; i++) {
                        inventory[15+j] += " ";
                    }
                    inventory[15+j] += to_string(j+1);
                    inventory[15+j] += ". ";
                    inventory[15+j] += temp;
                    if (temp.size() % 2 == 0) {
                        for (int i = 0; i < (144-temp.size()-3)/2; i++) {
                            inventory[15+j] += " ";
                        }
                    }
                    else {
                        for (int i = 0; i < ((144-temp.size()-3)/2)+1; i++) {
                            inventory[15+j] += " ";
                        }
                    }
                }
            }
            
            string temp = "HP: ";
            temp += to_string(player.getHP());
            temp += "/";
            temp += to_string(player.getStat(0));
            inventory[25] = "";
            for (int i = 0; i < (144-temp.size())/2; i++) {
                inventory[25] += " ";
            }
            inventory[25] += temp;
            if (temp.size() % 2 == 0) {
                for (int i = 0; i < (144-temp.size())/2; i++) {
                    inventory[25] += " ";
                }
            }
            else {
                for (int i = 0; i < ((144-temp.size())/2)+1; i++) {
                    inventory[25] += " ";
                }
            }
            sm.printScreen(&inventory);
            while (true) {
                char input2 = getchar();
                if (input2 == 'q') {
                    sm.printScreen(screen);
                    break;
                }
                else if (input2 == '1') {
                    string temp = player.useItem(0, 1);
                    if (temp != "") {
                        vector<string> itemGet = mapText(screen, temp);
                        sm.printScreen(&itemGet);
                        usleep(2*microsecond);
                        sm.printScreen(screen);
                    }
                    break;
                }
                else if (input2 == '2') {
                    string temp = player.useItem(1, 1);
                    if (temp != "") {
                        vector<string> itemGet = mapText(screen, temp);
                        sm.printScreen(&itemGet);
                        usleep(2*microsecond);
                        sm.printScreen(screen);
                    }
                    break;
                }
                else if (input2 == '3') {
                    string temp = player.useItem(2, 1);
                    if (temp != "") {
                        vector<string> itemGet = mapText(screen, temp);
                        sm.printScreen(&itemGet);
                        usleep(2*microsecond);
                        sm.printScreen(screen);
                    }
                    break;
                }
                else if (input2 == '4') {
                    string temp = player.useItem(3, 1);
                    if (temp != "") {
                        vector<string> itemGet = mapText(screen, temp);
                        sm.printScreen(&itemGet);
                        usleep(2*microsecond);
                        sm.printScreen(screen);
                    }
                    break;
                }
            }
            sm.printScreen(screen);
            


        
        }

    } while (true);

    return;

}

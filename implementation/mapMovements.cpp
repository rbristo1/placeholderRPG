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
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                                                                                                ",
            "                                                                       \x1B[31mp\033[0m                                                                        ",
            "                                                                       s                                                                        ",
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
                    }
                }
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 's'){
                screen -> at(playery) = tempString;
                bt.battleStart(1, &player);
                screen->at(playery).replace(playerx, 10, " ");
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
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
                    }
                }
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == 's'){
                bt.battleStart(1, &player);
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
                    }
                }
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == 's'){
                bt.battleStart(1, &player);
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
                    }
                }
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery-1)[playerx] == 's'){
                bt.battleStart(1, &player);
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

    } while (true);

    return;

}

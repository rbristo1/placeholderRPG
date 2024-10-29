#include "mapMovements.h"
#include "battle.h"
#include "screenManip.h"
#include <iostream>
#include <unistd.h>
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
            "                            o                                                                                                                   ",
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
            "                                                                       \x1B[31mp\033[0m                                                                        ",
            "                                                                       s                                                                        ",
            "                                                                                                                                                "
        }
    };

void mapMovements::gameStart(vector<string> * screen) {
    screenManip sm;
    battle bt;
    cout << "test" << endl;
    screen = &maps[0];
    /*for (int i = 0; i < screen->size(); i++) {
        cout << i;
        screen -> at(i) = maps[0][i];
    }*/
    cout << "test" << endl;
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
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx+1] == 's'){
                screen -> at(playery) = tempString;
                bt.battleStart(1);
                screen->at(playery).replace(playerx, 10, " ");
                playerx++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else {
                screen -> at(playery) = tempString;
            }
            
            
        }
        else if (input == 'a' && playerx != 0) {
            if (screen->at(playery)[playerx-1] == ' ') {
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery)[playerx-1] == 's'){
                bt.battleStart(1);
                screen->at(playery).replace(playerx, 10, " ");
                playerx--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            
        }
        else if (input == 's' && playery != 49) {
            if (screen->at(playery+1)[playerx] == ' ') {
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery+1)[playerx] == 's'){
                bt.battleStart(1);
                screen->at(playery).replace(playerx, 10, " ");
                playery++;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            
        }
        else if (input == 'w' && playery != 0) {
            if (screen->at(playery-1)[playerx] == ' ') {
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            else if (screen->at(playery-1)[playerx] == 's'){
                bt.battleStart(1);
                screen->at(playery).replace(playerx, 10, " ");
                playery--;
                screen->at(playery).replace(playerx, 1, "\033[31mp\033[0m");
                sm.printScreen(screen);
            }
            
        }

    } while (true);

    return;

}
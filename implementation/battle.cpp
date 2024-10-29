#include "battle.h"
#include "enemies.h"
#include "screenManip.h"
#include <unistd.h>

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

//loads the battle interface into the screen vector
void battle::loadBattleInterface(vector<string> * screen, int battleInterfaceState, int enemyNumber) {
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

    //prints
    sm.printScreen(screen);
    return;
}

int battle::battleStart(int enemyNumber) {
    vector<string> screen2;
    screen2.resize(50);
    
    screenManip sm;
    battle bt;
    sm.clearScreen(&screen2);
    bt.loadBattleInterface(&screen2, 0, 1);
    string initInput = "This is a test message to test the battle output text system.";
    bt.printBattleText(&screen2, initInput);
    sm.printScreen(&screen2);
    int lastInput = 0;
    int lastInput2 = 0;
    int submenu = 0;
    
    do{
        double microsecond = 1000000;
        usleep(0.03125 * microsecond);//sleeps for 3 second
        char input = getchar();

        if (input == 'd' && lastInput != 3 && submenu == 0) {
            lastInput++;
            bt.loadBattleInterface(&screen2, lastInput, 1);
            //printScreen(&screen);
        }
        else if (input == 'a' && lastInput != 0 && submenu == 0) {
            lastInput--;
            bt.loadBattleInterface(&screen2, lastInput, 1);
            
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
            bt.printBattleText(&screen2, initInput);
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
                bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                sm.printScreen(&screen2);
                submenu = 1;

                continue;
            }
            else if (lastInput == 2) {
                bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                sm.printScreen(&screen2);
                submenu = 1;

                continue;
            }
            else {
                bt.printBattleText(&screen2, battleSubMenuInterface[0]);
                sm.printScreen(&screen2);
                submenu = 1;

                continue;
            }
        }
        else if (input == '\n' && submenu == 1) {
            if (lastInput2 == 0) {
                break;
            }
            else if (lastInput2 == 1) {
                break;
            }
            else if (lastInput2 == 2) {
                break;
            }
            else {
                break;
            }
        }

    } while (true);


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





#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>
#include <thread>
#include <curses.h>


using namespace std;

vector<string> title = {"__________.__                      .__           .__       .___            ",
                        "\\______   \\  | _____    ____  ____ |  |__   ____ |  |    __| _/___________ ", 
                        " |     ___/  | \\__  \\ _/ ___\\/ __ \\|  |  \\ /  _ \\|  |   / __ |/ __ \\_  __ \\", 
                        " |    |   |  |__/ __ \\  \\__\\   ___/|   Y  (  <_> )  |__/ /_/ \\  ___/|  | \\/", 
                        " |____|   |____(____  /\\___  >___  >___|  /\\____/|____/\\____ |\\___  >__|   ", 
                        "                    \\/     \\/    \\/     \\/                  \\/    \\/       "};

void printScreen(vector<string> * screen) {
    for (int i = 0; i < screen->size(); i++) {
        screen-> at(i) = "                                                                                                                                                ";
    }
    for (int i = 10; i < 16; i++) {
        screen -> at(i) = "                                  " + title[i-10] + "                                   ";

    }
    screen -> at(30) = "                                                                 > Start game                                                                   ";
    screen -> at(33) = "                                                                   Quit                                                                         ";

    while (true) {
        double microsecond = 1000000;
        usleep(0.03125 * microsecond);//sleeps for 3 second

        struct winsize ws;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 
        int lines = ws.ws_row;
        int columns = ws.ws_col;
        int l_offset = (columns - (48*3+2))/2;
        string emptySpace;
        string ret;
        for (int j = 0; j < l_offset; j++) {
            emptySpace += " ";
        }
        for (int i = 0; i < (lines-(screen->size()))/2; i++) {
            ret += "\n";
        }
        printf ("lines %d\n", ws.ws_row);
        printf ("columns %d\n", ws.ws_col);
        cout << ret;
    
        cout << emptySpace << "┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
        for (int i = 0; i < screen -> size(); i++) {
            cout << emptySpace << "│" << screen->at(i) << "│" << endl;
        }
        cout << emptySpace << "└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
        cout << ret;
    }

}

int main() {
    //initscr();
    timeout(-1);
    cbreak();
    vector<string> screen;
    int max = 50;
    //dimensions of screen:
    //x:(max-2)*3
    //y: max
    screen.resize(max);


    for (int i = 0; i < max; i++) {
        screen[i] = "                                                                                                                                                ";
    }
    thread printLoop(printScreen, &screen);
    printLoop.join();
    //cout << screen[30];
    
    do{
        double microsecond = 1000000;
        usleep(0.03125 * microsecond);//sleeps for 3 second
        char input = getchar();

        if (input == 's') {
            screen[30][65] = ' ';
            screen[33][65] = '>';
        }
        else if (input == 'w') {
            screen[30][65] = '>';
            screen[33][65] = ' ';
        }

    } while (true);
    
    endwin();
    //printLoop.join();
    
    
    
    return 0;
}

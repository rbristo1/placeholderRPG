

#include "implementation/enemies.h"
#include "implementation/screenManip.h"
#include "implementation/battle.h"
#include "implementation/mapMovements.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <termios.h>
#include "miniAudioSounds.h"
#include <thread>


using namespace std;


vector<string> title = {"\x1B[96m__________.__                      .__           .__       .___            \033[0m",
                        "\x1B[96m\\______   \\  | _____    ____  ____ |  |__   ____ |  |    __| _/___________ \033[0m", 
                        "\x1B[96m |     ___/  | \\__  \\ _/ ___\\/ __ \\|  |  \\ /  _ \\|  |   / __ |/ __ \\_  __ \\\033[0m", 
                        "\x1B[96m |    |   |  |__/ __ \\  \\__\\   ___/|   Y  (  <_> )  |__/ /_/ \\  ___/|  | \\/\033[0m", 
                        "\x1B[96m |____|   |____(____  /\\___  >___  >___|  /\\____/|____/\\____ |\\___  >__|   \033[0m", 
                        "\x1B[96m                    \\/     \\/    \\/     \\/                  \\/    \\/       \033[0m"};

int main() {
    mapMovements mm;
    screenManip sm;
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 
    int lines = ws.ws_row;
    int columns = ws.ws_col;
    if (lines < 52 || columns < 146) {
        cerr << "Terminal size not large enough to display game, please fullscreen or zoom out of the terminal before restarting." << endl;
        return 1;
    }
    mini sounds;
    bool stop = false;
    string test = "Versus.mp3";
    //thread music(&mini::playMenuTheme, &sounds, &stop, test.data());
    vector<string> screen;
    int max = 50;
    screen.resize(max);
    sm.clearScreen(&screen);
    for (int i = 10; i < 16; i++) {
        screen.at(i) = "                                  " + title[i-10] + "                                   ";

    }
    screen.at(30) = "                                                                 > Start game                                                                   ";
    screen.at(33) = "                                                                   Quit                                                                         ";



    sm.printScreen(&screen);

    static struct termios oldt, newt;

    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr( STDIN_FILENO, &oldt);
    /*now the settings will be copied*/
    newt = oldt;

    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON);          

    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    /*This is your part:
    I choose 'e' to end input. Notice that EOF is also turned off
    in the non-canonical mode*/
    char lastInput = 'w';
    thread music(&mini::playMenuTheme, &sounds, &stop, test.data());
    do{
        sm.printScreen(&screen);
        double microsecond = 1000000;
        usleep(0.03125 * microsecond);//sleeps for 3 second
        char input = getchar();

        if (input == 's') {
            screen[30][65] = ' ';
            screen[33][65] = '>';
            sm.printScreen(&screen);
            lastInput = 's';
        }
        else if (input == 'w') {
            screen[30][65] = '>';
            screen[33][65] = ' ';
            sm.printScreen(&screen);
            lastInput = 'w';
        }
        else if (input == '\n') {
            if (lastInput == 's') {
                stop = true;
                music.join();
                //usleep(0.03125 * microsecond);
                break;
            }
            else {
                stop = true;
                mm.gameStart(&screen);
                stop = false;
                thread music2(&mini::playMenuTheme, &sounds, &stop, test.data());
                continue;
            }
        }
        


    } while (true);
    //printLoop.join();
    /*restore the old settings*/
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    
    
    return 0;
}

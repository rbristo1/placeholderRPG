#include "screenManip.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>


using namespace std;

void screenManip::clearScreen(vector<string> * screen) {
    for (int i = 0; i < screen->size(); i++) {
        screen->at(i) = "                                                                                                                                                ";
    }
    return;
}
void screenManip::printScreen(vector<string> * screen) {

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
    return;
    

}

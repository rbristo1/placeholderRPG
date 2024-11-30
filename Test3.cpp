#include <curses.h>
#include <panel.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>

using namespace std;


int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 
    int lines = ws.ws_row;
    int columns = ws.ws_col;
    int height = 50;
    int width = 144;
    int row = lines/2;
    int col = columns/2;
    WINDOW local_win = newwin(height, width, row, col);
    endwin();


    return 0;
}
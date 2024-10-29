#ifndef BATTLE_H
#define BATTLE_H
#include <vector>
#include <string>

using namespace std;
class battle {
    public:
        static const vector<vector<string> > battleInterfaceStates;
        void loadBattleInterface(vector<string> * screen, int battleInterfaceState, int enemyNumber);
        int battleStart(int enemyNumber);
        void printBattleText(vector<string> * screen, string text);
    private:

};
#endif
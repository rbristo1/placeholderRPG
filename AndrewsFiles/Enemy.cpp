#include "Enemy.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

Enemy::Enemy(int id) : Character(id, "", nullptr){ // Used ChatGPT for help figuring out inheritense with header files
    ifstream fin;
    fin.open("Enemies.txt");
    string temp;
    int idCompare;

    while (getline(fin, temp, '\n')){
        idCompare = stoi(temp.substr(0, 2));
        if (id == idCompare) {
            break;
        }
    }

    stringstream s(temp);
    s >> ID >> name >> stats[0] >> stats[1] >> stats[2] >> stats[3] >> stats[4] >> stats[5];
    hp = stats[0];
    
}
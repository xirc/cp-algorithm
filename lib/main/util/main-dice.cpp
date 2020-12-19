#include <iostream>
#include <string>
#include <algorithm>
#include "template/template-main.hpp"
#include "cpalgo/util/dice.hpp"

using namespace std;

using DiceT = Dice<int>;
DiceT dice;

void action_init() {
    dice = Dice<int>();
    dice[DiceT::TOP] = 1;
    dice[DiceT::BOTTOM] = 6;
    dice[DiceT::FRONT] = 2;
    dice[DiceT::BACK] = 5;
    dice[DiceT::LEFT] = 3;
    dice[DiceT::RIGHT] = 4;
}

void action_roll() {
    string dir;
    cin >> dir;
    if (dir == "lx") {
        dice.roll_lx();
    } else if (dir == "rx") {
        dice.roll_rx();
    } else if (dir == "ly") {
        dice.roll_ly();
    } else if (dir == "ry") {
        dice.roll_ry();
    } else if (dir == "lz") {
        dice.roll_lz();
    } else if (dir == "rz") {
        dice.roll_rz();
    } else {
        cout << "false" << endl;
        return;
    }
}

void action_dump() {
    cout << "TOP: " << dice[DiceT::TOP] << endl;
    cout << "BOTTOM: " << dice[DiceT::BOTTOM] << endl;
    cout << "LEFT: " << dice[DiceT::LEFT] << endl;
    cout << "RIGHT: " << dice[DiceT::RIGHT] << endl;
    cout << "FRONT: " << dice[DiceT::FRONT] << endl;
    cout << "BACK: " << dice[DiceT::BACK] << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Dice";
    commands["init"] = { "init", action_init };
    commands["roll"] = { "roll {lx|rx|ly|ry|lz|rz}", action_roll };
    commands["dump"] = { "dump", action_dump };
}
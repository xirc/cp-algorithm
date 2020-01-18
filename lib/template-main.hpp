#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>

using namespace std;

struct Command {
    string description;
    function<void()> action;
};

void setup(
    string& header,
    map<string,Command>& commands
);

void print_help(string& header, map<string,Command>& commands) {
    cout << header << endl;
    cout << "commands:" << endl;
    for (auto it = commands.begin(); it != commands.end(); ++it) {
        cout << "  * " << it->second.description << endl;
    }
    cout << endl;
}

int main() {
    string query;
    string header;
    map<string,Command> commands;
    
    setup(header, commands);
    if (commands.find("help") == commands.end()) {
        commands["help"] = Command { "help", bind(print_help, header, commands) };
    }

    while (true) {
        cout << ">>> ";
        cin >> query;
        if (cin.eof()) {
            cout << endl;
            break;
        }

        auto it = commands.find(query);
        if (it != commands.end()) {
            it->second.action();
        } else {
            cout << "invalid command" << endl << endl;
            auto help_action = commands.find("help");
            if (help_action != commands.end()) {
                help_action->second.action();
            }
        }
    }

    return 0;
}
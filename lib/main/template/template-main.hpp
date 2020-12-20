#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>

struct Command {
    std::string description;
    std::function<void()> action;
};

void setup(
    std::string& header,
    std::map<std::string,Command>& commands
);

void print_help(std::string& header, std::map<std::string,Command>& commands) {
    std::cout << header << std::endl;
    std::cout << "commands:" << std::endl;
    for (auto it = commands.begin(); it != commands.end(); ++it) {
        std::cout << "  * " << it->second.description << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::string query;
    std::string header;
    std::map<std::string,Command> commands;
    
    setup(header, commands);
    if (commands.find("help") == commands.end()) {
        commands["help"] = Command { "help", bind(print_help, header, commands) };
    }

    while (true) {
        std::cout << ">>> ";
        std::cin >> query;
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }

        auto it = commands.find(query);
        if (it != commands.end()) {
            it->second.action();
        } else {
            std::cout << "invalid command" << std::endl << std::endl;
            auto help_action = commands.find("help");
            if (help_action != commands.end()) {
                help_action->second.action();
            }
        }
    }

    return 0;
}
#include <iostream>
#include "../template-main.hpp"
#include "./minimum-stack.hpp"

using namespace std;

MinimumStack<int> minstack;

void action_init() {
    minstack = MinimumStack<int>();
}

void action_push() {
    int value;
    cin >> value;
    minstack.push(value);
}

void action_pop() {
    if (minstack.empty()) return;
    minstack.pop();
}

void action_top() {
    if (minstack.empty()) return;
    cout << minstack.top() << endl;
}

void action_minimum() {
    if (minstack.empty()) return;
    cout << minstack.minimum() << endl;
}


void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Stack";
    commands["init"] = { "init", action_init };
    commands["push"] = { "push {value}", action_push };
    commands["pop"] = { "pop", action_pop };
    commands["top"] = { "top", action_top };
    commands["min"] = { "min", action_minimum };
}
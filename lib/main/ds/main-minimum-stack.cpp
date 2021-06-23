#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/ds/minimum_stack.hpp"

using namespace std;

MinMaxStack<int> minmax_stack;

void action_init() {
    minmax_stack = MinMaxStack<int>();
}

void action_push() {
    int value;
    cin >> value;
    minmax_stack.push(value);
}

void action_pop() {
    if (minmax_stack.empty()) return;
    minmax_stack.pop();
}

void action_top() {
    if (minmax_stack.empty()) return;
    cout << minmax_stack.top() << endl;
}

void action_minimum() {
    if (minmax_stack.empty()) return;
    cout << minmax_stack.minimum() << endl;
}

void action_maximum() {
    if (minmax_stack.empty()) return;
    cout << minmax_stack.maximum() << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Stack";
    commands["init"] = { "init", action_init };
    commands["push"] = { "push {value}", action_push };
    commands["pop"] = { "pop", action_pop };
    commands["top"] = { "top", action_top };
    commands["min"] = { "min", action_minimum };
    commands["max"] = { "max", action_maximum };
}
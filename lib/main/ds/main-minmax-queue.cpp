#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/ds/minmax_queue.hpp"

using namespace std;

MinMaxQueue<int> minmax_queue;

void action_init() {
    minmax_queue = MinMaxQueue<int>();
}

void action_push() {
    int value;
    cin >> value;
    minmax_queue.push(value);
}

void action_pop() {
    if (minmax_queue.empty()) return;
    minmax_queue.pop();
}

void action_front() {
    if (minmax_queue.empty()) return;
    cout << minmax_queue.front() << endl;
}

void action_back() {
    if (minmax_queue.empty()) return;
    cout << minmax_queue.back() << endl;
}

void action_minimum() {
    if (minmax_queue.empty()) return;
    cout << minmax_queue.minimum() << endl;
}

void action_maximum() {
    if (minmax_queue.empty()) return;
    cout << minmax_queue.maximum() << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Stack";
    commands["init"] = { "init", action_init };
    commands["push"] = { "push {value}", action_push };
    commands["pop"] = { "pop", action_pop };
    commands["front"] = { "front", action_front };
    commands["back"] = { "back", action_back };
    commands["min"] = { "min", action_minimum };
    commands["max"] = { "max", action_maximum };
}
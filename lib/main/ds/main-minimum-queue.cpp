#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/ds/minimum-queue.hpp"

using namespace std;

MinimumQueue<int> minqueue;

void action_init() {
    minqueue = MinimumQueue<int>();
}

void action_push_back() {
    int value;
    cin >> value;
    minqueue.push_back(value);
}

void action_pop_front() {
    if (minqueue.empty()) return;
    minqueue.pop_front();
}

void action_front() {
    if (minqueue.empty()) return;
    cout << minqueue.front() << endl;
}

void action_back() {
    if (minqueue.empty()) return;
    cout << minqueue.back() << endl;
}

void action_minimum() {
    if (minqueue.empty()) return;
    cout << minqueue.minimum() << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Stack";
    commands["init"] = { "init", action_init };
    commands["push"] = { "push {value}", action_push_back };
    commands["pop"] = { "pop", action_pop_front };
    commands["front"] = { "front", action_front };
    commands["back"] = { "back", action_back };
    commands["min"] = { "min", action_minimum };
}
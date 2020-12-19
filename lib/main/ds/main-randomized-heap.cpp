#include <iostream>
#include "template/template-main.hpp"
#include "cpalgo/ds/randomized-heap.hpp"

using namespace std;

Heap<int> heap;

void action_init() {
    heap = Heap<int>();
}

void action_insert() {
    int value;
    cin >> value;
    heap.insert(value);
}

void action_top() {
    if (heap.empty()) {
        return;
    }
    cout << heap.top() << endl;
}

void action_pop() {
    if (heap.empty()) {
        cout << "false" << endl;
        return;
    }
    heap.pop();
    cout << "true" << endl;
}

void action_merge() {
    int size;
    cin >> size;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    auto other = Heap<int>();
    for (int i = 0; i < size; ++i) {
        int value;
        cin >> value;
        other.insert(value);
    }
    heap.merge(other);
    cout << "true" << endl;
}

void action_update() {
    int value;
    cin >> value;
    heap.update(value);
}

void setup(string& header, map<string,Command>& commands) {
    header = "Heap";
    commands["init"] = { "init", action_init };
    commands["insert"] = { "insert {value}", action_insert };
    commands["top"] = { "top", action_top };
    commands["pop"] = { "pop", action_pop };
    commands["merge"] = { "merge {size} {...}", action_merge };
    commands["update"] = { "update {value}", action_update };
}
#include <iostream>
#include <algorithm>
#include <numeric>
#include "cpalgo/ds/implicit-treap.hpp"
#include "template/template-main.hpp"

using namespace std;

struct Data {
    int value, minimum;
    Data() {}
    Data(int value): value(value), minimum(value) {}
};
struct Query {
    const Data id = Data(numeric_limits<int>::max());
    Data operator()(const Data& node, const Data& lhs, const Data& rhs) const {
        Data ans;
        ans.value = node.value;
        ans.minimum = min({ node.value, lhs.minimum, rhs.minimum });
        return ans;
    };
};
struct Update {
    Data operator()(const Data& lhs, const int& value) const {
        Data ans;
        ans.value = lhs.value + value;
        ans.minimum = lhs.minimum + value;
        return ans;
    };
};
struct Lazy {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};

auto Q = Query(); auto U = Update(); auto L = Lazy();
ImplicitTreap<Data,int> treap(Q, U, L);
vector<Data> buffer;

void action_insert() {
    int pos, value;
    cin >> pos >> value;
    treap.insert(pos, Data(value));
}

void action_add() {
    int l, r, value;
    cin >> l >> r >> value;
    treap.update(l, r, value);
}

void action_min() {
    int l, r;
    Data value;
    cin >> l >> r;
    bool ans = treap.query(l, r, value);
    if (ans) {
        cout << value.minimum << endl;
    }
}

void action_erase() {
    int pos;
    cin >> pos;
    int ans = treap.erase(pos);
    cout << (ans ? "true" : "false") << endl;
}

void action_at() {
    int pos, value;
    cin >> pos;
    if (pos < 0 || pos >= treap.size()) {
        return;
    }
    cout << treap[pos].value << endl;
}

void action_reverse() {
    int l, r;
    cin >> l >> r;
    treap.reverse(l, r);
}

void action_rotate() {
    int l, m, r;
    cin >> l >> m >> r;
    treap.rotate(l, m, r);
}

void action_count() {
    int l, r;
    cin >> l >> r;
    int ans = treap.count(l, r);
    cout << ans << endl;
}

void action_dump() {
    treap.dump(buffer);
    for (auto it = buffer.begin(); it != buffer.end(); it++) {
        if (it != buffer.begin()) cout << " ";
        cout << it->value;
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    commands["insert"] = { "insert {pos} {value}", action_insert };
    commands["add"] = { "add {left} {right} {value}", action_add };
    commands["min"] = { "min {left} {right}", action_min };
    commands["erase"] = { "erase {pos}", action_erase };
    commands["at"] = { "at {pos}", action_at };
    commands["reverse"] = { "reverse {left} {right}", action_reverse };
    commands["rotate"] = { "rotate {left} {middle} {right}", action_rotate };
    commands["count"] = { "count {left} {right}", action_count };
    commands["dump"] = { "dump", action_dump };
}
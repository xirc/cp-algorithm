#include <iostream>
#include <string>
#include <vector>
#include "cpalgo/ds/treap.hpp"
#include "template/template-main.hpp"

using namespace std;

struct Data {
    int value, count, sum;
    Data(): value(0), count(0), sum(0) {}
    Data(int value): value(value), count(1), sum(value) {}
    bool operator<(const Data other) const {
        return value < other.value;
    }
};
string to_string(const Data& value) {
    return "(" + to_string(value.value) + "," + to_string(value.count) + "," + to_string(value.sum) + ")";
}
struct Query {
    const Data id = Data();
    Data operator()(const Data& node, const Data& lhs, const Data& rhs) const {
        Data ans;
        ans.value = node.value;
        ans.count = 1 + lhs.count + rhs.count;
        ans.sum = node.value + lhs.sum + rhs.sum;
        return ans;
    }
};
struct Update {
    Data operator()(const Data& lhs, const int& rhs) const {
        Data ans;
        ans.value = lhs.value + rhs;
        ans.count = lhs.count;
        ans.sum = lhs.sum + rhs * lhs.count;
        return ans;
    }
};
struct Lazy {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};

auto Q = Query(); auto U = Update(); auto L = Lazy();
Treap<Data,int> treap(Q,U,L);
vector<Data> buffer;

void action_insert() {
    int value;
    cin >> value;
    treap.insert(Data(value));
}

void action_erase() {
    int value;
    cin >> value;
    int ans = treap.erase(Data(value));
    cout << (ans ? "true" : "false") << endl;
}

void action_find() {
    int value;
    cin >> value;
    bool ans = treap.find(Data(value));
    cout << (ans ? "true" : "false") << endl;
}

void action_query() {
    int l, r;
    cin >> l >> r;
    auto ans = treap.query(l, r);
    cout << to_string(ans) << endl;
}

void action_update() {
    int l, r, x;
    cin >> l >> r >> x;
    auto ans = treap.update(l, r, x);
    cout << (ans ? "true" : "false") << endl;
}

void action_dump() {
    treap.dump(buffer);
    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        if (it != buffer.begin()) cout << " ";
        cout << to_string(*it);
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    commands["insert"] = { "insert {value}", action_insert };
    commands["erase"] = { "erase {value}", action_erase };
    commands["find"] = { "find {value}", action_find };
    commands["query"] = { "query {l} {r}", action_query };
    commands["update"] = { "update {l} {r} {x}", action_update };
    commands["dump"] = { "dump", action_dump };
}
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include "treap.hpp"
#include "../template-main.hpp"

using namespace std;

struct Data {
    int value;
    int count;
    bool operator<(const Data& other) {
        return value < other.value;
    }
    bool operator==(const Data& other) {
        return value == other.value;
    }
};

class Treap : public TreapBase<Data> {
public:
    int count() {
        return count(root);
    }
protected:
    void pushup(Tree tree) override {
        TreapBase::pushup(tree);
        update_count(tree);
    }
    int count(Tree tree) {
        return tree ? tree->key.count : 0;
    }
    void update_count(Tree tree) {
        if (tree) {
            tree->key.count = 1 + count(tree->left) + count(tree->right);
        }
    }
};

Treap treap;
vector<Data> buffer;

void action_insert() {
    int value;
    cin >> value;
    treap.insert(Data { value, 1 });
}

void action_erase() {
    int value;
    cin >> value;
    int ans = treap.erase(Data { value, 1 });
    cout << (ans ? "true" : "false") << endl;
}

void action_find() {
    int value;
    cin >> value;
    bool ans = treap.find(Data { value, 1 });
    cout << (ans ? "true" : "false") << endl;
}

void action_size() {
    int ans = treap.count();
    cout << ans << endl;
}

void action_dump() {
    treap.dump(buffer);

    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        if (it != buffer.begin()) cout << " ";
        cout << it->value;
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    commands["insert"] = 
        Command { "insert {value}", action_insert };
    commands["erase"] =
        Command { "erase {value}", action_erase };
    commands["find"] =
        Command { "find {value}", action_find };
    commands["size"] =
        Command { "size", action_size };
    commands["dump"] = 
        Command { "dump", action_dump };
}
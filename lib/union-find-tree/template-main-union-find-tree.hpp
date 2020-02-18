#pragma once

#include <iostream>
#include <functional>
#include <map>
#include <string>
#include "../template-main.hpp"

template <class UnionFindTree, class Repr>
class UnionFindTreeInterp {
    using Tree = std::shared_ptr<UnionFindTree>;
    Tree tree = Tree(new UnionFindTree(0));
public:
    void action_init() {
        int size;
        cin >> size;
        if (size < 0) {
            cout << "false" << endl;
            return;
        }
        tree = Tree(new UnionFindTree(size));
        cout << "true" << endl;
    }
    void action_find() {
        int index;
        cin >> index;
        if (index < 0 || index >= tree->size()) {
            cout << -1 << endl;
            return;
        }
        auto ans = tree->find_set(index);
        cout << Repr::to_string(ans) << endl;
    }
    void action_union() {
        int index1, index2;
        cin >> index1 >> index2;
        if (index1 < 0 || index1 >= tree->size()) {
            cout << "false" << endl;
            return;
        }
        if (index2 < 0 || index2 >= tree->size()) {
            cout << "false" << endl;
            return;
        }
        tree->union_set(index1, index2);
        cout << "true" << endl;
    }
    void action_dump() {
        for (int i = 0; i < tree->size(); ++i) {
            if (i != 0) cout << " ";
            auto value = tree->find_set(i);
            cout << Repr::to_string(value);
        }
        cout << endl;
    }
};

template <class UnionFindTreeInterp>
void setup(UnionFindTreeInterp* repr, std::string& header, std::map<std::string,Command>& commands) {
    header = "Union Find Tree";
    using clazz = UnionFindTreeInterp;
    commands["init"] = Command { "init {size}", bind(&clazz::action_init, repr) };
    commands["find"] = Command { "find {index}", bind(&clazz::action_find, repr) };
    commands["union"] = Command { "union {index1} {index2}", bind(&clazz::action_union, repr) };
    commands["dump"] = Command { "dump", bind(&clazz::action_dump, repr) };
}
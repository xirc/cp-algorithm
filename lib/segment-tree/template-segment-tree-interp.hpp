#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <random>
#include "../template-main.hpp"

using namespace std;

template<class T, class SegmentTree>
class SegmentTreeInterpBase {
protected:
    SegmentTree m_tree = SegmentTree(8);
    vector<T> m_buffer;

protected:
    virtual T make_value(int value) = 0;
    virtual string repr_value(T value) = 0;

public:
    void action_build() {
        int n, v;
        cin >> n;
        vector<T> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> v;
            array[i] = make_value(v);
        }
        m_tree.build(array);
    }

    void action_random() {
        int n, min, max, v;
        cin >> n >> min >> max;
        random_device random;
        vector<T> array(n);
        for (int i = 0; i < n; ++i) {
            v = (random() % std::abs(max-min)) + std::min(max,min);
            array[i] = make_value(v);
        }
        m_tree.build(array);
    }

    void action_dump() {
        m_tree.dump(m_buffer);

        auto it = m_buffer.begin();
        if (it != m_buffer.end()) {
            cout << repr_value(*it);
            it++;
        }
        for (; it != m_buffer.end(); ++it) {
            cout << " " << repr_value(*it);
        }
        cout << endl;
    }
};

template<class SegmentTreeInterp>
void setup(
    SegmentTreeInterp* interp,
    string& header,
    map<string,Command>& commands
) {
    using clazz = SegmentTreeInterp;

    header = "Segment Tree";
    commands["build"] =
        Command { "build {count} {...}", bind(&clazz::action_build, interp) };
    commands["random"] =
        Command { "random {count} {min} {max}", bind(&clazz::action_random, interp) };
    commands["dump"] =
        Command { "dump", bind(&clazz::action_dump, interp) };
}
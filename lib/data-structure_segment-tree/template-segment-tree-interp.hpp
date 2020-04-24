#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <memory>
#include "../template-main.hpp"

template<class SegmentTree>
class SegmentTreeInterpBase {
public:
    using T = typename SegmentTree::value_type_T;
    using E = typename SegmentTree::value_type_E;

protected:
    std::shared_ptr<SegmentTree> m_tree = nullptr;

public:
    SegmentTreeInterpBase(std::shared_ptr<SegmentTree> tree): m_tree(tree) {
        // Do nothing
    }
    void action_build() {
        int n, v;
        std::cin >> n;
        std::vector<T> array(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> v;
            array[i] = T(v);
        }
        m_tree->build(array);
    }

    void action_random() {
        int n, min, max, v;
        std::cin >> n >> min >> max;
        std::random_device random;
        std::vector<T> array(n);
        for (int i = 0; i < n; ++i) {
            v = (random() % std::abs(max-min)) + std::min(max,min);
            array[i] = T(v);
        }
        m_tree->build(array);
    }

    void action_dump() {
        std::vector<T> buffer;
        m_tree->dump(buffer);
        for (auto it = buffer.begin(); it != buffer.end(); ++it) {
            if (it != buffer.begin()) std::cout << " ";
            std::cout << to_string(*it);
        }
        std::cout << std::endl;
    }
};

template<class SegmentTreeInterp>
void setup(
    SegmentTreeInterp* interp,
    std::string& header,
    std::map<std::string,Command>& commands
) {
    using clazz = SegmentTreeInterp;

    header = "Segment Tree";
    commands["build"] = { "build {count} {...}", std::bind(&clazz::action_build, interp) };
    commands["random"] = { "random {count} {min} {max}", std::bind(&clazz::action_random, interp) };
    commands["dump"] = { "dump", std::bind(&clazz::action_dump, interp) };
}
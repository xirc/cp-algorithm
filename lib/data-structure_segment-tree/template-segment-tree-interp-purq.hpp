#pragma once

#include <string>
#include "template-segment-tree-interp.hpp"

template <class T, class SegmentTree, class Value>
class SegmentTreeInterpPURQ
    : public SegmentTreeInterpBase<T,SegmentTree>
{
protected:
    T make_value(int value) {
        return Value::make_value(value);
    }
    std::string repr_value(T value) {
        return Value::repr_value(value);
    }
public:
    void action_query() {
        int l, r;
        std::cin >> l >> r;
        auto ans = this->m_tree.query(l, r);
        std::cout << repr_value(ans) << std::endl;
    }
    void action_update() {
        int i, v;
        std::cin >> i >> v;
        bool ans = this->m_tree.update(i, make_value(v));
        std::cout << (ans ? "true" : "false") << std::endl;
    }
};
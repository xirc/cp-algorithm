#pragma once

#include <string>
#include "template-segment-tree-interp.hpp"

template <class SegmentTree, class Query, class Update>
class SegmentTreeInterpPURQ
    : public SegmentTreeInterpBase<SegmentTree>
{
public:
    using T = typename SegmentTree::value_type_T;
    using E = typename SegmentTree::value_type_E;
    SegmentTreeInterpPURQ()
        : SegmentTreeInterpBase<SegmentTree>(std::shared_ptr<SegmentTree>(
            new SegmentTree(0, Query(), Update())
        ))
    {}
    void action_query() {
        int l, r;
        std::cin >> l >> r;
        auto ans = this->m_tree->query(l, r);
        std::cout << to_string(ans) << std::endl;
    }
    void action_update() {
        int i, v;
        std::cin >> i >> v;
        bool ans = this->m_tree->update(i, E(v));
        std::cout << (ans ? "true" : "false") << std::endl;
    }
};
// Range Update & Range Query
// Range Update: add a number to all numbers in the segments 'array[l,r)'
// Range Query: Finding the max in the segments 'array[l,r)'

#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include "segment-tree-rurq.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Query {
    const int id = numeric_limits<int>::lowest();
    int operator()(const int& lhs, const int& rhs) const {
        return max(lhs,rhs);
    }
};
struct Update {
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};
struct Lazy {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTree<int,int>>
{
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase<SegmentTree<int,int>>(
            std::shared_ptr<SegmentTree<int,int>>(
                new SegmentTree<int,int>(0, Query(), Update(), Lazy())
            )
        )
    {}
    void action_query() {
        int l, r;
        cin >> l >> r;
        auto ans = m_tree->query(l, r);
        cout << to_string(ans) << endl;
    }
    void action_update() {
        int l, r, v;
        cin >> l >> r >> v;
        m_tree->update(l, r, E(v));
    }
    string to_string(const int& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
// Finding the smallest number greater or equal to a specified number

#include <string>
#include <algorithm>
#include <map>
#include <set>
#include "segment-tree-vector.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Query {
    const int id = 0;
    int operator()(multiset<int>& set, int x) const {
        auto it = set.lower_bound(x);
        if (it == set.end()) {
            return INT_MAX;
        }
        return *it;
    }
    int operator()(int lhs, int rhs) const {
        return min(lhs, rhs);
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTree<int>>
{
protected:
    int make_value(const int& value) {
        return value;
    }
    string repr_value(const int& value) {
        return to_string(value);
    }
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase<SegmentTree<int>>(
            std::shared_ptr<SegmentTree<int>>(new SegmentTree<int>(0))
        )
    {}
    void action_query() {
        int l, r, x;
        cin >> l >> r >> x;
        auto ans = m_tree->query(l, r, x, Query());
        cout << repr_value(ans) << endl;
    }
    void action_update() {
        int i, v;
        cin >> i >> v;
        bool ans = m_tree->update(i, make_value(v));
        cout << (ans ? "true" : "false") << endl;
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {left} {right} {value}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
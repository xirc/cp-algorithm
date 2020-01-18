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
    static int id() {
        return INT_MAX;
    }
    static int op(multiset<int>& set, int x) {
        auto it = set.lower_bound(x);
        if (it == set.end()) {
            return INT_MAX;
        }
        return *it;
    }
    static int op(int lhs, int rhs) {
        return min(lhs, rhs);
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<int,SegmentTree<int>>
{
protected:
    int make_value(int value) {
        return value;
    }
    string repr_value(int value) {
        return to_string(value);
    }
public:
    void action_query() {
        int l, r, x;
        cin >> l >> r >> x;
        auto ans = m_tree.query<Query>(l, r, x);
        cout << repr_value(ans) << endl;
    }
    void action_update() {
        int i, v;
        cin >> i >> v;
        bool ans = m_tree.update(i, make_value(v));
        cout << (ans ? "true" : "false") << endl;
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {left} {right} {value}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
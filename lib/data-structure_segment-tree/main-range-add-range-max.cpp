// Range Update & Range Query
// Range Update: add a number to all numbers in the segments 'array[l,r)'
// Range Query: Finding the max in the segments 'array[l,r)'

#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include "segment-tree-rurq.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Data {
    int max;
    int lazy;
    Data() {}
    Data(int max): Data(max, 0) {}
    Data(int max, int lazy): max(max), lazy(lazy) {}
};
struct Query {
    static Data id() {
        return Data(INT_MIN);
    }
    static Data op(const Data& lhs, const Data& rhs) {
        return Data(std::max(lhs.max,rhs.max));
    }
};
struct Update {
    static Data id() {
        return Data(0);
    }
    static Data op(const Data& lhs, const Data& rhs) {
        int max = lhs.max + rhs.max + rhs.lazy;
        int lazy = lhs.lazy + rhs.max + rhs.lazy;
        return Data(max, lazy);
    }
};
struct Push {
    static void pushdown(Data& node, Data& lhs, Data& rhs) {
        lhs.max += node.lazy;
        lhs.lazy += node.lazy;
        rhs.max += node.lazy;
        rhs.lazy += node.lazy;
        node.lazy = 0;
    }
};
using SegmentTreeImpl = SegmentTree<Data,Query,Update,Push>;

class SegmentTreeInterp
    : public SegmentTreeInterpBase<Data,SegmentTreeImpl>
{
protected:
    Data make_value(int value) {
        return Data(value);
    }
    string repr_value(Data value) {
        return to_string(value.max);
    }

public:
    void action_query() {
        int l, r;
        cin >> l >> r;
        auto ans = m_tree.query(l, r);
        cout << repr_value(ans) << endl;
    }
    void action_update() {
        int l, r, v;
        cin >> l >> r >> v;
        m_tree.update(l, r, make_value(v));
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
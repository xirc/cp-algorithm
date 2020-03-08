// Range Update & Point Query
// Range Update: assign each element of a certain segment 'array[l,r)'
// Point Query: ask what is the value of 'array[i]'

#include <map>
#include <string>
#include "segment-tree-rupq.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Data {
    bool mark;
    int value;
    Data(): mark(false), value(0) {}
    Data(int value): mark(true), value(value) {}
};
struct Update {
    static Data id() {
        return Data();
    }
    static Data op(const Data& lhs, const Data& rhs) {
        return rhs;
    }
};
struct Push {
    static void pushdown(Data &node, Data& lhs, Data& rhs) {
        if (!node.mark) {
            return;
        }
        lhs = rhs = node;
        node = Data();
    }
};
using SegmentTreeImpl = SegmentTree<Data,Update,Push>;

class SegmentTreeInterp
    : public SegmentTreeInterpBase<Data,SegmentTreeImpl>
{
protected:
    Data make_value(int value) {
        return Data(value);
    }
    string repr_value(Data value) {
        return to_string(value.value);
    }

public:
    void action_query() {
        int x;
        cin >> x;
        auto ans = m_tree.query(x);
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
        Command { "query {index}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
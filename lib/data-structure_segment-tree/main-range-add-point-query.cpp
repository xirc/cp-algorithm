// Range Update & Point Query
// Range Update: add a number to all numbers in the segments 'array[l,r)'
// Point Query: ask what is the value of 'array[i]'

#include <map>
#include <string>
#include "segment-tree-rupq.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Update {
    static constexpr int id() {
        return 0;
    }
    static int op(const int& lhs, const int& rhs) {
        return lhs + rhs;
    }
};
struct Push {
    static void pushdown(int& node, int& lhs, int& rhs) {
        lhs += node;
        rhs += node;
        node = 0;
    }
};
using SegmentTreeImpl = SegmentTree<int,Update,Push>;

class SegmentTreeInterp
    : public SegmentTreeInterpBase<int,SegmentTreeImpl>
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
        int x;
        cin >> x;
        auto ans = m_tree.query(x);
        cout << repr_value(ans) << endl;
    }
    void action_update() {
        int l, r, v;
        cin >> l >> r >> v;
        m_tree.update(l, r, v);
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
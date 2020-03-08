// Finding the sum

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Sum {
    static constexpr int id() {
        return 0;
    }
    static constexpr int op(int lhs, int rhs) {
        return lhs + rhs;
    }
};
struct Assign {
    static constexpr int id() {
        return 0;
    }
    static int op(int lhs, int rhs) {
        return rhs;
    }
};
using SegmentTreeImpl = SegmentTree<int,Sum,Assign>;

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
        int l, r;
        cin >> l >> r;
        auto ans = m_tree.query(l, r);
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
        Command {"query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
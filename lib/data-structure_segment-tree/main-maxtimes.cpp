// Finding the maximum and the number of times it appears

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

using pii = pair<int,int>;

struct MaxTimes {
    static constexpr pii id() {
        return {0, 0};
    }
    static pii op(pii lhs, pii rhs) {
        if (lhs.first > rhs.first) {
            return lhs;
        } else if (lhs.first < rhs.first) {
            return rhs;
        } else {
            return { lhs.first, lhs.second + rhs.second };
        }
    }
};
struct Assign {
    static constexpr pii id() {
        return { 0, 0 };
    }
    static pii op(pii lhs, pii rhs) {
        return rhs;
    }
};
using SegmentTreeImpl = SegmentTree<pii,MaxTimes,Assign>;

class SegmentTreeInterp
    : public SegmentTreeInterpBase<pii,SegmentTreeImpl>
{
protected:
    pii make_value(int value) {
        return { value, 1 };
    }
    string repr_value(pii value) {
        return "(" + to_string(value.first) + "," + to_string(value.second) + ")";
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
void setup(string &header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
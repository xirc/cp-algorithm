// Searching for an array prefix with a given amount
//
// find smallest index 'i' such that 
// the sum of first 'i' elements of the array is greather or equal to 'x'.
// 
// Note: the array only contains non-negative values

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Sum {
    static int id() {
        return 0;
    }
    static int op(int lhs, int rhs) {
        return lhs + rhs;
    }
};

class SegmentTreeImpl : public SegmentTree<int, Sum>
{
public:
    SegmentTreeImpl(int n): SegmentTree(n) {}

    int query(int x) {
        if (x < 0) {
            return -1;
        }
        return query(0, 0, m_size, x);
    }
protected:
    int query(int v, int tl, int tr, int x) {
        if (tr - tl <= 0 || x > m_tree[v]) {
            return -1;
        }
        if (tr - tl == 1) {
            return tl;
        }
        int tm = (tl + tr) / 2;
        int vl = left(v), vr = right(v);
        if (m_tree[vl] >= x) {
            return query(vl, tl, tm, x);
        } else {
            return query(vr, tm, tr, x - m_tree[vl]);
        }
    }
};

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
        int k;
        cin >> k;
        int ans = m_tree.query(k);
        cout << ans << endl;
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
        Command { "query {kth}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
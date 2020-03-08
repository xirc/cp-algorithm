// Counting the number of zeros, searching for the k-th zero

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

using pii = pair<int,int>;

struct SumZero {
    static pii id() {
        return { !0, 0 };
    }
    static pii op(pii lhs, pii rhs) {
        return { !0, lhs.second + rhs.second };
    }
};
struct Assign {
    static pii id() {
        return { !0, 0 };
    }
    static pii op(pii lhs, pii rhs) {
        return rhs;
    }
};

class SegmentTreeImpl : public SegmentTree<pii,SumZero,Assign>
{
public:
    SegmentTreeImpl(int n): SegmentTree(n) {}

    // find the k-th zero (k is [0,...]
    int query(int k) {
        if (k < 0) {
            return -1;
        }
        return query(0, 0, m_size, k + 1);
    }

protected:
    int query(int v, int tl, int tr, int k) {
        if (tr - tl <= 0 || k > m_tree[v].second) {
            return -1;
        }
        if (tr - tl == 1) {
            return tl;
        }
        int tm = (tl + tr) / 2;
        int vl = left(v), vr = right(v);
        if (m_tree[vl].second >= k) {
            return query(vl, tl, tm, k);
        } else {
            return query(vr, tm, tr, k - m_tree[vl].second);
        }
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<pii,SegmentTreeImpl>
{
protected:
    pii make_value(int value) {
        return { value, value ? 0 : 1 };
    }
    string repr_value(pii value) {
        return to_string(value.first);
    }
public:
    void action_query() {
        int k;
        cin >> k;
        auto ans = m_tree.query(k);
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
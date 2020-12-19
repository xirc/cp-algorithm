// Searching for an array prefix with a given amount
//
// find smallest index 'i' such that 
// the sum of first 'i' elements of the array is greather or equal to 'x'.
// 
// Note: the array only contains non-negative values

#include <map>
#include <string>
#include "cpalgo/ds/segment-tree.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Query {
    const int id = 0;
    int operator()(int lhs, int rhs) const {
        return lhs + rhs;
    }
};
struct Update {
    int operator()(int lhs, int rhs) const {
        return rhs;
    }
};

class SegmentTreeImpl : public SegmentTree<int,int>
{
public:
    SegmentTreeImpl(int n): SegmentTree(n, Query(), Update()) {}

    int query(int x) {
        if (x < 0) {
            return -1;
        }
        return query(0, 0, N, x);
    }
protected:
    int query(int v, int tl, int tr, int x) {
        if (tr - tl <= 0 || x > tree[v]) {
            return -1;
        }
        if (tr - tl == 1) {
            return tl;
        }
        int tm = (tl + tr) / 2;
        int vl = left(v), vr = right(v);
        if (tree[vl] >= x) {
            return query(vl, tl, tm, x);
        } else {
            return query(vr, tm, tr, x - tree[vl]);
        }
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTreeImpl>
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
        : SegmentTreeInterpBase(
            std::shared_ptr<SegmentTreeImpl>(new SegmentTreeImpl(0))
        )
    {}
    void action_query() {
        int k;
        cin >> k;
        int ans = m_tree->query(k);
        cout << ans << endl;
    }
    void action_update() {
        int i, v;
        cin >> i >> v;
        bool ans = m_tree->update(i, make_value(v));
        cout << (ans ? "true" : "false") << endl;
    }
    string to_string(const int& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {x}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
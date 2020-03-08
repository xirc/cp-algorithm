// Searching for the first element greater than a given amount

#include <algorithm>
#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Maximum {
    static constexpr int id() {
        return INT_MIN;
    }
    static int op(int lhs, int rhs) {
        return std::max(lhs, rhs);
    }
};
struct Assign {
    static constexpr int id() {
        return INT_MIN;
    };
    static int op(int lhs, int rhs) {
        return rhs;
    }
};

class SegmentTreeImpl : public SegmentTree<int,Maximum,Assign> {
public:
    SegmentTreeImpl(int n): SegmentTree(n) {}

    int query(int l, int r, int x) {
        return query(0, 0, m_size, l, r, x);
    }

protected:
    int query(int v, int lv, int rv, int l, int r, int x) {
        if (lv >= r || rv <= l) {
            return -1;
        }
        if (l <= lv && rv <= r) {
            if (m_tree[v] <= x){
                return -1;
            }
            while (rv - lv > 1) {
                const int mv = lv + (rv - lv) / 2;
                if (m_tree[left(v)] > x) {
                    v = left(v);
                    rv = mv;
                } else {
                    v = right(v);
                    lv = mv;
                }
            }
            return lv;
        }

        const int mv = lv + (rv - lv) / 2;
        const int ans = query(left(v), lv, mv, l, r, x);
        if (ans != -1) {
            return ans;
        }
        return query(right(v), mv, rv, l, r, v);
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
        int l, r, x;
        cin >> l >> r >> x;
        auto ans = m_tree.query(l, r, x);
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
        Command {"query {left} {right} {value}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
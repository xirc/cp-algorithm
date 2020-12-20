// Counting the number of zeros, searching for the k-th zero

#include <map>
#include <string>
#include "cpalgo/ds/segment-tree.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Data {
    int value;
    int times;
    Data(): value(0), times(0) {}
    Data(int value): value(value), times(!value) {}
};

struct Query {
    const Data id = Data();
    Data operator()(const Data& lhs, const Data& rhs) const {
        Data ans;
        ans.value = lhs.value + rhs.value;
        ans.times = lhs.times + rhs.times;
        return ans;
    }
};
struct Update {
    Data operator()(const Data& lhs, int rhs) const {
        return Data(rhs);
    }
};

class SegmentTreeImpl : public SegmentTree<Data,int>
{
public:
    SegmentTreeImpl(int n): SegmentTree(n, Query(), Update()) {}

    // find the k-th zero (k is [0,...)
    int query(int k) {
        if (k < 0) {
            return -1;
        }
        return query(0, 0, N, k + 1);
    }

protected:
    int query(int v, int tl, int tr, int k) {
        if (tr - tl <= 0 || k > tree[v].times) {
            return -1;
        }
        if (tr - tl == 1) {
            return tl;
        }
        int tm = (tl + tr) / 2;
        int vl = left(v), vr = right(v);
        if (tree[vl].times >= k) {
            return query(vl, tl, tm, k);
        } else {
            return query(vr, tm, tr, k - tree[vl].times);
        }
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTreeImpl>
{
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase<SegmentTreeImpl>(
            std::shared_ptr<SegmentTreeImpl>(new SegmentTreeImpl(0))
        )
    {}
    void action_query() {
        int k;
        cin >> k;
        auto ans = m_tree->query(k);
        cout << ans << endl;
    }
    void action_update() {
        int i, v;
        cin >> i >> v;
        bool ans = m_tree->update(i, E(v));
        cout << (ans ? "true" : "false") << endl;
    }
    string to_string(const Data& value) override {
        return "(" + to_string(value.value) + "," + to_string(value.times) + ")";
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {kth}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
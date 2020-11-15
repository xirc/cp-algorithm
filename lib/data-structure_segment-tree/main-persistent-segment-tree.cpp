// Finding the sum with persistent segment tree

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "persistent-segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Query {
    long long id = 0;
    long long operator()(long long lhs, long long rhs) const {
        return lhs + rhs;
    }
};
struct Update {
    long long operator()(long long lhs, int rhs) const {
        return lhs + rhs;
    }
};
struct Lazy {
    const int id = 0;
    int operator()(int lhs, int rhs) const {
        return lhs + rhs;
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTree<long long,int>>
{
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase<SegmentTree<long long,int>>(
            std::shared_ptr<SegmentTree<long long,int>>(
                new SegmentTree<long long, int>(0, Query(), Update(), Lazy())
            )
        )
    {}
    void action_dump_history() {
        vector<T> buffer;
        for (int history = m_tree->history_size() - 1; history >= 0; --history) {
            m_tree->dump(buffer, history);
            cout << history << ": ";
            for (int i = 0; i < buffer.size(); ++i) {
                if (i > 0) cout << " ";
                cout << setw(3) << buffer[i];
            }
            cout << endl;
        }
    }
    void action_query() {
        int history, l, r;
        cin >> history >> l >> r;
        auto ans = m_tree->query(l, r, history);
        cout << to_string(ans) << endl;
    }
    void action_update() {
        int history, l, r, v;
        cin >> history >> l >> r >> v;
        auto ans = m_tree->update(l, r, E(v), history);
        cout << (ans ? "true" : "false") << endl;
    }
    string to_string(const long long& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {history} {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {history} {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
    commands["dump"] = { "dump", bind(&SegmentTreeInterp::action_dump_history, interp) }; // Overwrite
}
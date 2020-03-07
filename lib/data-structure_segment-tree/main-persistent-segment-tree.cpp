// Finding the sum with persistent segment tree

#include <map>
#include <string>
#include "persistent-segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

class SegmentTreeInterp
    : public SegmentTreeInterpBase<int,SegmentTree>
{
protected:
    int make_value(int value) {
        return value;
    }
    string repr_value(int value) {
        return to_string(value);
    }
public:
    void action_dump_history() {
        for (int history = m_tree.history_size() - 1; history >= 0; --history) {
            m_tree.dump(m_buffer, history);
            for (int i = 0; i < m_buffer.size(); ++i) {
                if (i > 0) cout << " ";
                cout << m_buffer[i];
            }
            cout << endl;
        }
    }
    void action_query() {
        int history, l, r;
        cin >> history >> l >> r;
        auto ans = m_tree.sum(l, r, history);
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
        Command { "query {history} {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
    commands["dump"] = // overwrite
        Command { "dump", bind(&SegmentTreeInterp::action_dump_history, interp) };
}
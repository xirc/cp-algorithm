// Finding the sum

#include "cpalgo/ds/segment-tree.hpp"
#include "template-segment-tree-interp-purq.hpp"

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
class SegmentTreeInterp : public SegmentTreeInterpPURQ<SegmentTree<int,int>,Query,Update> {
    string to_string(const int& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = {"query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
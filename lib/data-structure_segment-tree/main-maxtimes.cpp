// Finding the maximum and the number of times it appears

#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

struct Data {
    int maximum, times;
    Data(): maximum(0), times(0) {}
    Data(int value): maximum(value), times(1) {}
};
string to_string(const Data& value) {
    return "(" + to_string(value.maximum) + "," + to_string(value.times) + ")";
}

struct Query {
    const Data id = Data();
    Data operator()(const Data& lhs, const Data& rhs) const {
        if (lhs.maximum > rhs.maximum) {
            return lhs;
        } else if (lhs.maximum < rhs.maximum) {
            return rhs;
        } else {
            Data ans;
            ans.maximum = lhs.maximum;
            ans.times = lhs.times + rhs.times;
            return ans;
        }
    }
};
struct Update {
    Data operator()(const Data& lhs, int rhs) const {
        return Data(rhs);
    }
};
using SegmentTreeInterp = SegmentTreeInterpPURQ<SegmentTree<Data,int>,Query,Update>;

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string &header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
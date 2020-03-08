// Finding subsegments with the maximal sum

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

struct Data {
    int sum, prefix, suffix, ans;
    Data() {}
    Data(int value)
        : sum(value)
        , prefix(max(0,value))
        , suffix(max(0,value))
        , ans(max(0,value))
    {
        // Do nothing
    }
};

struct MaxSum {
    static Data id() {
        return Data(0);
    }
    static Data op(Data lhs, Data rhs) {
        Data data;
        data.sum = lhs.sum + rhs.sum;
        data.prefix = max(lhs.prefix, lhs.sum + rhs.prefix);
        data.suffix = max(rhs.suffix, lhs.suffix + rhs.sum);
        data.ans = max(max(lhs.ans,rhs.ans), lhs.suffix + rhs.prefix);
        return data;
    }
};
struct Assign {
    static Data id() {
        return Data(0);
    }
    static Data op(Data lhs, Data rhs) {
        return rhs;
    }
};
using SegmentTreeImpl = SegmentTree<Data,MaxSum,Assign>;

struct Value {
    static Data make_value(int value) {
        return Data(value);
    }
    static string repr_value(Data value) {
        return to_string(value.sum);
    }
};
using SegmentTreeInterp = SegmentTreeInterpPURQ<Data,SegmentTreeImpl,Value>;

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
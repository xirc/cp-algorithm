// Finding subsegments with the maximal sum

#include <map>
#include <string>
#include "cpalgo/ds/segment-tree.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

struct Data {
    int sum, prefix, suffix, maximum;
    Data() {}
    Data(int value)
        : sum(value)
        , prefix(max(0,value))
        , suffix(max(0,value))
        , maximum(max(0,value))
    {
        // Do nothing
    }
};

struct Query {
    const Data id = Data(0);
    Data operator()(Data lhs, Data rhs) const {
        Data data;
        data.sum = lhs.sum + rhs.sum;
        data.prefix = max(lhs.prefix, lhs.sum + rhs.prefix);
        data.suffix = max(rhs.suffix, lhs.suffix + rhs.sum);
        data.maximum = max({ lhs.maximum, rhs.maximum , lhs.suffix + rhs.prefix});
        return data;
    }
};
struct Update {
    Data operator()(Data lhs, int rhs) const {
        return Data(rhs);
    }
};
class SegmentTreeInterp : public SegmentTreeInterpPURQ<SegmentTree<Data,int>,Query,Update> {
    string to_string(const Data& value) override {
        return "(" + to_string(value.sum) + "," + to_string(value.maximum) + ")";
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}
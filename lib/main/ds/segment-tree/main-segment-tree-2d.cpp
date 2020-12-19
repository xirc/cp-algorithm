#include <bits/stdc++.h>
#include "cpalgo/ds/segment-tree-2d.hpp"
#include "template/template-main.hpp"

using namespace std;

struct Data {
    int maximum;
    int times;
    Data(): maximum(numeric_limits<int>::lowest()), times(0) {}
    Data(int value): maximum(value), times(1) {}
};
string to_string(const Data& value) {
    return "(" + to_string(value.maximum) + "," + to_string(value.times) + ")";
}
struct Option {
    bool active;
    int value;
    Option(): active(false), value(0) {}
    Option(int value): active(true), value(value) {}
};
struct Query {
    const Data id = Data();
    Data operator()(const Data& lhs, const Data& rhs) {
        if (lhs.maximum > rhs.maximum) {
            return lhs;
        } else if (rhs.maximum > lhs.maximum) {
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
    Data operator()(const Data& lhs, const Option& rhs) {
        if (!rhs.active) {
            return lhs;
        }
        return Data(rhs.value);
    }
};
SegmentTree<Data,Option> tree(0, 0, Query(), Update());

using row = vector<Data>;
using matrix = vector<row>;

void action_random() {
    int n, m, minv, maxv;
    random_device random;
    cin >> n >> m >> minv >> maxv;

    auto mat = matrix(n, row(m));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            mat[x][y] = Data((random() % abs(maxv - minv)) + minv);
        }
    }
    tree.build(mat);
}

void action_dump() {
    int N, M;
    tie(N,M) = tree.size();
    matrix buffer;
    tree.dump(buffer);
    for (int y = 0; y < M; ++y) {
        if (y > 0) cout << endl;
        for (int x = 0; x < N; ++x) {
            if (x > 0) cout << " ";
            cout << to_string(buffer[x][y]);
        }
    }
    cout << endl;
}

void action_query() {
    int lx, rx, ly, ry;
    cin >> lx >> rx >> ly >> ry;
    auto ans = tree.query(lx, rx, ly, ry);
    cout << to_string(ans) << endl;
}

void action_update() {
    int x, y, value;
    cin >> x >> y >> value;
    bool ans = tree.update(x, y, Option(value));
    cout << (ans ? "true" : "false") << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Segment Tree 2D";
    commands["random"] = { "random {n} {m} {min} {max}", action_random };
    commands["dump"] = { "dump", action_dump };
    commands["query"] = { "query {lx} {rx} {ly} {ry}", action_query };
    commands["update"] = { "update {x} {y} {value}", action_update };
}
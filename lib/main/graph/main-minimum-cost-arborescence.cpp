#include <iostream>
#include <tuple>
#include "template/template-main.hpp"
#include "cpalgo/graph/minimum-cost-arborescence.hpp"

using namespace std;

MinimumCostArborescence mca;
vector<tuple<int,int,long long>> edges;

void action_init() {
    int N;
    cin >> N;
    mca = MinimumCostArborescence(N);
    edges.clear();
}

void action_edge() {
    int from, to;
    long long cost;
    cin >> from >> to >> cost;
    if (
        from < 0 || from >= mca.size() ||
        to < 0 || to >= mca.size() ||
        cost < 0
    ) {
        cout << "false" << endl;
        return;
    }
    int index = edges.size();
    edges.push_back(make_tuple(from, to, cost));
    mca.add_edge(index, from, to, cost);
}

void action_solve() {
    int root;
    long long ans;
    vector<int> edge_indices;

    cin >> root;
    ans = mca.solve(root, edge_indices);

    cout << ans << endl;
    for (auto ei : edge_indices) {
        int from, to; long long cost;
        tie(from, to, cost) = edges[ei];
        cout << from << "->" << to << ", cost(" << cost << ")" << endl;
    }
}

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum-Cost Arborescence";
    commands["init"] = { "init {size}", action_init };
    commands["edge"] = { "edge {from} {to} {cost}", action_edge };
    commands["solve"] = { "solve {root}", action_solve };
}
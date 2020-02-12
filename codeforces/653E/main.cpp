// https://codeforces.com/contest/653/problem/E

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct UnionFindTree {
    struct node { int parent, rank; };
    vector<node> nodes;
    int n;
    UnionFindTree(int n): n(n), nodes(n) {
        for (int i = 0; i < n; ++i) {
            nodes[i] = node { i, 0 };
        }
    }
    node find_set(int v) {
        if (v != nodes[v].parent) {
            auto root = find_set(nodes[v].parent);
            nodes[v].parent = root.parent;
        }
        return nodes[v];
    }
    void union_set(int a, int b) {
        a = find_set(a).parent;
        b = find_set(b).parent;
        if (a == b) {
            return;
        }
        if (nodes[a].rank < nodes[b].rank) {
            swap(a, b);
        }
        nodes[b].parent = a;
        if (nodes[a].rank == nodes[b].rank) {
            nodes[a].rank++;
        }
    }
};


int N, M, K;
set<pair<int,int>> forbidden;

bool solve() {
    UnionFindTree tree(N);

    deque<int> seta;
    set<int> setb;

    seta.push_back(1);
    for (int i = 2; i < N; ++i) {
        setb.insert(i);
    }
    while (!seta.empty() || !setb.empty()) {
        if (seta.empty()) {
            seta.push_back(*setb.begin());
            setb.erase(setb.begin());
        }
        auto a = seta.front();
        seta.pop_front();
        for (auto b : vector<int>(setb.begin(), setb.end())) {
            if (forbidden.find({a,b}) != forbidden.end()) continue;
            tree.union_set(a,b);
            setb.erase(b);
            seta.push_back(b);
        }
    }

    set<int> connected;
    for (int i = 1; i < N; ++i) {
        if (forbidden.find({0,i}) != forbidden.end()) {
            continue;
        }
        connected.insert(tree.find_set(i).parent);
    }
    for (int i = 1; i < N; ++i) {
        auto p = tree.find_set(i).parent;
        if (connected.find(p) == connected.end()) {
            return false;
        }
    }
    int E = 0;
    for (int i = 1; i < N; ++i) {
        if (forbidden.find({0,i}) != forbidden.end()) {
            continue;
        }
        E++;
    }

    return connected.size() <= K && E >= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b; --a, --b;
        forbidden.insert({a,b});
        forbidden.insert({b,a});
    }
    cout << (solve() ? "possible" : "impossible") << endl;

    return 0;
}
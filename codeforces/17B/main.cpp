// http://codeforces.com/contest/17/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
    struct node { int parent, rank; };
    vector<node> nodes;
    DSU(int n): nodes(n) {
        for (int i = 0; i < n; ++i) {
            nodes[i] = { i, 0 };
        }
    }
    node find_set(int v) {
        if (v != nodes[v].parent) {
            nodes[v] = find_set(nodes[v].parent);
        }
        return nodes[v];
    }
    void union_set(int a, int b) {
        a = find_set(a).parent;
        b = find_set(b).parent;
        if (a == b) return;
        if (nodes[a].rank < nodes[b].rank) {
            swap(a, b);
        }
        nodes[b].parent = a;
        if (nodes[a].rank == nodes[b].rank) {
            nodes[a].rank++;
        }
    }
};

struct edge { int u, v, c; };
bool operator<(const edge& lhs, const edge& rhs) {
    return lhs.c < rhs.c;
}

int N, M;
vector<int> Q;
vector<edge> edges;

long long solve() {
    sort(edges.begin(), edges.end());

    vector<int> supervisor(N, -1);
    int count = 0;
    long long ans = 0;
    DSU dsu(N);
    for (auto edge : edges) {
        if (Q[edge.u] <= Q[edge.v]) continue;
        if (supervisor[edge.v] != -1) continue;
        if (dsu.find_set(edge.u).parent == dsu.find_set(edge.v).parent) continue;
        supervisor[edge.v] = edge.u;
        dsu.union_set(edge.u, edge.v);
        count++;
        ans += edge.c;
    }

    if (count != N - 1) return -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    Q.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> Q[i];
    }
    cin >> M;
    edges.assign(M, {});
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges[i] = { a, b, c };
    }
    cout << solve() << endl;

    return 0;
}
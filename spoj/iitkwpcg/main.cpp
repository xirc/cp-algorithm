// https://www.spoj.com/problems/IITKWPCG/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge { int u, v, c; };
bool operator<(const edge& lhs, const edge& rhs) {
    if (lhs.c != rhs.c) return lhs.c < rhs.c;
    if (lhs.u != rhs.u) return lhs.u < rhs.u;
    return lhs.v < rhs.v;
}

int ctzl(long long n) {
    int b = 0;
    while (n > 0) {
        if (n & 1) {
            return b;
        }
        b++;
        n >>= 1;
    }
    return 0;
}

struct DSU {
    struct node { int parent, rank; };
    vector<node> nodes;
    DSU(int n): nodes(n) {
        for (int i = 0; i < n; ++i) {
            nodes[i] = { i, 0 };
        }
    }
    void throw_if_invalid(int index) {
        if (index < 0 || index >= nodes.size()) throw;
    }
    node find_set(int v) {
        throw_if_invalid(v);
        if (v != nodes[v].parent) {
            auto root = find_set(nodes[v].parent);
            nodes[v].parent = root.parent;
            nodes[v].rank = root.rank;
        }
        return nodes[v];
    }
    void union_set(int a, int b) {
        throw_if_invalid(a);
        throw_if_invalid(b);
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

int N, M;
vector<edge> edges;

int solve() {
    sort(edges.begin(), edges.end());

    int ans = 0;
    DSU dsu(N);
    for (auto edge : edges) {
        if (dsu.find_set(edge.u).parent == dsu.find_set(edge.v).parent) continue;
        dsu.union_set(edge.u, edge.v);
        ans += edge.c;
    }
    return ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N >> M;
        edges.assign(M, {});
        for (int i = 0; i < M; ++i) {
            int u, v, lc;
            long long c;
            cin >> u >> v >> c;
            --u, --v;
            lc = ctzl(c);
            edges[i] = { u, v, lc };
        }
        cout << solve() << endl;
    }

    return 0;
}
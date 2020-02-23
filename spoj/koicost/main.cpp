// https://www.spoj.com/problems/KOICOST/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct DSU {
    struct node { int parent, rank, size; };
    int n;
    vector<node> nodes;
    DSU(int n): n(n), nodes(n) {
        for (int i = 0; i < n; ++i) {
            nodes[i] = { i, 0, 1 };
        }
    }
    node find_set(int v) {
        if (v != nodes[v].parent) {
            auto root = find_set(nodes[v].parent);
            nodes[v].parent = root.parent;
            nodes[v].rank = root.rank;
            nodes[v].size = root.size;
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
        nodes[a].size += nodes[b].size;
        if (nodes[a].rank == nodes[b].rank) {
            nodes[a].rank++;
        }
    }
};

const long long MODULO = 1000000000;
struct edge { int u, v, w; };
int N, M;
vector<edge> edges;

bool operator<(const edge& lhs, const edge& rhs) {
    return lhs.w < rhs.w;
}
long long solve() {
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    long long allw = 0;
    for (int i = 0; i < M; ++i) {
        allw += edges[i].w;
    }

    DSU dsu(N);
    long long totw = 0;
    long long ans = 0;
    for (auto edge : edges) {
        auto setu = dsu.find_set(edge.u), setv = dsu.find_set(edge.v);
        if (setu.parent != setv.parent) {
            long long a = (long long)setu.size * setv.size;
            long long b = allw - totw;
            long long c = (a * b) % MODULO;
            ans = (ans + c) % MODULO;
            dsu.union_set(edge.u, edge.v);
        }
        totw += edge.w;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({ u, v, w });
    }

    cout << solve() << endl;

    return 0;
}
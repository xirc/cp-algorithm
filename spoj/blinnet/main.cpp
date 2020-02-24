// https://www.spoj.com/problems/BLINNET/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct edge { int u, v, c; };
bool operator<(const edge& lhs, const edge& rhs) {
    return lhs.c < rhs.c;
}

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

int N;
vector<edge> edges;

long long solve() {
    sort(edges.begin(), edges.end());

    long long ans = 0;
    DSU dsu(N);
    for (auto edge : edges) {
        if (dsu.find_set(edge.u).parent == dsu.find_set(edge.v).parent) continue;
        dsu.union_set(edge.u, edge.v);
        ans += edge.c;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        edges.clear();
        for (int i = 0; i < N; ++i) {
            string name;
            cin >> name;
            int M;
            cin >> M;
            for (int j = 0; j < M; ++j) {
                int v, c;
                cin >> v >> c;
                --v;
                edges.push_back({ i, v, c });
            }
        }
        cout << solve() << endl;
    }

    return 0;
}
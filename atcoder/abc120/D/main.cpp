#include <bits/stdc++.h>

// Union Find Tree (Disjoint Set Union)
// Memory: O(N)
class UnionFindTree {
public:
    struct node { int parent, rank, size; };

protected:
    int N;
    std::vector<node> nodes;

public:
    // O(N)
    UnionFindTree(int n = 0)
        : N(n)
        , nodes(n)
    {
        for (int i = 0; i < N; ++i) {
            nodes[i] = { i, 0 , 1 };
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(N))
    node find(int v) {
        throw_if_invalid_index(v);
        if (v != nodes[v].parent) {
            // Path Compression
            nodes[v] = find(nodes[v].parent);
        }
        return nodes[v];
    }
    // O(a(N))
    bool same(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return find(u).parent == find(v).parent;
    }
    // O(a(N))
    bool unite(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        u = find(u).parent;
        v = find(v).parent;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
        }
        nodes[u].size += nodes[v].size;
        nodes[v].parent = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        return true;
    }

protected:
    void throw_if_invalid_index(int v) {
        if (v < 0 || v >= N) throw "index out of range";
    }
};

using namespace std;
using ll = long long;

int N, M;
vector<int> A, B;

void solve() {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    UnionFindTree dsu(N);
    vector<ll> ans;
    ll score = (ll)N * (N - 1) / 2;
    for (int i = 0; i < M; ++i) {
        ans.push_back(score);
        int u = A[i], v = B[i];
        --u, --v;
        if (!dsu.same(u, v)) {
            auto k = dsu.find(u).size;
            auto l = dsu.find(v).size;
            score -= (ll)k * l;
            dsu.unite(u, v);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < M; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
    }
    solve();

    return 0;
}
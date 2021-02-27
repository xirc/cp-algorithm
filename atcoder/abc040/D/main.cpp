#include <bits/stdc++.h>

class UnionFindTree {
public:
    struct node {
        size_t leader;
        size_t rank;
        size_t size;
    };

private:
    size_t N;
    std::vector<node> nodes;

public:
    // Time: O(N)
    UnionFindTree(size_t const N = 0)
        : N(N)
        , nodes(N)
    {
        for (size_t i = 0; i < N; ++i) {
            nodes[i] = { i, 0, 1 };
        }
    }
    // Time: O(1)
    size_t size() {
        return N;
    }
    // v = [0,N)
    // Time: O(a(N))
    node find(size_t const v) {
        if (v >= N) throw std::out_of_range("v");
        if (v != nodes[v].leader) {
            // Path Compression
            nodes[v] = find(nodes[v].leader);
        }
        return nodes[v];
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool same(size_t const u, size_t const v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        return find(u).leader == find(v).leader;
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool unite(size_t u, size_t v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        u = find(u).leader;
        v = find(v).leader;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
        }
        nodes[v].leader = u;
        nodes[u].size += nodes[v].size;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        return true;
    }
};

using namespace std;
using ll = int64_t;
using ff = long double;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, Q;
    struct edge { int a, b, y; };
    vector<edge> es;
    struct query { int i, v, w, ans; };
    vector<query> qs;

    cin >> N >> M;
    es.assign(M, {});
    for (int i = 0; i < M; i++) {
        cin >> es[i].a >> es[i].b >> es[i].y;
        --es[i].a, --es[i].b;
    }

    cin >> Q;
    qs.assign(Q, {});
    for (int i = 0; i < Q; ++i) {
        qs[i].i = i;
        cin >> qs[i].v >> qs[i].w;
        --qs[i].v;
    }

    sort(es.begin(), es.end(), [](auto const& l, auto const& r) {
        return l.y > r.y;
    });
    sort(qs.begin(), qs.end(), [](auto const& l, auto const& r) {
        return l.w > r.w;
    });

    auto it = es.begin();
    UnionFindTree dsu(N);
    for (int i = 0; i < Q; ++i) {
        auto v = qs[i].v, w = qs[i].w;
        while (it != es.end() && it->y > w) {
            dsu.unite(it->a, it->b);
            ++it;
        }
        qs[i].ans = dsu.find(v).size;
    }

    sort(qs.begin(), qs.end(), [](auto const& l, auto const& r) {
        return l.i < r.i;
    });
    for (int i = 0; i < Q; ++i) {
        cout << qs[i].ans << endl;
    }

    return 0;
}
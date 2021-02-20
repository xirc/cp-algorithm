#include <bits/stdc++.h>

class Dijkstra {
    struct edge { size_t to; uint64_t distance; };
    size_t N;
    uint64_t inf;
    std::vector<std::vector<edge>> adj;

public:
    // O(V)
    Dijkstra(size_t n = 0, uint64_t inf = std::numeric_limits<uint64_t>::max() / 2)
        : N(n), inf(inf), adj(n) {
    }
    // O(1)
    size_t size() {
        return N;
    }
    // O(1)
    uint64_t infinity() {
        return inf;
    }
    // O(1)
    void add_edge(size_t from, size_t to, uint64_t distance) {
        if (from >= N) throw std::out_of_range("from");
        if (to >= N) throw std::out_of_range("to");
        adj[from].push_back({ to, distance });
    }
    // O(V logV + E)
    void solve(size_t s, std::vector<uint64_t>& D, std::vector<size_t>& P) {
        D.assign(N, inf);
        P.assign(N, N);

        using entry = std::pair<uint64_t,size_t>;
        std::priority_queue<entry, std::vector<entry>, std::greater<entry>> Q;
        std::vector<bool> used(N, false);

        D[s] = 0;
        Q.push({0, s});

        while (!Q.empty()) {
            size_t v = Q.top().second; Q.pop();
            if (used[v]) continue;
            used[v] = true;
            for (auto const& edge : adj[v]) {
                auto to = edge.to;
                auto len = edge.distance;
                if (D[v] + len < D[to]) {
                    D[to] = D[v] + len;
                    P[to] = v;
                    Q.push({D[to], to});
                }
            }
        }
    }
};

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    const ll inf = 1e16;
    int N, M, T;
    vector<int> A;

    cin >> N >> M >> T;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    Dijkstra f(N, inf);
    Dijkstra r(N, inf);

    for (int i = 0; i < M; ++i) {
        size_t a, b;
        uint64_t c;
        cin >> a >> b >> c;
        --a, --b; // 0-index
        f.add_edge(a, b, c);
        r.add_edge(b, a, c);
    }

    vector<uint64_t> Df, Dr;
    vector<size_t> Pf, Pr;
    f.solve(0, Df, Pr);
    r.solve(0, Dr, Pr);

    ll ans = ll(A[0]) * T;
    for (int v = 1; v < N; ++v) {
        ll a = max(ll(0), ll(T) - ll(Df[v]) - ll(Dr[v])) * A[v];
        ans = max(ans, a);
    }
    cout << ans << endl;

    return 0;
}
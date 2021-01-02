#include <bits/stdc++.h>

class BellmanFord {
    struct edge {
        size_t from;
        size_t to;
        long long cost;
    };
    size_t N;
    std::vector<edge> edges;
    long long inf;

public:
    BellmanFord(
        size_t N = 0,
        long long inf = std::numeric_limits<long long>::max() / 2
    )
        : N(N)
        , edges()
        , inf(inf)
    {
        // Do nothing
    }
    size_t size() const {
        return N;
    }
    void add_edge(size_t const from, size_t const to, long long const cost) {
        if (from >= N) throw std::out_of_range("from");
        if (to >= N) throw std::out_of_range("to");
        edges.push_back({ from, to, cost });
    }
    bool solve(size_t from, std::vector<long long>& D, std::vector<size_t>& P) const {
        if (from >= N) throw std::out_of_range("from");
        D.assign(N, inf);
        P.assign(N, N);

        bool any_update = false;
        D[from] = 0;
        for (size_t i = 0; i < N; ++i) {
            any_update = false;
            for (auto const& e : edges) {
                if (D[e.from] >= inf) continue;
                if (D[e.to] > D[e.from] + e.cost) {
                    // suppress negative overflow
                    D[e.to] = std::max(-inf, D[e.from] + e.cost);
                    P[e.to] = e.from;
                    any_update = true;
                }
            }
            if (!any_update) break;
        }
        // if any_update == true, a negative cycle is found.
        return !any_update;
    }
};


using namespace std;
using ll = long long;

int N, M;
vector<int> A, B, C;

bool solve(ll& score) {
    BellmanFord solver(N);
    for (int i = 0; i < M; ++i) {
        solver.add_edge(A[i], B[i], -C[i]);
    }

    vector<ll> D;
    vector<size_t> P;
    bool no_cycle = solver.solve(0, D, P);
    score = -D[N-1];

    if (no_cycle) {
        return true;
    }

    int i = N - 1;
    set<int> cs;
    while (P[i] != N) {
        if (cs.count(P[i]) > 0) {
            return false;
        }
        cs.insert(P[i]);
        i = P[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    B.assign(M, 0);
    C.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i] >> C[i];
        --A[i], --B[i]; // 0-indexed
    }

    ll ans;
    auto has_ans = solve(ans);
    if (!has_ans) {
        cout << "inf" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
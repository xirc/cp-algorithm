#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<array<int,2>> solve(int N, int K) {
    int M = (N-1) * (N-2) / 2;
    if (K > M) return {};

    vector<array<int,2>> G;
    for (int v = 1; v < N; ++v) {
        G.push_back({ 0, v });
    }
    for (int u = 1; u < N; ++u) {
        for (int v = u + 1; v < N; ++v) {
            if (K == M) break;
            G.push_back({ u, v });
            --M;
        }
    }
    return G;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    auto G = solve(N, K);
    if (G.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << G.size() << endl;
        for (auto e : G) {
            int u = e[0] + 1, v = e[1] + 1;
            cout << u << " " << v << endl;
        }
    }

    return 0;
}
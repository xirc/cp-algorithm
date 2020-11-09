#include <bits/stdc++.h>

using namespace std;

int L;
int N, M;
vector<vector<vector<int>>> G;

void solve() {
    int K = log2(L);
    K = min(K, 19);
    N = K + 1;
    G.assign(N, vector<vector<int>>());
    for (int i = 0; i + 1 < N; ++i) {
        G[i].push_back({ i + 1, 0 });
        G[i].push_back({ i + 1, 1 << i });
        M += 2;
    }
    for (int t = N - 2; t >= 0; --t) {
        if (L - (1 << t) >= (1 << K)) {
            G[t].push_back({ N - 1, L - (1 << t) });
            L -= (1 << t);
            ++M;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> L;
    solve();
    cout << N << " " << M << endl;
    for (int u = 0; u < N; ++u) {
        for (auto e : G[u]) {
            auto v = e[0], w = e[1];
            cout << u + 1 << " " << v + 1 << " " << w << endl;
        }
    }

    return 0;
}
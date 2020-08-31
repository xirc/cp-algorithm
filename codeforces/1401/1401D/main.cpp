#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
int N, M;
vector<vector<int>> G;
vector<int> P;

vector<ll> subsize;
vector<ll> weights;

void dfs(int v, int p) {
    subsize[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        auto weight = (N - subsize[u]) * subsize[u];
        weights.push_back(weight);
        subsize[v] += subsize[u];
    }
}

ll solve() {
    sort(P.begin(), P.end());
    vector<ll> values(N - 1, 1);
    if (M < N - 1) {
        for (int i = 0; i < M; ++i) {
            values[N - 2 - i] *= P[M - 1 - i];
        }
    } else {
        for (int i = 0; i < M; ++i) {
            int index = min(i, N-2);
            values[index] *= P[i];
            values[index] %= MOD;
        }
    }

    subsize.assign(N, 0);
    weights.clear();
    dfs(0, 0);
    assert(weights.size() == N - 1);
    sort(weights.begin(), weights.end());

    ll ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        ans = (ans + values[i] * weights[i]) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        G.assign(N, vector<int>());
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cin >> M;
        P.assign(M, 0);
        for (int i = 0; i < M; ++i) {
            cin >> P[i];
        }
        cout << solve() << endl;
    }

    return 0;
}
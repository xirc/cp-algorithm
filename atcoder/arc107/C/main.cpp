#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
int N, K;
vector<vector<int>> A;

ll factorial(int M) {
    if (M == 0) return 1;
    ll ans = 1;
    for (int i = 1; i <= M; ++i) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

vector<bool> used;
int dfs(int v, vector<vector<bool>> const& G) {
    if (used[v]) return 0;
    used[v] = true;
    int count = 1;
    for (int u = 0; u < N; ++u) {
        if (u != v && G[u][v]) {
            count += dfs(u, G);
        }
    }
    return count;
}

ll solve() {
    vector<vector<bool>> R(N, vector<bool>(N, false));
    vector<vector<bool>> C(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bool canSwapRow = true;
            bool canSwapCol = true;
            for (int k = 0; k < N; ++k) {
                if (A[i][k] + A[j][k] > K) canSwapRow = false;
                if (A[k][i] + A[k][j] > K) canSwapCol = false;
            }
            if (canSwapRow) R[i][j] = R[j][i] = true;
            if (canSwapCol) C[i][j] = C[j][i] = true;
        }
    }

    ll ans = 1;
    used = vector<bool>(N, false);
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        int m = dfs(i, R);
        ans *= factorial(m);
        ans %= MOD;
    }
    used = vector<bool>(N, false);
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        int m = dfs(i, C);
        ans *= factorial(m);
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}
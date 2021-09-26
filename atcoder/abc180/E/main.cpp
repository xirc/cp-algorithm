#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> X, Y, Z;

inline int distance(int s, int d) {
    return abs(X[s] - X[d]) + abs(Y[s] - Y[d]) + max(0, Z[d] - Z[s]);
}

int solve() {
    int const inf = 1e8;
    int const M = 1 << N;
    vector<vector<int>> DP(N, vector<int>(M, inf));
    DP[0][1] = 0;
    for (int s = 0; s < M; ++s) {
        for (int i = 0; i < N; ++i) {
            if ((s&(1<<i)) == 1) continue; 
            for (int j = 0; j < N; ++j) {
                if(i == j) continue;
                if ((s&(1<<j)) == 0) continue;
                int ns = s|(1<<i);
                DP[i][ns] = min(DP[i][ns], DP[j][s] + distance(j,i));
            }
        }
    }
    int ans = inf;
    for (int i = 1; i < N; ++i) {
        ans = min(ans, DP[i][M-1] + distance(i,0));
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    X.assign(N, 0);
    Y.assign(N, 0);
    Z.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    cout << solve() << endl;

    return 0;
}
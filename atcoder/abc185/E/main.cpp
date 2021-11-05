#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A, B;

int solve() {
    int const inf = 1e8;
    vector<vector<int>> DP(N+1, vector<int>(M+1, inf));
    function<int(int,int)> f = [&](int i, int j) {
        if (DP[i][j] < inf) return DP[i][j];
        if (i == 0) return j;
        if (j == 0) return i;
        int gi = f(i-1, j) + 1;
        int gj = f(i, j-1) + 1;
        int gij = f(i-1,j-1) + (A[i-1] != B[j-1] ? 1 : 0);
        return DP[i][j] = min({ gi, gj, gij });
    };
    return f(N, M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    cout << solve() << endl;

    return 0;
}
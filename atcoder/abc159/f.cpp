// https://atcoder.jp/contests/abc159/tasks/abc159_f

#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> A;

const long long MOD = 998244353;
long long DP[3001][3001][3];
long long solve() {
    DP[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k <= S; ++k) {
            (DP[i+1][k][0] += DP[i][k][0]) %= MOD;
            (DP[i+1][k][1] += DP[i][k][1] + DP[i][k][0]) %= MOD;
            (DP[i+1][k][2] += DP[i][k][2] + DP[i][k][1] + DP[i][k][0]) %= MOD;
            if (k + A[i] <= S) {
                (DP[i+1][k+A[i]][1] += DP[i][k][1] + DP[i][k][0]) %= MOD;
                (DP[i+1][k+A[i]][2] += DP[i][k][1] + DP[i][k][0]) %= MOD;
            }
        }
    }
    return DP[N][S][2];
}

int main() {
    cin >> N >> S;

    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
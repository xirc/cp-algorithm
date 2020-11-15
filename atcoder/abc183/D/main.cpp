#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, W;
vector<vector<int>> STP;

bool solve() {
    vector<ll> A(1e6, 0);
    for (int i = 0; i < N; ++i) {
        auto S = STP[i][0], T = STP[i][1], P = STP[i][2];
        A[S] += P;
        A[T] -= P;
    }
    for (int i = 1; i < N; ++i) {
        A[i] += A[i-1];
    }
    for (int i = 0; i < N; ++i) {
        if (A[i] > W) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> W;
    STP.assign(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> STP[i][0] >> STP[i][1] >> STP[i][2];
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, K;
vector<vector<int>> T;

bool solve(int i = 0, int s = 0) {
    if (i == N) return s == 0;
    for (int j = 0; j < K; ++j) {
        if (solve(i + 1, s ^ T[i][j])) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    T.assign(N, vector<int>(K, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> T[i][j];
        }
    }
    auto ans = solve() ? "Found" : "Nothing";
    cout << ans << endl;

    return 0;
}
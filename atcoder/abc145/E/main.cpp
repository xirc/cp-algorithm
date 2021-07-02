#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, T;
vector<array<int,2>> AB;

int solve() {
    sort(AB.begin(), AB.end());
    vector<int> DP(T + 3000, 0);
    for (int i = 0; i < N; ++i) {
        int A = AB[i][0];
        int B = AB[i][1];
        for (int t = T - 1; t >= 0; --t) {
            DP[t+A] = max(DP[t]+B, DP[t+A]);
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)DP.size(); ++i) {
        ans = max(ans, DP[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    AB.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> AB[i][0] >> AB[i][1];
    }
    cout << solve() << endl;

    return 0;
}
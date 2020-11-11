#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> X;

int solve() {
    int ans = 1e9;
    for (int i = 0; i+K-1 < N; ++i) {
        int l = X[i];
        int r = X[i+K-1];
        ans = min(ans, abs(l) + abs(l - r));
        ans = min(ans, abs(r) + abs(r - l));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    X.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    cout << solve() << endl;

    return 0;
}
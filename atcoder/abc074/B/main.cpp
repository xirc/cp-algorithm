#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> xs;

int solve() {
    int ans = 0;
    for (auto x : xs) {
        ans += min(2 * x, 2 * (K - x));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    xs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i];
    }
    cout << solve() << endl;

    return 0;
}
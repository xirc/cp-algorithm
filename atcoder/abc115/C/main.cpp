#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> H;

int solve() {
    int ans = 1e9;
    sort(H.begin(), H.end());
    for (int i = 0; i + K - 1 < N; ++i) {
        int j = i + K - 1;
        ans = min(ans, H[i+K-1] - H[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    H.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    cout << solve() << endl;

    return 0;
}
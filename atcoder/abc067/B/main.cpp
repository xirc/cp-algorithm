#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> L;

int solve() {
    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());
    int ans = 0;
    for (int i = 0; i < K; ++i) {
        ans += L[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    L.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    cout << solve() << endl;

    return 0;
}
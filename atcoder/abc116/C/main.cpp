#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> H;

int solve() {
    int ans = H[0];
    for (int i = 1; i < N; ++i) {
        ans += max(0, H[i]-H[i-1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    H.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    cout << solve() << endl;

    return 0;
}
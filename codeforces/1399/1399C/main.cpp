#include <bits/stdc++.h>

using namespace std;

int count(const vector<int>& W, const int S) {
    int ans = 0;
    int l = 0, r = W.size() - 1;
    while (l < r) {
        const int w = W[l] + W[r];
        if (w < S) {
            l++;
        } else if (w > S) {
            r--;
        } else {
            ans++;
            l++;
            r--;
        }
    }
    return ans;
}

int solve(vector<int>& W) {
    sort(W.begin(), W.end());
    const int M = *W.rbegin() * 2 + 1;
    int ans = 0;
    for (int s = 1; s < M; ++s) {
        ans = max(ans, count(W, s));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> W;
    
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        W.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> W[i];
        }
        auto ans = solve(W);
        cout << ans << endl;
    }

    return 0;
}
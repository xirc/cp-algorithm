#include <bits/stdc++.h>

using namespace std;

bool solve(int N, vector<int> const& T, vector<int> const& X, vector<int> const& Y) {
    int ct = 0;
    int cx = 0, cy = 0;
    for (int i = 0; i < N; ++i) {
        int dt = T[i] - ct;
        int dx = abs(X[i] - cx);
        int dy = abs(Y[i] - cy);
        int dd = dx + dy;
        if (dt < dd) return false;
        if ((dt - dd) % 2 == 1) return false;
        ct = T[i];
        cx = X[i];
        cy = Y[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> T, X, Y;
    
    cin >> N;
    T.assign(N, 0);
    X.assign(N, 0);
    Y.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> X[i] >> Y[i];
    }
    auto ans = solve(N, T, X, Y) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
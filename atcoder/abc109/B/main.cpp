#include <bits/stdc++.h>

using namespace std;

bool solve(int N, vector<string> const& W) {
    assert(N >= 2);

    unordered_set<string> S;
    S.insert(W[0]);

    for (int i = 1; i < N; ++i) {
        if (S.count(W[i]) != 0) return false;
        S.insert(W[i]);
        if (W[i-1].back() != W[i].front()) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<string> W;

    cin >> N;
    W.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }
    auto ans = solve(N, W) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
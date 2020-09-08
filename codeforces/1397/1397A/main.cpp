#include <bits/stdc++.h>

using namespace std;

bool solve(vector<string> const& S) {
    const int N = S.size();
    unordered_map<char,int> M;
    for (auto ss : S) {
        for (auto c : ss) {
            M[c]++;
        }
    }
    for (auto kv : M) {
        int count = kv.second;
        if (count % N != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<string> S;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        S.assign(N, "");
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }
        auto ans = solve(S) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool ok(vector<char> const& S) {
    if (S.size() & 1) return false;
    const int N = S.size() / 2;
    for (int i = 0; i < N; ++i) {
        if (S[i] != S[i+N]) return false;
    }
    return true;
}

int solve(string const& S) {
    vector<char> ss(S.begin(), S.end());
    while (ss.size()) {
        ss.pop_back();
        ss.pop_back();
        if (ok(ss)) {
            return ss.size();
        }
    }
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}
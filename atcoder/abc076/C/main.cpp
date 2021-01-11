#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string const NOP = "UNRESTORABLE";
string S, T;

bool solve(vector<char>& W, int s) {
    for (int i = 0; i < s; ++i) {
        if (W[i] == '?') W[i] = 'a';
    }
    for (int i = 0; i < T.size(); ++i) {
        if (W[s+i] == '?') {
            W[s+i] = T[i];
        }
        if (W[s+i] != T[i]) return false;
    }
    for (int i = s + T.size(); i < S.size(); ++i) {
        if (W[i] == '?') W[i] = 'a';
    }
    return true;
}

string solve() {
    for (int i = S.size() - T.size(); i >= 0; --i) {
        vector<char> W(S.begin(), S.end());
        if (solve(W, i)) return string(W.begin(), W.end());
    }
    return NOP;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S >> T;
    cout << solve() << endl;

    return 0;
}
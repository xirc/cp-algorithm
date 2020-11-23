#include <bits/stdc++.h>

using namespace std;

bool solve(string const& S) {
    assert(S.size() >= 4);
    if (S[0] != 'A') return false;
    const int N = S.size();
    int count = 0;
    for (int i = 2; i < N -1; ++i) {
        if (S[i] == 'C') ++count;
    }
    if (count != 1) return false;
    for (int i = 1; i < N; ++i) {
        if (S[i] != 'C' && isupper(S[i])) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S) ? "AC" : "WA";
    cout << ans << endl;

    return 0;
}
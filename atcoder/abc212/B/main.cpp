#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool solve(string const& S) {
    if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3]) return false;
    bool stairs = true;
    for (int i = 0; i < 3; ++i) {
        auto n = S[i+1] - '0', p = S[i] - '0';
        if (n != (p+1) % 10) {
            stairs = false;
            break;
        }
    }
    return !stairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S) ? "Strong" : "Weak";
    cout << ans << endl;

    return 0;
}
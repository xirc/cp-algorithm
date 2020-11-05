#include <bits/stdc++.h>

using namespace std;

bool solve(string const&S, string const& T) {
    const int N = S.size();
    unordered_map<char,char> Ms, Mt;

    for (int i = 0; i < N; ++i) {
        auto si = S[i], ti = T[i];
        if (Ms.count(si) > 0 && Ms[si] != ti) {
            return false;
        } else if (Ms.count(si) == 0) {
            Ms[si] = ti;
        }
        if (Mt.count(ti) > 0 && Mt[ti] != si) {
            return false;
        } else if (Mt.count(ti) == 0) {
            Mt[ti] = si;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;

    cin >> S >> T;
    auto ans = solve(S, T) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
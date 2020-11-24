#include <bits/stdc++.h>

using namespace std;

bool solve(string const& S, string const &T) {
    assert(T.size() == S.size());
    const int N = S.size();
    for (int i = 0; i < N; ++i) {
        bool match = true;
        for (int j = 0; j < N; ++j) {
            if (S[(N-1-i+j)%N] != T[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
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
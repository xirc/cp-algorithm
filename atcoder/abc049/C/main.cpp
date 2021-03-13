#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool solve(string const& S) {
    vector<bool> pass(S.size(), false);
    vector<string> const dict = { "dream", "dreamer", "erase", "eraser" };
    for (int i = 0; i < (int)S.size(); ++i) {
        if (i > 0 && !pass[i-1]) continue;
        for (auto word : dict) {
            if (i + word.size() > S.size()) continue;
            bool match = true;
            for (int j = 0; j < (int)word.size(); ++j) {
                if (S[i+j] != word[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                pass[i+word.size()-1] = true;
            }
        }
    }
    return pass[S.size()-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}
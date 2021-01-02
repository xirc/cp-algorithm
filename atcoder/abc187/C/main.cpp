#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> S;

string solve() {
    set<string> keys;

    set<string> ps, ns;
    for (auto const& s : S) {
        bool neg = s[0] == '!';
        auto ss = neg ? s.substr(1) : s;
        keys.insert(ss);
        if (neg) {
            ns.insert(ss);
        } else {
            ps.insert(ss);
        }
    }
    for (auto s : keys) {
        if (ps.count(s) > 0 && ns.count(s) > 0) {
            return s;
        }
    }
    return "satisfiable";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> S;

string solve() {
    unordered_set<string> ss;

    for (auto const& s : S) {
        ss.insert(s);
    }
    for (auto const& s : S) {
        if (ss.count("!" + s) > 0) {
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
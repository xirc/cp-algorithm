#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<string> S;

ll solve() {
    map<char, int> counter;
    for (int i = 0; i < N; ++i) {
        ++counter[S[i][0]];
    }
    ll ans = 0;
    vector<char> cs = { 'M', 'A', 'R', 'C', 'H' };
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += ll(1) * counter[cs[i]] * counter[cs[j]] * counter[cs[k]];
            }
        }
    }
    return ans;
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
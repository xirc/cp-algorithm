#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<int> P, Y;

vector<ll> solve() {
    map<int,set<pair<int,int>>> S;
    for (int i = 0; i < M; ++i) {
        S[P[i]].insert({ Y[i], i });
    }

    vector<ll> ans(M, 0);
    for (auto const& e : S) {
        int x = 1;
        auto p = e.first;
        auto const& xs = e.second;
        for (auto yi : xs) {
            auto i = yi.second;
            ll id = p * ll(1000000) + x;
            ans[i] = id;
            ++x;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    P.assign(M, 0);
    Y.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> P[i] >> Y[i];
    }

    auto ans = solve();
    for (int i = 0; i < M; ++i) {
        cout << setw(12) << setfill('0') << ans[i] << endl;
    }

    return 0;
}
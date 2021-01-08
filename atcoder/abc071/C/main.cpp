#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    map<int,int> mp;
    for (auto v : A) {
        ++mp[v];
    }

    ll ans = 0;
    deque<int> Q;
    for (auto e : mp) {
        auto v = e.first, c = e.second;
        if (c <= 1) continue;
        if (c >= 4) {
            ans = max(ans, ll(v) * v);
        }
        Q.push_back(v);
        if (Q.size() < 2) continue;
        if (Q.size() > 2) Q.pop_front();
        ans = max(ans, ll(Q[0]) * Q[1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
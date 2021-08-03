#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(int K) {
    vector<ll> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < 10; ++i) {
        if (s.size() >= K) {
            return s[K-1];
        }
        vector<ll> ns;
        for (auto v : s) {
            ll c = v % 10;
            if (c > 0) ns.push_back(v * 10 + (c - 1));
            ns.push_back(v * 10 + c);
            if (c < 9) ns.push_back(v * 10 + (c + 1));
        }
        K -= s.size();
        s = ns;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;
    cout << solve(K) << endl;

    return 0;
}
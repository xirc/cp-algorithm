#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

ll solve() {
    unordered_map<int,int> count;
    for (auto a : A) {
        count[a]++;
    }
    ll ans = 0;
    for (auto a : count) {
        for (auto b : count) {
            ll x = abs(a.first - b.first);
            ans += ll(1) * a.second * b.second * x * x;
        }
    }
    return ans / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}
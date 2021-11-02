#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    for (auto &c : C) cin >> c;

    vector<int> D(N+1, 0);
    for (auto c : C) {
        ++D[B[c-1]];
    }

    ll ans = 0;
    for (auto a : A) {
        ans += D[a];
    }
    cout << ans << endl;

    return 0;
}
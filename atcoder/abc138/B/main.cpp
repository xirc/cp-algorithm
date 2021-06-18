#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;
    
    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    ff ans = 0;
    for (auto a : A) {
        ans += 1 / ff(a);
    }
    ans = 1.0 / ans;
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
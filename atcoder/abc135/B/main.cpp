#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> ps;
    
    cin >> N;
    ps.assign(N, 0);
    for (auto &p : ps) cin >> p;

    auto qs = ps;
    sort(qs.begin(), qs.end());
    int diff = 0;
    for (int i = 0; i < N; ++i) {
        if (ps[i] != qs[i]) ++diff;
    }
    auto ans = (diff == 0 || diff == 2) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}
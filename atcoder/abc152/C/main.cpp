#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    set<int> ps;
    int ans = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int p; cin >> p;
        if (ps.upper_bound(p-1) == ps.begin()) ++ans;
        ps.insert(p);
    }
    cout << ans << endl;

    return 0;
}
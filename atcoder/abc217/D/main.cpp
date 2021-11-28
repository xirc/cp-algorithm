#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int L, Q;

    cin >> L >> Q;

    set<int> xs;
    xs.insert(0);
    xs.insert(L);

    for (int i = 0; i < Q; ++i) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            xs.insert(x);
        } else if (c == 2) {
            auto it = xs.upper_bound(x);
            assert(it != xs.begin());
            auto r = *it; --it;
            auto l = *it;
            cout << (r - l) << endl;
        } else throw;
    }

    return 0;
}
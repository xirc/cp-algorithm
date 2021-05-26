#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll bsum = 0;
ll amin = 0;
multiset<int> L, R;

void update(int a, int b) {
    bsum += b;
    if (L.empty()) {
        L.insert(a);
        R.insert(a);
        return;
    }

    auto l = *L.rbegin();
    auto r = *R.begin();
    if (a >= l && a <= r) {
        L.insert(a);
        R.insert(a);
    } else if (a < l) {
        R.insert(l);
        L.erase(L.find(l));
        L.insert(a);
        L.insert(a);
        amin += l - a;
    } else if (a > r) {
        L.insert(r);
        R.erase(R.find(r));
        R.insert(a);
        R.insert(a);
        amin += a - r;
    }
}

array<ll,2> query() {
    assert(!L.empty());
    int x = *L.rbegin();
    ll fx = amin + bsum;
    return { x, fx };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, a, b;
        cin >> x;
        if (x == 1) {
            cin >> a >> b;
            update(a, b);
        } else if (x == 2) {
            auto ans = query();
            cout << ans[0] << " " << ans[1] << endl;
        } else throw;
    }

    return 0;
}
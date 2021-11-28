#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int L, Q;

    cin >> L >> Q;

    set<int> bs;
    map<int,int> ls;
    bs.insert(0);
    ls[0] = L;

    for (int i = 0; i < Q; ++i) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            auto it = bs.upper_bound(x);
            assert(it != bs.begin());
            --it;
            auto b = *it, l = ls[b];
            ls[b] = x - b;
            bs.insert(x);
            ls[x] = l - ls[b];
        } else if (c == 2) {
            auto it = bs.upper_bound(x);
            assert(it != bs.begin());
            --it;
            auto b = *it;
            cout << ls[b] << endl;
        } else throw;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    multiset<int> S;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type, x, l, r;
        cin >> type;
        if (type == 0) {
            // insert x
            cin >> x;
            S.insert(x);
            cout << S.size() << endl;
        } else if (type == 1) {
            // find x 
            cin >> x;
            cout << S.count(x) << endl;
        } else if (type == 2) {
            // erase x
            cin >> x;
            S.erase(x);
        } else if (type == 3) {
            // dump [l,r]
            cin >> l >> r;
            auto begin = S.lower_bound(l), end = S.upper_bound(r);
            for (auto it = begin; it != end; ++it) {
                cout << *it << endl;
            }
        } else throw;
    }

    return 0;
}
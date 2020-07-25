#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string,int> M;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type, value;
        string key, l, r;
        cin >> type;
        if (type == 0) {
            // insert key value
            cin >> key >> value;
            M[key] = value;
        } else if (type == 1) {
            // find key
            cin >> key;
            if (M.count(key)) {
                cout << M[key] << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (type == 2) {
            // erase key
            cin >> key;
            M.erase(key);
        } else if (type == 3) {
            // dump [l,r]
            cin >> l >> r;
            auto begin = M.lower_bound(l), end = M.upper_bound(r);
            for (auto it = begin; it != end; ++it) {
                cout << it->first << " " << it->second << endl;
            }
        } else throw;
    }

    return 0;
}
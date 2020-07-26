#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    multimap<string,int> M;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string key, l, r;
        int type, value;
        cin >> type;
        if (type == 0) {
            // insert key value
            cin >> key >> value;
            M.insert({ key, value });
        } else if (type == 1) {
            // find key
            cin >> key;
            auto range = M.equal_range(key);
            for (auto it = range.first; it != range.second; ++it) {
                cout << it->second << endl;
            }
        } else if (type == 2) {
            // erase key
            cin >> key;
            M.erase(key);
        } else if (type == 3) {
            cin >> l >> r;
            auto begin = M.lower_bound(l);
            auto end = M.upper_bound(r);
            for (auto it = begin; it != end; ++it) {
                cout << it->first << " " << it->second << endl;
            }
        } else throw;
    }

    return 0;
}
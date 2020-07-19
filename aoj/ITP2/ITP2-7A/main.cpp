#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_set<int> S;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type, value;
        cin >> type >> value;
        if (type == 0) {
            // insert
            S.insert(value);
            cout << S.size() << endl;
        } else if (type == 1) {
            // find
            auto ans = S.count(value);
            cout << ans << endl;
        } else throw;
    }

    return 0;
}
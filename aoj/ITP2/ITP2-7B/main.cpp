#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_set<int> S;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            // insert
            S.insert(x);
            cout << S.size() << endl;
        } else if (t == 1) {
            // find
            cout << S.count(x) << endl;
        } else if (t == 2) {
            // delete
            S.erase(x);
        } else throw;
    }

    return 0;
}
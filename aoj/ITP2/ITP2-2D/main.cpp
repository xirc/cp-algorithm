#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<list<int>> lists(N);
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int t, x;
            cin >> t >> x;
            lists[t].push_back(x);
        } else if (type == 1) {
            int t;
            cin >> t;
            for (auto it = lists[t].begin(); it != lists[t].end(); ++it) {
                if (it != lists[t].begin()) cout << " ";
                cout << *it;
            }
            cout << endl;
        } else if (type == 2) {
            int s, t;
            cin >> s >> t;
            lists[t].splice(lists[t].end(), move(lists[s]));
        } else throw;
    }

    return 0;
}
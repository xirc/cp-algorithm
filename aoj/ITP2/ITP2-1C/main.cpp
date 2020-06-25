#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    list<int> ls;
    auto it = ls.begin();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int x;
            cin >> x;
            it = ls.insert(it, x);
        } else if (type == 1) {
            int d;
            cin >> d;
            if (d > 0) {
                for (int j = 0; j < d; ++j) it++;
            } else {
                for (int j = 0; j < abs(d); ++j) it--;
            }
        } else if (type == 2) {
            it = ls.erase(it);
        } else throw;
    }

    for (auto v : ls) {
        cout << v << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> A;
    A.reserve(200000);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int x;
            cin >> x;
            A.push_back(x);
        } else if (type == 1) {
            int p;
            cin >> p;
            cout << A[p] << endl;
        } else if (type == 2) {
            A.pop_back();
        } else throw;
    }

    return 0;
}
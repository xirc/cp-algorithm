#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    deque<int> A;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int d, x;
            cin >> d >> x;
            if (d == 0) {
                A.push_front(x);
            } else if (d == 1) {
                A.push_back(x);
            } else throw;
        } else if (type == 1) {
            int p;
            cin >> p;
            cout << A[p] << endl;
        } else if (type == 2) {
            int d;
            cin >> d;
            if (d == 0) {
                A.pop_front();
            } else if (d == 1) {
                A.pop_back();
            } else throw;
        } else throw;
    }

    return 0;
}
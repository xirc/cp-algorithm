#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int dv = 0, v = 0;
    for (int i = 1; i < N; ++i) {
        int d;
        cout << "? " << 1 << " " << (i + 1) << endl;
        cin >> d;
        if (d > dv) {
            dv = d;
            v = i;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (i == v) continue;
        int d;
        cout << "? " << (v + 1) << " " << (i + 1) << endl;
        cin >> d;
        if (d > dv) {
            dv = d;
        }
    }
    cout << "! " << dv << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<int> T;
    int l, r, t;

    cin >> N >> Q;
    T.assign(N, 0);
    for (int i = 0; i < Q; i++) {
        cin >> l >> r >> t;
        --l, --r;
        for (int j = l; j <= r; ++j) {
            T[j] = t;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << T[i] << endl;
    }

    return 0;
}
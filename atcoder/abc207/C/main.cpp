#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> L, R;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        l *= 2; r *= 2;
        if (t == 1) {
            r++;
        } else if (t == 2) {
            // nothing
        } else if (t == 3) {
            ++l, ++r;
        } else if (t == 4) {
            ++l;
        }
        L.push_back(l);
        R.push_back(r);
    }
    auto const is_cross = [&](int i, int j) -> bool{
        int l = max(L[i], L[j]);
        int r = min(R[i], R[j]);
        return l < r;
    };
    int ps = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (is_cross(i, j)) {
                ++ps;
            }
        }
    }
    cout << ps << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> T, L, R;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        T.push_back(t);
        L.push_back(l);
        R.push_back(r);
    }
    auto const is_cross = [&](int i, int j) -> bool{
        if (R[i] < L[j]) return false;
        if (R[i] == L[j] && (T[i] % 2 == 0 || T[j] >= 3)) return false;
        if (L[i] > R[j]) return false;
        if (L[i] == R[j] && (T[i] >= 3 || T[j] % 2 == 0)) return false;
        return true;
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
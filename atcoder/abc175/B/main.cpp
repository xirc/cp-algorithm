#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<ll> L;

    cin >> N;
    L.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }

    int triangles = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (L[i] == L[j]) continue;
            for (int k = j + 1; k < N; ++k) {
                if (L[i] == L[k] || L[j] == L[k]) continue;
                if (L[i] + L[j] <= L[k]) continue;
                if (L[i] + L[k] <= L[j]) continue;
                if (L[j] + L[k] <= L[i]) continue;
                ++triangles;
            }
        }
    }
    cout << triangles << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> ds;

    cin >> N;
    ds.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> ds[i];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ans += ds[i] * ds[j];
        }
    }
    cout << ans << endl;

    return 0;
}
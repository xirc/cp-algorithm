#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> H;

    cin >> N;
    H.assign(N, 0);
    for (auto &h : H) cin >> h;

    vector<int> ps(N, 0);
    for (int i = N - 2; i >= 0; --i) {
        if (H[i] >= H[i+1]) ps[i] += ps[i+1] + 1;
        else ps[i] = 0;
    }
    int ans = *max_element(ps.begin(), ps.end());
    cout << ans << endl;

    return 0;
}
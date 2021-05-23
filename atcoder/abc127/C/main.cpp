#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> L, R;

    cin >> N >> M;
    L.assign(M, 0);
    R.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> L[i] >> R[i];
        --L[i], --R[i];
    }

    int l = *max_element(L.begin(), L.end());
    int r = *min_element(R.begin(), R.end());
    int ans = max(r - l + 1, 0);
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W;
    cin >> H >> W;

    vector<int> A(H * W);
    for (int i = 0; i < H * W; ++i) {
        cin >> A[i];
    }
    int mini = *min_element(A.begin(), A.end());
    int ans = accumulate(A.begin(), A.end(), 0, [&](int s, int v) {
        return s + (v - mini);
    });
    cout << ans << endl;

    return 0;
}
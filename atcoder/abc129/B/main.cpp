#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> W;
    cin >> N;
    W.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    int ans = 100000;
    int total = accumulate(W.begin(), W.end(), 0, plus<int>());
    int acc = 0;
    for (int i = 0; i < N - 1; ++i) {
        acc += W[i];
        ans = min(ans, abs(total - 2 * acc));
    }
    cout << ans << endl;

    return 0;
}
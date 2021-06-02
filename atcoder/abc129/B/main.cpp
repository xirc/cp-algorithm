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
    int sum = accumulate(W.begin(), W.end(), 0, plus<int>());
    int prefix_sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        sum += W[i];
        ans = min(ans, abs(sum - 2 * prefix_sum));
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int const M = 1000000 + 2;
    vector<int> D(M, 0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        D[a]++;
        D[b+1]--;
    }
    int ans = D[0];
    for (int i = 1; i < M; ++i) {
        D[i] += D[i-1];
        ans = max(ans, D[i]);
    }
    cout << ans << endl;

    return 0;
}
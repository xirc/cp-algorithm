#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int N, int K) {
    int v = 1;
    for (int i = 0; i < N; ++i) {
        int nv1 = v * 2, nv2 = v + K;
        v = min(nv1, nv2);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    cout << solve(N, K) << endl;

    return 0;
}
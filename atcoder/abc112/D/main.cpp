#include <bits/stdc++.h>

using namespace std;

int solve(int N, int M) {
    int ans = 1;
    for (int i = 1; i * i <= M; ++i) {
        if (M % i != 0) continue;
        if (M / i >= N) {
            ans = max(ans, i);
        }
        int j = M / i;
        if (M / j >= N) {
            ans = max(ans, j);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    cout << solve(N, M) << endl;

    return 0;
}